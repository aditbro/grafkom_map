#include "Point.h"
#include <stdio.h>

int main(){
    int i1 = 2, j1 = 1;
    int i2 = 1, j2 = 1;
    Point p1 = point(i1,j1);
    Point p2 = point(i2,j2);

    //check constructor
    if(p1.i != i1 || p1.j != j1 || p2.i != i2 || p2.j != j2){
        printf("ERROR DETECTED! Point Constructor\n");
    }

    //check isEqual
    //should be : p1 != p2 and p1 == point(2,1)
    if(Point_isEqual(p1, p2) || !Point_isEqual(p1, point(2,1))){
        printf("ERROR DETECTED! Point isEqual\n");
    }

    //check add
    //should be : p1 == p2 + point(-1,0)
    if(!Point_isEqual(p1, Point_add(p2,point(1,0)))){
        printf("ERROR DETECTED! Point add\n");
    }

    //check substract
    //should be : p1 == p2 - point(1,0)
    if(!Point_isEqual(p1, Point_substract(p2,point(-1,0)))){
        printf("ERROR DETECTED! Point substract\n");
    }

    //check move
    //should be : move(p1,-1,0); p1 == p2;
    Point_move(&p2, 1, 0);
    if(!Point_isEqual(p1, p2)){
        printf("ERROR DETECTED! Point move\n");
    }
}