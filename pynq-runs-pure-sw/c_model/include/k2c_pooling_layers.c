/**
k2c_pooling_layers.c
Optimized version
*/

#include <math.h>
#include <string.h>
#include "k2c_include.h"

/* ===================== GLOBAL MAX POOL ===================== */

void k2c_global_max_pooling(k2c_tensor* output, const k2c_tensor* input) {

    const size_t ch = input->shape[input->ndim - 1];
    const float *restrict in  = input->array;
    float *restrict out = output->array;

    /* init */
    for (size_t c = 0; c < ch; ++c)
        out[c] = in[c];

    const size_t steps = input->numel / ch;

    for (size_t i = 1; i < steps; ++i) {
        const float *pin = in + i * ch;

        size_t c = 0;
        for (; c + 3 < ch; c += 4) {
            if (pin[c]   > out[c])   out[c]   = pin[c];
            if (pin[c+1] > out[c+1]) out[c+1] = pin[c+1];
            if (pin[c+2] > out[c+2]) out[c+2] = pin[c+2];
            if (pin[c+3] > out[c+3]) out[c+3] = pin[c+3];
        }
        for (; c < ch; ++c) {
            if (pin[c] > out[c]) out[c] = pin[c];
        }
    }
}

/* ===================== GLOBAL AVG POOL ===================== */

void k2c_global_avg_pooling(k2c_tensor* output, const k2c_tensor* input) {

    const size_t ch = input->shape[input->ndim - 1];
    const size_t steps = input->numel / ch;

    const float *restrict in  = input->array;
    float *restrict out = output->array;

    for (size_t c = 0; c < ch; ++c)
        out[c] = 0.0f;

    for (size_t i = 0; i < steps; ++i) {
        const float *pin = in + i * ch;

        size_t c = 0;
        for (; c + 3 < ch; c += 4) {
            out[c]   += pin[c];
            out[c+1] += pin[c+1];
            out[c+2] += pin[c+2];
            out[c+3] += pin[c+3];
        }
        for (; c < ch; ++c) {
            out[c] += pin[c];
        }
    }

    const float inv = 1.0f / (float)steps;
    for (size_t c = 0; c < ch; ++c)
        out[c] *= inv;
}

/* ===================== MAXPOOL 1D ===================== */

void k2c_maxpool1d(
    k2c_tensor* output,
    const k2c_tensor* input,
    const size_t pool_size,
    const size_t stride
) {
    const size_t out_len = output->shape[0];
    const size_t ch = input->shape[1];

    const float *restrict in  = input->array;
    float *restrict out = output->array;

    for (size_t o = 0; o < out_len; ++o) {
        const size_t base = o * stride * ch;
        float *outp = out + o * ch;

        for (size_t c = 0; c < ch; ++c)
            outp[c] = in[base + c];

        for (size_t p = 1; p < pool_size; ++p) {
            const float *pin = in + base + p * ch;

            for (size_t c = 0; c < ch; ++c)
                if (pin[c] > outp[c]) outp[c] = pin[c];
        }
    }
}

/* ===================== MAXPOOL 2D ===================== */

void k2c_maxpool2d(
    k2c_tensor* output,
    const k2c_tensor* input,
    const size_t *pool_size,
    const size_t *stride
) {
    const size_t out_h = output->shape[0];
    const size_t out_w = output->shape[1];
    const size_t in_w  = input->shape[1];
    const size_t ch    = input->shape[2];

    const size_t ph = pool_size[0];
    const size_t pw = pool_size[1];

    const float *restrict in  = input->array;
    float *restrict out = output->array;

    for (size_t oh = 0; oh < out_h; ++oh) {
        const size_t ih0 = oh * stride[0];

        for (size_t ow = 0; ow < out_w; ++ow) {
            const size_t iw0 = ow * stride[1];

            float *outp = out + (oh * out_w + ow) * ch;

            for (size_t c = 0; c < ch; ++c)
                outp[c] = -HUGE_VALF;

            for (size_t kh = 0; kh < ph; ++kh) {
                const float *row =
                    in + (ih0 + kh) * in_w * ch + iw0 * ch;

                for (size_t kw = 0; kw < pw; ++kw) {
                    const float *pin = row + kw * ch;

                    for (size_t c = 0; c < ch; ++c)
                        if (pin[c] > outp[c]) outp[c] = pin[c];
                }
            }
        }
    }
}

/* ===================== AVGPOOL 1D ===================== */

void k2c_avgpool1d(
    k2c_tensor* output,
    const k2c_tensor* input,
    const size_t pool_size,
    const size_t stride
) {
    const size_t out_len = output->shape[0];
    const size_t ch = input->shape[1];

    const float *restrict in  = input->array;
    float *restrict out = output->array;

    for (size_t o = 0; o < out_len; ++o) {
        const size_t base = o * stride * ch;
        float *outp = out + o * ch;

        for (size_t c = 0; c < ch; ++c)
            outp[c] = 0.0f;

        for (size_t p = 0; p < pool_size; ++p) {
            const float *pin = in + base + p * ch;
            for (size_t c = 0; c < ch; ++c)
                outp[c] += pin[c];
        }

        const float inv = 1.0f / (float)pool_size;
        for (size_t c = 0; c < ch; ++c)
            outp[c] *= inv;
    }
}

/* ===================== AVGPOOL 2D ===================== */

void k2c_avgpool2d(
    k2c_tensor* output,
    const k2c_tensor* input,
    const size_t *pool_size,
    const size_t *stride
) {
    const size_t out_h = output->shape[0];
    const size_t out_w = output->shape[1];
    const size_t in_w  = input->shape[1];
    const size_t ch    = input->shape[2];

    const size_t ph = pool_size[0];
    const size_t pw = pool_size[1];

    const float *restrict in  = input->array;
    float *restrict out = output->array;

    for (size_t oh = 0; oh < out_h; ++oh) {
        const size_t ih0 = oh * stride[0];

        for (size_t ow = 0; ow < out_w; ++ow) {
            const size_t iw0 = ow * stride[1];
            float *outp = out + (oh * out_w + ow) * ch;

            for (size_t c = 0; c < ch; ++c)
                outp[c] = 0.0f;

            for (size_t kh = 0; kh < ph; ++kh) {
                const float *row =
                    in + (ih0 + kh) * in_w * ch + iw0 * ch;

                for (size_t kw = 0; kw < pw; ++kw) {
                    const float *pin = row + kw * ch;
                    for (size_t c = 0; c < ch; ++c)
                        outp[c] += pin[c];
                }
            }

            const float inv = 1.0f / (float)(ph * pw);
            for (size_t c = 0; c < ch; ++c)
                outp[c] *= inv;
        }
    }
}
