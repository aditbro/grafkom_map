#include "Object.h"

//object constructor
Object object(int id, Shape* s, int num_shape, Point loc) {
    Object ob;
    ob.s = s;
    ob.num_shape = num_shape;
    ob.id = id;
    ob.location = loc;
}

//add action function
void Object_add_action(Object* ob, void (*f)(char*)){
    ob->actionFunction = f;
}