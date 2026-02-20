import os
import numpy as np

# === CONFIGURATION ===
input_folder = "image_txt"
output_folder = "image_roms_mem"
os.makedirs(output_folder, exist_ok=True)

channels = ["r", "g", "b"]

def load_8bit_image_matrix(filepath):
    """Load a 32x32 image with 8-bit unsigned integers."""
    arr = np.loadtxt(filepath, dtype=np.uint8)
    if arr.size != 1024:
        raise ValueError(f"Expected 1024 values in {filepath}, got {arr.size}")
    return arr.reshape((32, 32))

def write_mem_file(filepath, array):
    """Write a 32x32 array to .mem file in row-major order."""
    with open(filepath, "w") as f:
        for i in range(32):
            for j in range(32):
                f.write(f"{array[i, j]:02X}\n")   # hex (2 digits)

def generate_verilog_rom(name, depth=1024):
    """Generate synchronous ROM Verilog code."""
    module_name = f"image_{name}_rom"
    addr_width = (depth - 1).bit_length()

    return f"""// Auto-generated ROM for image channel {name}
// 32x32 = {depth} pixels, 8-bit
module {module_name} (
    input  wire                  clk,
    input  wire [{addr_width-1}:0] addr,
    output reg  [7:0]            data
);
    reg [7:0] rom [0:{depth-1}];

    initial begin
        $readmemh("image_roms_mem/image_{name}.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
"""

def main():
    for ch in channels:
        filename = f"image_{ch}.txt"
        filepath = os.path.join(input_folder, filename)

        arr = load_8bit_image_matrix(filepath)

        # === 1. Write .mem file ===
        mem_path = os.path.join(output_folder, f"image_{ch}.mem")
        write_mem_file(mem_path, arr)

        # === 2. Write Verilog ROM ===
        verilog_code = generate_verilog_rom(ch, depth=32*32)
        rom_path = os.path.join(output_folder, f"image_{ch}_rom.v")
        with open(rom_path, "w") as f:
            f.write(verilog_code)

        print(f"✅ Generated: {mem_path}, {rom_path}")

if __name__ == "__main__":
    main()
