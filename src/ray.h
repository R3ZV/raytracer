#pragma once
#include "vec3.h"

typedef struct {
    Vec3 origin, direction;
} Ray;

Ray ray_init(Vec3 origin, Vec3 direction);
Vec3 ray_at(Ray const *const self, double t);
