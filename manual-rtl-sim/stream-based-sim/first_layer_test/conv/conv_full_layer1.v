`timescale 1ns / 1ps

module conv2d_q17_dump_from_txt;

    parameter WIDTH    = 32;
    parameter HEIGHT   = 32;
    parameter CHANNELS = 3;
    parameter FILTERS  = 28;
    parameter K        = 3;
    parameter PAD      = 1;

    // --------------------------------------------------
    // Memories
    // --------------------------------------------------
    reg [7:0] image_r [0:HEIGHT-1][0:WIDTH-1];
    reg [7:0] image_g [0:HEIGHT-1][0:WIDTH-1];
    reg [7:0] image_b [0:HEIGHT-1][0:WIDTH-1];

    reg signed [7:0] kernel [0:26][0:FILTERS-1];
    reg signed [7:0] bias   [0:FILTERS-1];

    // --------------------------------------------------
    // Variables
    // --------------------------------------------------
    integer f,i,j,c,m,n;
    integer in_x,in_y;
    integer fout,file;
    integer r,cc;
    integer ret;

    integer tmp_int;   // <-- REQUIRED for Icarus

    reg signed [28:0] accum;
    reg signed [28:0] numerator;
    reg signed [23:0] kernel_mul;
    reg signed [23:0] bias_times_255;
    reg signed [20:0] out_int;
    reg signed [20:0] out_int_relu;

    reg [7:0] pix8;
    reg signed [15:0] kern16;
    reg signed [15:0] bias16;

    integer row_idx;
    reg [200*8:1] fname_out;

    // --------------------------------------------------
    // INITIAL
    // --------------------------------------------------
    initial begin

        $display("Loading images...");

        // ---------- R ----------
        file = $fopen("image_txt/image_r.txt","r");
        if(file==0) begin $display("R file missing"); $finish; end
        for(r=0;r<HEIGHT;r=r+1)
            for(cc=0;cc<WIDTH;cc=cc+1) begin
                ret = $fscanf(file,"%d",tmp_int);
                image_r[r][cc] = tmp_int[7:0];
            end
        $fclose(file);

        // ---------- G ----------
        file = $fopen("image_txt/image_g.txt","r");
        if(file==0) begin $display("G file missing"); $finish; end
        for(r=0;r<HEIGHT;r=r+1)
            for(cc=0;cc<WIDTH;cc=cc+1) begin
                ret = $fscanf(file,"%d",tmp_int);
                image_g[r][cc] = tmp_int[7:0];
            end
        $fclose(file);

        // ---------- B ----------
        file = $fopen("image_txt/image_b.txt","r");
        if(file==0) begin $display("B file missing"); $finish; end
        for(r=0;r<HEIGHT;r=r+1)
            for(cc=0;cc<WIDTH;cc=cc+1) begin
                ret = $fscanf(file,"%d",tmp_int);
                image_b[r][cc] = tmp_int[7:0];
            end
        $fclose(file);

        $display("Loading kernel...");

        file = $fopen("01_conv2d_kernel.txt","r");
        if(file==0) begin $display("Kernel file missing"); $finish; end
        for(r=0;r<27;r=r+1)
            for(cc=0;cc<FILTERS;cc=cc+1) begin
                ret = $fscanf(file,"%d",tmp_int);
                kernel[r][cc] = tmp_int;
            end
        $fclose(file);

        $display("Loading bias...");

        file = $fopen("01_conv2d_bias.txt","r");
        if(file==0) begin $display("Bias file missing"); $finish; end
        for(r=0;r<FILTERS;r=r+1) begin
            ret = $fscanf(file,"%d",tmp_int);
            bias[r] = tmp_int;
        end
        $fclose(file);

        $display("Starting convolution...");

        // --------------------------------------------------
        // CONVOLUTION
        // --------------------------------------------------
        for(f=0;f<FILTERS;f=f+1) begin

            $sformat(fname_out,"conv_res/feature_map_%0d.txt",f);
            fout = $fopen(fname_out,"w");
            if(fout==0) begin
                $display("Cannot open output file");
                $finish;
            end

            bias16 = bias[f];
            bias_times_255 = bias16 * 32'sd255;

            for(i=0;i<HEIGHT;i=i+1) begin
                for(j=0;j<WIDTH;j=j+1) begin

                    accum = bias_times_255;

                    for(m=0;m<K;m=m+1)
                        for(n=0;n<K;n=n+1) begin

                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if(!(in_y<0 || in_y>=HEIGHT ||
                                 in_x<0 || in_x>=WIDTH)) begin

                                for(c=0;c<CHANNELS;c=c+1) begin

                                    case(c)
                                        0: pix8 = image_r[in_y][in_x];
                                        1: pix8 = image_g[in_y][in_x];
                                        2: pix8 = image_b[in_y][in_x];
                                    endcase

                                    row_idx = m*K*CHANNELS + n*CHANNELS + c;
                                    kern16  = kernel[row_idx][f];

                                    kernel_mul = kern16 * $signed({8'd0,pix8});
                                    accum = accum + kernel_mul;
                                end
                            end
                        end

                    numerator = accum;

                    if(numerator>=0)
                        out_int = (numerator + 32'sd127)/32'sd255;
                    else
                        out_int = -((-numerator + 32'sd127)/32'sd255);

                    if(out_int<0)
                        out_int_relu = 0;
                    else
                        out_int_relu = out_int;

                    $fwrite(fout,"%0d ",out_int_relu);

                    if((j+1)%WIDTH==0)
                        $fwrite(fout,"\n");
                end
            end

            $fclose(fout);
            $display("Filter %0d done.",f);
        end

        $display("All 28 feature maps generated.");
        $finish;
    end

endmodule
