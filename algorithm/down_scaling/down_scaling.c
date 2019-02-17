#include "down_scaling.h"
#include <stdlib.h>

Color get_average_color(Buffer* buff, int init_i, int init_j, int scale) {
    Color surrounding_colors[100];
    Color c;
    int num_color = 0;

    for(int i = init_i; i-init_i < scale && i < buff->height; i++){
        // printf("masuk loop, scale %d\n", scale);
        for(int j = init_j; j-init_j < scale && j < buff->width; j++){
            surrounding_colors[num_color++] = Buffer_getColorAt(buff, i, j);
        }
    }

    // printf("num_color %d\n", num_color);
    c = Color_get_average(surrounding_colors, num_color);
    return c;
}

Buffer down_scale(Buffer* buff, int scale) {
    int new_width = buff->width/scale;
    int new_height = buff->height/scale;
    Buffer b = create_buffer(buff->width, buff->height);

    Color c;

    for(int i = 0; i < buff->height; i = i + scale) {
        for(int j = 0; j < buff->width; j = j + scale) {
            // printf("%d %d\n", i/scale, j/scale);
            c = get_average_color(buff, i, j, scale);
            // Color_print(c);
            Buffer_fillAt(&b, i/scale, j/scale, &c);
        }
    }

    return b;
}