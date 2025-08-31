#pragma once

#include <stdint.h>

typedef struct {
    double x, y, z;
} Vec3;

void vec3_add(Vec3* const self, Vec3 const *const other);
void vec3_mul(Vec3* const self, double alpha);
void vec3_div(Vec3* const self, double alpha);
double vec3_length(Vec3 const *const self);
