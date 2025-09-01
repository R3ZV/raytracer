#include "ray.h"

Ray ray_init(Vec3 origin, Vec3 direction) {
    return (Ray) {
        .origin = origin,
        .direction = direction,
    };
}

Vec3 ray_at(Ray const *const self, double t) {
    // origin + t * direction
    Vec3 rhs = vec3_mul_new(&self->direction, t);
    return vec3_add_new(&self->origin, &rhs);
}
