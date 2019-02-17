#ifndef OBJECT_H
#define OBJECT_H

#include "../../data_structures.h"
#include "../../algorithm.h"

typedef struct {
    Point location;
    Buffer** b;
    int num_buffer;
    int id;
    int is_appearing;
} Object;

extern int num_object;
extern Object** object_array;

//draw all object to a buffer
void Object_draw_all(Buffer* buff);

//object constructor
Object* object(Point loc);

//add more shape to objcet
void Object_add_buffer(Object* ob, Buffer* buff);

//draw object to a buffer
void Object_draw(Object* ob, Buffer* buff);

void Object_update_zoom_position(int iSelector, int jSelector, Buffer *map_img);
#endif