

`timescale 1ns/1ps
// maxpool_module.v
// Parametrized 2D max pooling module - PURE VERILOG
// Performs 2x2 max pooling with stride 2

module maxpool_module #(
  parameter integer H_IN = 32,      // input height
  parameter integer W_IN = 32,      // input width
  parameter integer CH = 28,        // channels
  parameter integer POOL_SIZE = 2,  // pooling window size
  parameter integer IN_SIZE = 28672,  // H_IN * W_IN * CH
  parameter integer OUT_SIZE = 7168   // (H_IN/2) * (W_IN/2) * CH
) (
  input wire clk,
  input wire rst_n,
  input wire start,
  output reg done
);

// Internal memories
reg signed [31:0] input_fm [0:IN_SIZE-1];
reg signed [31:0] output_fm [0:OUT_SIZE-1];

// Helper functions
function integer idx_in;
  input integer ih, iw, ic;
  begin
    idx_in = ((ih * W_IN) + iw) * CH + ic;
  end
endfunction

function integer idx_out;
  input integer oh, ow, oc;
  begin
    idx_out = ((oh * (W_IN/POOL_SIZE)) + ow) * CH + oc;
  end
endfunction

integer i, j, oc, ph, pw, h0, w0, vh, vw;
integer mv, vv;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    done <= 1'b0;
  end else begin
    done <= done;
    
    if (start) begin
      done <= 1'b0;
      
      // Perform max pooling
      for (i = 0; i < H_IN/POOL_SIZE; i = i + 1) begin
        for (j = 0; j < W_IN/POOL_SIZE; j = j + 1) begin
          for (oc = 0; oc < CH; oc = oc + 1) begin
            h0 = i * POOL_SIZE;
            w0 = j * POOL_SIZE;
            mv = -2147483648; // minimum 32-bit signed value
            
            for (ph = 0; ph < POOL_SIZE; ph = ph + 1) begin
              for (pw = 0; pw < POOL_SIZE; pw = pw + 1) begin
                vh = h0 + ph;
                vw = w0 + pw;
                vv = input_fm[idx_in(vh, vw, oc)];
                if (vv > mv) mv = vv;
              end
            end
            
            output_fm[idx_out(i, j, oc)] = mv;
          end
        end
      end
      
      done <= 1'b1;
    end
  end
end

endmodule

