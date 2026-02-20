`timescale 1ns/1ps
// conv2d_module.v
// Parametrized 2D convolution module - PURE VERILOG
// No array ports - uses internal registers accessed by top module

module conv2d_module #(
  parameter integer H_IN = 32,
  parameter integer W_IN = 32,
  parameter integer CH_IN = 3,
  parameter integer CH_OUT = 28,
  parameter integer K_SIZE = 3,
  parameter integer SCALE = 128,
  parameter integer APPLY_RELU = 1,
  parameter integer PADDING = 1,
  parameter integer IN_SIZE = 3072,    // H_IN*W_IN*CH_IN
  parameter integer K_SIZE_TOTAL = 756, // K_SIZE*K_SIZE*CH_IN*CH_OUT
  parameter integer OUT_SIZE = 28672   // H_IN*W_IN*CH_OUT
) (
  input wire clk,
  input wire rst_n,
  input wire start,
  output reg done
);

// Internal memories - top module will access these directly via hierarchy
reg signed [31:0] input_fm [0:IN_SIZE-1];
reg signed [31:0] kernel [0:K_SIZE_TOTAL-1];
reg signed [31:0] bias [0:CH_OUT-1];
reg signed [31:0] output_fm [0:OUT_SIZE-1];

function integer idx_in;
  input integer ih, iw, ic;
  begin
    idx_in = ((ih * W_IN) + iw) * CH_IN + ic;
  end
endfunction

function integer idx_k;
  input integer kh, kw, ic, oc;
  begin
    idx_k = (((kh * K_SIZE + kw) * CH_IN + ic) * CH_OUT) + oc;
  end
endfunction

function integer idx_out;
  input integer oh, ow, oc;
  begin
    idx_out = ((oh * W_IN) + ow) * CH_OUT + oc;
  end
endfunction

function signed [63:0] sx64;
  input signed [31:0] v;
  begin
    sx64 = {{32{v[31]}}, v};
  end
endfunction

integer i, j, kh, kw, ic, oc;
integer ih, iw;
integer tmp_int;
reg signed [63:0] sum;
reg signed [63:0] prod;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    done <= 1'b0;
  end else begin
    done <= done;
    
    if (start) begin
      done <= 1'b0;
      
      for (i = 0; i < H_IN; i = i + 1) begin
        for (j = 0; j < W_IN; j = j + 1) begin
          for (oc = 0; oc < CH_OUT; oc = oc + 1) begin
            sum = 64'sd0;
            
            for (kh = 0; kh < K_SIZE; kh = kh + 1) begin
              for (kw = 0; kw < K_SIZE; kw = kw + 1) begin
                if (PADDING == 1) begin
                  ih = i + kh - (K_SIZE/2);
                  iw = j + kw - (K_SIZE/2);
                end else begin
                  ih = i + kh;
                  iw = j + kw;
                end
                
                if (ih >= 0 && ih < H_IN && iw >= 0 && iw < W_IN) begin
                  for (ic = 0; ic < CH_IN; ic = ic + 1) begin
                    prod = sx64(kernel[idx_k(kh, kw, ic, oc)]) * 
                           sx64(input_fm[idx_in(ih, iw, ic)]);
                    sum = sum + prod;
                  end
                end
              end
            end
            
            tmp_int = $signed((sum + (SCALE/2)) / SCALE);
            output_fm[idx_out(i, j, oc)] = $signed(tmp_int) + bias[oc];
            
            if (APPLY_RELU == 1) begin
              if (output_fm[idx_out(i, j, oc)] < 0) begin
                output_fm[idx_out(i, j, oc)] = 32'sd0;
              end
            end
          end
        end
      end
      
      done <= 1'b1;
    end
  end
end

endmodule

