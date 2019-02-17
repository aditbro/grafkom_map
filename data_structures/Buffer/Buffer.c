#include "Buffer.h"
#include <stdlib.h>
#include <stdio.h>

//buffer constructor
Buffer buffer(char* buff, int width, int height){
    Buffer b;
    b.buffer = buff;
    b.width = width;
    b.height = height;

    return b;
}

//buffer constructor but manually create the buffer
Buffer create_buffer(int width, int height) {
    Buffer b;
    b.width = width;
    b.height = height;
    b.buffer = (char*) malloc(width*height*4);

    return b;
}

//buffer copy constructor
Buffer copy_buffer(Buffer* buff){
    Buffer b;
    b.width = buff->width;
    b.height = buff->height;
    b.buffer = (char*)malloc(b.width*b.height*4);
    for(int i = 0; i < b.height * b.width * 4; i++){
        b.buffer[i] = buff->buffer[i];
    }

    return b;
}

//fill a buffer point
void Buffer_fillAt(Buffer* buff, int i, int j, Color* col){
    //the 4 is in there because the width is in char while the measurement of width is in int
    buff->buffer[(buff->width * i + j) * 4] = col->b;
    buff->buffer[(buff->width * i + j) * 4 + 1] = col->g;
    buff->buffer[(buff->width * i + j) * 4 + 2] = col->r;
    buff->buffer[(buff->width * i + j) * 4 + 3] = 0;
}

//draw a buffer point, difference with fill, if black then not drawn
void Buffer_drawAt(Buffer* buff, int i, int j, Color* col){
    Color b = Color_black();
    if(Color_compare(col, &b)){
        return;
    }

    buff->buffer[(buff->width * i + j) * 4] = col->b;
    buff->buffer[(buff->width * i + j) * 4 + 1] = col->g;
    buff->buffer[(buff->width * i + j) * 4 + 2] = col->r;
    buff->buffer[(buff->width * i + j) * 4 + 3] = 0;
}

//get buffer Color at a certain point in buffer
Color Buffer_getColorAt(Buffer* buff, int i, int j){
    Color c;
    c.r = buff->buffer[(buff->width * i + j) * 4 + 2];
    c.g = buff->buffer[(buff->width * i + j) * 4 + 1];
    c.b = buff->buffer[(buff->width * i + j) * 4];

    return c;
}

//copy the second buffer into the first one given the destination buffer can contain the source
int Buffer_copy(Buffer* dest, Buffer* src, Point init) {
    if(dest->width < src->width+init.j || dest->height < src->height+init.i){
        printf("buffer copy rejected src dim %d %d, dest dim %d %d \n",src->width+init.j, src->height+init.i, dest->width, dest->height);
        return 1;
    }

    Color c;

    for(int i = 0; i < src->height; i++){
        for(int j = 0; j < src->width; j++){
            c = Buffer_getColorAt(src, i, j);
            Buffer_fillAt(dest, i+init.i, j+init.j, &c);
        }
    }

    return 0;
}

int Buffer_draw(Buffer* dest, Buffer* src, Point init) {
    if(dest->width < src->width+init.j || dest->height < src->height+init.i){
        printf("buffer draw rejected src dim %d %d, dest dim %d %d \n",src->width+init.j, src->height+init.i, dest->width, dest->height);
        return 1;
    }

    Color b = Color_black();
    Color c;

    for(int i = 0; i < src->height; i++){
        for(int j = 0; j < src->width; j++){
            c = Buffer_getColorAt(src, i, j);
            if(!Color_compare(&c, &b)){
                Buffer_fillAt(dest, i+init.i, j+init.j, &c);
            }
        }
    }

    return 0;
}

/*
 *crop a buffer then return the cropped buffer
 *example : 
 *buff :    1 2 3  top_left : (1,1)     return :    5 6
 *          4 5 6  bot_right : (2,2)                8 9
 *          7 8 9
 */
Buffer Buffer_get_crop(Buffer* buff, Point top_left, Point bot_right) {    
    Color c;

    int leftmost = top_left.j;
    int rightmost = bot_right.j;
    int highest = top_left.i;
    int lowest = bot_right.i;
    Buffer ret_buff = create_buffer(rightmost-leftmost+1, lowest-highest+1);
    
    for(int i = highest; i <= lowest; i++){
        for(int j = leftmost; j <= rightmost; j++){
            c = Buffer_getColorAt(buff, i, j);
            Buffer_fillAt(&ret_buff, i-highest, j-leftmost, &c);
        }
    }

    return ret_buff;
}