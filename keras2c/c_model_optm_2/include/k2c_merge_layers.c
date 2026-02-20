/**
k2c_merge_layers.c
Optimized merge ops (binary fast-path)
*/

#include <string.h>
#include <stdarg.h>
#include "k2c_include.h"

/* -------------------- ADD -------------------- */

void k2c_add(k2c_tensor* output, const size_t num_tensors, ...) {

    float * restrict out = output->array;

    if (num_tensors == 2) {
        va_list args;
        va_start(args, num_tensors);
        const k2c_tensor *a = va_arg(args, k2c_tensor*);
        const k2c_tensor *b = va_arg(args, k2c_tensor*);
        va_end(args);

        const float * restrict A = a->array;
        const float * restrict B = b->array;

        for (size_t i = 0; i < output->numel; ++i)
            out[i] = A[i] + B[i];

        return;
    }

    /* generic slow path */
    memset(out, 0, output->numel * sizeof(float));

    va_list args;
    va_start(args, num_tensors);
    for (size_t t = 0; t < num_tensors; ++t) {
        const k2c_tensor *arr = va_arg(args, k2c_tensor*);
        const float * restrict A = arr->array;
        for (size_t i = 0; i < output->numel; ++i)
            out[i] += A[i];
    }
    va_end(args);
}

/* -------------------- SUBTRACT -------------------- */

void k2c_subtract(k2c_tensor* output, const size_t num_tensors,
                  const k2c_tensor* a, const k2c_tensor* b) {

    float * restrict out = output->array;
    const float * restrict A = a->array;
    const float * restrict B = b->array;

    for (size_t i = 0; i < output->numel; ++i)
        out[i] = A[i] - B[i];
}

/* -------------------- MULTIPLY -------------------- */

void k2c_multiply(k2c_tensor* output, const size_t num_tensors, ...) {

    float * restrict out = output->array;

    if (num_tensors == 2) {
        va_list args;
        va_start(args, num_tensors);
        const k2c_tensor *a = va_arg(args, k2c_tensor*);
        const k2c_tensor *b = va_arg(args, k2c_tensor*);
        va_end(args);

        const float * restrict A = a->array;
        const float * restrict B = b->array;

        for (size_t i = 0; i < output->numel; ++i)
            out[i] = A[i] * B[i];

        return;
    }

    for (size_t i = 0; i < output->numel; ++i)
        out[i] = 1.0f;

    va_list args;
    va_start(args, num_tensors);
    for (size_t t = 0; t < num_tensors; ++t) {
        const k2c_tensor *arr = va_arg(args, k2c_tensor*);
        const float * restrict A = arr->array;
        for (size_t i = 0; i < output->numel; ++i)
            out[i] *= A[i];
    }
    va_end(args);
}

/* -------------------- AVERAGE -------------------- */

void k2c_average(k2c_tensor* output, const size_t num_tensors, ...) {

    float * restrict out = output->array;
    const float inv = 1.0f / num_tensors;

    if (num_tensors == 2) {
        va_list args;
        va_start(args, num_tensors);
        const k2c_tensor *a = va_arg(args, k2c_tensor*);
        const k2c_tensor *b = va_arg(args, k2c_tensor*);
        va_end(args);

        const float * restrict A = a->array;
        const float * restrict B = b->array;

        for (size_t i = 0; i < output->numel; ++i)
            out[i] = (A[i] + B[i]) * inv;

        return;
    }

    memset(out, 0, output->numel * sizeof(float));

    va_list args;
    va_start(args, num_tensors);
    for (size_t t = 0; t < num_tensors; ++t) {
        const k2c_tensor *arr = va_arg(args, k2c_tensor*);
        const float * restrict A = arr->array;
        for (size_t i = 0; i < output->numel; ++i)
            out[i] += A[i] * inv;
    }
    va_end(args);
}

/* -------------------- MAX / MIN -------------------- */

void k2c_max(k2c_tensor* output, const size_t num_tensors, ...) {

    float * restrict out = output->array;

    va_list args;
    va_start(args, num_tensors);
    const k2c_tensor *a = va_arg(args, k2c_tensor*);
    memcpy(out, a->array, output->numel * sizeof(float));

    for (size_t t = 1; t < num_tensors; ++t) {
        const k2c_tensor *arr = va_arg(args, k2c_tensor*);
        const float * restrict A = arr->array;
        for (size_t i = 0; i < output->numel; ++i)
            if (A[i] > out[i]) out[i] = A[i];
    }
    va_end(args);
}

void k2c_min(k2c_tensor* output, const size_t num_tensors, ...) {

    float * restrict out = output->array;

    va_list args;
    va_start(args, num_tensors);
    const k2c_tensor *a = va_arg(args, k2c_tensor*);
    memcpy(out, a->array, output->numel * sizeof(float));

    for (size_t t = 1; t < num_tensors; ++t) {
        const k2c_tensor *arr = va_arg(args, k2c_tensor*);
        const float * restrict A = arr->array;
        for (size_t i = 0; i < output->numel; ++i)
            if (A[i] < out[i]) out[i] = A[i];
    }
    va_end(args);
}
