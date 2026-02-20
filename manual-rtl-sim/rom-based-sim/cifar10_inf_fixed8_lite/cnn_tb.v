`timescale 1ns/1ps
// cifar10_infer_tb.v
// Testbench: reads the same text files you used previously, writes image+weights+biases
// into cifar10_top via the simple write interface, pulses start, waits done, prints outputs.
// The testbench performs the file I/O and mapping; it does NOT compute inference.

module cifar10_infer_tb;
  reg clk;
  reg rst_n;

  // drive/write interface to top
  reg wr_en;
  reg [4:0] wr_sel;
  reg [15:0] wr_addr;
  reg [31:0] wr_data;

  reg start;
  wire done;
  wire [3:0] pred_index;
  wire [31:0] logits0, logits1, logits2, logits3, logits4, logits5, logits6, logits7, logits8, logits9;

  // instantiate top
  cifar10_top dut (
    .clk(clk),
    .rst_n(rst_n),
    .wr_en(wr_en),
    .wr_sel(wr_sel),
    .wr_addr(wr_addr),
    .wr_data(wr_data),
    .start(start),
    .done(done),
    .pred_index(pred_index),
    .logits0(logits0),
    .logits1(logits1),
    .logits2(logits2),
    .logits3(logits3),
    .logits4(logits4),
    .logits5(logits5),
    .logits6(logits6),
    .logits7(logits7),
    .logits8(logits8),
    .logits9(logits9)
  );

  // same params as top (duplicate for TB indexing & file loops)
  localparam integer SCALE = 128;
  localparam integer H_IN = 32;
  localparam integer W_IN = 32;
  localparam integer CH_IN = 3;
  localparam integer OUT1 = 28;
  localparam integer OUT2 = 28;
  localparam integer OUT3 = 28;
  localparam integer OUT6 = 56;
  localparam integer OUT7 = 56;
  localparam integer OUT8 = 56;
  localparam integer DENSE_IN = 56;
  localparam integer DENSE_OUT = 10;

  integer fd, status, tmp;
  integer i,j,kh,kw,ic,oc;
  integer r,g,b;
  integer addr;
  reg [80*8-1:0] labels [0:9];

  // helper local functions for flattening indices (same logic as top)
  function integer idx_img;
    input integer ih, iw, ic;
    begin idx_img = ((ih * W_IN) + iw) * CH_IN + ic; end
  endfunction

  function integer idx_k01;
    input integer kh, kw, ic, oc;
    begin idx_k01 = (((kh*3 + kw)*3 + ic) * OUT1) + oc; end
  endfunction

  function integer idx_k02;
    input integer kh, kw, ic, oc;
    begin idx_k02 = ((((kh*3) + kw) * OUT1 + ic) * OUT2) + oc; end
  endfunction

  function integer idx_k03;
    input integer kh, kw, ic, oc;
    begin idx_k03 = (((kh*1 + kw)*3 + ic) * OUT3) + oc; end
  endfunction

  function integer idx_k06;
    input integer kh, kw, ic, oc;
    begin idx_k06 = ((((kh*3) + kw) * OUT1 + ic) * OUT6) + oc; end
  endfunction

  function integer idx_k07;
    input integer kh, kw, ic, oc;
    begin idx_k07 = ((((kh*3) + kw) * OUT6 + ic) * OUT7) + oc; end
  endfunction

  function integer idx_k08;
    input integer kh, kw, ic, oc;
    begin idx_k08 = (((kh*1 + kw) * OUT1 + ic) * OUT8) + oc; end
  endfunction

  function integer idx_k12;
    input integer ii,jj;
    begin idx_k12 = ii * DENSE_OUT + jj; end
  endfunction

  // local memory sizes (matching top)
  localparam integer IMG_SZ  = H_IN * W_IN * CH_IN;
  localparam integer K01_SZ  = 3*3*3*OUT1;
  localparam integer B01_SZ  = OUT1;
  localparam integer K02_SZ  = 3*3*OUT1*OUT2;
  localparam integer B02_SZ  = OUT2;
  localparam integer K03_SZ  = 1*1*3*OUT3;
  localparam integer B03_SZ  = OUT3;
  localparam integer K06_SZ  = 3*3*OUT1*OUT6;
  localparam integer B06_SZ  = OUT6;
  localparam integer K07_SZ  = 3*3*OUT6*OUT7;
  localparam integer B07_SZ  = OUT7;
  localparam integer K08_SZ  = 1*1*OUT1*OUT8;
  localparam integer B08_SZ  = OUT8;
  localparam integer K12_SZ  = DENSE_IN * DENSE_OUT;
  localparam integer B12_SZ  = DENSE_OUT;

  // write selection constants (must match top)
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

  // clk generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk; // 100MHz-like (10ns period) but arbitrary
  end

  // initial / stimulus
  initial begin
    rst_n = 1'b0;
    wr_en = 1'b0;
    wr_sel = 5'd0;
    wr_addr = 16'd0;
    wr_data = 32'd0;
    start = 1'b0;

    labels[0] = "airplane"; labels[1] = "automobile"; labels[2] = "bird"; labels[3] = "cat";
    labels[4] = "deer"; labels[5] = "dog"; labels[6] = "frog"; labels[7] = "horse";
    labels[8] = "ship"; labels[9] = "truck";

    #20;
    rst_n = 1'b1;

    $display("TB: Loading image channels into DUT via write port...");

    // load image R
    fd = $fopen("image_txt/image_r.txt","r");
    if (fd==0) begin $display("ERR open image_r"); $finish; end
    addr = 0;
    for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) begin
      status = $fscanf(fd, " %d", tmp);
      if (status != 1) begin $display("ERR read image_r %0d %0d", i,j); $finish; end
      r = tmp;
      // convert same as TB: imgFP = (r*(SCALE-1)+127)/255
      tmp = (r * (SCALE-1) + 127) / 255;
      // write to DUT image memory: channel 0
      @(posedge clk);
      wr_en <= 1'b1;
      wr_sel <= SEL_IMG;
      wr_addr <= idx_img(i,j,0);
      wr_data <= tmp;
      @(posedge clk);
      wr_en <= 1'b0;
    end
    $fclose(fd);

    // load image G
    fd = $fopen("image_txt/image_g.txt","r");
    if (fd==0) begin $display("ERR open image_g"); $finish; end
    for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) begin
      status = $fscanf(fd, " %d", tmp);
      if (status != 1) begin $display("ERR read image_g %0d %0d", i,j); $finish; end
      g = tmp;
      tmp = (g * (SCALE-1) + 127) / 255;
      @(posedge clk);
      wr_en <= 1'b1;
      wr_sel <= SEL_IMG;
      wr_addr <= idx_img(i,j,1);
      wr_data <= tmp;
      @(posedge clk);
      wr_en <= 1'b0;
    end
    $fclose(fd);

    // load image B
    fd = $fopen("image_txt/image_b.txt","r");
    if (fd==0) begin $display("ERR open image_b"); $finish; end
    for (i=0;i<H_IN;i=i+1) for (j=0;j<W_IN;j=j+1) begin
      status = $fscanf(fd, " %d", tmp);
      if (status != 1) begin $display("ERR read image_b %0d %0d", i,j); $finish; end
      b = tmp;
      tmp = (b * (SCALE-1) + 127) / 255;
      @(posedge clk);
      wr_en <= 1'b1;
      wr_sel <= SEL_IMG;
      wr_addr <= idx_img(i,j,2);
      wr_data <= tmp;
      @(posedge clk);
      wr_en <= 1'b0;
    end
    $fclose(fd);
    $display("TB: Image loaded.");

    // ------------------------------------------------------------------
    // Load all weight/bias files and write into DUT via write interface
    // ------------------------------------------------------------------

    // 01_conv2d kernel
    fd = $fopen("model_weights_fixed8/01_conv2d_kernel.txt","r");
    if (fd==0) begin $display("ERR open 01_conv2d_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<3;ic=ic+1) for (oc=0;oc<OUT1;oc=oc+1) begin
      status = $fscanf(fd," %d", tmp); if (status!=1) begin $display("ERR 01 read"); $finish; end
      @(posedge clk);
      wr_en <= 1'b1; wr_sel <= SEL_K01; wr_addr <= idx_k01(kh,kw,ic,oc); wr_data <= tmp;
      @(posedge clk);
      wr_en <= 1'b0;
    end
    $fclose(fd);

    // 01 bias
    fd = $fopen("model_weights_fixed8/01_conv2d_bias.txt","r");
    if (fd==0) begin
      // if missing, write zeros
      for (oc=0;oc<OUT1;oc=oc+1) begin
        @(posedge clk); wr_en <= 1'b1; wr_sel <= SEL_B01; wr_addr <= oc; wr_data <= 32'd0; @(posedge clk); wr_en <= 1'b0;
      end
    end else begin
      for (oc=0;oc<OUT1;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 01bias"); $finish; end
        @(posedge clk); wr_en <= 1'b1; wr_sel <= SEL_B01; wr_addr <= oc; wr_data <= tmp; @(posedge clk); wr_en <= 1'b0;
      end
      $fclose(fd);
    end

    // 02_conv2d_1 kernel
    fd = $fopen("model_weights_fixed8/02_conv2d_1_kernel.txt","r");
    if (fd==0) begin $display("ERR open 02_conv2d_1_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<OUT1;ic=ic+1) for (oc=0;oc<OUT2;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 02 read"); $finish; end
      @(posedge clk); wr_en <= 1'b1; wr_sel <= SEL_K02; wr_addr <= idx_k02(kh,kw,ic,oc); wr_data <= tmp; @(posedge clk); wr_en <= 1'b0;
    end
    $fclose(fd);

    // 02 bias
    fd = $fopen("model_weights_fixed8/02_conv2d_1_bias.txt","r");
    if (fd==0) begin
      for (oc=0;oc<OUT2;oc=oc+1) begin @(posedge clk); wr_en <= 1'b1; wr_sel <= SEL_B02; wr_addr <= oc; wr_data <= 32'd0; @(posedge clk); wr_en <= 1'b0; end
    end else begin
      for (oc=0;oc<OUT2;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 02bias"); $finish; end @(posedge clk); wr_en <= 1'b1; wr_sel <= SEL_B02; wr_addr <= oc; wr_data <= tmp; @(posedge clk); wr_en <= 1'b0; end
      $fclose(fd);
    end

    // 03_conv2d_2 kernel (1x1x3 -> 28)
    fd = $fopen("model_weights_fixed8/03_conv2d_2_kernel.txt","r");
    if (fd==0) begin $display("ERR open 03_conv2d_2_kernel"); $finish; end
    for (kh=0;kh<1;kh=kh+1) for (kw=0;kw<1;kw=kw+1) for (ic=0;ic<3;ic=ic+1) for (oc=0;oc<OUT3;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 03 read"); $finish; end
      @(posedge clk); wr_en <= 1'b1; wr_sel <= SEL_K03; wr_addr <= idx_k03(kh,kw,ic,oc); wr_data <= tmp; @(posedge clk); wr_en <= 1'b0;
    end
    $fclose(fd);
    // 03 bias
    fd = $fopen("model_weights_fixed8/03_conv2d_2_bias.txt","r");
    if (fd==0) begin for (oc=0;oc<OUT3;oc=oc+1) begin @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B03; wr_addr<=oc; wr_data<=32'd0; @(posedge clk); wr_en<=1'b0; end end
    else begin for (oc=0;oc<OUT3;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 03bias"); $finish; end @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B03; wr_addr<=oc; wr_data<=tmp; @(posedge clk); wr_en<=1'b0; end $fclose(fd); end

    // 06_conv2d_3
    fd = $fopen("model_weights_fixed8/06_conv2d_3_kernel.txt","r");
    if (fd==0) begin $display("ERR open 06_conv2d_3_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<OUT1;ic=ic+1) for (oc=0;oc<OUT6;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 06 read"); $finish; end
      @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_K06; wr_addr<=idx_k06(kh,kw,ic,oc); wr_data<=tmp; @(posedge clk); wr_en<=1'b0;
    end
    $fclose(fd);
    // 06 bias
    fd = $fopen("model_weights_fixed8/06_conv2d_3_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT6;oc=oc+1) begin @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B06; wr_addr<=oc; wr_data<=32'd0; @(posedge clk); wr_en<=1'b0; end
    else begin for (oc=0;oc<OUT6;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 06bias"); $finish; end @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B06; wr_addr<=oc; wr_data<=tmp; @(posedge clk); wr_en<=1'b0; end $fclose(fd); end

    // 07_conv2d_4
    fd = $fopen("model_weights_fixed8/07_conv2d_4_kernel.txt","r");
    if (fd==0) begin $display("ERR open 07_conv2d_4_kernel"); $finish; end
    for (kh=0;kh<3;kh=kh+1) for (kw=0;kw<3;kw=kw+1) for (ic=0;ic<OUT6;ic=ic+1) for (oc=0;oc<OUT7;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 07 read"); $finish; end
      @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_K07; wr_addr<=idx_k07(kh,kw,ic,oc); wr_data<=tmp; @(posedge clk); wr_en<=1'b0;
    end
    $fclose(fd);
    // 07 bias
    fd = $fopen("model_weights_fixed8/07_conv2d_4_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT7;oc=oc+1) begin @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B07; wr_addr<=oc; wr_data<=32'd0; @(posedge clk); wr_en<=1'b0; end
    else begin for (oc=0;oc<OUT7;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 07bias"); $finish; end @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B07; wr_addr<=oc; wr_data<=tmp; @(posedge clk); wr_en<=1'b0; end $fclose(fd); end

    // 08_conv2d_5 (shortcut2)
    fd = $fopen("model_weights_fixed8/08_conv2d_5_kernel.txt","r");
    if (fd==0) begin $display("ERR open 08_conv2d_5_kernel"); $finish; end
    for (kh=0;kh<1;kh=kh+1) for (kw=0;kw<1;kw=kw+1) for (ic=0;ic<OUT1;ic=ic+1) for (oc=0;oc<OUT8;oc=oc+1) begin
      status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 08 read"); $finish; end
      @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_K08; wr_addr<=idx_k08(kh,kw,ic,oc); wr_data<=tmp; @(posedge clk); wr_en<=1'b0;
    end
    $fclose(fd);
    // 08 bias
    fd = $fopen("model_weights_fixed8/08_conv2d_5_bias.txt","r");
    if (fd==0) for (oc=0;oc<OUT8;oc=oc+1) begin @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B08; wr_addr<=oc; wr_data<=32'd0; @(posedge clk); wr_en<=1'b0; end
    else begin for (oc=0;oc<OUT8;oc=oc+1) begin status=$fscanf(fd," %d",tmp); if (status!=1) begin $display("ERR 08bias"); $finish; end @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B08; wr_addr<=oc; wr_data<=tmp; @(posedge clk); wr_en<=1'b0; end $fclose(fd); end

    // 12_dense
    fd = $fopen("model_weights_fixed8/12_dense_kernel.txt","r");
    if (fd==0) begin $display("ERR open 12_dense_kernel"); $finish; end
    for (i=0;i<DENSE_IN;i=i+1) for (j=0;j<DENSE_OUT;j=j+1) begin
      status = $fscanf(fd," %d", tmp); if (status!=1) begin $display("ERR 12 read"); $finish; end
      @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_K12; wr_addr<=idx_k12(i,j); wr_data<=tmp; @(posedge clk); wr_en<=1'b0;
    end
    $fclose(fd);
    // 12 bias
    fd = $fopen("model_weights_fixed8/12_dense_bias.txt","r");
    if (fd==0) for (j=0;j<DENSE_OUT;j=j+1) begin @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B12; wr_addr<=j; wr_data<=32'd0; @(posedge clk); wr_en<=1'b0; end
    else begin for (j=0;j<DENSE_OUT;j=j+1) begin status=$fscanf(fd," %d", tmp); if (status!=1) begin $display("ERR 12bias"); $finish; end @(posedge clk); wr_en<=1'b1; wr_sel<=SEL_B12; wr_addr<=j; wr_data<=tmp; @(posedge clk); wr_en<=1'b0; end $fclose(fd); end

    $display("TB: Loaded all weights and biases into DUT.");

    // give a cycle
    @(posedge clk);
    #1;

    // start inference by pulsing start for one clock
    @(posedge clk); start <= 1'b1;
    @(posedge clk); start <= 1'b0;

    // wait for done
    wait (done == 1'b1);

    // print results (match format in original TB)
    $display("\n=== Prediction result ===");
    $display("Pred index: %0d (%s)", pred_index, labels[pred_index]);
    $display("logit[0] = %0d", logits0);
    $display("logit[1] = %0d", logits1);
    $display("logit[2] = %0d", logits2);
    $display("logit[3] = %0d", logits3);
    $display("logit[4] = %0d", logits4);
    $display("logit[5] = %0d", logits5);
    $display("logit[6] = %0d", logits6);
    $display("logit[7] = %0d", logits7);
    $display("logit[8] = %0d", logits8);
    $display("logit[9] = %0d", logits9);

    $display("TB: Done. Finishing simulation.");
    #10;
    $finish;
  end

endmodule
