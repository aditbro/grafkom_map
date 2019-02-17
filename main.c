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
    Buffer fb = get_image_buffer("/dev/fb0", screen_width, screen_height);
    Buffer img = get_image_buffer("file.pmp", 800, 600);

    img = Buffer_get_crop(&img, point(0,0), point(300,300));
    Buffer_copy(&fb, &img, point(100,100));
}
