import finn.builder.build_dataflow as build
import finn.builder.build_dataflow_config as build_cfg
import finn.util.basic as finn_basic
import finn.transformation.fpgadataflow.templates as finn_templates
import re

# =========================================================================
# CRITICAL FIX 1: Inject board into FINN's Python registries
# Physical board: Digilent Zybo (original, B.4)
# FPGA: xc7z010clg400-1 (same silicon as Zybo Z7-10)
# =========================================================================
finn_basic.pynq_part_map["Zybo-Z7-10"] = "xc7z010clg400-1"
finn_basic.pynq_native_port_width["Zybo-Z7-10"] = 32
print("✅ Fix 1: Python board registry patched.")

# =========================================================================
# CRITICAL FIX 2: Bypass AXI-Lite interface limit (9 → 99)
# =========================================================================
template_path = finn_templates.__file__

with open(template_path, "r") as f:
    template_code = f.read()

if 'if {$NUM_AXILITE > 9}' in template_code:
    template_code = template_code.replace(
        'if {$NUM_AXILITE > 9}',
        'if {$NUM_AXILITE > 99}'
    )
    print("✅ Fix 2: AXI-Lite limit raised to 99.")

# =========================================================================
# CRITICAL FIX 3: Inject Zybo board branch into TCL if/elseif chain
# Uses the Zybo B.4 board_part string from the installed board files at:
# /tools/Xilinx/Vivado/2022.2/data/boards/board_files/zybo/B.4/board.xml
# =========================================================================
ZYBO_BRANCH = """} elseif {$BOARD == "Zybo-Z7-10"} {
    set ZYNQ_TYPE "zynq_7000"
    set_property board_part xilinx.com:zybo:part0:B.4 [current_project]
"""

TCL_ELSE_ANCHOR = '} else {\n    puts "Unrecognized board"\n'

if 'Zybo-Z7-10' not in template_code:
    # First time — inject the branch
    if TCL_ELSE_ANCHOR in template_code:
        template_code = template_code.replace(
            TCL_ELSE_ANCHOR,
            ZYBO_BRANCH + TCL_ELSE_ANCHOR
        )
        print("✅ Fix 3: Zybo TCL branch injected.")
    else:
        print("❌ Fix 3 FAILED: else anchor not found.")
else:
    # Branch already exists — just correct the board_part string
    template_code = re.sub(
        r'(elseif \{\$BOARD == "Zybo-Z7-10"\} \{\s*\n\s*set ZYNQ_TYPE "zynq_7000"\s*\n\s*set_property board_part )\S+( \[current_project\])',
        r'\1xilinx.com:zybo:part0:B.4\2',
        template_code
    )
    print("✅ Fix 3: Zybo TCL branch board_part corrected to xilinx.com:zybo:part0:B.4")

with open(template_path, "w") as f:
    f.write(template_code)

# =========================================================================
# VERIFY: Print the Zybo block so you can confirm it looks right
# =========================================================================
print("\n--- Verifying Zybo block in template ---")
idx = template_code.find('Zybo-Z7-10')
if idx >= 0:
    print(template_code[idx-2:idx+180])
print("----------------------------------------\n")

# =========================================================================
# Build Configuration
# =========================================================================
model_file = "zybo_resnet.onnx"

cfg = build_cfg.DataflowBuildConfig(
    output_dir          = "output_hardware",
    target_fps          = 10,
    synth_clk_period_ns = 10.0,
    board               = "Zybo-Z7-10",
    fpga_part           = "xc7z010clg400-1",
    shell_flow_type     = build_cfg.ShellFlowType.VIVADO_ZYNQ,
    generate_outputs    = [
        build_cfg.DataflowOutputType.BITFILE,
        build_cfg.DataflowOutputType.PYNQ_DRIVER,
    ]
)

print("🚀 Starting FINN Hardware Build for Zybo (original, B.4)...")
build.build_dataflow_cfg(model_file, cfg)
print("✅ Build Complete!")
