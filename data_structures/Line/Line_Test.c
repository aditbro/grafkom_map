#include "Line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "../../kbhit.c"

int main(){
    Point p1 = point(700,70);
    Point p2 = point(20,20);
    Point init = point(0,0);
    int fb_fd = 0;
    int SCREEN_SIZE = 800 * 1176 * 4;
    fb_fd = open("/dev/fb0", O_RDWR);
    char * fb = mmap(NULL,
					SCREEN_SIZE,
					PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED,
					fb_fd,
					0);
    memset(fb, 0, SCREEN_SIZE);
    Buffer b = buffer(fb,1176 * 4, 800);
    Color c = color(255,0,0);
    Line l = line(p1, p2);
    Line_draw(&l, &b, &c, &init);
}