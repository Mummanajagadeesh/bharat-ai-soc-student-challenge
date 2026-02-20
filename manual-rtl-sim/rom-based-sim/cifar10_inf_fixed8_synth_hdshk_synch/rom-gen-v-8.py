import os
import numpy as np

# === CONFIGURATION ===
input_folder = "model_weights_fixed8"   # folder with already quantized Q1.7 ints
output_folder = "verilog_roms_genv_16"
os.makedirs(output_folder, exist_ok=True)

TOTAL_BITS = 8  # Q1.7 = 8 bits total (1 sign + 0 integer + 7 fractional)

def sanitize_name(filename):
    """Convert filename to a valid Verilog module name."""
    return filename.replace(".txt", "").replace("-", "_").replace(".", "_")

def get_signed_str(val, bits=TOTAL_BITS):
    """
    Returns Verilog-style signed decimal.
    Example: -8'd123 or 8'd45
    """
    val = int(val)
    return f"{'-' if val < 0 else ''}{bits}'d{abs(val)}"

def load_and_shape_array(filepath):
    """Load already-quantized fixed-point values as int8."""
    arr = np.loadtxt(filepath, dtype=np.int8)  # match Q1.7 8-bit format
    if arr.ndim == 1:
        arr = arr.reshape(-1, 1)
    return arr

def generate_2d_rom_module(name, array):
    """Generate Verilog ROM module for a 2D array."""
    rows, cols = array.shape
    module_name = f"rom_{name}"

    # ROM initialization lines
    lines = []
    for i in range(rows):
        for j in range(cols):
            val = array[i][j]
            lines.append(f"        rom[{i}][{j}] = {get_signed_str(val)};")

    init_body = "\n".join(lines)

    verilog = f"""module {module_name} (
    input  wire [15:0] row,
    input  wire [15:0] col,
    output reg signed [{TOTAL_BITS-1}:0] data
);

    // Q1.7 fixed-point format ({TOTAL_BITS} bits total)
    reg signed [{TOTAL_BITS-1}:0] rom [0:{rows-1}][0:{cols-1}];

    initial begin
{init_body}
    end

    always @(*) begin
        data = rom[row][col];
    end

endmodule
"""
    return verilog

def process_file(filepath):
    filename = os.path.basename(filepath)
    name = sanitize_name(filename)

    arr = load_and_shape_array(filepath)
    verilog_code = generate_2d_rom_module(name, arr)

    output_path = os.path.join(output_folder, f"rom_{name}.v")
    with open(output_path, "w") as f:
        f.write(verilog_code)

    print(f"✅ Generated: rom_{name}.v   ({arr.shape[0]}x{arr.shape[1]})")

# === MAIN ===
if __name__ == "__main__":
    for file in sorted(os.listdir(input_folder)):
        if file.endswith(".txt"):
            process_file(os.path.join(input_folder, file))
