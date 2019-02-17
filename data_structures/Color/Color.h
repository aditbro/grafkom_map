#ifndef COLOR_H
#define COLOR_H

typedef struct {
    char r;
    char g;
    char b;
} Color;

//construct color
Color color(char r, char g, char b);

//print color
void Color_print(Color col);

//compare two colors for equality
int Color_compare(Color* c1, Color* c2);

//get the average color of given pixels
Color Color_get_average(Color* colors, int num_color);

//various predefined color
Color Color_red();
Color Color_green();
Color Color_blue();
Color Color_black();
Color Color_white();
int is_color_same(Color c1, Color c2);
#endif