import torch
import torch.nn as nn
import torch.optim as optim
from torchvision import datasets, transforms

# Brevitas Quantization Imports
import brevitas.nn as qnn
from brevitas.quant import Int8WeightPerTensorFloat as WeightQuant
from brevitas.quant import Int8ActPerTensorFloat as ActQuant
from brevitas.quant import Uint8ActPerTensorFloat as UActQuant
from brevitas.export import export_qonnx

# ==========================================
# 1. HARDWARE CONFIGURATION
# ==========================================
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"🚀 Initializing Training... Using device: {device}")

# ==========================================
# 2. MODEL DEFINITION (Zybo xc7z010 friendly)
# ==========================================
class ZyboResNet(nn.Module):
    def __init__(self):
        super(ZyboResNet, self).__init__()
        
        # Initial Scaling: Prepares the input image
        self.input_quant = qnn.QuantIdentity(act_quant=ActQuant, bit_width=8, return_quant_tensor=True)

        # --- Block 1 (28 Filters) ---
        self.conv1a = qnn.QuantConv2d(3, 28, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn1a = nn.BatchNorm2d(28)
        self.relu1a = qnn.QuantReLU(act_quant=UActQuant, bit_width=4, return_quant_tensor=True)
        
        self.conv1b = qnn.QuantConv2d(28, 28, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn1b = nn.BatchNorm2d(28)
        
        # Shortcut 1
        self.shortcut1 = qnn.QuantConv2d(3, 28, 1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.add1 = qnn.QuantEltwiseAdd(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.pool1 = nn.MaxPool2d(2)

        # --- Block 2 (56 Filters) ---
        self.conv2a = qnn.QuantConv2d(28, 56, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn2a = nn.BatchNorm2d(56)
        self.relu2a = qnn.QuantReLU(act_quant=UActQuant, bit_width=4, return_quant_tensor=True)
        
        self.conv2b = qnn.QuantConv2d(56, 56, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn2b = nn.BatchNorm2d(56)
        
        # Shortcut 2
        self.shortcut2 = qnn.QuantConv2d(28, 56, 1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.add2 = qnn.QuantEltwiseAdd(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.pool2 = nn.MaxPool2d(2)

        # --- Output Head ---
        self.gap = nn.AdaptiveAvgPool2d(1)
        self.fc = qnn.QuantLinear(56, 10, weight_quant=WeightQuant, weight_bit_width=4, bias=True)

    def forward(self, x):
        x = self.input_quant(x)
        
        # Block 1
        s1 = self.shortcut1(x)
        x = self.relu1a(self.bn1a(self.conv1a(x)))
        x = self.bn1b(self.conv1b(x))
        x = self.pool1(self.add1(x, s1))
        
        # Block 2
        s2 = self.shortcut2(x)
        x = self.relu2a(self.bn2a(self.conv2a(x)))
        x = self.bn2b(self.conv2b(x))
        x = self.pool2(self.add2(x, s2))
        
        x = self.gap(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x

# ==========================================
# 3. DATA LOADING (CIFAR-10)
# ==========================================
print("📦 Loading CIFAR-10 Dataset...")
transform = transforms.Compose([
    transforms.RandomHorizontalFlip(),
    transforms.ToTensor(),
])

trainset = datasets.CIFAR10(root='./data', train=True, download=True, transform=transform)
trainloader = torch.utils.data.DataLoader(trainset, batch_size=64, shuffle=True, 
                                          num_workers=2, pin_memory=True)

# ==========================================
# 4. INITIALIZATION
# ==========================================
model = ZyboResNet().to(device)
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

EPOCHS = 30 # Adjust this based on how much time you have

# ==========================================
# 5. TRAINING LOOP
# ==========================================
print(f"🔥 Starting Training for {EPOCHS} Epochs...")
for epoch in range(EPOCHS):
    model.train() # Set model to training mode
    running_loss = 0.0
    
    for i, (inputs, labels) in enumerate(trainloader):
        # Move data to GPU
        inputs, labels = inputs.to(device), labels.to(device)

        # Forward pass & backpropagation
        optimizer.zero_grad()
        outputs = model(inputs)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()
        
        running_loss += loss.item()
        
    print(f"   Epoch [{epoch+1}/{EPOCHS}] | Average Loss: {running_loss / len(trainloader):.4f}")

# ==========================================
# 6. EXPORT TO FINN (QONNX)
# ==========================================
print("💾 Training complete. Saving and exporting model...")

# Save the raw PyTorch weights just in case
torch.save(model.state_dict(), "zybo_resnet.pth")

# Critical: Switch to Evaluation Mode to freeze BatchNorm for hardware
model.eval()

# To use export_qonnx, we need a dummy input tensor on the same device as the model
dummy_input = torch.randn(1, 3, 32, 32).to(device)
output_filename = "zybo_resnet.onnx"

print("⚙️ Translating PyTorch logic into QONNX hardware nodes...")
export_qonnx(model, dummy_input, export_path=output_filename)

print(f"✅ Success! Your model is compiled and saved as: {output_filename}")
print("   You are now ready to open the FINN Docker container!")
