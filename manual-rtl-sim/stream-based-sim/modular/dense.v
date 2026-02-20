
// ============================================================================
// ============================================================================

`timescale 1ns/1ps
// dense_module.v
// Parametrized dense (fully connected) layer - PURE VERILOG
// Performs: output[j] = sum_i(kernel[i][j] * input[i]) + bias[j]

module dense_module #(
  parameter integer IN_FEATURES = 56,
  parameter integer OUT_FEATURES = 10,
  parameter integer SCALE = 128,
  parameter integer K_SIZE = 560  // IN_FEATURES * OUT_FEATURES
) (
  input wire clk,
  input wire rst_n,
  input wire start,
  output reg done
);

// Internal memories
reg signed [31:0] input_vec [0:IN_FEATURES-1];
reg signed [31:0] kernel [0:K_SIZE-1];
reg signed [31:0] bias [0:OUT_FEATURES-1];
reg signed [31:0] output_vec [0:OUT_FEATURES-1];

// Helper function for kernel indexing: kernel[i][j]
function integer idx_k;
  input integer i, j;
  begin
    idx_k = i * OUT_FEATURES + j;
  end
endfunction

// Sign extend helper
function signed [63:0] sx64;
  input signed [31:0] v;
  begin
    sx64 = {{32{v[31]}}, v};
  end
endfunction

integer i, j, tmp_int;
reg signed [63:0] sum, prod;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    done <= 1'b0;
  end else begin
    done <= done;
    
    if (start) begin
      done <= 1'b0;
      
      // Dense layer computation
      for (j = 0; j < OUT_FEATURES; j = j + 1) begin
        sum = 64'sd0;
        
        for (i = 0; i < IN_FEATURES; i = i + 1) begin
          prod = sx64(kernel[idx_k(i, j)]) * sx64(input_vec[i]);
          sum = sum + prod;
        end
        
        // Scale and add bias
        tmp_int = $signed((sum + (SCALE/2)) / SCALE);
        output_vec[j] = $signed(tmp_int) + bias[j];
      end
      
      done <= 1'b1;
    end
  end
end

endmodule