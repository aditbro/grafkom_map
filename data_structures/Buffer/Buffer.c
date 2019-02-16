#include "Buffer.h"
#include <stdlib.h>
//buffer constructor
Buffer buffer(char* buff, int width, int height){
    Buffer b;
    b.buffer = buff;
    b.width = width;
    b.height = height;

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

//get buffer Color at a certain point in buffer
Color Buffer_getColorAt(Buffer* buff, int i, int j){
    Color c;
    c.r = buff->buffer[(buff->width * i + j) * 4 + 2];
    c.g = buff->buffer[(buff->width * i + j) * 4 + 1];
    c.b = buff->buffer[(buff->width * i + j) * 4];

    return c;
}
