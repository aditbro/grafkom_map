#ifndef BUFFER_H
#define BUFFER_H

#include "../Color/Color.h"
#include "../Point/Point.h"

typedef struct{
    char* buffer;
    int width;
    int height;
} Buffer;

//buffer constructor
Buffer buffer(char* buff, int width, int height);

//buffer constructor but manually create the buffer
Buffer create_buffer(int width, int height);

//buffer copy constructor
Buffer copy_buffer(Buffer* buff);

//fill a buffer point
void Buffer_fillAt(Buffer* buff, int i, int j, Color* col);

//draw a buffer point, difference with fill, if black then not drawn
void Buffer_drawAt(Buffer* buff, int i, int j, Color* col);

//get buffer Color at a certain point in buffer
Color Buffer_getColorAt(Buffer* buff, int i, int j);

//copy the second buffer into the first one given the destination buffer can contain the source
int Buffer_copy(Buffer* dest, Buffer* src, Point init);

//same like copy but skip black color
int Buffer_draw(Buffer* dest, Buffer* src, Point init);

/*
 *crop a buffer then return the cropped buffer
 *example : 
 *buff :    1 2 3  top_left : (1,1)     return :    5 6
 *          4 5 6  bot_right : (2,2)                8 9
 *          7 8 9
 */
Buffer Buffer_get_crop(Buffer* buff, Point top_left, Point bot_right);

#endif