#include "Color.h"
#include <stdio.h>

Color color(char r, char g, char b){
    Color c;
    c.r = r;
    c.g = g;
    c.b = b;

    return c;
}

void Color_print(Color col){
    printf("(%d, %d, %d)\n", col.r, col.g, col.b);
}

int Color_compare(Color* c1, Color* c2){
    return(c1->r == c2->r && c1->g == c2->g && c1->b == c2->b);
}

Color Color_get_average(Color* colors, int num_color) {
    if(num_color == 0){
        return color(0,0,0);
    }

    int r = 0;
    int g = 0; 
    int b = 0;

    for(int i = 0; i < num_color; i++){
        r += colors[i].r;
        g += colors[i].g;
        b += colors[i].b;
    }

    r = r/num_color;
    g = g/num_color;
    b = b/num_color;

    return color(r,g,b);
}

//color constants
Color Color_red(){
    return color(255,0,0);
}

Color Color_green(){
    return color(0,255,0);
}

Color Color_blue(){
    return color(0,0,255);
}

Color Color_black(){
    return color(0,0,0);
}

Color Color_white(){
    return color(255,255,255);
}

int is_color_same(Color c1, Color c2){
    if(c1.r == c2.r && c1.g == c2.g && c1.b == c2.b){
        return 1;
    }else{
        return 0;
    }
}