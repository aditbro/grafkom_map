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

int screen_width = 2048;
int screen_height = 2048;

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

void renderLayer(Buffer* tb, Shape* layer, int size) {
    for (int i = 0; i < size; i++) {
        Shape_drawTo(&layer[i], tb, point(0, 0));
    }
}


int main(){
    int SCREEN_SIZE = screen_width * screen_height * 4;

    Buffer tb = create_buffer(screen_width, screen_height);
    Buffer fb = get_image_buffer("/dev/fb0", screen_width, screen_height);
    
    memset(fb.buffer, 0, SCREEN_SIZE);

    Shape* layer1 = (Shape*) malloc(100*sizeof(Shape));
    Shape* layer2 = (Shape*) malloc(100*sizeof(Shape));
    Shape* layer3 = (Shape*) malloc(100*sizeof(Shape));
    Shape* layer4 = (Shape*) malloc(100*sizeof(Shape));
    Shape* layer5 = (Shape*) malloc(100*sizeof(Shape));
    Shape* layer6 = (Shape*) malloc(100*sizeof(Shape));
    Shape* layer7 = (Shape*) malloc(100*sizeof(Shape));
    
    int layer1_size = 0;
    int layer2_size = 0;
    int layer3_size = 0;
    int layer4_size = 0;
    int layer5_size = 0;
    int layer6_size = 0;
    int layer7_size = 0;

    int layer1_stats = 0;
    int layer2_stats = 0;
    int layer3_stats = 0;
    int layer4_stats = 0;
    int layer5_stats = 0;
    int layer6_stats = 0;
    int layer7_stats = 0;

    char ch;

    while(1){
        memset(tb.buffer, 0, SCREEN_SIZE);

        usleep(10000);
        if (kbhit())
        {
            ch = getchar();
            if (ch == '1') {
                if (!layer1_stats) {
                    layer1_stats = 1;
                } else {
                    layer1_stats = 0;
                }
            } else if (ch == '2') {
                if (!layer2_stats) {
                    layer2_stats = 1;
                } else {
                    layer2_stats = 0;
                }
            } else if (ch == '3') {
                if (!layer3_stats) {
                    layer3_stats = 1;
                } else {
                    layer3_stats = 0;
                }
            } else if (ch == '4') {
                if (!layer4_stats) {
                    layer4_stats = 1;
                } else {
                    layer4_stats = 0;
                }
            } else if (ch == '5') {
                if (!layer5_stats) {
                    layer5_stats = 1;
                } else {
                    layer5_stats = 0;
                }
            } else if (ch == '6') {
                if (!layer6_stats) {
                    layer6_stats = 1;
                } else {
                    layer6_stats = 0;
                }
            } else if (ch == '7') {
                if (!layer7_stats) {
                    layer7_stats = 1;
                } else {
                    layer7_stats = 0;
                }
            }
        }

        Color on = color(200, 10, 10);

        if (layer1_stats) {
            Shape s = drawA(0,0,on);
            Shape_drawTo(&s, &tb, point(10, 700));
            renderLayer(&tb, layer1, layer1_size);
        } 
        if (layer2_stats) {
            Shape s = drawB(0,0,on);
            Shape_drawTo(&s, &tb, point(60, 700));
            renderLayer(&tb, layer2, layer2_size);
        } 
        if (layer3_stats) {
            Shape s = drawC(0,0,on);
            Shape_drawTo(&s, &tb, point(110, 700));
            renderLayer(&tb, layer3, layer3_size);
        }
        if (layer4_stats) {
            Shape s = drawD(0,0,on);
            Shape_drawTo(&s, &tb, point(160, 700));
            renderLayer(&tb, layer4, layer4_size);
        }
        if (layer5_stats) {
            Shape s = drawE(0,0,on);
            Shape_drawTo(&s, &tb, point(210, 700));
            renderLayer(&tb, layer5, layer5_size);
        }
        if (layer6_stats) {
            Shape s = drawF(0,0,on);
            Shape_drawTo(&s, &tb, point(260, 700));
            renderLayer(&tb, layer6, layer6_size);
        }
        if (layer7_stats) {
            Shape s = drawG(0,0,on);
            Shape_drawTo(&s, &tb, point(310, 700));
            renderLayer(&tb, layer7, layer7_size);
        }

        memcpy((fb.buffer), (tb.buffer), SCREEN_SIZE);
    }
    getchar();
}
