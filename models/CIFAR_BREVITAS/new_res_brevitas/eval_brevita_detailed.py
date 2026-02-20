import os
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
# 3. DATA LOADING (CUSTOM SAMPLE IMAGES)
# ==========================================
print("📦 Loading Custom Sample Images...")
transform = transforms.Compose([
    transforms.Resize((28, 28)), # CRITICAL: Resize to match hardware specs!
    transforms.ToTensor(),
])

# Use ImageFolder to read the directory structure dynamically
testset = datasets.ImageFolder(root='./sample_images', transform=transform)
testloader = torch.utils.data.DataLoader(testset, batch_size=64, shuffle=False, 
                                         num_workers=2, pin_memory=True)

# Grab the class names (e.g., ['airplane', 'automobile', ...])
class_names = testset.classes

# ==========================================
# 4. INITIALIZE MODEL & LOAD WEIGHTS
# ==========================================
model = ZyboResNet().to(device)

print("💾 Loading trained PyTorch weights...")
model.load_state_dict(torch.load("zybo_resnet_unsigned.pth", map_location=device))
model.to(device)

# CRITICAL: Put the model in evaluation mode to freeze BatchNorm and Dropout
model.eval()

# ==========================================
# 5. EVALUATION LOOP
# ==========================================
print(f"🎯 Testing accuracy on {len(testset)} sample images...\n")
print(f"{'FILENAME':<18} | {'TRUE LABEL':<12} | {'PREDICTION':<12} | {'STATUS'}")
print("-" * 65)

correct = 0
total = 0
global_idx = 0  # To track our position in the dataset

with torch.no_grad():
    for inputs, labels in testloader:
        inputs, labels = inputs.to(device), labels.to(device)
        
        # Get predictions
        outputs = model(inputs)
        _, predicted = torch.max(outputs.data, 1)
        
        # Iterate through this specific batch
        for i in range(inputs.size(0)):
            true_label_idx = labels[i].item()
            pred_label_idx = predicted[i].item()
            
            # Extract the filename using our global index
            filepath = testset.samples[global_idx][0]
            filename = os.path.basename(filepath)
            
            # Map indices to actual text labels
            true_label_text = class_names[true_label_idx]
            pred_label_text = class_names[pred_label_idx]
            
            # Check correctness
            is_correct = (true_label_idx == pred_label_idx)
            status = "✅ Correct" if is_correct else "❌ Incorrect"
            
            # Print row
            print(f"{filename:<18} | {true_label_text:<12} | {pred_label_text:<12} | {status}")
            
            # Tally up
            if is_correct:
                correct += 1
            total += 1
            global_idx += 1

accuracy = 100 * correct / total
print("=================================================================")
print(f"🏆 Final Test Accuracy: {accuracy:.2f}% ({correct}/{total} correct)")
print("=================================================================")
