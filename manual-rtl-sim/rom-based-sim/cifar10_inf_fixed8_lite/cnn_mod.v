`timescale 1ns/1ps
// cifar10_top.v (Fully Modular version - PURE VERILOG)
// Uses separate modules: conv2d, maxpool, avgpool, dense

module cifar10_top (
  input  wire         clk,
  input  wire         rst_n,
  input  wire         wr_en,
  input  wire [4:0]   wr_sel,
  input  wire [15:0]  wr_addr,
  input  wire [31:0]  wr_data,
  input  wire         start,
  output reg          done,
  output reg [3:0]    pred_index,
  output reg [31:0]   logits0,
  output reg [31:0]   logits1,
  output reg [31:0]   logits2,
  output reg [31:0]   logits3,
  output reg [31:0]   logits4,
  output reg [31:0]   logits5,
  output reg [31:0]   logits6,
  output reg [31:0]   logits7,
  output reg [31:0]   logits8,
  output reg [31:0]   logits9
);

localparam integer SCALE = 128;
localparam integer H_IN  = 32;
localparam integer W_IN  = 32;
localparam integer CH_IN = 3;

localparam integer OUT1 = 28;
localparam integer OUT2 = 28;
localparam integer OUT3 = 28;
localparam integer OUT6 = 56;
localparam integer OUT7 = 56;
localparam integer OUT8 = 56;
localparam integer DENSE_IN = 56;
localparam integer DENSE_OUT = 10;

localparam integer IMG_SZ = H_IN * W_IN * CH_IN;

localparam integer K01_SZ = 3*3*3*OUT1;
localparam integer B01_SZ = OUT1;
localparam integer K02_SZ = 3*3*OUT1*OUT2;
localparam integer B02_SZ = OUT2;
localparam integer K03_SZ = 1*1*3*OUT3;
localparam integer B03_SZ = OUT3;
localparam integer K06_SZ = 3*3*OUT1*OUT6;
localparam integer B06_SZ = OUT6;
localparam integer K07_SZ = 3*3*OUT6*OUT7;
localparam integer B07_SZ = OUT7;
localparam integer K08_SZ = 1*1*OUT1*OUT8;
localparam integer B08_SZ = OUT8;
localparam integer K12_SZ = DENSE_IN * DENSE_OUT;
localparam integer B12_SZ = DENSE_OUT;

localparam integer CONV1_SZ   = H_IN * W_IN * OUT1;
localparam integer POOL1_SZ   = 16 * 16 * OUT1;
localparam integer CONV2A_SZ  = 16 * 16 * OUT6;
localparam integer BLOCK2_SZ  = 16 * 16 * OUT7;
localparam integer POOL2_SZ   = 8 * 8 * OUT7;

// Main memory arrays for weights/biases
reg signed [31:0] img_mem   [0:IMG_SZ-1];
reg signed [31:0] kernel01  [0:K01_SZ-1];
reg signed [31:0] bias01    [0:B01_SZ-1];
reg signed [31:0] kernel02  [0:K02_SZ-1];
reg signed [31:0] bias02    [0:B02_SZ-1];
reg signed [31:0] kernel03  [0:K03_SZ-1];
reg signed [31:0] bias03    [0:B03_SZ-1];
reg signed [31:0] kernel06  [0:K06_SZ-1];
reg signed [31:0] bias06    [0:B06_SZ-1];
reg signed [31:0] kernel07  [0:K07_SZ-1];
reg signed [31:0] bias07    [0:B07_SZ-1];
reg signed [31:0] kernel08  [0:K08_SZ-1];
reg signed [31:0] bias08    [0:B08_SZ-1];
reg signed [31:0] kernel12  [0:K12_SZ-1];
reg signed [31:0] bias12    [0:B12_SZ-1];

// Intermediate feature maps
reg signed [31:0] block1    [0:CONV1_SZ-1];
reg signed [31:0] block2    [0:BLOCK2_SZ-1];

localparam SEL_IMG = 5'd0;
localparam SEL_K01 = 5'd1;
localparam SEL_B01 = 5'd2;
localparam SEL_K02 = 5'd3;
localparam SEL_B02 = 5'd4;
localparam SEL_K03 = 5'd5;
localparam SEL_B03 = 5'd6;
localparam SEL_K06 = 5'd7;
localparam SEL_B06 = 5'd8;
localparam SEL_K07 = 5'd9;
localparam SEL_B07 = 5'd10;
localparam SEL_K08 = 5'd11;
localparam SEL_B08 = 5'd12;
localparam SEL_K12 = 5'd13;
localparam SEL_B12 = 5'd14;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
  end else begin
    if (wr_en) begin
      case (wr_sel)
        SEL_IMG: if (wr_addr < IMG_SZ) img_mem[wr_addr] <= $signed(wr_data);
        SEL_K01: if (wr_addr < K01_SZ) kernel01[wr_addr] <= $signed(wr_data);
        SEL_B01: if (wr_addr < B01_SZ) bias01[wr_addr] <= $signed(wr_data);
        SEL_K02: if (wr_addr < K02_SZ) kernel02[wr_addr] <= $signed(wr_data);
        SEL_B02: if (wr_addr < B02_SZ) bias02[wr_addr] <= $signed(wr_data);
        SEL_K03: if (wr_addr < K03_SZ) kernel03[wr_addr] <= $signed(wr_data);
        SEL_B03: if (wr_addr < B03_SZ) bias03[wr_addr] <= $signed(wr_data);
        SEL_K06: if (wr_addr < K06_SZ) kernel06[wr_addr] <= $signed(wr_data);
        SEL_B06: if (wr_addr < B06_SZ) bias06[wr_addr] <= $signed(wr_data);
        SEL_K07: if (wr_addr < K07_SZ) kernel07[wr_addr] <= $signed(wr_data);
        SEL_B07: if (wr_addr < B07_SZ) bias07[wr_addr] <= $signed(wr_data);
        SEL_K08: if (wr_addr < K08_SZ) kernel08[wr_addr] <= $signed(wr_data);
        SEL_B08: if (wr_addr < B08_SZ) bias08[wr_addr] <= $signed(wr_data);
        SEL_K12: if (wr_addr < K12_SZ) kernel12[wr_addr] <= $signed(wr_data);
        SEL_B12: if (wr_addr < B12_SZ) bias12[wr_addr] <= $signed(wr_data);
        default: begin end
      endcase
    end
  end
end

// Control signals for all modules
reg start_conv01, start_conv02, start_sc1, start_conv06, start_conv07, start_sc2;
reg start_pool1, start_pool2, start_avgpool, start_dense;
wire done_conv01, done_conv02, done_sc1, done_conv06, done_conv07, done_sc2;
wire done_pool1, done_pool2, done_avgpool, done_dense;

// Conv01: 32x32x3 -> 32x32x28
conv2d_module #(
  .H_IN(32), .W_IN(32), .CH_IN(3), .CH_OUT(28),
  .K_SIZE(3), .SCALE(128), .APPLY_RELU(1), .PADDING(1),
  .IN_SIZE(3072), .K_SIZE_TOTAL(2268), .OUT_SIZE(28672)
) conv01_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_conv01), .done(done_conv01)
);

// Conv02: 32x32x28 -> 32x32x28
conv2d_module #(
  .H_IN(32), .W_IN(32), .CH_IN(28), .CH_OUT(28),
  .K_SIZE(3), .SCALE(128), .APPLY_RELU(1), .PADDING(1),
  .IN_SIZE(28672), .K_SIZE_TOTAL(21168), .OUT_SIZE(28672)
) conv02_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_conv02), .done(done_conv02)
);

// Shortcut1: 32x32x3 -> 32x32x28
conv2d_module #(
  .H_IN(32), .W_IN(32), .CH_IN(3), .CH_OUT(28),
  .K_SIZE(1), .SCALE(128), .APPLY_RELU(0), .PADDING(0),
  .IN_SIZE(3072), .K_SIZE_TOTAL(84), .OUT_SIZE(28672)
) sc1_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_sc1), .done(done_sc1)
);

// MaxPool1: 32x32x28 -> 16x16x28
maxpool_module #(
  .H_IN(32), .W_IN(32), .CH(28), .POOL_SIZE(2),
  .IN_SIZE(28672), .OUT_SIZE(7168)
) pool1_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_pool1), .done(done_pool1)
);

// Conv06: 16x16x28 -> 16x16x56
conv2d_module #(
  .H_IN(16), .W_IN(16), .CH_IN(28), .CH_OUT(56),
  .K_SIZE(3), .SCALE(128), .APPLY_RELU(1), .PADDING(1),
  .IN_SIZE(7168), .K_SIZE_TOTAL(42336), .OUT_SIZE(14336)
) conv06_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_conv06), .done(done_conv06)
);

// Conv07: 16x16x56 -> 16x16x56
conv2d_module #(
  .H_IN(16), .W_IN(16), .CH_IN(56), .CH_OUT(56),
  .K_SIZE(3), .SCALE(128), .APPLY_RELU(0), .PADDING(1),
  .IN_SIZE(14336), .K_SIZE_TOTAL(84672), .OUT_SIZE(14336)
) conv07_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_conv07), .done(done_conv07)
);

// Shortcut2: 16x16x28 -> 16x16x56
conv2d_module #(
  .H_IN(16), .W_IN(16), .CH_IN(28), .CH_OUT(56),
  .K_SIZE(1), .SCALE(128), .APPLY_RELU(0), .PADDING(0),
  .IN_SIZE(7168), .K_SIZE_TOTAL(1568), .OUT_SIZE(14336)
) sc2_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_sc2), .done(done_sc2)
);

// MaxPool2: 16x16x56 -> 8x8x56
maxpool_module #(
  .H_IN(16), .W_IN(16), .CH(56), .POOL_SIZE(2),
  .IN_SIZE(14336), .OUT_SIZE(3584)
) pool2_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_pool2), .done(done_pool2)
);

// Global Average Pool: 8x8x56 -> 56
avgpool_module #(
  .H_IN(8), .W_IN(8), .CH(56),
  .IN_SIZE(3584)
) avgpool_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_avgpool), .done(done_avgpool)
);

// Dense: 56 -> 10
dense_module #(
  .IN_FEATURES(56), .OUT_FEATURES(10),
  .SCALE(128), .K_SIZE(560)
) dense_inst (
  .clk(clk), .rst_n(rst_n),
  .start(start_dense), .done(done_dense)
);

localparam ST_IDLE     = 4'd0;
localparam ST_CONV01   = 4'd1;
localparam ST_CONV02   = 4'd2;
localparam ST_SC1      = 4'd3;
localparam ST_ADD1     = 4'd4;
localparam ST_POOL1    = 4'd5;
localparam ST_CONV06   = 4'd6;
localparam ST_CONV07   = 4'd7;
localparam ST_SC2      = 4'd8;
localparam ST_ADD2     = 4'd9;
localparam ST_POOL2    = 4'd10;
localparam ST_AVGPOOL  = 4'd11;
localparam ST_DENSE    = 4'd12;
localparam ST_ARGMAX   = 4'd13;
localparam ST_DONE     = 4'd14;

reg [3:0] state, next_state;

function signed [63:0] sx64;
  input signed [31:0] v;
  begin
    sx64 = {{32{v[31]}}, v};
  end
endfunction

integer i, j, oc, addr, tmp_int;
reg signed [63:0] tmp_sum64;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    state <= ST_IDLE;
  end else begin
    state <= next_state;
  end
end

always @(*) begin
  next_state = state;
  start_conv01 = 1'b0;
  start_conv02 = 1'b0;
  start_sc1 = 1'b0;
  start_pool1 = 1'b0;
  start_conv06 = 1'b0;
  start_conv07 = 1'b0;
  start_sc2 = 1'b0;
  start_pool2 = 1'b0;
  start_avgpool = 1'b0;
  start_dense = 1'b0;
  
  case (state)
    ST_IDLE: if (start) next_state = ST_CONV01;
    ST_CONV01: begin
      start_conv01 = 1'b1;
      if (done_conv01) next_state = ST_CONV02;
    end
    ST_CONV02: begin
      start_conv02 = 1'b1;
      if (done_conv02) next_state = ST_SC1;
    end
    ST_SC1: begin
      start_sc1 = 1'b1;
      if (done_sc1) next_state = ST_ADD1;
    end
    ST_ADD1: next_state = ST_POOL1;
    ST_POOL1: begin
      start_pool1 = 1'b1;
      if (done_pool1) next_state = ST_CONV06;
    end
    ST_CONV06: begin
      start_conv06 = 1'b1;
      if (done_conv06) next_state = ST_CONV07;
    end
    ST_CONV07: begin
      start_conv07 = 1'b1;
      if (done_conv07) next_state = ST_SC2;
    end
    ST_SC2: begin
      start_sc2 = 1'b1;
      if (done_sc2) next_state = ST_ADD2;
    end
    ST_ADD2: next_state = ST_POOL2;
    ST_POOL2: begin
      start_pool2 = 1'b1;
      if (done_pool2) next_state = ST_AVGPOOL;
    end
    ST_AVGPOOL: begin
      start_avgpool = 1'b1;
      if (done_avgpool) next_state = ST_DENSE;
    end
    ST_DENSE: begin
      start_dense = 1'b1;
      if (done_dense) next_state = ST_ARGMAX;
    end
    ST_ARGMAX: next_state = ST_DONE;
    ST_DONE: next_state = ST_IDLE;
    default: next_state = ST_IDLE;
  endcase
end

// Copy data to/from modules
always @(posedge clk) begin
  case (state)
    ST_CONV01: begin
      if (start_conv01 && !done_conv01) begin
        for (addr = 0; addr < IMG_SZ; addr = addr + 1)
          conv01_inst.input_fm[addr] = img_mem[addr];
        for (addr = 0; addr < K01_SZ; addr = addr + 1)
          conv01_inst.kernel[addr] = kernel01[addr];
        for (addr = 0; addr < B01_SZ; addr = addr + 1)
          conv01_inst.bias[addr] = bias01[addr];
      end
    end
    
    ST_CONV02: begin
      if (start_conv02 && !done_conv02) begin
        for (addr = 0; addr < CONV1_SZ; addr = addr + 1)
          conv02_inst.input_fm[addr] = conv01_inst.output_fm[addr];
        for (addr = 0; addr < K02_SZ; addr = addr + 1)
          conv02_inst.kernel[addr] = kernel02[addr];
        for (addr = 0; addr < B02_SZ; addr = addr + 1)
          conv02_inst.bias[addr] = bias02[addr];
      end
    end
    
    ST_SC1: begin
      if (start_sc1 && !done_sc1) begin
        for (addr = 0; addr < IMG_SZ; addr = addr + 1)
          sc1_inst.input_fm[addr] = img_mem[addr];
        for (addr = 0; addr < K03_SZ; addr = addr + 1)
          sc1_inst.kernel[addr] = kernel03[addr];
        for (addr = 0; addr < B03_SZ; addr = addr + 1)
          sc1_inst.bias[addr] = bias03[addr];
      end
    end
    
    ST_POOL1: begin
      if (start_pool1 && !done_pool1) begin
        for (addr = 0; addr < CONV1_SZ; addr = addr + 1)
          pool1_inst.input_fm[addr] = block1[addr];
      end
    end
    
    ST_CONV06: begin
      if (start_conv06 && !done_conv06) begin
        for (addr = 0; addr < POOL1_SZ; addr = addr + 1)
          conv06_inst.input_fm[addr] = pool1_inst.output_fm[addr];
        for (addr = 0; addr < K06_SZ; addr = addr + 1)
          conv06_inst.kernel[addr] = kernel06[addr];
        for (addr = 0; addr < B06_SZ; addr = addr + 1)
          conv06_inst.bias[addr] = bias06[addr];
      end
    end
    
    ST_CONV07: begin
      if (start_conv07 && !done_conv07) begin
        for (addr = 0; addr < CONV2A_SZ; addr = addr + 1)
          conv07_inst.input_fm[addr] = conv06_inst.output_fm[addr];
        for (addr = 0; addr < K07_SZ; addr = addr + 1)
          conv07_inst.kernel[addr] = kernel07[addr];
        for (addr = 0; addr < B07_SZ; addr = addr + 1)
          conv07_inst.bias[addr] = bias07[addr];
      end
    end
    
    ST_SC2: begin
      if (start_sc2 && !done_sc2) begin
        for (addr = 0; addr < POOL1_SZ; addr = addr + 1)
          sc2_inst.input_fm[addr] = pool1_inst.output_fm[addr];
        for (addr = 0; addr < K08_SZ; addr = addr + 1)
          sc2_inst.kernel[addr] = kernel08[addr];
        for (addr = 0; addr < B08_SZ; addr = addr + 1)
          sc2_inst.bias[addr] = bias08[addr];
      end
    end
    
    ST_POOL2: begin
      if (start_pool2 && !done_pool2) begin
        for (addr = 0; addr < BLOCK2_SZ; addr = addr + 1)
          pool2_inst.input_fm[addr] = block2[addr];
      end
    end
    
    ST_AVGPOOL: begin
      if (start_avgpool && !done_avgpool) begin
        for (addr = 0; addr < POOL2_SZ; addr = addr + 1)
          avgpool_inst.input_fm[addr] = pool2_inst.output_fm[addr];
      end
    end
    
    ST_DENSE: begin
      if (start_dense && !done_dense) begin
        for (addr = 0; addr < DENSE_IN; addr = addr + 1)
          dense_inst.input_vec[addr] = avgpool_inst.output_vec[addr];
        for (addr = 0; addr < K12_SZ; addr = addr + 1)
          dense_inst.kernel[addr] = kernel12[addr];
        for (addr = 0; addr < B12_SZ; addr = addr + 1)
          dense_inst.bias[addr] = bias12[addr];
      end
    end
  endcase
end

// Datapath for add operations and argmax
always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    done <= 1'b0;
    pred_index <= 4'd0;
    logits0 <= 32'd0; logits1 <= 32'd0; logits2 <= 32'd0; logits3 <= 32'd0; logits4 <= 32'd0;
    logits5 <= 32'd0; logits6 <= 32'd0; logits7 <= 32'd0; logits8 <= 32'd0; logits9 <= 32'd0;
  end else begin
    done <= 1'b0;
    
    case (state)
      ST_ADD1: begin
        // Add conv02 + sc1 -> block1
        for (i = 0; i < H_IN; i = i + 1) begin
          for (j = 0; j < W_IN; j = j + 1) begin
            for (oc = 0; oc < OUT1; oc = oc + 1) begin
              addr = ((i*W_IN)+j)*OUT1 + oc;
              tmp_sum64 = $signed(conv02_inst.output_fm[addr]) + $signed(sc1_inst.output_fm[addr]);
              block1[addr] = $signed(tmp_sum64);
            end
          end
        end
      end
      
      ST_ADD2: begin
        // Add conv07 + sc2 -> block2 with ReLU
        for (i = 0; i < 16; i = i + 1) begin
          for (j = 0; j < 16; j = j + 1) begin
            for (oc = 0; oc < OUT7; oc = oc + 1) begin
              addr = ((i*16)+j)*OUT7 + oc;
              tmp_sum64 = $signed(conv07_inst.output_fm[addr]) + $signed(sc2_inst.output_fm[addr]);
              if (tmp_sum64 < 0) block2[addr] = 32'sd0;
              else block2[addr] = $signed(tmp_sum64);
            end
          end
        end
      end
      
      ST_ARGMAX: begin
        // Argmax on dense output
        pred_index = 4'd0;
        tmp_int = dense_inst.output_vec[0];
        for (j = 1; j < DENSE_OUT; j = j + 1) begin
          if (dense_inst.output_vec[j] > tmp_int) begin
            tmp_int = dense_inst.output_vec[j];
            pred_index = j[3:0];
          end
        end
        
        // Copy logits to output
        logits0 <= dense_inst.output_vec[0];
        logits1 <= dense_inst.output_vec[1];
        logits2 <= dense_inst.output_vec[2];
        logits3 <= dense_inst.output_vec[3];
        logits4 <= dense_inst.output_vec[4];
        logits5 <= dense_inst.output_vec[5];
        logits6 <= dense_inst.output_vec[6];
        logits7 <= dense_inst.output_vec[7];
        logits8 <= dense_inst.output_vec[8];
        logits9 <= dense_inst.output_vec[9];
      end
      
      ST_DONE: done <= 1'b1;
    endcase
  end
end

endmodule