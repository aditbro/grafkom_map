#ifndef LINE_H
#define LINE_H

#include "../Point/Point.h"
#include "../Color/Color.h"
#include "../Buffer/Buffer.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Point p1;
    Point p2;
    int di;
    int dj;
    int direction;
} Line;

//construct a line
Line line(Point p1, Point p2);

//get i difference
int Line_getDi(Line l);

//get j difference
int Line_getDj(Line l);

//get gradient
int Line_getDirection(int di, int dj);

//print line points
void Line_printLinePoints(Line l);

//draw line to a buffer
//using pointer as parameter to speed up the parameter passing process
void Line_draw(Line* l, Buffer* buff, Color* col, Point* init);

//get the line direction quadrant
int Line_getQuadrant(int di, int dj, float gradient);

//get the line gradient
float Line_getGradient(Line l);

#endif