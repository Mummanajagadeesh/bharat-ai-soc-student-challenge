`timescale 1ns/1ps
// cifar10_top.v
// Synchronous synthesizable top module for CIFAR-10 inference
// All inference logic inside this module. Testbench writes image + weights via write interface,
// then pulses start. Module asserts done when prediction is ready and presents logits + pred_index.
//
// Interface:
//   clk, rst
//   wr_en, wr_sel[4:0], wr_addr[15:0], wr_data[31:0]   -- simple write port to upload image/weights/biases
//   start (pulse) -> begin inference
//   done (output) -> inference finished
//   pred_index [3:0], logits0..logits9 [31:0]
//
// NOTE: All memories are flattened 1-D reg arrays internally (no multi-dimensional ports).
module cifar10_top (
  input  wire         clk,
  input  wire         rst_n,      // active low reset
  input  wire         wr_en,
  input  wire [4:0]   wr_sel,     // which memory to write
  input  wire [15:0]  wr_addr,
  input  wire [31:0]  wr_data,
  input  wire         start,      // 1-cycle pulse to start inference
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

// -----------------------------------------------------------------------------
// Parameters (same as original TB)
localparam integer SCALE = 128;
localparam integer H_IN  = 32;
localparam integer W_IN  = 32;
localparam integer CH_IN = 3;

localparam integer OUT1 = 28;
localparam integer OUT2 = 28; // same as OUT1
localparam integer OUT3 = 28;
localparam integer OUT6 = 56;
localparam integer OUT7 = 56;
localparam integer OUT8 = 56;
localparam integer DENSE_IN = 56;
localparam integer DENSE_OUT = 10;

// sizes (flattened)
localparam integer IMG_SZ = H_IN * W_IN * CH_IN; // 32*32*3 = 3072

localparam integer K01_SZ = 3*3*3*OUT1;   // kernel01: 3x3x3 x OUT1
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

// internal feature map sizes (flattened)
localparam integer CONV1_SZ   = H_IN * W_IN * OUT1;   // 32*32*28
localparam integer CONV1_2_SZ = H_IN * W_IN * OUT2;   // 32*32*28
localparam integer SC1_SZ     = H_IN * W_IN * OUT3;   // 32*32*28
localparam integer BLOCK1_SZ  = H_IN * W_IN * OUT1;
localparam integer POOL1_SZ   = 16 * 16 * OUT1;       // 16x16x28

localparam integer CONV2A_SZ  = 16 * 16 * OUT6;
localparam integer CONV2B_SZ  = 16 * 16 * OUT7;
localparam integer SC2_SZ     = 16 * 16 * OUT8;
localparam integer BLOCK2_SZ  = 16 * 16 * OUT7;
localparam integer POOL2_SZ   = 8 * 8 * OUT7;

localparam integer AVG_SZ     = DENSE_IN;
localparam integer LOGIT_SZ   = DENSE_OUT;

// -----------------------------------------------------------------------------
// Memory declarations (flattened). Use signed 32-bit for kernels, biases, and feature maps.
reg signed [31:0] img_mem   [0:IMG_SZ-1];

reg signed [31:0] kernel01  [0:K01_SZ-1];
reg signed [31:0] bias01    [0:B01_SZ-1];

reg signed [31:0] kernel02  [0:K02_SZ-1];
reg signed [31:0] bias02    [0:B02_SZ-1];

reg signed [31:0] kernel03  [0:K03_SZ-1];
reg signed [31:32] bias03_workaround; // dummy to avoid lint (we actually define bias03 below)
reg signed [31:0] bias03    [0:B03_SZ-1];

reg signed [31:0] kernel06  [0:K06_SZ-1];
reg signed [31:0] bias06    [0:B06_SZ-1];

reg signed [31:0] kernel07  [0:K07_SZ-1];
reg signed [31:0] bias07    [0:B07_SZ-1];

reg signed [31:0] kernel08  [0:K08_SZ-1];
reg signed [31:0] bias08    [0:B08_SZ-1];

reg signed [31:0] kernel12  [0:K12_SZ-1];
reg signed [31:0] bias12    [0:B12_SZ-1];

// feature maps
reg signed [31:0] conv1     [0:CONV1_SZ-1];
reg signed [31:0] relu1     [0:CONV1_SZ-1];
reg signed [31:0] conv1_2   [0:CONV1_2_SZ-1];
reg signed [31:0] relu1_2   [0:CONV1_2_SZ-1];
reg signed [31:0] sc1_map   [0:SC1_SZ-1];
reg signed [31:0] block1    [0:BLOCK1_SZ-1];
reg signed [31:0] pool1     [0:POOL1_SZ-1];

reg signed [31:0] conv2a    [0:CONV2A_SZ-1];
reg signed [31:0] relu2a    [0:CONV2A_SZ-1];
reg signed [31:0] conv2b    [0:CONV2B_SZ-1];
reg signed [31:0] sc2_map   [0:SC2_SZ-1];
reg signed [31:0] block2    [0:BLOCK2_SZ-1];
reg signed [31:0] pool2     [0:POOL2_SZ-1];

reg signed [31:0] avg_pool  [0:AVG_SZ-1];
reg signed [31:0] logits    [0:LOGIT_SZ-1];

// -----------------------------------------------------------------------------
// Write interface memory selection encoding (wr_sel)
localparam SEL_IMG    = 5'd0;
localparam SEL_K01    = 5'd1;
localparam SEL_B01    = 5'd2;
localparam SEL_K02    = 5'd3;
localparam SEL_B02    = 5'd4;
localparam SEL_K03    = 5'd5;
localparam SEL_B03    = 5'd6;
localparam SEL_K06    = 5'd7;
localparam SEL_B06    = 5'd8;
localparam SEL_K07    = 5'd9;
localparam SEL_B07    = 5'd10;
localparam SEL_K08    = 5'd11;
localparam SEL_B08    = 5'd12;
localparam SEL_K12    = 5'd13;
localparam SEL_B12    = 5'd14;

// -----------------------------------------------------------------------------
// Helper functions (combinational) to compute flattened indices
// Note: functions are pure combinational.

function integer idx_img;
  input integer ih, iw, ic;
  begin
    idx_img = ((ih * W_IN) + iw) * CH_IN + ic;
  end
endfunction

// kernel01 index: ((kh*3 + kw)*3 + ic)*OUT1 + oc
function integer idx_k01;
  input integer kh, kw, ic, oc;
  begin
    idx_k01 = (((kh*3 + kw)*3 + ic) * OUT1) + oc;
  end
endfunction

// kernel02 index: ((kh*3 + kw)*OUT1 + ic)*OUT2 + oc  with kh,kw in 0..2, ic in 0..OUT1-1
function integer idx_k02;
  input integer kh, kw, ic, oc;
  begin
    idx_k02 = ((((kh*3) + kw) * OUT1 + ic) * OUT2) + oc;
  end
endfunction

// kernel03 index: ((kh*1 + kw)*3 + ic)*OUT3 + oc  (kh/kw are 0)
function integer idx_k03;
  input integer kh, kw, ic, oc;
  begin
    idx_k03 = (((kh*1 + kw)*3 + ic) * OUT3) + oc;
  end
endfunction

// kernel06 index: ((((kh*3)+kw)*OUT1)+ic)*OUT6 + oc
function integer idx_k06;
  input integer kh, kw, ic, oc;
  begin
    idx_k06 = ((((kh*3) + kw) * OUT1 + ic) * OUT6) + oc;
  end
endfunction

// kernel07 index: ((((kh*3)+kw)*OUT6)+ic)*OUT7 + oc
function integer idx_k07;
  input integer kh, kw, ic, oc;
  begin
    idx_k07 = ((((kh*3) + kw) * OUT6 + ic) * OUT7) + oc;
  end
endfunction

// kernel08 index: ((kh*1 + kw)*OUT1 + ic)*OUT8 + oc
function integer idx_k08;
  input integer kh, kw, ic, oc;
  begin
    idx_k08 = (((kh*1 + kw) * OUT1 + ic) * OUT8) + oc;
  end
endfunction

// kernel12 index: i * DENSE_OUT + j
function integer idx_k12;
  input integer i,j;
  begin
    idx_k12 = i * DENSE_OUT + j;
  end
endfunction

// conv1 index: ((i*W_IN)+j)*OUT1 + oc
function integer idx_conv1;
  input integer i,j,oc;
  begin
    idx_conv1 = ((i * W_IN) + j) * OUT1 + oc;
  end
endfunction

// conv1_2 index: ((i*W_IN)+j)*OUT2 + oc
function integer idx_conv1_2;
  input integer i,j,oc;
  begin
    idx_conv1_2 = ((i * W_IN) + j) * OUT2 + oc;
  end
endfunction

// sc1 index: ((i*W_IN)+j)*OUT3 + oc
function integer idx_sc1;
  input integer i,j,oc;
  begin
    idx_sc1 = ((i * W_IN) + j) * OUT3 + oc;
  end
endfunction

// pool1 index: ((i*16)+j)*OUT1 + oc  // i 0..15, j 0..15
function integer idx_pool1;
  input integer i,j,oc;
  begin
    idx_pool1 = ((i * 16) + j) * OUT1 + oc;
  end
endfunction

// conv2a/conv2b/sc2/block2/pool2 indices similar (16x16 / 8x8)
function integer idx_16x16_OUTx;
  input integer i,j,oc, out_ch;
  begin
    // out_ch is channel dimension (OUT6/OUT7/OUT8/OUT7)
    // but we flatten by passing oc and multiplying by proper constants externally where necessary
    idx_16x16_OUTx = ((i * 16) + j) * out_ch + oc;
  end
endfunction

function integer idx_pool2;
  input integer i,j,oc;
  begin
    idx_pool2 = ((i * 8) + j) * OUT7 + oc;
  end
endfunction

// -----------------------------------------------------------------------------
// Synchronous write port: testbench writes image/weights/biases via wr_en,wr_sel,wr_addr,wr_data
always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    // nothing to initialize here (mems remain X until TB writes)
  end else begin
    if (wr_en) begin
      case (wr_sel)
        SEL_IMG: begin
          if (wr_addr < IMG_SZ) img_mem[wr_addr] <= $signed(wr_data);
        end
        SEL_K01: begin
          if (wr_addr < K01_SZ) kernel01[wr_addr] <= $signed(wr_data);
        end
        SEL_B01: begin
          if (wr_addr < B01_SZ) bias01[wr_addr] <= $signed(wr_data);
        end
        SEL_K02: begin
          if (wr_addr < K02_SZ) kernel02[wr_addr] <= $signed(wr_data);
        end
        SEL_B02: begin
          if (wr_addr < B02_SZ) bias02[wr_addr] <= $signed(wr_data);
        end
        SEL_K03: begin
          if (wr_addr < K03_SZ) kernel03[wr_addr] <= $signed(wr_data);
        end
        SEL_B03: begin
          if (wr_addr < B03_SZ) bias03[wr_addr] <= $signed(wr_data);
        end
        SEL_K06: begin
          if (wr_addr < K06_SZ) kernel06[wr_addr] <= $signed(wr_data);
        end
        SEL_B06: begin
          if (wr_addr < B06_SZ) bias06[wr_addr] <= $signed(wr_data);
        end
        SEL_K07: begin
          if (wr_addr < K07_SZ) kernel07[wr_addr] <= $signed(wr_data);
        end
        SEL_B07: begin
          if (wr_addr < B07_SZ) bias07[wr_addr] <= $signed(wr_data);
        end
        SEL_K08: begin
          if (wr_addr < K08_SZ) kernel08[wr_addr] <= $signed(wr_data);
        end
        SEL_B08: begin
          if (wr_addr < B08_SZ) bias08[wr_addr] <= $signed(wr_data);
        end
        SEL_K12: begin
          if (wr_addr < K12_SZ) kernel12[wr_addr] <= $signed(wr_data);
        end
        SEL_B12: begin
          if (wr_addr < B12_SZ) bias12[wr_addr] <= $signed(wr_data);
        end
        default: begin
          // ignore
        end
      endcase
    end
  end
end

// -----------------------------------------------------------------------------
// sign-extend helper function: extend 32-bit to 64-bit signed
function signed [63:0] sx64;
  input signed [31:0] v;
  begin
    sx64 = {{32{v[31]}}, v};
  end
endfunction

// -----------------------------------------------------------------------------
// Main synchronous inference: when start is asserted (1-cycle pulse), run the
// exact same sequence of operations as your original TB, but all inside this module.
// When finished, set done=1 and present outputs.
//
// NOTE: This implementation uses blocking for-loops inside an always @(posedge clk) block.
// That keeps behavior identical to your original testbench for simulation, while the
// block is still synchronous (executes on posedge clk).
//
integer i,j,kh,kw,ic,oc;
integer ih, iw;
integer ph, pw, h0, w0, mv, vh, vw, vv;
integer tmp_int;
reg signed [63:0] sum;
reg signed [63:0] prod;
reg signed [63:0] tmp_sum64;

always @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    done <= 1'b0;
    pred_index <= 4'd0;
    logits0 <= 32'd0; logits1 <= 32'd0; logits2 <= 32'd0; logits3 <= 32'd0; logits4 <= 32'd0;
    logits5 <= 32'd0; logits6 <= 32'd0; logits7 <= 32'd0; logits8 <= 32'd0; logits9 <= 32'd0;
    // do not clear memories here (TB will re-write)
  end else begin
    done <= done; // default hold
    if (start) begin
      // clear done
      done <= 1'b0;

      // ---- conv01: img_mem(32x32x3) -> conv1 (32x32x28) -> relu1
      for (i=0;i<H_IN;i=i+1) begin
        for (j=0;j<W_IN;j=j+1) begin
          for (oc=0; oc<OUT1; oc=oc+1) begin
            sum = 64'sd0;
            for (kh=0; kh<3; kh=kh+1) for (kw=0; kw<3; kw=kw+1) begin
              ih = i + kh - 1; iw = j + kw - 1;
              if (ih>=0 && ih<H_IN && iw>=0 && iw<W_IN) begin
                for (ic=0; ic<3; ic=ic+1) begin
                  prod = sx64(kernel01[idx_k01(kh,kw,ic,oc)]) * sx64(img_mem[idx_img(ih,iw,ic)]);
                  sum = sum + prod;
                end
              end
            end
            // rounding division by SCALE
            tmp_int = $signed((sum + (SCALE/2)) / SCALE);
            conv1[idx_conv1(i,j,oc)] = $signed(tmp_int) + bias01[oc];
            if (conv1[idx_conv1(i,j,oc)] < 0) relu1[idx_conv1(i,j,oc)] = 32'sd0;
            else relu1[idx_conv1(i,j,oc)] = conv1[idx_conv1(i,j,oc)];
          end
        end
      end

      // ---- conv02: relu1 -> conv1_2 -> relu1_2
      for (i=0;i<H_IN;i=i+1) begin
        for (j=0;j<W_IN;j=j+1) begin
          for (oc=0; oc<OUT2; oc=oc+1) begin
            sum = 64'sd0;
            for (kh=0; kh<3; kh=kh+1) for (kw=0; kw<3; kw=kw+1) begin
              ih = i + kh - 1; iw = j + kw - 1;
              if (ih>=0 && ih<H_IN && iw>=0 && iw<W_IN) begin
                for (ic=0; ic<OUT1; ic=ic+1) begin
                  prod = sx64(kernel02[idx_k02(kh,kw,ic,oc)]) * sx64(relu1[idx_conv1(ih,iw,ic)]);
                  sum = sum + prod;
                end
              end
            end
            tmp_int = $signed((sum + (SCALE/2)) / SCALE);
            conv1_2[idx_conv1_2(i,j,oc)] = $signed(tmp_int) + bias02[oc];
            if (conv1_2[idx_conv1_2(i,j,oc)] < 0) relu1_2[idx_conv1_2(i,j,oc)] = 32'sd0;
            else relu1_2[idx_conv1_2(i,j,oc)] = conv1_2[idx_conv1_2(i,j,oc)];
          end
        end
      end

      // ---- shortcut1: 1x1 conv on original input -> sc1_map
      for (i=0;i<H_IN;i=i+1) begin
        for (j=0;j<W_IN;j=j+1) begin
          for (oc=0; oc<OUT3; oc=oc+1) begin
            sum = 64'sd0;
            for (ic=0; ic<3; ic=ic+1) begin
              prod = sx64(kernel03[idx_k03(0,0,ic,oc)]) * sx64(img_mem[idx_img(i,j,ic)]);
              sum = sum + prod;
            end
            tmp_int = $signed((sum + (SCALE/2)) / SCALE);
            sc1_map[idx_sc1(i,j,oc)] = $signed(tmp_int) + bias03[oc];
          end
        end
      end

      // ---- add relu1_2 + sc1_map -> block1
      for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) for (oc=0; oc<OUT1; oc=oc+1) begin
        tmp_sum64 = $signed(relu1_2[idx_conv1_2(i,j,oc)]) + $signed(sc1_map[idx_sc1(i,j,oc)]);
        block1[((i*W_IN)+j)*OUT1 + oc] = $signed(tmp_sum64);
      end

      // ---- pool1: 2x2 max pool -> 16x16x28
      for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0; oc<OUT1; oc=oc+1) begin
        h0 = i*2;
        w0 = j*2;
        mv = -2147483648;
        for (ph=0; ph<2; ph=ph+1) for (pw=0; pw<2; pw=pw+1) begin
          vh = h0 + ph; vw = w0 + pw;
          vv = block1[((vh*W_IN)+vw)*OUT1 + oc];
          if (vv > mv) mv = vv;
        end
        pool1[idx_pool1(i,j,oc)] = mv;
      end

      // ---- conv06 on pool1 (16x16x28 -> 16x16x56)
      for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT6;oc=oc+1) begin
        sum = 64'sd0;
        for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) begin
          ih = i + kh - 1; iw = j + kw - 1;
          if (ih>=0 && ih<16 && iw>=0 && iw<16) begin
            for (ic=0; ic<OUT1; ic=ic+1) begin
              prod = sx64(kernel06[idx_k06(kh,kw,ic,oc)]) * sx64(pool1[idx_pool1(ih,iw,ic)]);
              sum = sum + prod;
            end
          end
        end
        tmp_int = $signed((sum + (SCALE/2)) / SCALE);
        conv2a[((i*16)+j)*OUT6 + oc] = $signed(tmp_int) + bias06[oc];
        if (conv2a[((i*16)+j)*OUT6 + oc] < 0) relu2a[((i*16)+j)*OUT6 + oc] = 32'sd0;
        else relu2a[((i*16)+j)*OUT6 + oc] = conv2a[((i*16)+j)*OUT6 + oc];
      end

      // ---- conv07 on relu2a (16x16x56 -> 16x16x56)
      for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT7;oc=oc+1) begin
        sum = 64'sd0;
        for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) begin
          ih = i + kh - 1; iw = j + kw - 1;
          if (ih>=0 && ih<16 && iw>=0 && iw<16) begin
            for (ic=0; ic<OUT6; ic=ic+1) begin
              prod = sx64(kernel07[idx_k07(kh,kw,ic,oc)]) * sx64(relu2a[((ih*16)+iw)*OUT6 + ic]);
              sum = sum + prod;
            end
          end
        end
        tmp_int = $signed((sum + (SCALE/2)) / SCALE);
        conv2b[((i*16)+j)*OUT7 + oc] = $signed(tmp_int) + bias07[oc];
        // apply ReLU here
        if (conv2b[((i*16)+j)*OUT7 + oc] < 0) conv2b[((i*16)+j)*OUT7 + oc] = 32'sd0;
      end

      // ---- shortcut2: 1x1 conv on pool1 -> sc2_map
      for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT8;oc=oc+1) begin
        sum = 64'sd0;
        for (ic=0; ic<OUT1; ic=ic+1) begin
          prod = sx64(kernel08[idx_k08(0,0,ic,oc)]) * sx64(pool1[idx_pool1(i,j,ic)]);
          sum = sum + prod;
        end
        tmp_int = $signed((sum + (SCALE/2)) / SCALE);
        sc2_map[((i*16)+j)*OUT8 + oc] = $signed(tmp_int) + bias08[oc];
      end

      // ---- add conv2b + sc2 -> block2; apply ReLU after add
      for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT7;oc=oc+1) begin
        tmp_sum64 = $signed(conv2b[((i*16)+j)*OUT7 + oc]) + $signed(sc2_map[((i*16)+j)*OUT8 + oc]);
        if (tmp_sum64 < 0) block2[((i*16)+j)*OUT7 + oc] = 32'sd0;
        else block2[((i*16)+j)*OUT7 + oc] = $signed(tmp_sum64);
      end

      // ---- pool2: 2x2 max -> 8x8x56
      for (i=0;i<8;i=i+1) for (j=0;j<8;j=j+1) for (oc=0;oc<OUT7;oc=oc+1) begin
        h0 = i*2;
        w0 = j*2;
        mv = -2147483648;
        for (ph=0; ph<2; ph=ph+1) for (pw=0; pw<2; pw=pw+1) begin
          vh = h0 + ph; vw = w0 + pw;
          vv = block2[((vh*16)+vw)*OUT7 + oc];
          if (vv > mv) mv = vv;
        end
        pool2[idx_pool2(i,j,oc)] = mv;
      end

      // ---- Head: global avg pool over 8x8, rounding
      for (oc=0; oc<OUT7; oc=oc+1) begin
        sum = 64'sd0;
        for (i=0;i<8;i=i+1) for (j=0;j<8;j=j+1) begin
          sum = sum + sx64(pool2[idx_pool2(i,j,oc)]);
        end
        // divide by 64 with rounding
        tmp_int = $signed((sum + 32) / 64);
        avg_pool[oc] = $signed(tmp_int);
      end

      // ---- dense: avg (56) x kernel12 (56x10) -> logits
      for (j=0; j<DENSE_OUT; j=j+1) begin
        sum = 64'sd0;
        for (i=0; i<DENSE_IN; i=i+1) begin
          prod = sx64(kernel12[idx_k12(i,j)]) * sx64(avg_pool[i]);
          sum = sum + prod;
        end
        tmp_int = $signed((sum + (SCALE/2)) / SCALE);
        logits[j] = $signed(tmp_int) + bias12[j];
      end

      // ---- argmax
      pred_index = 4'd0;
      tmp_int = logits[0];
      for (j=1;j<DENSE_OUT;j=j+1) begin
        if (logits[j] > tmp_int) begin
          tmp_int = logits[j];
          pred_index = j[3:0];
        end
      end

      // drive outputs (pack into outputs)
      logits0 <= logits[0];
      logits1 <= logits[1];
      logits2 <= logits[2];
      logits3 <= logits[3];
      logits4 <= logits[4];
      logits5 <= logits[5];
      logits6 <= logits[6];
      logits7 <= logits[7];
      logits8 <= logits[8];
      logits9 <= logits[9];

      done <= 1'b1;
    end // if (start)
  end
end

endmodule
