#include <iostream>

#include "myproject.h"
#include "parameters.h"


void myproject(
    input_t input_layer[32*32*3],
    result_t layer17_out[10]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=input_layer complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer17_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=input_layer,layer17_out 
    #pragma HLS DATAFLOW

    // hls-fpga-machine-learning insert load weights
#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        nnet::load_weights_from_txt<conv2d_weight_t, 756>(w2, "w2.txt");
        nnet::load_weights_from_txt<conv2d_bias_t, 28>(b2, "b2.txt");
        nnet::load_weights_from_txt<conv2d_1_weight_t, 7056>(w4, "w4.txt");
        nnet::load_weights_from_txt<conv2d_1_bias_t, 28>(b4, "b4.txt");
        nnet::load_weights_from_txt<conv2d_2_weight_t, 84>(w6, "w6.txt");
        nnet::load_weights_from_txt<conv2d_2_bias_t, 28>(b6, "b6.txt");
        nnet::load_weights_from_txt<conv2d_3_weight_t, 14112>(w9, "w9.txt");
        nnet::load_weights_from_txt<conv2d_3_bias_t, 56>(b9, "b9.txt");
        nnet::load_weights_from_txt<conv2d_4_weight_t, 28224>(w11, "w11.txt");
        nnet::load_weights_from_txt<conv2d_4_bias_t, 56>(b11, "b11.txt");
        nnet::load_weights_from_txt<conv2d_5_weight_t, 1568>(w13, "w13.txt");
        nnet::load_weights_from_txt<conv2d_5_bias_t, 56>(b13, "b13.txt");
        nnet::load_weights_from_txt<dense_weight_t, 560>(w17, "w17.txt");
        nnet::load_weights_from_txt<dense_bias_t, 10>(b17, "b17.txt");
        loaded_weights = true;    }
#endif
    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    conv2d_result_t layer2_out[32*32*28];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0

    layer3_t layer3_out[32*32*28];
    #pragma HLS ARRAY_PARTITION variable=layer3_out complete dim=0

    conv2d_1_result_t layer4_out[32*32*28];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0

    layer5_t layer5_out[32*32*28];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0

    conv2d_2_result_t layer6_out[32*32*28];
    #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0

    add_result_t layer7_out[32*32*28];
    #pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0

    layer8_t layer8_out[16*16*28];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0

    conv2d_3_result_t layer9_out[16*16*56];
    #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0

    layer10_t layer10_out[16*16*56];
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0

    conv2d_4_result_t layer11_out[16*16*56];
    #pragma HLS ARRAY_PARTITION variable=layer11_out complete dim=0

    layer12_t layer12_out[16*16*56];
    #pragma HLS ARRAY_PARTITION variable=layer12_out complete dim=0

    conv2d_5_result_t layer13_out[16*16*56];
    #pragma HLS ARRAY_PARTITION variable=layer13_out complete dim=0

    add_1_result_t layer14_out[16*16*56];
    #pragma HLS ARRAY_PARTITION variable=layer14_out complete dim=0

    layer15_t layer15_out[8*8*56];
    #pragma HLS ARRAY_PARTITION variable=layer15_out complete dim=0

    layer16_t layer16_out[56];
    #pragma HLS ARRAY_PARTITION variable=layer16_out complete dim=0

    nnet::conv_2d_cl<input_t, conv2d_result_t, config2>(input_layer, layer2_out, w2, b2); // conv2d

    nnet::relu<conv2d_result_t, layer3_t, relu_config3>(layer2_out, layer3_out); // conv2d_relu

    nnet::conv_2d_cl<layer3_t, conv2d_1_result_t, config4>(layer3_out, layer4_out, w4, b4); // conv2d_1

    nnet::relu<conv2d_1_result_t, layer5_t, relu_config5>(layer4_out, layer5_out); // conv2d_1_relu

    nnet::pointwise_conv_2d_cl<input_t, conv2d_2_result_t, config18>(input_layer, layer6_out, w6, b6); // conv2d_2

    nnet::add<layer5_t, conv2d_2_result_t, add_result_t, config7>(layer5_out, layer6_out, layer7_out); // add

    nnet::pooling2d_cl<add_result_t, layer8_t, config8>(layer7_out, layer8_out); // max_pooling2d

    nnet::conv_2d_cl<layer8_t, conv2d_3_result_t, config9>(layer8_out, layer9_out, w9, b9); // conv2d_3

    nnet::relu<conv2d_3_result_t, layer10_t, relu_config10>(layer9_out, layer10_out); // conv2d_3_relu

    nnet::conv_2d_cl<layer10_t, conv2d_4_result_t, config11>(layer10_out, layer11_out, w11, b11); // conv2d_4

    nnet::relu<conv2d_4_result_t, layer12_t, relu_config12>(layer11_out, layer12_out); // conv2d_4_relu

    nnet::pointwise_conv_2d_cl<layer8_t, conv2d_5_result_t, config19>(layer8_out, layer13_out, w13, b13); // conv2d_5

    nnet::add<layer12_t, conv2d_5_result_t, add_1_result_t, config14>(layer12_out, layer13_out, layer14_out); // add_1

    nnet::pooling2d_cl<add_1_result_t, layer15_t, config15>(layer14_out, layer15_out); // max_pooling2d_1

    nnet::global_pooling2d_cl<layer15_t, layer16_t, config16>(layer15_out, layer16_out); // global_average_pooling2d

    nnet::dense<layer16_t, result_t, config17>(layer16_out, layer17_out, w17, b17); // dense

}

