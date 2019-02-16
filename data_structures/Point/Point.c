#include "Point.h"
#include <stdio.h>

Point point(int i, int j){
    Point p;
    p.i = i;
    p.j = j;

    return p;
}

int Point_isEqual(Point p1, Point p2){
    return(p1.i == p2.i && p1.j == p2.j);
}

Point Point_add(Point p1, Point p2){
    p1.i = p1.i + p2.i;
    p1.j = p2.j + p1.j;

    return p1;
}

Point Point_substract(Point p1, Point p2){
    p1.i = p1.i - p2.i;
    p1.j = p1.j - p2.j;

    return p1;
}

void Point_move(Point* p, int i, int j){
    p->i = p->i + i;
    p->j = p->j + j;
}

void Point_scale(Point* p, float factor) {
    p->i = (int) p->i * factor;
    p->j = (int) p->j * factor;
}