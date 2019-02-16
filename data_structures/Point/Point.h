#ifndef POINT_H
#define POINT_H

typedef struct {
    int i;
    int j;
} Point;

//construt a point
Point point(int i, int j);

//check if p1 == p2
int Point_isEqual(Point p1, Point p2);

//results in p1 + p2
Point Point_add(Point p1, Point p2);

//results in p1 - p2
Point Point_substract(Point p1, Point p2);

//move point by i and j
void Point_move(Point* p, int i, int j);

//scale up or down point distance with origin
void Point_scale(Point* p, float factor);

#endif