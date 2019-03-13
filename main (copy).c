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
    Buffer img = create_buffer(screen_width, screen_height);
    
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
            int scale = 2;
            if (null_count == 0) {
                layer1[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], scale);
                layer1_size++;
            }
            else if (null_count == 1) {
                layer2[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], scale);
                layer2_size++;
            }
            else if (null_count == 2) {
                layer3[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], scale);
                layer3_size++;
            }
            else if (null_count == 3) {
                layer4[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], scale);
                layer4_size++;
            }
            else if (null_count == 4) {
                layer5[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], scale);
                layer5_size++;
            }
            else if (null_count == 5) {
                layer6[layer_shape_index] = getShapeFromInstructions(peta_itb[peta_shape_index], scale);
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

    int iSelector, jSelector,scaleSelector;

    iSelector = 150;
    jSelector = 50;
    scaleSelector = 2;

 

    renderLayer(&img, layer1, layer1_size);
    renderLayer(&img, layer2, layer2_size);
    renderLayer(&img, layer3, layer3_size);
    renderLayer(&img, layer4, layer4_size);
    renderLayer(&img, layer5, layer5_size);
    renderLayer(&img, layer6, layer6_size);

    Buffer thumbnail_img = down_scale(&img, 4);
    Buffer map_img = down_scale(&img, 8 / scaleSelector);
    map_img = Buffer_get_crop(&map_img, point(iSelector - 150 ,jSelector - 50), point((iSelector - 150) +  600,(jSelector - 50) + 400));
    Shape rectangle1 = Shape_free_rectangle(100, 150, Color_black());
    Shape rectangle2 = Shape_free_rectangle(50, 75, Color_black());

    Object* thumbnail = object(point(150,50));
    Object_add_buffer(thumbnail, &thumbnail_img);

    Object* map = object(point(0,0));
    Object_add_buffer(map, &map_img);


    Object* selector1 = object(point(iSelector,jSelector));
    Object_add_buffer(selector1, &rectangle1.shape_buffer);

    Object* selector2 = object(point(iSelector,jSelector));
    Object_add_buffer(selector2, &rectangle2.shape_buffer);
    selector2->is_appearing = 0;



    while(1){
        memset(tb.buffer, 0, SCREEN_SIZE);
        memset(img.buffer, 0, SCREEN_SIZE);

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

        Color on = color(200, 10, 10);

        if (layer1_stats) {
            Shape s = drawA(0,0,on);
            Shape_drawTo(&s, &tb, point(10, 700));
            // renderLayer(&tb, layer1, layer1_size);
            renderLayer(&img, layer1, layer1_size);
        } 
        if (layer2_stats) {
            Shape s = drawB(0,0,on);
            Shape_drawTo(&s, &tb, point(60, 700));
            // renderLayer(&tb, layer2, layer2_size);
            renderLayer(&img, layer2, layer2_size);
        } 
        if (layer3_stats) {
            Shape s = drawC(0,0,on);
            Shape_drawTo(&s, &tb, point(110, 700));
            // renderLayer(&tb, layer3, layer3_size);
            renderLayer(&img, layer3, layer3_size);
        }
        if (layer4_stats) {
            Shape s = drawD(0,0,on);
            Shape_drawTo(&s, &tb, point(160, 700));
            // renderLayer(&tb, layer4, layer4_size);
            renderLayer(&img, layer4, layer4_size);
        }
        if (layer5_stats) {
            Shape s = drawE(0,0,on);
            Shape_drawTo(&s, &tb, point(210, 700));
            // renderLayer(&tb, layer5, layer5_size);
            renderLayer(&img, layer5, layer5_size);
        }
        if (layer6_stats) {
            Shape s = drawF(0,0,on);
            Shape_drawTo(&s, &tb, point(260, 700));
            // renderLayer(&tb, layer6, layer6_size);
            renderLayer(&img, layer6, layer6_size);
        }
        thumbnail_img = down_scale(&img, 4);
        map_img = down_scale(&img, 8 / scaleSelector);
        map_img = Buffer_get_crop(&map_img, point(iSelector - 150 ,jSelector - 50), point((iSelector - 150) +  600,(jSelector - 50) + 400));
        
        Object_add_buffer(thumbnail, &thumbnail_img);
        Object_add_buffer(map, &map_img);

        Object_draw_all(&tb);
        memcpy((fb.buffer), (tb.buffer), SCREEN_SIZE);
        if(ch == 'w' && iSelector >= 160){
            iSelector -= 10;
        }else if(ch == 's' && iSelector <= (450 - (300 / scaleSelector)- 10)){
            iSelector += 10;
        }else if(ch == 'a' && jSelector >= 60){
            jSelector -= 10;
        }else if(ch == 'd' && jSelector <= (250 - (200 / scaleSelector) - 10)){
            jSelector += 10;
        }else if(ch == 'q' && scaleSelector <= 2){
                scaleSelector *= 2;
                if(scaleSelector == 4){
                    selector1->is_appearing = 0;
                    selector2->is_appearing = 1;
                }else{
                    selector1->is_appearing = 1;
                    selector2->is_appearing = 0;
                }
            }else if(ch == 'e' && scaleSelector >= 2){
                scaleSelector /= 2;
                if(scaleSelector == 1){
                    selector1->is_appearing = 0;
                    selector2->is_appearing = 0;
                }else{
                    selector1->is_appearing = 1;
                    selector2->is_appearing = 0;
                }
            }
            if(iSelector > (450 - (300 / scaleSelector)- 10)){
                iSelector = (450 - (300 / scaleSelector));
            }
            if(jSelector > (250 - (200 / scaleSelector) - 10)){
                jSelector = (250 - (200 / scaleSelector));
            }
            // printf("%d %d\n",iSelector,jSelector);
            map_img = down_scale(&img, 4 / scaleSelector);
            map_img = Buffer_get_crop(&map_img, point((iSelector - 150) * scaleSelector * 2,(jSelector - 50) * scaleSelector * 2), point((iSelector - 150) * scaleSelector * 2 +  600,(jSelector - 50) * scaleSelector * 2 + 400));
            Object_update_zoom_position(iSelector,jSelector, &map_img);
        }

    }
    getchar();
}
