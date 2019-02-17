#include "data_structures.h"
#include "algorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "kbhit.c"

int screen_width = 1176;
int screen_height = 800;

Buffer get_image_buffer(char* dir, int width, int height){
    int fb_fd = 0;
    int SCREEN_SIZE = width * height * 4;
    fb_fd = open(dir, O_RDWR);
    char * fb = mmap(NULL,
					SCREEN_SIZE,
					PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED,
					fb_fd,
					0);
    Buffer b = buffer(fb,width,height);

    return b;
}



int main(){
    int SCREEN_SIZE = screen_width * screen_height * 4;
    Buffer tb = create_buffer(screen_width, screen_height);
    Buffer fb = get_image_buffer("/dev/fb0", screen_width, screen_height);
    Buffer img = get_image_buffer("file.pmp", 1600, 2400);
    Buffer thumbnail_img = down_scale(&img, 8);
    Buffer map_img = down_scale(&img, 2);
    map_img = Buffer_get_crop(&map_img, point(0,0), point(600,400));
    Shape rectangle1 = Shape_free_rectangle(100, 150, Color_black());
    Shape rectangle2 = Shape_free_rectangle(50, 75, Color_black());

    memset(tb.buffer, 0, SCREEN_SIZE);

    Object* thumbnail = object(point(150,50));
    Object_add_buffer(thumbnail, &thumbnail_img);

    Object* map = object(point(0,400));
    Object_add_buffer(map, &map_img);

    Object* selector1 = object(point(200,50));
    Object_add_buffer(selector1, &rectangle1.shape_buffer);

    Object* selector2 = object(point(200,50));
    Object_add_buffer(selector2, &rectangle2.shape_buffer);
    selector2->is_appearing = 0;

    Object_draw_all(&fb);

    getchar();
}
