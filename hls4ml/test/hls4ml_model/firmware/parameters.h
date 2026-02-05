#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_fixed.h"
#include "ap_int.h"

#include "nnet_utils/nnet_code_gen.h"
#include "nnet_utils/nnet_helpers.h"
// hls-fpga-machine-learning insert includes
#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_activation_stream.h"
#include "nnet_utils/nnet_conv2d.h"
#include "nnet_utils/nnet_conv2d_stream.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_dense_stream.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_merge_stream.h"
#include "nnet_utils/nnet_pooling.h"
#include "nnet_utils/nnet_pooling_stream.h"
#include "nnet_utils/nnet_sepconv2d_stream.h"

// hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/w9.h"
#include "weights/b9.h"
#include "weights/w11.h"
#include "weights/b11.h"
#include "weights/w13.h"
#include "weights/b13.h"
#include "weights/w17.h"
#include "weights/b17.h"


// hls-fpga-machine-learning insert layer-config
// conv2d
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 27;
    static const unsigned n_out = 28;
    static const unsigned reuse_factor = 1;
    static const unsigned strategy = nnet::latency;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef conv2d_bias_t bias_t;
    typedef conv2d_weight_t weight_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = 32;
    static const unsigned in_width = 32;
    static const unsigned n_chan = 3;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 28;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 32;
    static const unsigned out_width = 32;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit =
        DIV_ROUNDUP(kernel_size * n_chan * n_filt, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 32;
    static const unsigned min_width = 32;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 1024;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_2<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv2d_bias_t bias_t;
    typedef conv2d_weight_t weight_t;
    typedef config2_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_height = nnet::scale_index_regular<K, S, W>;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_width = nnet::scale_index_regular<K, S, W>;
};
const ap_uint<config2::filt_height * config2::filt_width> config2::pixels[] = {0};

// conv2d_relu
struct relu_config3 : nnet::activ_config {
    static const unsigned n_in = 28672;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef conv2d_relu_table_t table_t;
};

// conv2d_1
struct config4_mult : nnet::dense_config {
    static const unsigned n_in = 252;
    static const unsigned n_out = 28;
    static const unsigned reuse_factor = 1;
    static const unsigned strategy = nnet::latency;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef conv2d_1_bias_t bias_t;
    typedef conv2d_1_weight_t weight_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config4 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = 32;
    static const unsigned in_width = 32;
    static const unsigned n_chan = 28;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 28;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 32;
    static const unsigned out_width = 32;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit =
        DIV_ROUNDUP(kernel_size * n_chan * n_filt, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 32;
    static const unsigned min_width = 32;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 1024;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_4<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv2d_1_bias_t bias_t;
    typedef conv2d_1_weight_t weight_t;
    typedef config4_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_height = nnet::scale_index_regular<K, S, W>;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_width = nnet::scale_index_regular<K, S, W>;
};
const ap_uint<config4::filt_height * config4::filt_width> config4::pixels[] = {0};

// conv2d_1_relu
struct relu_config5 : nnet::activ_config {
    static const unsigned n_in = 28672;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef conv2d_1_relu_table_t table_t;
};

// conv2d_2
struct config18_mult : nnet::dense_config {
    static const unsigned n_in = 3;
    static const unsigned n_out = 28;
    static const unsigned reuse_factor = 1;
    static const unsigned strategy = nnet::latency;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef conv2d_2_bias_t bias_t;
    typedef conv2d_2_weight_t weight_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config18 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 32;
    static const unsigned in_width = 32;
    static const unsigned n_chan = 3;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 28;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 32;
    static const unsigned out_width = 32;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit =
        DIV_ROUNDUP(kernel_size * n_chan * n_filt, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 32;
    static const unsigned min_width = 32;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 1024;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_18<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv2d_2_bias_t bias_t;
    typedef conv2d_2_weight_t weight_t;
    typedef config18_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_height = nnet::scale_index_regular<K, S, W>;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_width = nnet::scale_index_regular<K, S, W>;
};
const ap_uint<config18::filt_height * config18::filt_width> config18::pixels[] = {0};

// add
struct config7 : nnet::merge_config {
    static const unsigned n_elem = 32*32*28;
    static const unsigned reuse_factor = 1;
};

// max_pooling2d
struct config8 : nnet::pooling2d_config {
    static const unsigned in_height = 32;
    static const unsigned in_width = 32;
    static const unsigned n_filt = 28;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;

    static const unsigned filt_height = pool_height;
    static const unsigned filt_width = pool_width;
    static const unsigned n_chan = n_filt;

