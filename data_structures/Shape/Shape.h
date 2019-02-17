#ifndef SHAPE_H
#define SHAPE_H

#include "../Point/Point.h"
#include "../Line/Line.h"
#include "../Color/Color.h"
#include <stdlib.h>

typedef struct {
    Line* lines;
    int line_number;
    Color shape_color;
    Color line_color;
    Buffer shape_buffer;

    int leftmost_point;
    int rightmost_point;
    int highest_point;
    int lowest_point;
} Shape;

//Shape constructor
Shape shape(Line* lines, int num_line, Color* col);

//Shape copy constructor (yep we need this)
Shape copy_shape(Shape* sh);

//draw shape to internal buffer
void Shape_draw(Shape* sh);

//TODO
//draw the lines of the shape
void Shape_draw_wireframe(Shape *sh);

//TODO
//fill shape color
void Shape_fillColor(Shape* sh);

//fill shape row with color
void Shape_fillRow(Shape* sh, int i, Shape* dummy);

//find a point inside the shape
Point Shape_findInsidePoint(Shape* sh);

//fill shape with floodfill
void Shape_floodFill(Shape* sh, Point init);

//check if a point is inside
int Shape_isPointInside(Shape* sh, Point init);

//check the "anomality" of a point
//the anomality of a point is determined by how "long" the point is and if it is anomaly
//a point can be a line (hear me out here) because barrier to the next place to draw can
//be a line
//the return will be how long is the line (a point is 1) * !is_it_anomaly
//an anomaly will always return 0
int Shape_checkAnomalyValue(Shape* sh, int i , int j);

//TODO
//copy shape to external buffer
void Shape_drawTo(Shape* sh, Buffer* buff, Point p);

//initialize critical point
void Shape_init_critical_point(Shape* sh);

//initialize shape buffer
void Shape_init_buffer(Shape* sh);

/* Shape Transformation Functions */
// Translate
void Shape_translate(Shape* sh, int i, int j);

// Dilate
void Shape_dilate(Shape* sh, Point ref_point, float factor);

// Mirror
void Shape_mirror(Shape* sh, Line ref_line);

// Rotate
void Shape_rotate(Shape* sh, float angle);

//check if a point in buffer is blank
int Shape_isPointBlank(Shape* sh, int i, int j);


/**
 * SHAPE CONSTANTS
 */

Shape Shape_star(int scale, Color c);
Shape Shape_hexagon(int scale, Color c);
Shape Shape_plane(int scale, Color c);
Shape Shape_cannon(int scale, Color c);
Shape Shape_bullet(int scale, Color c);
Shape Shape_rectangle(int scale, Color c);
Shape Shape_free_rectangle(int width, int height, Color c);
#endif
