#!/usr/bin/env python3
import os
import glob

WEIGHT_DIR = "model_weights_fixed8"

def int8_to_hex(val):
    """
    Convert signed int to 8-bit two's complement hex
    """
    if val < 0:
        val = (1 << 8) + val
    return f"{val & 0xFF:02X}"

def convert_txt_to_mem(txt_path):
    mem_path = txt_path.replace(".txt", ".mem")

    with open(txt_path, "r") as f_in, open(mem_path, "w") as f_out:
        for line_num, line in enumerate(f_in, 1):
            stripped = line.strip()

            # Preserve empty lines exactly
            if stripped == "":
                f_out.write("\n")
                continue

            tokens = stripped.split()
            hex_tokens = []

            for tok in tokens:
                try:
                    val = int(tok)
                except ValueError:
                    raise ValueError(
                        f"Non-integer token in {txt_path} at line {line_num}: '{tok}'"
                    )

                hex_tokens.append(int8_to_hex(val))

            # Preserve single-space separation (clean + predictable)
            f_out.write(" ".join(hex_tokens) + "\n")

    print(f"[OK] {os.path.basename(txt_path)} -> {os.path.basename(mem_path)}")

def main():
    txt_files = sorted(glob.glob(os.path.join(WEIGHT_DIR, "*.txt")))

    if not txt_files:
        print(f"[ERR] No .txt files found in {WEIGHT_DIR}")
        return

    print(f"Converting {len(txt_files)} files...\n")

    for txt_file in txt_files:
        convert_txt_to_mem(txt_file)

    print("\nDone. TXT untouched. MEM files generated.")

if __name__ == "__main__":
    main()
