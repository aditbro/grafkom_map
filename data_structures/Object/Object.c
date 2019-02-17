#include "Object.h"
#include <stdio.h>

int num_object = 0;
Object** object_array;

//object constructor
Object* object(Point loc){
    if(num_object == 0){
        object_array = (Object**) malloc(100*sizeof(Object*));
    }

    Object* ob = (Object*)malloc(sizeof(Object));
    ob->b = (Buffer**)malloc(10*sizeof(Buffer*));
    ob->num_buffer = 0;
    ob->id = num_object++;
    ob->location = loc;
    ob->is_appearing = 1;

    object_array[ob->id] = ob;

    return ob;
}

//draw object to a buffer
void Object_draw(Object* ob, Buffer* buff) {
    // printf("ob %d num buffer %d\n", ob->id, ob->num_buffer);
    if(ob->is_appearing){
        for(int i = 0; i < ob->num_buffer; i++){
            // printf("ob %d, buff %d, dim %d %d\n", ob->id, i, ob->b[i]->width, ob->b[i]->height);
            Buffer_draw(buff, ob->b[i], ob->location);
        }
    }    
}

//add more shape to objcet
void Object_add_buffer(Object* ob, Buffer* buff){
    ob->b[ob->num_buffer++] = buff;
}

//draw all object to a buffer
void Object_draw_all(Buffer* buff) {
    // printf("num objects %d\n", num_object);
    for(int i = 0; i < num_object; i++){
        Object_draw(object_array[i], buff);
    }
}

void Object_update_zoom_position(int iSelector, int jSelector, Buffer *map_img){
    object_array[2]->location.i = iSelector;
    object_array[2]->location.j = jSelector;
    object_array[3]->location.i = iSelector;
    object_array[3]->location.j = jSelector;
    object_array[1]->b[0] = map_img;
}