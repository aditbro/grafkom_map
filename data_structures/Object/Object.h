#ifndef OBJECT_H
#define OBJECT_H

#include "../../data_structures.h"
#include "../../algorithm.h"

typedef struct {
    Point location;
    Shape* s;
    int num_shape;
    int id;
    void (*actionFunction)(char*);
} Object;

//object constructor
Object object(int id, Shape* s, int num_shape, Point loc);

//add action function
void Object_add_action(Object* ob, void (*f)(char*));

#endif