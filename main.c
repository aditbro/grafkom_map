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
    int iSelector, jSelector,scaleSelector;

    iSelector = 150;
    jSelector = 50;
    scaleSelector = 2;

    Buffer tb = create_buffer(screen_width, screen_height);
    Buffer fb = get_image_buffer("/dev/fb0", screen_width, screen_height);
    Buffer img = get_image_buffer("file.pmp", 1600, 2400);
    Buffer thumbnail_img = down_scale(&img, 8);
    Buffer map_img = down_scale(&img, 4 / scaleSelector);
    map_img = Buffer_get_crop(&map_img, point(iSelector - 150 ,jSelector - 50), point((iSelector - 150) +  600,(jSelector - 50) + 400));
    Shape rectangle1 = Shape_free_rectangle(100, 150, Color_black());
    Shape rectangle2 = Shape_free_rectangle(50, 75, Color_black());

    memset(tb.buffer, 0, SCREEN_SIZE);

    Object* thumbnail = object(point(150,50));
    Object_add_buffer(thumbnail, &thumbnail_img);

    Object* map = object(point(0,400));
    Object_add_buffer(map, &map_img);


    Object* selector1 = object(point(iSelector,jSelector));
    Object_add_buffer(selector1, &rectangle1.shape_buffer);

    Object* selector2 = object(point(iSelector,jSelector));
    Object_add_buffer(selector2, &rectangle2.shape_buffer);
    selector2->is_appearing = 0;
    char ch;
    while(1){
        memset(tb.buffer, 0, SCREEN_SIZE);
        Object_draw_all(&tb);
        memcpy((fb.buffer), (tb.buffer), SCREEN_SIZE);
        usleep(10000);
        if (kbhit())
        {
            ch = getchar();
            if(ch == 'w' && iSelector >= 160){
                iSelector -= 10;
            }else if(ch == 's' && iSelector <= (450 - (300 / scaleSelector)- 10)){
                iSelector += 10;
            }else if(ch == 'a' && jSelector >= 60){
                jSelector -= 10;
            }else if(ch == 'd' && jSelector <= (250 - (200 / scaleSelector) - 10)){
                jSelector += 10;
            }else if(ch == 'q' && scaleSelector <= 4){
                scaleS            if(iSelector > (450 - (300 / scaleSelector)- 10)){
                iSelector = (450 - (300 / scaleSelector)- 10);
            }
            if(jSelector > (250 - (200 / scaleSelector) - 10)){
                jSelector = (250 - (200 / scaleSelector) - 10);
            }
                if(sca            if(iSelector > (450 - (300 / scaleSelector)- 10)){
                iSelector = (450 - (300 / scaleSelector)- 10);
            }
            if(jSelector > (250 - (200 / scaleSelector) - 10)){
                jSelector = (250 - (200 / scaleSelector) - 10);
            }
                    se            if(iSelector > (450 - (300 / scaleSelector)- 10)){
                iSelector = (450 - (300 / scaleSelector)- 10);
            }
            if(jSelector > (250 - (200 / scaleSelector) - 10)){
                jSelector = (250 - (200 / scaleSelector) - 10);
            }
                    se            if(iSelector > (450 - (300 / scaleSelector)- 10)){
                iSelector = (450 - (300 / scaleSelector)- 10);
            }
            if(jSelector > (250 - (200 / scaleSelector) - 10)){
                jSelector = (250 - (200 / scaleSelector) - 10);
            }
                }else{            if(iSelector > (450 - (300 / scaleSelector)- 10)){
                iSelector = (450 - (300 / scaleSelector)- 10);
            }
            if(jSelector > (250 - (200 / scaleSelector) - 10)){
                jSelector = (250 - (200 / scaleSelector) - 10);
            }
                    selector1->is_appearing = 0;
                    selector2->is_appearing = 1;

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
