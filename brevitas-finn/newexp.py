from brevitas.export import QONNXManager
import torch
import torch.nn as nn
import brevitas.nn as qnn
from brevitas.quant import Int8WeightPerTensorFloat as WeightQuant
from brevitas.quant import Int8ActPerTensorFloat as ActQuant
from brevitas.export import export_qonnx
import torch._dynamo

# 1. MODEL DEFINITION (Required to load the .pth weights)
class ZyboResNet(nn.Module):
    def __init__(self):
        super(ZyboResNet, self).__init__()
        self.input_quant = qnn.QuantIdentity(act_quant=ActQuant, bit_width=8, return_quant_tensor=True)
        self.conv1a = qnn.QuantConv2d(3, 28, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn1a = nn.BatchNorm2d(28)
        self.relu1a = qnn.QuantReLU(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.conv1b = qnn.QuantConv2d(28, 28, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn1b = nn.BatchNorm2d(28)
        self.shortcut1 = qnn.QuantConv2d(3, 28, 1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.add1 = qnn.QuantEltwiseAdd(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.pool1 = nn.MaxPool2d(2)

        self.conv2a = qnn.QuantConv2d(28, 56, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn2a = nn.BatchNorm2d(56)
        self.relu2a = qnn.QuantReLU(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.conv2b = qnn.QuantConv2d(56, 56, 3, padding=1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.bn2b = nn.BatchNorm2d(56)
        self.shortcut2 = qnn.QuantConv2d(28, 56, 1, weight_quant=WeightQuant, weight_bit_width=4, bias=False)
        self.add2 = qnn.QuantEltwiseAdd(act_quant=ActQuant, bit_width=4, return_quant_tensor=True)
        self.pool2 = nn.MaxPool2d(2)

        self.gap = nn.AdaptiveAvgPool2d(1)
        self.fc = qnn.QuantLinear(56, 10, weight_quant=WeightQuant, weight_bit_width=4, bias=True)

    def forward(self, x):
        x = self.input_quant(x)
        s1 = self.shortcut1(x)
        x = self.relu1a(self.bn1a(self.conv1a(x)))
        x = self.bn1b(self.conv1b(x))
        x = self.pool1(self.add1(x, s1))
        
        s2 = self.shortcut2(x)
        x = self.relu2a(self.bn2a(self.conv2a(x)))
        x = self.bn2b(self.conv2b(x))
        x = self.pool2(self.add2(x, s2))
        
        x = self.gap(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x

# 2. INITIALIZATION & LOADING
print("🔄 Loading model architecture...")
model = ZyboResNet()

print("📂 Loading trained weights from zybo_resnet.pth...")
# map_location='cpu' ensures we don't crash if the weights were trained on a GPU
model.load_state_dict(torch.load("zybo_resnet.pth", map_location=torch.device('cpu')))

# 3. PREPARE FOR EXPORT
# Freeze the layers (like BatchNorm) so they become static hardware constants
model.eval()

# Disable Dynamo to force the legacy TorchScript exporter that Brevitas requires
torch._dynamo.config.disable = True

# Create a dummy image tensor (Batch Size 1, 3 Channels, 32x32)
dummy_input = torch.randn(1, 3, 28, 28)
#dummy_input = torch.randn(1, 3, 32, 32)
output_filename = "zybo_resnet.onnx"

# 4. EXPORT TO QONNX
print("⚙️ Exporting PyTorch graph to QONNX hardware nodes...")
#export_qonnx(model, dummy_input, export_path=output_filename)
QONNXManager.export(model, dummy_input, export_path="zybo_resnet.onnx")
print(f"✅ Success! Your model is compiled and saved as: {output_filename}")
