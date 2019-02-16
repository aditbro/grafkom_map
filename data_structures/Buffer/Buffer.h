#ifndef BUFFER_H
#define BUFFER_H

#include "../Color/Color.h"

typedef struct{
    char* buffer;
    int width;
    int height;
} Buffer;

//buffer constructor
Buffer buffer(char* buff, int width, int height);

//buffer copy constructor
Buffer copy_buffer(Buffer* buff);

//fill a buffer point
void Buffer_fillAt(Buffer* buff, int i, int j, Color* col);

//get buffer Color at a certain point in buffer
Color Buffer_getColorAt(Buffer* buff, int i, int j);

#endif