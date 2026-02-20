import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
import torchvision.transforms as transforms
from torch.utils.data import DataLoader

# Brevitas & FINN Imports
import brevitas.nn as qnn
from brevitas.quant import Int8WeightPerTensorFloat as WeightQuant
from brevitas.quant import Uint8ActPerTensorFloat as UActQuant
from brevitas.export import QONNXManager

# ==========================================
# 1. Model Architecture Definition
# ==========================================
class ZyboResNetBlock(nn.Module):
    def __init__(self, in_channels, out_channels):
        super(ZyboResNetBlock, self).__init__()
        self.conv1 = qnn.QuantConv2d(
            in_channels, out_channels, kernel_size=3, padding=1, 
            weight_quant=WeightQuant, weight_bit_width=4
        )
        self.bn1 = nn.BatchNorm2d(out_channels)
        
        self.relu1 = qnn.QuantReLU(
            act_quant=UActQuant, bit_width=4, return_quant_tensor=True
        )
        
    def forward(self, x):
        x = self.conv1(x)
        x = self.bn1(x)
        x = self.relu1(x)
        return x

class ZyboResNet(nn.Module):
    def __init__(self):
        super(ZyboResNet, self).__init__()
        
        self.quant_inp = qnn.QuantIdentity(
            act_quant=UActQuant, bit_width=8, return_quant_tensor=True
        )
        
        self.block1 = ZyboResNetBlock(3, 16)
        self.pool1 = nn.MaxPool2d(2) 
        
        self.block2 = ZyboResNetBlock(16, 32)
        self.pool2 = nn.MaxPool2d(2) 
        
        self.flatten = nn.Flatten()
        
        self.fc = qnn.QuantLinear(
            1568, 10, bias=True, 
            weight_quant=WeightQuant, weight_bit_width=4
        )

    def forward(self, x):
        x = self.quant_inp(x) 
        x = self.block1(x)
        x = self.pool1(x)
        x = self.block2(x)
        x = self.pool2(x)
        x = self.flatten(x)
        x = self.fc(x)
        return x

# ==========================================
# 2. Setup & Real Training Loop (GPU Accelerated)
# ==========================================
def main():
    # Detect GPU
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"🔥 Using device: {device}")

    print("⚙️ Initializing ZyboResNet...")
    # Move model to GPU
    model = ZyboResNet().to(device)
    
    transform = transforms.Compose([
        transforms.Resize((28, 28)),
        transforms.ToTensor()
    ])
    
    print("📂 Downloading/Loading Real Dataset (CIFAR-10)...")
    train_dataset = torchvision.datasets.CIFAR10(
        root='./data', train=True, download=True, transform=transform
    )
    dataloader = DataLoader(train_dataset, batch_size=32, shuffle=True)
    
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.001)

    print("🚀 Starting 30-Epoch GPU Training Pass...")
    model.train()
    
    epochs = 30
    for epoch in range(epochs): 
        running_loss = 0.0
        for batch_idx, (data, target) in enumerate(dataloader):
            # Move data and labels to GPU
            data, target = data.to(device), target.to(device)
            
            optimizer.zero_grad()
            output = model(data)
            loss = criterion(output, target)
            loss.backward()
            optimizer.step()
            running_loss += loss.item()
            
        print(f"Epoch {epoch+1}/{epochs} Complete | Avg Loss: {running_loss/len(dataloader):.4f}")
            
    print("✅ Training complete. Saving PyTorch weights...")
    torch.save(model.state_dict(), "zybo_resnet_unsigned.pth")

    # ==========================================
    # 3. Hardware Export (QONNX for FINN)
    # ==========================================
    print("📦 Exporting to FINN-compatible QONNX format...")
    
    # CRITICAL: Move model back to CPU before tracing for ONNX export!
    model.cpu()
    model.eval()
    
    export_dummy_input = torch.randn(1, 3, 28, 28) # CPU dummy input
    
    QONNXManager.export(
        model, 
        input_shape=(1, 3, 28, 28), 
        export_path="zybo_resnet.onnx"
    )
    
    print("🎉 Success! 'zybo_resnet.onnx' generated and ready for the Docker container.")

if __name__ == "__main__":
    main()
