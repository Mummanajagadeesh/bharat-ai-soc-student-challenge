#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <array>
#include <cstddef>
#include <cstdio>
#include <tuple>
#include <tuple>


// hls-fpga-machine-learning insert numbers

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<38,18> conv2d_result_t;
typedef ap_fixed<16,6> conv2d_weight_t;
typedef ap_fixed<16,6> conv2d_bias_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<18,8> conv2d_relu_table_t;
typedef ap_fixed<41,21> conv2d_1_result_t;
typedef ap_fixed<16,6> conv2d_1_weight_t;
typedef ap_fixed<16,6> conv2d_1_bias_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<18,8> conv2d_1_relu_table_t;
typedef ap_fixed<35,15> conv2d_2_result_t;
typedef ap_fixed<16,6> conv2d_2_weight_t;
typedef ap_fixed<16,6> conv2d_2_bias_t;
typedef ap_fixed<36,16> add_result_t;
typedef ap_fixed<36,16> layer8_t;
typedef ap_fixed<61,31> conv2d_3_result_t;
typedef ap_fixed<16,6> conv2d_3_weight_t;
typedef ap_fixed<16,6> conv2d_3_bias_t;
typedef ap_fixed<16,6> layer10_t;
typedef ap_fixed<18,8> conv2d_3_relu_table_t;
typedef ap_fixed<42,22> conv2d_4_result_t;
typedef ap_fixed<16,6> conv2d_4_weight_t;
typedef ap_fixed<16,6> conv2d_4_bias_t;
typedef ap_fixed<16,6> layer12_t;
typedef ap_fixed<18,8> conv2d_4_relu_table_t;
typedef ap_fixed<58,28> conv2d_5_result_t;
typedef ap_fixed<16,6> conv2d_5_weight_t;
typedef ap_fixed<16,6> conv2d_5_bias_t;
typedef ap_fixed<59,29> add_1_result_t;
typedef ap_fixed<59,29> layer15_t;
typedef ap_fixed<16,6> layer16_t;
typedef ap_fixed<39,19> result_t;
typedef ap_fixed<16,6> dense_weight_t;
typedef ap_fixed<16,6> dense_bias_t;
typedef ap_uint<1> layer17_index;

// hls-fpga-machine-learning insert emulator-defines


#endif
