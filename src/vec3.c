#include <math.h>
#include <stdio.h>

#include "vec3.h"

void vec3_add(Vec3* const self, Vec3 const *const other) {
    self->x += other->x;
    self->y += other->y;
    self->z += other->z;
}

void vec3_mul(Vec3* const self, double alpha) {
    self->x *= alpha;
    self->y *= alpha;
    self->z *= alpha;
}

void vec3_div(Vec3* const self, double alpha) {
    self->x *= (1 / alpha);
    self->y *= (1 / alpha);
    self->z *= (1 / alpha);
}

double length_squared(Vec3 const *const self) {
    return self->x * self->x + self->y * self->y + self->z * self->z;
}

double vec3_length(Vec3 const *const self) {
    return sqrt(length_squared(self));
}

void vec3_print(Vec3 const *const self) {
    printf("Vec3{x=%f, y=%f, z=%lf}\n", self->x, self->y, self->y);
}