    static const unsigned out_height = 16;
    static const unsigned out_width = 16;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const bool count_pad = false;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned reuse_factor = 1;
    typedef model_default_t accum_t;
};

// conv2d_3
struct config9_mult : nnet::dense_config {
    static const unsigned n_in = 252;
    static const unsigned n_out = 56;
    static const unsigned reuse_factor = 1;
    static const unsigned strategy = nnet::latency;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef conv2d_3_bias_t bias_t;
    typedef conv2d_3_weight_t weight_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config9 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = 16;
    static const unsigned in_width = 16;
    static const unsigned n_chan = 28;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 56;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 16;
    static const unsigned out_width = 16;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit =
        DIV_ROUNDUP(kernel_size * n_chan * n_filt, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 16;
    static const unsigned min_width = 16;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 256;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_9<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv2d_3_bias_t bias_t;
    typedef conv2d_3_weight_t weight_t;
    typedef config9_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_height = nnet::scale_index_regular<K, S, W>;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_width = nnet::scale_index_regular<K, S, W>;
};
const ap_uint<config9::filt_height * config9::filt_width> config9::pixels[] = {0};

// conv2d_3_relu
struct relu_config10 : nnet::activ_config {
    static const unsigned n_in = 14336;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef conv2d_3_relu_table_t table_t;
};

// conv2d_4
struct config11_mult : nnet::dense_config {
    static const unsigned n_in = 504;
    static const unsigned n_out = 56;
    static const unsigned reuse_factor = 1;
    static const unsigned strategy = nnet::latency;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef conv2d_4_bias_t bias_t;
    typedef conv2d_4_weight_t weight_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config11 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = 16;
    static const unsigned in_width = 16;
    static const unsigned n_chan = 56;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 56;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 16;
    static const unsigned out_width = 16;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit =
        DIV_ROUNDUP(kernel_size * n_chan * n_filt, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 16;
    static const unsigned min_width = 16;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 256;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_11<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv2d_4_bias_t bias_t;
    typedef conv2d_4_weight_t weight_t;
    typedef config11_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_height = nnet::scale_index_regular<K, S, W>;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_width = nnet::scale_index_regular<K, S, W>;
};
const ap_uint<config11::filt_height * config11::filt_width> config11::pixels[] = {0};

// conv2d_4_relu
struct relu_config12 : nnet::activ_config {
    static const unsigned n_in = 14336;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef conv2d_4_relu_table_t table_t;
};

// conv2d_5
struct config19_mult : nnet::dense_config {
    static const unsigned n_in = 28;
    static const unsigned n_out = 56;
    static const unsigned reuse_factor = 1;
    static const unsigned strategy = nnet::latency;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef conv2d_5_bias_t bias_t;
    typedef conv2d_5_weight_t weight_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config19 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = 16;
    static const unsigned in_width = 16;
    static const unsigned n_chan = 28;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_height * filt_width;
    static const unsigned n_filt = 56;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = 16;
    static const unsigned out_width = 16;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit =
        DIV_ROUNDUP(kernel_size * n_chan * n_filt, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_height = 16;
    static const unsigned min_width = 16;
    static const ap_uint<filt_height * filt_width> pixels[min_height * min_width];
    static const unsigned n_partitions = 256;
    static const unsigned n_pixels = out_height * out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_19<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv2d_5_bias_t bias_t;
    typedef conv2d_5_weight_t weight_t;
    typedef config19_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_height = nnet::scale_index_regular<K, S, W>;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index_width = nnet::scale_index_regular<K, S, W>;
};
const ap_uint<config19::filt_height * config19::filt_width> config19::pixels[] = {0};

// add_1
struct config14 : nnet::merge_config {
    static const unsigned n_elem = 16*16*56;
    static const unsigned reuse_factor = 1;
};

// max_pooling2d_1
struct config15 : nnet::pooling2d_config {
    static const unsigned in_height = 16;
    static const unsigned in_width = 16;
    static const unsigned n_filt = 56;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;

    static const unsigned filt_height = pool_height;
    static const unsigned filt_width = pool_width;
    static const unsigned n_chan = n_filt;

    static const unsigned out_height = 8;
    static const unsigned out_width = 8;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const bool count_pad = false;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned reuse_factor = 1;
    typedef model_default_t accum_t;
};

// global_average_pooling2d
struct config16 : nnet::pooling2d_config {
    static const unsigned in_height = 8;
    static const unsigned in_width = 8;
    static const unsigned n_filt = 56;
    static const nnet::Pool_Op pool_op = nnet::Average;
    static const unsigned reuse_factor = 1;
    typedef model_default_t accum_t;
};

// dense
struct config17 : nnet::dense_config {
    static const unsigned n_in = 56;
    static const unsigned n_out = 10;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned strategy = nnet::latency;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 560;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef model_default_t accum_t;
    typedef dense_bias_t bias_t;
    typedef dense_weight_t weight_t;
    typedef layer17_index index_t;
    template<class data_T, class res_T, class CONFIG_T>
    using kernel = nnet::DenseLatency<data_T, res_T, CONFIG_T>;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};



#endif
