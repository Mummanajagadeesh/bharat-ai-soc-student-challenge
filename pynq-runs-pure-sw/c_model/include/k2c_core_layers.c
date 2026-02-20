/**
k2c_core_layers.c
Safe optimized version (no NULL bias, no segfaults)
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "k2c_include.h"

/* ---------- helpers ---------- */

static inline void k2c_softmax_inplace(float *x, size_t n) {
    float maxv = x[0];
    for (size_t i = 1; i < n; ++i)
        if (x[i] > maxv) maxv = x[i];

    float sum = 0.0f;
    for (size_t i = 0; i < n; ++i) {
        x[i] = expf(x[i] - maxv);
        sum += x[i];
    }

    const float inv = 1.0f / sum;
    for (size_t i = 0; i < n; ++i)
        x[i] *= inv;
}

/* ---------- Dense ---------- */

void k2c_dense(k2c_tensor* output, const k2c_tensor* input,
               const k2c_tensor* kernel, const k2c_tensor* bias,
               k2c_activationType *activation, float * fwork) {

    /* Fast path (your model uses this) */
    if (input->ndim <= 2) {

        const size_t outrows  = (input->ndim > 1) ? input->shape[0] : 1;
        const size_t outcols  = kernel->shape[1];
        const size_t innerdim = kernel->shape[0];
        const size_t outsize  = outrows * outcols;

        /* zero-bias buffer (safe) */
        float zerobias[outcols];
        for (size_t i = 0; i < outcols; ++i)
            zerobias[i] = 0.0f;

        /* matmul */
        k2c_affine_matmul(
            output->array,
            input->array,
            kernel->array,
            zerobias,          /* ✅ SAFE */
            outrows,
            outcols,
            innerdim
        );

        float *out = output->array;
        const float *b = bias->array;

        /* fused paths */
        if (activation == k2c_softmax) {
            for (size_t i = 0; i < outsize; ++i)
                out[i] += b[i % outcols];

            k2c_softmax_inplace(out, outsize);
            return;
        }

        if (activation == k2c_linear) {
            for (size_t i = 0; i < outsize; ++i)
                out[i] += b[i % outcols];
            return;
        }

        /* fallback */
        for (size_t i = 0; i < outsize; ++i)
            out[i] += b[i % outcols];

        activation(out, outsize);
        return;
    }

    /* ---------- generic slow path ---------- */

    const size_t axesA[1] = {input->ndim - 1};
    const size_t axesB[1] = {0};
    const size_t naxes = 1;
    const int normalize = 0;

    k2c_dot(output, input, kernel, axesA, axesB, naxes, normalize, fwork);
    k2c_bias_add(output, bias);
    activation(output->array, output->numel);
}

/* ---------- Flatten ---------- */

void k2c_flatten(k2c_tensor *output, const k2c_tensor* input) {

    memcpy(output->array, input->array,
           input->numel * sizeof(input->array[0]));

    for (size_t i = 0; i < input->ndim; ++i)
        output->shape[i] = 1;

    output->shape[0] = input->numel;
    output->numel = input->numel;
    output->ndim = 1;
}

/* ---------- Reshape ---------- */

void k2c_reshape(k2c_tensor *output, const k2c_tensor* input,
                 const size_t * newshp, const size_t newndim) {

    memcpy(output->array, input->array,
           input->numel * sizeof(input->array[0]));

    for (size_t i = 0; i < newndim; ++i)
        output->shape[i] = newshp[i];

    output->ndim = newndim;
    output->numel = input->numel;
}

/* ---------- Permute ---------- */

void k2c_permute_dims(k2c_tensor* output, const k2c_tensor* input,
                      const size_t * permute) {

    size_t Asub[K2C_MAX_NDIM];
    size_t Bsub[K2C_MAX_NDIM];
    size_t newshp[K2C_MAX_NDIM];
    size_t oldshp[K2C_MAX_NDIM];

    const size_t ndim = input->ndim;

    for (size_t i = 0; i < ndim; ++i)
        oldshp[i] = input->shape[i];

    for (size_t i = 0; i < ndim; ++i)
        newshp[i] = oldshp[permute[i]];

    for (size_t i = 0; i < input->numel; ++i) {
        k2c_idx2sub(i, Asub, oldshp, ndim);
        for (size_t j = 0; j < ndim; ++j)
            Bsub[j] = Asub[permute[j]];

        const size_t bidx = k2c_sub2idx(Bsub, newshp, ndim);
        output->array[bidx] = input->array[i];
    }
}

/* ---------- Repeat ---------- */

void k2c_repeat_vector(k2c_tensor* output,
                       const k2c_tensor* input,
                       const size_t n) {

    const size_t in_width = input->shape[0];
    for (size_t i = 0; i < n; ++i)
        memcpy(&output->array[i * in_width],
               input->array,
               in_width * sizeof(input->array[0]));
}
