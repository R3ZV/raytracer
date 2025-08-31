#include "colors.h"

void color_write(Color const *const color) {
    double r = color->x;
    double g = color->y;
    double b = color->z;

    int32_t ir = (int)(255.999 * r);
    int32_t ig = (int)(255.999 * g);
    int32_t ib = (int)(255.999 * b);

    printf("%d %d %d\n", ir, ig, ib);
}
