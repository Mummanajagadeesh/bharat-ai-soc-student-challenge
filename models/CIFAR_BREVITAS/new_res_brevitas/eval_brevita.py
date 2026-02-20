import torch
import torch.nn as nn
from torchvision import datasets, transforms

# Brevitas Quantization Imports
import brevitas.nn as qnn
from brevitas.quant import Int8WeightPerTensorFloat as WeightQuant
from brevitas.quant import Int8ActPerTensorFloat as ActQuant
from brevitas.quant import Uint8ActPerTensorFloat as UActQuant

# ==========================================
# 1. HARDWARE CONFIGURATION
# ==========================================
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"🚀 Initializing Evaluation... Using device: {device}")

# ==========================================
# 2. MODEL DEFINITION
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
# 3. DATA LOADING (CUSTOM SAMPLE IMAGES)
# ==========================================
print("📦 Loading Custom Sample Images...")
transform = transforms.Compose([
    transforms.ToTensor(),
])

# Use ImageFolder to read the directory structure dynamically
testset = datasets.ImageFolder(root='./sample_images', transform=transform)
testloader = torch.utils.data.DataLoader(testset, batch_size=64, shuffle=False, 
                                         num_workers=2, pin_memory=True)

# ==========================================
# 4. INITIALIZE MODEL & LOAD WEIGHTS
# ==========================================
model = ZyboResNet().to(device)

print("💾 Loading trained PyTorch weights...")
model.load_state_dict(torch.load("zybo_resnet.pth", map_location=device))

# CRITICAL: Put the model in evaluation mode to freeze BatchNorm and Dropout
model.to('cuda')
model.eval()

# ==========================================
# 5. EVALUATION LOOP
# ==========================================
# testset.targets holds the labels; len(testset) is the total number of images (100)
print(f"🎯 Testing accuracy on {len(testset)} sample images...")

correct = 0
total = 0

with torch.no_grad():
    for inputs, labels in testloader:
        inputs, labels = inputs.to(device), labels.to(device)
        
        # Get predictions
        outputs = model(inputs)
        
        # The class with the highest energy is what we choose as prediction
        _, predicted = torch.max(outputs.data, 1)
        
        # Tally up the results
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

accuracy = 100 * correct / total
print("==========================================")
print(f"✅ Final Test Accuracy: {accuracy:.2f}%")
print("==========================================")
