
`timescale 1ns/1ps
// avgpool_module.v
// Global average pooling module - PURE VERILOG
// Averages each channel across spatial dimensions

module avgpool_module #(
  parameter integer H_IN = 8,       // input height
  parameter integer W_IN = 8,       // input width
  parameter integer CH = 56,        // channels
  parameter integer IN_SIZE = 3584  // H_IN * W_IN * CH
) (
  input wire clk,
  input wire rst_n,
  input wire start,
  output reg done
);

// Internal memories
reg signed [31:0] input_fm [0:IN_SIZE-1];
reg signed [31:0] output_vec [0:CH-1];

// Helper function
function integer idx_in;
  input integer ih, iw, ic;
  begin
    idx_in = ((ih * W_IN) + iw) * CH + ic;
  end
endfunction

// Sign extend helper
function signed [63:0] sx64;
  input signed [31:0] v;
  begin
    sx64 = {{32{v[31]}}, v};
  end
endfunction

integer i, j, oc, tmp_int;
reg signed [63:0] sum;
localparam integer TOTAL_PIXELS = H_IN * W_IN;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    done <= 1'b0;
  end else begin
    done <= done;
    
    if (start) begin
      done <= 1'b0;
      
      // Global average pooling
      for (oc = 0; oc < CH; oc = oc + 1) begin
        sum = 64'sd0;
        
        for (i = 0; i < H_IN; i = i + 1) begin
          for (j = 0; j < W_IN; j = j + 1) begin
            sum = sum + sx64(input_fm[idx_in(i, j, oc)]);
          end
        end
        
        // Divide by total pixels with rounding
        tmp_int = $signed((sum + (TOTAL_PIXELS/2)) / TOTAL_PIXELS);
        output_vec[oc] = $signed(tmp_int);
      end
      
      done <= 1'b1;
    end
  end
end

endmodule
