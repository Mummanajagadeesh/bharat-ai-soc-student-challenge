/**
k2c_convolution_layers.c
This file is part of keras2c
Copyright 2020 Rory Conlin
Licensed under MIT License
https://github.com/f0uriest/keras2c
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "k2c_include.h"

/* ----------------------------- Padding ----------------------------- */

void k2c_pad1d(k2c_tensor* output, const k2c_tensor* input, const float fill,
               const size_t * pad) {

    const size_t in_width = input->shape[1];
    const size_t pad_top = pad[0];

    if (fabs(fill) < 1e-6) {
        memset(output->array, 0, output->numel * sizeof(output->array[0]));
    } else {
        for (size_t i = 0; i < output->numel; ++i) output->array[i] = fill;
    }

    const size_t offset = pad_top * in_width;
    memcpy(&output->array[offset], &input->array[0],
           input->numel * sizeof(input->array[0]));
}

void k2c_pad2d(k2c_tensor* output, const k2c_tensor* input, const float fill,
               const size_t * pad) {

    const size_t in_height = input->shape[0];
    const size_t in_width  = input->shape[1];
    const size_t in_ch     = input->shape[2];
    const size_t pad_top   = pad[0];
    const size_t pad_left  = pad[2];
    const size_t pad_right = pad[3];

    if (fabs(fill) < 1e-6) {
        memset(output->array, 0, output->numel * sizeof(output->array[0]));
    } else {
        for (size_t i = 0; i < output->numel; ++i) output->array[i] = fill;
    }

    size_t offset = in_ch * (pad_left + pad_right + in_width) * pad_top +
                    in_ch * pad_left;
    const size_t num  = in_ch * in_width;
    const size_t step = num + in_ch * (pad_left + pad_right);

    for (size_t i = 0; i < in_height; ++i) {
        memcpy(&output->array[offset], &input->array[i * num],
               num * sizeof(input->array[0]));
        offset += step;
    }
}

/* ----------------------------- Conv helpers ----------------------------- */

static inline float k2c_relu_f(float x) {
    return x > 0.0f ? x : 0.0f;
}

/* ----------------------------- Conv1D (unchanged) ----------------------------- */

void k2c_conv1d(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
                const k2c_tensor* bias, const size_t stride, const size_t dilation,
                k2c_activationType *activation) {

    memset(output->array, 0, output->numel * sizeof(output->array[0]));

    const size_t out_times    = output->shape[0];
    const size_t out_channels = output->shape[1];
    const size_t in_channels  = input->shape[1];

    for (size_t x0 = 0; x0 < out_times; ++x0) {
        for (size_t z = 0; z < kernel->shape[0]; ++z) {
            for (size_t q = 0; q < in_channels; ++q) {
                for (size_t k = 0; k < out_channels; ++k) {
                    output->array[x0 * out_channels + k] +=
                        kernel->array[z * (kernel->shape[2] * kernel->shape[1]) +
                                      q * (kernel->shape[2]) + k] *
                        input->array[(x0 * stride + dilation * z) * in_channels + q];
                }
            }
        }
    }
    k2c_bias_add(output, bias);
    activation(output->array, output->numel);
}

/* ----------------------------- Conv2D: Generic (optimized) ----------------------------- */

