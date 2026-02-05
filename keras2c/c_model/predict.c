#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "my_model.h"
#include "k2c_tensor_include.h"

/* CIFAR-10 labels */
const char *class_names[10] = {
    "airplane","automobile","bird","cat","deer",
    "dog","frog","horse","ship","truck"
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <image.png>\n", argv[0]);
        return 1;
    }

    /* Load image */
    int w, h, c;
    unsigned char *img = stbi_load(argv[1], &w, &h, &c, 3);
    if (!img) {
        printf("Error: could not load image\n");
        return 1;
    }

    if (w != 32 || h != 32) {
        printf("Error: image must be 32x32\n");
        stbi_image_free(img);
        return 1;
    }

    /* Buffers */
    static float input_data[32 * 32 * 3];
    static float output_data[10];

    /* Preprocess: EXACTLY like predict.py --preprocess 01 */
    for (int i = 0; i < 32 * 32 * 3; i++) {
        input_data[i] = img[i] / 255.0f;
    }

    stbi_image_free(img);

    /* ---- INPUT TENSOR (MATCHES TEST SUITE) ---- */
    k2c_tensor input_tensor;
    input_tensor.array = input_data;
    input_tensor.ndim = 3;
    input_tensor.numel = 32 * 32 * 3;
    input_tensor.shape[0] = 32;
    input_tensor.shape[1] = 32;
    input_tensor.shape[2] = 3;
    input_tensor.shape[3] = 1;
    input_tensor.shape[4] = 1;

    /* ---- OUTPUT TENSOR (MATCHES TEST SUITE) ---- */
    k2c_tensor output_tensor;
    output_tensor.array = output_data;
    output_tensor.ndim = 1;
    output_tensor.numel = 10;
    output_tensor.shape[0] = 10;
    output_tensor.shape[1] = 1;
    output_tensor.shape[2] = 1;
    output_tensor.shape[3] = 1;
    output_tensor.shape[4] = 1;

    /* REQUIRED INIT */
    my_model_initialize();

    /* Run inference */
    my_model(&input_tensor, &output_tensor);

    /* Print results */
    printf("\nPrediction:\n");
    int best = 0;
    for (int i = 0; i < 10; i++) {
        printf("%-12s : %.6f\n", class_names[i], output_data[i]);
        if (output_data[i] > output_data[best])
            best = i;
    }

    printf("\nPredicted class: %s (%d)\n",
           class_names[best], best);

    return 0;
}
