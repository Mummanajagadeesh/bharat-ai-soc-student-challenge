import torch
import torch.nn as nn
import brevitas.nn as qnn
from brevitas.quant import Int8WeightPerTensorFloat as WeightQuant
from brevitas.quant import Int8ActPerTensorFloat as ActQuant
class ZyboResNet(nn.Module):
    def __init__(self):
        super(ZyboResNet, self).__init__()

        # Initial Scaling
        self.input_quant = qnn.QuantIdentity(act_quant=ActQuant, bit_width=8, return_quant_tensor=True)

        # === Block 1 ===
        self.conv1a = qnn.QuantConv2d(3, 28, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn1a = nn.BatchNorm2d(28)
        self.relu1a = qnn.QuantReLU(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)

        self.conv1b = qnn.QuantConv2d(28, 28, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn1b = nn.BatchNorm2d(28)

        # Shortcut 1
        self.shortcut1 = qnn.QuantConv2d(3, 28, 1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.add1 = qnn.QuantEltwiseAdd(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.pool1 = nn.MaxPool2d(2)

        # === Block 2 ===
        self.conv2a = qnn.QuantConv2d(28, 56, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn2a = nn.BatchNorm2d(56)
        self.relu2a = qnn.QuantReLU(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)

        self.conv2b = qnn.QuantConv2d(56, 56, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn2b = nn.BatchNorm2d(56)

        # Shortcut 2
        self.shortcut2 = qnn.QuantConv2d(28, 56, 1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.add2 = qnn.QuantEltwiseAdd(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.pool2 = nn.MaxPool2d(2)

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
import torch.optim as optim
from torchvision import datasets, transforms

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Training on device: {device}")

# Data Setup
transform = transforms.Compose([
    transforms.RandomHorizontalFlip(),
    transforms.ToTensor(),
])

trainset = datasets.CIFAR10(root='./data', train=True, download=True, transform=transform)
# Tip: num_workers speeds up data loading, pin_memory speeds up CPU-to-GPU transfer
trainloader = torch.utils.data.DataLoader(trainset, batch_size=64, shuffle=True,
                                          num_workers=2, pin_memory=True)

# 2. MOVE THE MODEL TO THE GPU
model = ZyboResNet().to(device)

optimizer = optim.Adam(model.parameters(), lr=0.001)
criterion = nn.CrossEntropyLoss()

# 3. THE TRAINING LOOP
for epoch in range(30):
    model.train() # Set model to training mode
    running_loss = 0.0

    for i, (inputs, labels) in enumerate(trainloader):
        # MOVE THE DATA TO THE GPU
        # This must happen inside the loop for every single batch
        inputs, labels = inputs.to(device), labels.to(device)

        # Standard PyTorch Training Steps
        optimizer.zero_grad()
        outputs = model(inputs)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

    print(f"Epoch {epoch+1} complete. Average Loss: {running_loss / len(trainloader):.4f}")

# Save the trained weights
torch.save(model.state_dict(), "zybo_resnet.pth")
print("Training complete and model saved!")
