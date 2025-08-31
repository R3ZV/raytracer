#include <stdio.h>

#include "colors.h"


int main(void) {
    const int16_t width =  256;
    const int16_t height = 256;

    printf("P3\n");
    printf("%d %d\n", width, height);
    printf("255\n");

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            Color pixel = (Color) {
                .x =(double)(i) / (width-1),
                .y = (double)(j) / (height-1),
                .z = 0,
            };

            color_write(&pixel);
        }
    }
}
