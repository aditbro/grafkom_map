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
#include "svglibs.h"

// DO NOT FORGET TO CHANGE THIS!
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

    
    int layer1_size = 0;
    int layer2_size = 0;
    int layer3_size = 0;
    int layer4_size = 0;
    int layer5_size = 0;
    int layer6_size = 0;

    // flag for layer switch
    int null_count = 0;
    int peta_shape_index = 0;
    int layer_shape_index = 0;  
    char** layer_names = (char**) malloc (6 * sizeof(char*)); 
    char** peta_itb = streamFile("svg_reader/peta_itb.svg", layer_names);

    while (null_count < 6) {
        if (peta_itb[peta_shape_index] != NULL) {
            if (null_count == 0) {
                layer1[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], 3);
                layer1_size++;
            }
            else if (null_count == 1) {
                layer2[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], 3);
                layer2_size++;
            }
            else if (null_count == 2) {
                layer3[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], 3);
                layer3_size++;
            }
            else if (null_count == 3) {
                layer4[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], 3);
                layer4_size++;
            }
            else if (null_count == 4) {
                layer5[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], 3);
                layer5_size++;
            }
            else if (null_count == 5) {
                layer6[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], 3);
                layer6_size++;
            }
            layer_shape_index++;
        }
        else {
            null_count++;
            layer_shape_index = 0;
        }
        peta_shape_index++;
    }

    int layer1_stats = 1;
    int layer2_stats = 1;
    int layer3_stats = 1;
    int layer4_stats = 1;
    int layer5_stats = 1;
    int layer6_stats = 1;

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
            }
        }

        if (layer1_stats) {
            renderLayer(&tb, layer1, layer1_size);
        }
        if (layer2_stats) {
            renderLayer(&tb, layer2, layer2_size);
        }
        if (layer3_stats) {
            renderLayer(&tb, layer3, layer3_size);
        }
        if (layer4_stats) {
            renderLayer(&tb, layer4, layer4_size);
        }
        if (layer5_stats) {
            renderLayer(&tb, layer5, layer5_size);
        }
        if (layer6_stats) {
            renderLayer(&tb, layer6, layer6_size);
        }

        memcpy((fb.buffer), (tb.buffer), SCREEN_SIZE);
    }
    getchar();
}
