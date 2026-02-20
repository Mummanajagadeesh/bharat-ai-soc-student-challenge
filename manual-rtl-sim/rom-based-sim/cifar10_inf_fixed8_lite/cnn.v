// cifar10_infer_tb.v
`timescale 1ns/1ps

module cifar10_infer_tb;
  // Q1.7
  localparam integer SCALE = 128;
  localparam integer H_IN = 32;
  localparam integer W_IN = 32;
  localparam integer CH_IN = 3;

  localparam integer OUT1 = 28;
  localparam integer OUT2 = 28; // same as OUT1 but kept for clarity
  localparam integer OUT3 = 28;
  localparam integer OUT6 = 56;
  localparam integer OUT7 = 56;
  localparam integer OUT8 = 56;
  localparam integer DENSE_IN = 56;
  localparam integer DENSE_OUT = 10;

  // weights/bias (32-bit ints, Q1.7)
  integer kernel01 [0:2][0:2][0:2][0:OUT1-1];
  integer bias01   [0:OUT1-1];

  integer kernel02 [0:2][0:2][0:OUT1-1][0:OUT2-1];
  integer bias02   [0:OUT2-1];

  integer kernel03 [0:0][0:0][0:2][0:OUT3-1];
  integer bias03   [0:OUT3-1];

  integer kernel06 [0:2][0:2][0:OUT1-1][0:OUT6-1];
  integer bias06   [0:OUT6-1];

  integer kernel07 [0:2][0:2][0:OUT6-1][0:OUT7-1];
  integer bias07   [0:OUT7-1];

  integer kernel08 [0:0][0:0][0:OUT1-1][0:OUT8-1];
  integer bias08   [0:OUT8-1];

  integer kernel12 [0:DENSE_IN-1][0:DENSE_OUT-1];
  integer bias12   [0:DENSE_OUT-1];

  // image Q1.7
  integer imgFP [0:H_IN-1][0:W_IN-1][0:CH_IN-1];

  // intermediate maps
  integer conv1   [0:H_IN-1][0:W_IN-1][0:OUT1-1];
  integer relu1   [0:H_IN-1][0:W_IN-1][0:OUT1-1];

  // conv02 outputs (second conv in block1) - MANDATORY
  integer conv1_2 [0:H_IN-1][0:W_IN-1][0:OUT2-1];
  integer relu1_2 [0:H_IN-1][0:W_IN-1][0:OUT2-1];

  integer sc1     [0:H_IN-1][0:W_IN-1][0:OUT3-1];
  integer block1  [0:H_IN-1][0:W_IN-1][0:OUT1-1];
  integer pool1   [0:15][0:15][0:OUT1-1];

  integer conv2a  [0:15][0:15][0:OUT6-1];
  integer relu2a  [0:15][0:15][0:OUT6-1];
  integer conv2b  [0:15][0:15][0:OUT7-1];
  integer sc2     [0:15][0:15][0:OUT8-1];
  integer block2  [0:15][0:15][0:OUT7-1];
  integer pool2   [0:7][0:7][0:OUT7-1];

  integer avg     [0:DENSE_IN-1];
  integer logits  [0:DENSE_OUT-1];

  // loop vars
  integer i,j,kh,kw,ic,oc;
  integer fd, status, tmp;
  integer r,g,b;
  reg [80*8-1:0] labels [0:9];

  // 64-bit signed accumulators
  reg signed [63:0] sum;
  reg signed [63:0] prod; // temp product
  reg signed [63:0] tmp_sum;

  integer ph, pw, vh, vw, vv;
  integer h0, w0, mv;

  integer best, best_val;
  real rlog;

  integer ih, iw;


  // helper function: sign-extend 32-bit integer to 64 bits
  function automatic signed [63:0] sx64(input integer v);
    sx64 = {{32{v[31]}}, v};
  endfunction

  initial begin
    labels[0] = "airplane"; labels[1] = "automobile"; labels[2] = "bird"; labels[3] = "cat";
    labels[4] = "deer"; labels[5] = "dog"; labels[6] = "frog"; labels[7] = "horse";
    labels[8] = "ship"; labels[9] = "truck";

    $display("Start: loading image channels...");

    // load R
    fd = $fopen("image_txt/image_r.txt","r");
    if (fd==0) begin $display("ERR open image_r"); $finish; end
    for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) begin
      status = $fscanf(fd, " %d", tmp);
      if (status != 1) begin $display("ERR read image_r %0d %0d", i,j); $finish; end
      r = tmp;
      imgFP[i][j][0] = (r * (SCALE-1) + 127) / 255; // keep max 127
    end
    $fclose(fd);

    // load G
    fd = $fopen("image_txt/image_g.txt","r");
    if (fd==0) begin $display("ERR open image_g"); $finish; end
    for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) begin
      status = $fscanf(fd, " %d", tmp);
      if (status != 1) begin $display("ERR read image_g %0d %0d", i,j); $finish; end
      g = tmp;
      imgFP[i][j][1] = (g * (SCALE-1) + 127) / 255;
    end
    $fclose(fd);

    // load B
    fd = $fopen("image_txt/image_b.txt","r");
    if (fd==0) begin $display("ERR open image_b"); $finish; end
    for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) begin
      status = $fscanf(fd, " %d", tmp);
      if (status != 1) begin $display("ERR read image_b %0d %0d", i,j); $finish; end
      b = tmp;
      imgFP[i][j][2] = (b * (SCALE-1) + 127) / 255;
    end
    $fclose(fd);
    $display("Image loaded.");

    // ------------------------------------------------------------------
    // Load all weight/bias files (assume all are whitespace separated ints)
    // ------------------------------------------------------------------
    // Helper macro-like inline for reading pattern; explicit loops below

    // 01_conv2d
    fd = $fopen("model_weights_fixed8/01_conv2d_kernel.txt","r");
    if (fd==0) begin $display("ERR open 01_conv2d_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<3;ic=ic+1) for (oc=0;oc<OUT1;oc=oc+1) begin
      status = $fscanf(fd," %d", tmp); if (status!=1) begin $display("ERR 01 read"); $finish; end
      kernel01[kh][kw][ic][oc] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/01_conv2d_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT1;oc=oc+1) bias01[oc]=0; else begin
      for (oc=0;oc<OUT1;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 01bias"); $finish; end bias01[oc]=tmp; end
      $fclose(fd);
    end

    // 02_conv2d_1 (second conv in block1)
    fd = $fopen("model_weights_fixed8/02_conv2d_1_kernel.txt","r");
    if (fd==0) begin $display("ERR open 02_conv2d_1_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<OUT1;ic=ic+1) for (oc=0;oc<OUT2;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 02 read"); $finish; end
      kernel02[kh][kw][ic][oc] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/02_conv2d_1_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT2;oc=oc+1) bias02[oc]=0; else begin
      for (oc=0;oc<OUT2;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 02bias"); $finish; end bias02[oc]=tmp; end
      $fclose(fd);
    end

    // 03_conv2d_2 shortcut1 (1x1x3 -> 28)
    fd = $fopen("model_weights_fixed8/03_conv2d_2_kernel.txt","r");
    if (fd==0) begin $display("ERR open 03_conv2d_2_kernel"); $finish; end
    for (kh=0;kh<1;kh=kh+1) for (kw=0;kw<1;kw=kw+1) for (ic=0;ic<3;ic=ic+1) for (oc=0;oc<OUT3;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 03 read"); $finish; end
      kernel03[kh][kw][ic][oc] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/03_conv2d_2_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT3;oc=oc+1) bias03[oc]=0; else begin
      for (oc=0;oc<OUT3;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 03bias"); $finish; end bias03[oc]=tmp; end
      $fclose(fd);
    end

    // 06_conv2d_3
    fd = $fopen("model_weights_fixed8/06_conv2d_3_kernel.txt","r");
    if (fd==0) begin $display("ERR open 06_conv2d_3_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<OUT1;ic=ic+1) for (oc=0;oc<OUT6;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 06 read"); $finish; end
      kernel06[kh][kw][ic][oc] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/06_conv2d_3_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT6;oc=oc+1) bias06[oc]=0; else begin
      for (oc=0;oc<OUT6;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 06bias"); $finish; end bias06[oc]=tmp; end
      $fclose(fd);
    end

    // 07_conv2d_4
    fd = $fopen("model_weights_fixed8/07_conv2d_4_kernel.txt","r");
    if (fd==0) begin $display("ERR open 07_conv2d_4_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<OUT6;ic=ic+1) for (oc=0;oc<OUT7;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 07 read"); $finish; end
      kernel07[kh][kw][ic][oc] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/07_conv2d_4_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT7;oc=oc+1) bias07[oc]=0; else begin
      for (oc=0;oc<OUT7;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 07bias"); $finish; end bias07[oc]=tmp; end
      $fclose(fd);
    end

    // 08_conv2d_5 (shortcut2)
    fd = $fopen("model_weights_fixed8/08_conv2d_5_kernel.txt","r");
    if (fd==0) begin $display("ERR open 08_conv2d_5_kernel"); $finish; end
    for (kh=0;kh<1;kh=kh+1) for (kw=0;kw<1;kw=kw+1) for (ic=0;ic<OUT1;ic=ic+1) for (oc=0;oc<OUT8;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 08 read"); $finish; end
      kernel08[kh][kw][ic][oc] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/08_conv2d_5_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT8;oc=oc+1) bias08[oc]=0; else begin
      for (oc=0;oc<OUT8;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 08bias"); $finish; end bias08[oc]=tmp; end
      $fclose(fd);
    end

    // 12_dense
    fd = $fopen("model_weights_fixed8/12_dense_kernel.txt","r");
    if (fd==0) begin $display("ERR open 12_dense_kernel"); $finish; end
    for (i=0;i<DENSE_IN;i=i+1) for (j=0;j<DENSE_OUT;j=j+1) begin
      status = $fscanf(fd," %d", tmp); if (status!=1) begin $display("ERR 12 read"); $finish; end
      kernel12[i][j] = tmp;
    end
    $fclose(fd);
    fd = $fopen("model_weights_fixed8/12_dense_bias.txt","r");
    if (fd==0) for (j=0;j<DENSE_OUT;j=j+1) bias12[j]=0; else begin
      for (j=0;j<DENSE_OUT;j=j+1) begin status=$fscanf(fd," %d", tmp); if (status!=1) begin $display("ERR 12bias"); $finish; end bias12[j]=tmp; end
      $fclose(fd);
    end

    $display("Loaded all weights.");

    // ===========================
    // Block1 - conv01 -> relu -> conv02 -> relu -> add shortcut -> pool
    // ===========================

    // conv01: input imgFP (32x32x3) -> conv1 (32x32x28)
    for (i=0;i<H_IN;i=i+1) begin
      for (j=0;j<W_IN;j=j+1) begin
        for (oc=0; oc<OUT1; oc=oc+1) begin
          sum = 0;
          for (kh=0; kh<3; kh=kh+1) for (kw=0; kw<3; kw=kw+1) begin
            ih = i + kh - 1; iw = j + kw - 1;
            if (ih>=0 && ih<H_IN && iw>=0 && iw<W_IN) begin
              for (ic=0; ic<3; ic=ic+1) begin
                // sign-extend both operands to 64 bits then multiply
                prod = sx64(kernel01[kh][kw][ic][oc]) * sx64(imgFP[ih][iw][ic]);
                sum = sum + prod;
              end
            end
          end
          // rounding division by SCALE
          conv1[i][j][oc] = $signed((sum + (SCALE/2)) / SCALE) + bias01[oc];
          if (conv1[i][j][oc] < 0) relu1[i][j][oc] = 0; else relu1[i][j][oc] = conv1[i][j][oc];
        end
      end
    end

    // conv02: takes relu1 (32x32x28) -> conv1_2 (32x32x28)
    for (i=0;i<H_IN;i=i+1) begin
      for (j=0;j<W_IN;j=j+1) begin
        for (oc=0; oc<OUT2; oc=oc+1) begin
          sum = 0;
          for (kh=0; kh<3; kh=kh+1) for (kw=0; kw<3; kw=kw+1) begin
            ih = i + kh - 1; iw = j + kw - 1;
            if (ih>=0 && ih<H_IN && iw>=0 && iw<W_IN) begin
              for (ic=0; ic<OUT1; ic=ic+1) begin
                prod = sx64(kernel02[kh][kw][ic][oc]) * sx64(relu1[ih][iw][ic]);
                sum = sum + prod;
              end
            end
          end
          conv1_2[i][j][oc] = $signed((sum + (SCALE/2)) / SCALE) + bias02[oc];
          if (conv1_2[i][j][oc] < 0) relu1_2[i][j][oc] = 0; else relu1_2[i][j][oc] = conv1_2[i][j][oc];
        end
      end
    end

    // shortcut1: 1x1 conv on original input
    for (i=0;i<H_IN;i=i+1) begin
      for (j=0;j<W_IN;j=j+1) begin
        for (oc=0; oc<OUT3; oc=oc+1) begin
          sum = 0;
          for (ic=0; ic<3; ic=ic+1) begin
            prod = sx64(kernel03[0][0][ic][oc]) * sx64(imgFP[i][j][ic]);
            sum = sum + prod;
          end
          sc1[i][j][oc] = $signed((sum + (SCALE/2)) / SCALE) + bias03[oc];
        end
      end
    end

    // add relu1_2 + shortcut -> block1
    for (i=0;i<H_IN;i=i+1) begin
      for (j=0;j<W_IN;j=j+1) begin
        for (oc=0; oc<OUT1; oc=oc+1) begin
          tmp_sum = $signed(relu1_2[i][j][oc]) + $signed(sc1[i][j][oc]);
          block1[i][j][oc] = tmp_sum;
        end
      end
    end

    // pool1: 2x2 max pool -> 16x16x28
    for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0; oc<OUT1; oc=oc+1) begin
      h0 = i*2;
      w0 = j*2;
      mv = -2147483648;
      for (ph=0; ph<2; ph=ph+1) for (pw=0; pw<2; pw=pw+1) begin
        vh = h0+ph; vw = w0+pw; vv = block1[vh][vw][oc];
        if (vv > mv) mv = vv;
      end
      pool1[i][j][oc] = mv;
    end

    // ===========================
    // Block2 - conv06 -> relu -> conv07 -> relu -> shortcut(1x1 on pool1) -> add -> pool
    // ===========================

    // conv06 on pool1 (16x16x28 -> 16x16x56)
    for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT6;oc=oc+1) begin
      sum = 0;
      for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) begin
        ih = i+kh-1; iw = j+kw-1;
        if (ih>=0 && ih<16 && iw>=0 && iw<16) begin
          for (ic=0; ic<OUT1; ic=ic+1) begin
            prod = sx64(kernel06[kh][kw][ic][oc]) * sx64(pool1[ih][iw][ic]);
            sum = sum + prod;
          end
        end
      end
      conv2a[i][j][oc] = $signed((sum + (SCALE/2)) / SCALE) + bias06[oc];
      if (conv2a[i][j][oc] < 0) relu2a[i][j][oc] = 0; else relu2a[i][j][oc] = conv2a[i][j][oc];
    end

    // conv07 on relu2a (16x16x56 -> 16x16x56)
    for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT7;oc=oc+1) begin
      sum = 0;
      for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) begin
        ih = i+kh-1; iw = j+kw-1;
        if (ih>=0 && ih<16 && iw>=0 && iw<16) begin
          for (ic=0; ic<OUT6; ic=ic+1) begin
            prod = sx64(kernel07[kh][kw][ic][oc]) * sx64(relu2a[ih][iw][ic]);
            sum = sum + prod;
          end
        end
      end
      conv2b[i][j][oc] = $signed((sum + (SCALE/2)) / SCALE) + bias07[oc];
      // apply ReLU here after conv2b (matching Python pattern: relu after second conv)
      if (conv2b[i][j][oc] < 0) conv2b[i][j][oc] = 0;
    end

    // shortcut2: 1x1 conv on pool1
    for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT8;oc=oc+1) begin
      sum = 0;
      for (ic=0; ic<OUT1; ic=ic+1) begin
        prod = sx64(kernel08[0][0][ic][oc]) * sx64(pool1[i][j][ic]);
        sum = sum + prod;
      end
      sc2[i][j][oc] = $signed((sum + (SCALE/2)) / SCALE) + bias08[oc];
    end

    // add conv2b + sc2 -> block2; conv2b already relu'ed
    for (i=0;i<16;i=i+1) for (j=0;j<16;j=j+1) for (oc=0;oc<OUT7;oc=oc+1) begin
      tmp_sum = $signed(conv2b[i][j][oc]) + $signed(sc2[i][j][oc]);
      // apply ReLU after add (important)
      if (tmp_sum < 0) block2[i][j][oc] = 0; else block2[i][j][oc] = tmp_sum;
    end

    // pool2: 2x2 max -> 8x8x56
    for (i=0;i<8;i=i+1) for (j=0;j<8;j=j+1) for (oc=0;oc<OUT7;oc=oc+1) begin
      h0 = i*2;
      w0 = j*2;
      mv = -2147483648;
      for (ph=0; ph<2; ph=ph+1) for (pw=0; pw<2; pw=pw+1) begin
        vh = h0+ph; vw = w0+pw; vv = block2[vh][vw][oc];
        if (vv > mv) mv = vv;
      end
      pool2[i][j][oc] = mv;
    end

    // Head: global avg pool over 8x8, rounding
    for (oc=0; oc<OUT7; oc=oc+1) begin
      sum = 0;
      for (i=0;i<8;i=i+1) for (j=0;j<8;j=j+1) sum = sum + sx64(pool2[i][j][oc]);
      // divide by 64 with rounding
      avg[oc] = $signed((sum + 32) / 64);
    end

    // dense: avg (56) x kernel12 (56x10)
    for (j=0; j<DENSE_OUT; j=j+1) begin
      sum = 0;
      for (i=0; i<DENSE_IN; i=i+1) begin
        prod = sx64(kernel12[i][j]) * sx64(avg[i]);
        sum = sum + prod;
      end
      // rounding division by SCALE
      logits[j] = $signed((sum + (SCALE/2)) / SCALE) + bias12[j];
    end

    // argmax
    best = 0;
    best_val = logits[0];
    for (j=1;j<DENSE_OUT;j=j+1) if (logits[j] > best_val) begin best_val = logits[j]; best = j; end

    $display("\n=== Prediction result ===");
    $display("Pred index: %0d (%s)", best, labels[best]);
    for (j=0;j<DENSE_OUT;j=j+1) begin
      rlog = $itor(logits[j]) / SCALE;
      $display("logit[%0d] = %0d  (≈ %0f)", j, logits[j], rlog);
    end

    $display("Done.");
    $finish;
  end
endmodule