void k2c_conv2d(
    k2c_tensor * restrict output,
    const k2c_tensor * restrict input,
    const k2c_tensor * restrict kernel,
    const k2c_tensor * restrict bias,
    const size_t * restrict stride,
    const size_t * restrict dilation,
    k2c_activationType *activation
) {
    float * restrict out = output->array;
    const float * restrict in  = input->array;
    const float * restrict ker = kernel->array;

    const size_t out_rows = output->shape[0];
    const size_t out_cols = output->shape[1];
    const size_t out_ch   = output->shape[2];
    const size_t in_ch    = input->shape[2];

    const size_t out_row_step = out_cols * out_ch;
    const size_t in_row_step  = input->shape[1] * in_ch;

    memset(out, 0, output->numel * sizeof(float));

    for (size_t x0 = 0; x0 < out_rows; ++x0) {
        float *out_row = out + x0 * out_row_step;
        const size_t in_x0 = x0 * stride[0];

        for (size_t x1 = 0; x1 < out_cols; ++x1) {
            float *out_pix = out_row + x1 * out_ch;
            const size_t in_x1 = x1 * stride[1];

            for (size_t z0 = 0; z0 < kernel->shape[0]; ++z0) {
                const size_t in_r = (in_x0 + z0 * dilation[0]) * in_row_step;
                const size_t ker_z0 = z0 * kernel->shape[1] * in_ch * out_ch;

                for (size_t z1 = 0; z1 < kernel->shape[1]; ++z1) {
                    const float *in_pix =
                        in + in_r + (in_x1 + z1 * dilation[1]) * in_ch;
                    const float *ker_pix =
                        ker + ker_z0 + z1 * in_ch * out_ch;

                    for (size_t q = 0; q < in_ch; ++q) {
                        const float v = in_pix[q];
                        const float *krow = ker_pix + q * out_ch;

                        size_t k = 0;
                        for (; k + 3 < out_ch; k += 4) {
                            out_pix[k]   += krow[k]   * v;
                            out_pix[k+1] += krow[k+1] * v;
                            out_pix[k+2] += krow[k+2] * v;
                            out_pix[k+3] += krow[k+3] * v;
                        }
                        for (; k < out_ch; ++k) {
                            out_pix[k] += krow[k] * v;
                        }
                    }
                }
            }
        }
    }

    k2c_bias_add(output, bias);
    activation(out, output->numel);
}

/* ----------------------------- Conv2D: LINEAR (bias fused) ----------------------------- */

void k2c_conv2d_linear(
    k2c_tensor * restrict output,
    const k2c_tensor * restrict input,
    const k2c_tensor * restrict kernel,
    const k2c_tensor * restrict bias,
    const size_t * restrict stride,
    const size_t * restrict dilation
) {
    float * restrict out = output->array;
    const float * restrict in  = input->array;
    const float * restrict ker = kernel->array;
    const float * restrict b   = bias->array;

    const size_t out_rows = output->shape[0];
    const size_t out_cols = output->shape[1];
    const size_t out_ch   = output->shape[2];
    const size_t in_ch    = input->shape[2];

    const size_t out_row_step = out_cols * out_ch;
    const size_t in_row_step  = input->shape[1] * in_ch;

    memset(out, 0, output->numel * sizeof(float));

    for (size_t x0 = 0; x0 < out_rows; ++x0) {
        float *out_row = out + x0 * out_row_step;
        const size_t in_x0 = x0 * stride[0];

        for (size_t x1 = 0; x1 < out_cols; ++x1) {
            float *out_pix = out_row + x1 * out_ch;
            const size_t in_x1 = x1 * stride[1];

            for (size_t z0 = 0; z0 < kernel->shape[0]; ++z0) {
                const size_t in_r = (in_x0 + z0 * dilation[0]) * in_row_step;
                const size_t ker_z0 = z0 * kernel->shape[1] * in_ch * out_ch;

                for (size_t z1 = 0; z1 < kernel->shape[1]; ++z1) {
                    const float *in_pix =
                        in + in_r + (in_x1 + z1 * dilation[1]) * in_ch;
                    const float *ker_pix =
                        ker + ker_z0 + z1 * in_ch * out_ch;

                    for (size_t q = 0; q < in_ch; ++q) {
                        const float v = in_pix[q];
                        const float *krow = ker_pix + q * out_ch;

                        size_t k = 0;
                        for (; k + 3 < out_ch; k += 4) {
                            out_pix[k]   += krow[k]   * v;
                            out_pix[k+1] += krow[k+1] * v;
                            out_pix[k+2] += krow[k+2] * v;
                            out_pix[k+3] += krow[k+3] * v;
                        }
                        for (; k < out_ch; ++k) {
                            out_pix[k] += krow[k] * v;
                        }
                    }
                }
            }

            for (size_t k = 0; k < out_ch; ++k) {
                out_pix[k] += b[k];
            }
        }
    }
}

/* ----------------------------- Conv2D: RELU (bias + ReLU fused) ----------------------------- */

