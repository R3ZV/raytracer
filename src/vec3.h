#pragma once

#include <stdint.h>

typedef struct {
    double x, y, z;
} Vec3;

Vec3 vec3_add_new(Vec3 const * const self, Vec3 const *const other);
void vec3_add(Vec3* const self, Vec3 const *const other);

Vec3 vec3_sub_new(Vec3 const * const self, Vec3 const *const other);
void vec3_sub(Vec3* const self, Vec3 const *const other);

Vec3 vec3_mul_new(Vec3 const* const self, double alpha);
void vec3_mul(Vec3* const self, double alpha);

Vec3 vec3_div_new(Vec3 const* const self, double alpha);
void vec3_div(Vec3* const self, double alpha);

double vec3_length(Vec3 const *const self);
Vec3 vec3_unit_vector(Vec3 const *const v);
