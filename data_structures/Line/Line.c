#include "Line.h"
#include <float.h>
#include <stdio.h>

Line line(Point p1, Point p2){
    Line l;
    l.p1 = p1;
    l.p2 = p2;
    l.di = Line_getDi(l);
    l.dj = Line_getDj(l);
    l.direction = Line_getDirection(l.di, l.dj);

    return l;
}

int Line_getDi(Line l){
    return(l.p2.i - l.p1.i);
}

int Line_getDj(Line l){
    return(l.p2.j - l.p1.j);
}

float Line_getGradient(Line l){
    int di = Line_getDi(l);
    int dj = Line_getDj(l);

    if(di == 0){
        return(FLT_MAX);
    } else {
        return(abs(di/dj));
    }
}

void Line_printLinePoints(Line l){
    printf("%d, %d to %d, %d\n", l.p1.i, l.p1.j, l.p2.i, l.p2.j);
}

//get the line direction
//1 means dj from p1 to p2
//2 means di from p1 to p2
//3 means dj from p2 to p1
//4 means di from p2 to p1
int Line_getDirection(int di, int dj){
    if(abs(dj) > abs(di)){
        if(dj > 0){
            return 1;
        } else {
            return 3;
        }
    } else {
        if(di > 0){
            return 2;
        } else {
            return 4;
        }
    };
}


//draw the line
void Line_draw(Line* l, Buffer* buff, Color* col, Point* init){
    int di = l->di;
    int dj = l->dj;

    //deciding which direction the line will be drawn
    int direction = l->direction;

    Point p_start, p_end;
    if(direction == 1 || direction == 2){
        p_start = point(l->p1.i, l->p1.j);
        p_end = point(l->p2.i, l->p2.j);
    } else {
        p_end = point(l->p1.i, l->p1.j);
        p_start = point(l->p2.i, l->p2.j);
    }

    //deciding how to draw the line based on the gradient
    int i, j, end;
    if(direction % 2 == 1){
        dj = p_end.j - p_start.j;
        di = p_end.i - p_start.i;
        j = p_start.j, i = p_start.i;
        end = p_end.j;
    } else {
        dj = p_end.i - p_start.i;
        di = p_end.j - p_start.j;
        j = p_start.i, i = p_start.j;
        end = p_end.i;
    }

    //drawing the line
    int adjust_i = (di < 0 ? -1 : 1);

    di = abs(di);
    dj = abs(dj);
    int p = 2*di - dj;

    for(; j <= end; j++){

        if(direction % 2 == 1){
            Buffer_fillAt(buff,i + init->i,j + init->j,col);
        } else {
            Buffer_fillAt(buff,j + init->i,i  + init->j,col);

        }
        if(p < 0){
            p = p + 2*di;
        } else {
            i = i + adjust_i;
            p = p + 2*di - (2 * dj);
        }
    }    
}