void k2c_conv2d_relu(
    k2c_tensor * restrict output,
    const k2c_tensor * restrict input,
    const k2c_tensor * restrict kernel,
    const k2c_tensor * restrict bias,
    const size_t * restrict stride,
    const size_t * restrict dilation
) {
    float * restrict out = output->array;
    const float * restrict in  = input->array;
    const float * restrict ker = kernel->array;
    const float * restrict b   = bias->array;

    const size_t out_rows = output->shape[0];
    const size_t out_cols = output->shape[1];
    const size_t out_ch   = output->shape[2];
    const size_t in_ch    = input->shape[2];

    const size_t out_row_step = out_cols * out_ch;
    const size_t in_row_step  = input->shape[1] * in_ch;

    memset(out, 0, output->numel * sizeof(float));

    for (size_t x0 = 0; x0 < out_rows; ++x0) {
        float *out_row = out + x0 * out_row_step;
        const size_t in_x0 = x0 * stride[0];

        for (size_t x1 = 0; x1 < out_cols; ++x1) {
            float *out_pix = out_row + x1 * out_ch;
            const size_t in_x1 = x1 * stride[1];

            for (size_t z0 = 0; z0 < kernel->shape[0]; ++z0) {
                const size_t in_r = (in_x0 + z0 * dilation[0]) * in_row_step;
                const size_t ker_z0 = z0 * kernel->shape[1] * in_ch * out_ch;

                for (size_t z1 = 0; z1 < kernel->shape[1]; ++z1) {
                    const float *in_pix =
                        in + in_r + (in_x1 + z1 * dilation[1]) * in_ch;
                    const float *ker_pix =
                        ker + ker_z0 + z1 * in_ch * out_ch;

                    for (size_t q = 0; q < in_ch; ++q) {
                        const float v = in_pix[q];
                        const float *krow = ker_pix + q * out_ch;

                        size_t k = 0;
                        for (; k + 3 < out_ch; k += 4) {
                            out_pix[k]   += krow[k]   * v;
                            out_pix[k+1] += krow[k+1] * v;
                            out_pix[k+2] += krow[k+2] * v;
                            out_pix[k+3] += krow[k+3] * v;
                        }
                        for (; k < out_ch; ++k) {
                            out_pix[k] += krow[k] * v;
                        }
                    }
                }
            }

            for (size_t k = 0; k < out_ch; ++k) {
                out_pix[k] = k2c_relu_f(out_pix[k] + b[k]);
            }
        }
    }
}

/* ----------------------------- Conv3D (unchanged) ----------------------------- */

void k2c_conv3d(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
                const k2c_tensor* bias, const size_t * stride, const size_t * dilation,
                k2c_activationType *activation) {

    memset(output->array, 0, output->numel * sizeof(output->array[0]));
    const size_t dim1 = output->shape[0];
    const size_t dim2 = output->shape[1];
    const size_t dim3 = output->shape[2];
    const size_t out_channels = output->shape[3];
    const size_t in_channels  = input->shape[3];

    for (size_t x0 = 0; x0 < dim1; ++x0) {
        for (size_t x1 = 0; x1 < dim2; ++x1) {
            for (size_t x2 = 0; x2 < dim3; ++x2) {
                for (size_t z0 = 0; z0 < kernel->shape[0]; ++z0) {
                    for (size_t z1 = 0; z1 < kernel->shape[1]; ++z1) {
                        for (size_t z2 = 0; z2 < kernel->shape[2]; ++z2) {
                            for (size_t q = 0; q < in_channels; ++q) {
                                for (size_t k = 0; k < out_channels; ++k) {
                                    output->array[x0*(output->shape[3]*output->shape[2]*output->shape[1])
                                                  + x1*(output->shape[3]*output->shape[2])
                                                  + x2*(output->shape[3]) + k] +=
                                        kernel->array[z0*(kernel->shape[4]*kernel->shape[3]
                                                          *kernel->shape[2]*kernel->shape[1])
                                                      + z1*(kernel->shape[4]*kernel->shape[3]
                                                            *kernel->shape[2])
                                                      + z2*(kernel->shape[4]*kernel->shape[3])
                                                      + q*(kernel->shape[4]) + k]
                                        * input->array[(x0*stride[0] + dilation[0]*z0)
                                                       *(input->shape[3]*input->shape[2]*input->shape[1])
                                                       + (x1*stride[1] + dilation[1]*z1)
                                                       *(input->shape[3]*input->shape[2])
                                                       + (x2*stride[2] + dilation[2]*z2)
                                                       *(input->shape[3]) + q];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    k2c_bias_add(output, bias);
    activation(output->array, output->numel);
}
