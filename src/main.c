#include <stdio.h>

#include "colors.h"
#include "ray.h"
#include "vec3.h"


Color ray_color(Ray const *const ray) {
    const Vec3 unit_direction = vec3_unit_vector(&ray->direction);
    const double a = 0.5 * (unit_direction.y + 1.0);

    const Color c1 = (Color){.x = 1.0, .y = 1.0, .z = 1.0};
    const Color c2 = (Color){.x = 0.5, .y = 0.7, .z = 1.0};

    const Color res1 = vec3_mul_new(&c1, (1.0 - a));
    const Color res2 = vec3_mul_new(&c2, a);
    return vec3_add_new(&res1, &res2);
}

int main(void) {
    const uint16_t img_width =  400;
    const double aspect_ratio = 16.0 / 9.0;

    const int height = (int)(img_width / aspect_ratio);
    const uint16_t img_height = (height < 1) ? 1 : height;

    const double focal_length = 1.0;
    const double viewport_height = 2.0;
    const double viewport_width = viewport_height * ((double)(img_width) / (double)img_height);

    // Camera
    const Vec3 camera_center = (Vec3){.x = 0.0, .y = 0.0, .z = 0.0};

    const Vec3 viewport_u = (Vec3){.x = viewport_width, .y = 0.0, .z = 0.0};
    const Vec3 viewport_v = (Vec3){.x = 0.0, .y = -viewport_height, .z = 0.0};

    const Vec3 pixel_delta_u = vec3_div_new(&viewport_u, img_width);
    const Vec3 pixel_delta_v = vec3_div_new(&viewport_v, img_height);

    // Calculate the location of the upper left pixel.
    const Vec3 focal_vec = (Vec3){.x = 0.0, .y = 0.0, .z = focal_length};
    const Vec3 half_viewport_u = vec3_div_new(&viewport_u, 2.0);
    const Vec3 half_viewport_v = vec3_div_new(&viewport_v, 2.0);

    Vec3 viewport_upper_left = camera_center;
    vec3_sub(&viewport_upper_left, &focal_vec);
    vec3_sub(&viewport_upper_left, &half_viewport_u);
    vec3_sub(&viewport_upper_left, &half_viewport_v);

    Vec3 pixel00_loc = vec3_add_new(&pixel_delta_u, &pixel_delta_v);
    vec3_mul(&pixel00_loc, 0.5);
    vec3_add(&pixel00_loc, &viewport_upper_left);

    // Render
    printf("P3\n");
    printf("%d %d\n", img_width, height);
    printf("255\n");

    for (size_t j = 0; j < (size_t)img_height; j++) {
        for (size_t i = 0; i < (size_t)img_width; i++) {
            const Vec3 pixel_i = vec3_mul_new(&pixel_delta_u, i);
            const Vec3 pixel_j = vec3_mul_new(&pixel_delta_v, j);

            Vec3 pixel_center = pixel00_loc;
            vec3_add(&pixel_center, &pixel_i);
            vec3_add(&pixel_center, &pixel_j);

            const Vec3 ray_direction = vec3_sub_new(&pixel_center, &camera_center);

            Ray ray = (Ray){.origin = camera_center, .direction = ray_direction};

            Color pixel = ray_color(&ray);
            color_write(&pixel);
        }
    }
}
