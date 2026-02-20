`timescale 1ns / 1ps

module conv2d_q17_tb;

    parameter WIDTH=32;
    parameter HEIGHT=32;
    parameter FILTERS=28;

    reg clk=0;
    always #5 clk=~clk;

    reg rst=1;
    reg start=0;
    wire done;

    integer r,c,f,file,ret,tmp;
    integer fout;
    reg [200*8:1] fname;

    conv2d_q17_top uut(
        .clk(clk),
        .rst(rst),
        .start(start),
        .done(done)
    );

    //--------------------------------------------------
    // Load inputs
    //--------------------------------------------------
    initial begin

        // R
        file=$fopen("image_txt/image_r.txt","r");
        for(r=0;r<HEIGHT;r=r+1)
            for(c=0;c<WIDTH;c=c+1) begin
                ret=$fscanf(file,"%d",tmp);
                uut.image_r[r][c]=tmp[7:0];
            end
        $fclose(file);

        // G
        file=$fopen("image_txt/image_g.txt","r");
        for(r=0;r<HEIGHT;r=r+1)
            for(c=0;c<WIDTH;c=c+1) begin
                ret=$fscanf(file,"%d",tmp);
                uut.image_g[r][c]=tmp[7:0];
            end
        $fclose(file);

        // B
        file=$fopen("image_txt/image_b.txt","r");
        for(r=0;r<HEIGHT;r=r+1)
            for(c=0;c<WIDTH;c=c+1) begin
                ret=$fscanf(file,"%d",tmp);
                uut.image_b[r][c]=tmp[7:0];
            end
        $fclose(file);

        // Kernel
        file=$fopen("01_conv2d_kernel.txt","r");
        for(r=0;r<27;r=r+1)
            for(c=0;c<FILTERS;c=c+1) begin
                ret=$fscanf(file,"%d",tmp);
                uut.kernel[r][c]=tmp;
            end
        $fclose(file);

        // Bias
        file=$fopen("01_conv2d_bias.txt","r");
        for(r=0;r<FILTERS;r=r+1) begin
            ret=$fscanf(file,"%d",tmp);
            uut.bias[r]=tmp;
        end
        $fclose(file);

        //--------------------------------------------------
        // Run
        //--------------------------------------------------
        #20 rst=0;
        #10 start=1;
        #10 start=0;

        wait(done);

        //--------------------------------------------------
        // Dump feature maps
        //--------------------------------------------------
        for(f=0; f<FILTERS; f=f+1) begin

            $sformat(fname,"conv_res/feature_map_%0d.txt",f);
            fout=$fopen(fname,"w");

            for(r=0;r<HEIGHT;r=r+1) begin
                for(c=0;c<WIDTH;c=c+1)
                    $fwrite(fout,"%0d ",uut.feature_map[f][r][c]);
                $fwrite(fout,"\n");
            end

            $fclose(fout);
        end

        $display("All feature maps dumped.");
        $finish;
    end

endmodule
