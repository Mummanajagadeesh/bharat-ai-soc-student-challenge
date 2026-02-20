import os
import numpy as np

# === PARAMETERS ===
input_dir = "model_weights"               # original float weights
fixed_dir = "model_weights_fixed8"        # Q1.7 fixed-point
recon_dir = "model_weights_2"             # reconstructed float weights from fixed-point
verilog_dir = "verilog_roms_mems"         # output directory for roms + mems

TOTAL_BITS = 8
FRAC_BITS = 7                             # Q1.7 format
SCALE = 1 << FRAC_BITS                    # 128
MAX_VAL = (1 << (TOTAL_BITS - 1)) - 1     # 127
MIN_VAL = -(1 << (TOTAL_BITS - 1))        # -128

os.makedirs(fixed_dir, exist_ok=True)
os.makedirs(recon_dir, exist_ok=True)
os.makedirs(verilog_dir, exist_ok=True)

overflow_count = 0

def float_to_fixed_str(num_str):
    """Convert float string to fixed-point int string, preserving empty lines."""
    global overflow_count
    if not num_str.strip():
        return ""
    val = float(num_str)
    fixed_val = int(round(val * SCALE))
    if fixed_val > MAX_VAL:
        fixed_val = MAX_VAL
        overflow_count += 1
    elif fixed_val < MIN_VAL:
        fixed_val = MIN_VAL
        overflow_count += 1
    return str(fixed_val)

def fixed_to_float_str(num_str):
    """Convert fixed-point int string back to float string, preserving empty lines."""
    if not num_str.strip():
        return ""
    val = int(num_str)
    return f"{val / SCALE:.8f}"

# === STEP 1: Float → Q1.7 int8 ===
for filename in os.listdir(input_dir):
    if filename.lower().endswith(".txt"):
        in_path = os.path.join(input_dir, filename)
        fixed_path = os.path.join(fixed_dir, filename)

        with open(in_path, "r") as f:
            lines = f.readlines()

        fixed_lines = []
        for line in lines:
            parts = line.strip().split()
            if not parts:
                fixed_lines.append("\n")
                continue
            fixed_parts = [float_to_fixed_str(p) for p in parts]
            fixed_lines.append(" ".join(fixed_parts) + "\n")

        with open(fixed_path, "w") as f:
            f.writelines(fixed_lines)

print(f"[STEP 1] Fixed-point conversion complete. Overflow count: {overflow_count}")
print(f"Fixed-point files saved in: {fixed_dir}")

# === STEP 2: Q1.7 int8 → Float ===
for filename in os.listdir(fixed_dir):
    if filename.lower().endswith(".txt"):
        fixed_path = os.path.join(fixed_dir, filename)
        recon_path = os.path.join(recon_dir, filename)

        with open(fixed_path, "r") as f:
            lines = f.readlines()

        recon_lines = []
        for line in lines:
            parts = line.strip().split()
            if not parts:
                recon_lines.append("\n")
                continue
            recon_parts = [fixed_to_float_str(p) for p in parts]
            recon_lines.append(" ".join(recon_parts) + "\n")

        with open(recon_path, "w") as f:
            f.writelines(recon_lines)

print(f"[STEP 2] Reconstruction complete. Files saved in: {recon_dir}")

# === STEP 3: Generate Verilog ROMs + .mem files ===
for filename in os.listdir(fixed_dir):
    if filename.lower().endswith(".txt"):
        base_name = os.path.splitext(filename)[0]

        fixed_path = os.path.join(fixed_dir, filename)
        mem_path   = os.path.join(verilog_dir, base_name + ".mem")
        rom_path   = os.path.join(verilog_dir, base_name + "_rom.v")

        # Flatten all numbers into one list
        data = []
        with open(fixed_path, "r") as f:
            for line in f:
                parts = line.strip().split()
                for p in parts:
                    if p.strip():
                        # Format as 2-digit hex (8-bit, two's complement)
                        val = int(p)
                        hexval = format((val + (1 << TOTAL_BITS)) % (1 << TOTAL_BITS), "02X")
                        data.append(hexval)

        depth = len(data)
        addr_width = (depth - 1).bit_length() or 1

        # Write .mem file
        with open(mem_path, "w") as f:
            for d in data:
                f.write(d + "\n")

        # Write Verilog ROM module (synchronous)
        rom_code = f"""// Auto-generated ROM for {base_name}
// Depth: {depth}, Width: {TOTAL_BITS}
module rom_{base_name} (
    input  wire                   clk,
    input  wire [{addr_width-1}:0] addr,
    output reg  [{TOTAL_BITS-1}:0] data
);
    reg [{TOTAL_BITS-1}:0] rom [0:{depth-1}];

    initial begin
        $readmemh("verilog_roms_mems/{base_name}.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
"""
        with open(rom_path, "w") as f:
            f.write(rom_code)

print(f"[STEP 3] Verilog ROMs + .mem generated in: {verilog_dir}")
