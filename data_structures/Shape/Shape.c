#include "Shape.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Shape constructor
Shape shape(Line* lines, int num_line, Color* col){
    Shape sh;
    sh.shape_color = *col;
    sh.line_number = num_line;
    sh.lines = (Line*)malloc(num_line*sizeof(Line));
    for(int i = 0; i < num_line; i++){
        sh.lines[i] = lines[i];
    }
    Shape_init_critical_point(&sh);
    Shape_init_buffer(&sh);    
    Shape_draw(&sh);

    return sh;
}

//Shape copy constructor (yep we need this)
Shape copy_shape(Shape* sh){
    Shape sh2;
    sh2.shape_color = sh->shape_color;
    sh2.line_number = sh->line_number;
    sh2.lines = (Line*)malloc(sh->line_number*sizeof(Line));
    for(int i = 0; i < sh->line_number; i++){
        sh2.lines[i] = sh->lines[i];
    }
    Shape_init_critical_point(&sh2);
    Shape_init_buffer(&sh2);    
    sh2.shape_buffer = copy_buffer(&sh->shape_buffer);

    return sh2;
}

//draw shape to internal buffer
void Shape_draw(Shape* sh){
    Shape_draw_wireframe(sh);
    Shape_fillColor(sh);
}

//get the leftmost, top, bottom, rightmost points and save it to struct
void Shape_init_critical_point(Shape* sh) {
    int i;
    sh->leftmost_point = sh->lines[0].p1.i;
    sh->rightmost_point = sh->lines[0].p1.i;
    sh->highest_point = sh->lines[0].p1.j;
    sh->lowest_point = sh->lines[0].p1.j;
    for (i = 0;i < sh->line_number; i++){
        if( sh->leftmost_point > sh->lines[i].p1.j){
            sh->leftmost_point = sh->lines[i].p1.j;
        }
        if( sh->leftmost_point > sh->lines[i].p2.j){
            sh->leftmost_point = sh->lines[i].p2.j;
        }
        if( sh->rightmost_point < sh->lines[i].p1.j){
            sh->rightmost_point = sh->lines[i].p1.j;
        }
        if( sh->rightmost_point < sh->lines[i].p2.j){
            sh->rightmost_point = sh->lines[i].p2.j;
        }
        if( sh->highest_point > sh->lines[i].p1.i){
            sh->highest_point = sh->lines[i].p1.i;
        }
        if( sh->highest_point > sh->lines[i].p2.i){
            sh->highest_point = sh->lines[i].p2.i;
        }
        if( sh->lowest_point < sh->lines[i].p1.i){
            sh->lowest_point = sh->lines[i].p1.i;
        }
        if( sh->lowest_point < sh->lines[i].p2.i){
            sh->lowest_point = sh->lines[i].p2.i;
        }
    }
}

//initialize shape buffer
void Shape_init_buffer(Shape* sh){
    int width = sh->rightmost_point + 1;
    int height = sh->lowest_point + 1;
    char* fb = (char*) malloc (sizeof(char) * width * height * 4);
    sh->shape_buffer = buffer(fb,width,height);
}


//copy shape to external buffer
void Shape_drawTo(Shape* sh, Buffer* buff, Point init){
    Color c;
    for(int i = 0; i < sh->shape_buffer.height; i++){
        for(int j = 0; j < sh->shape_buffer.width; j++){
            c = Buffer_getColorAt(&sh->shape_buffer,i,j);
            Buffer_fillAt(buff,i + init.i ,j + init.j, &c);
        }
    }
}


//draw the lines of the shape
void Shape_draw_wireframe(Shape *sh){
    Point init = point(0,0);
    for (int i = 0;i < sh->line_number; i++){
        Line_draw(&(sh->lines[i]), &(sh->shape_buffer), &(sh->shape_color), &init);
    }
}

//fill shape color
void Shape_fillColor(Shape* sh){
    // Shape dummy = copy_shape(sh);
    // for(int i = 0; i < sh->shape_buffer.height; i++){
    //     Shape_fillRow(sh, i, &dummy);
    // }

    Point init = Shape_findInsidePoint(sh);
    Shape_floodFill(sh, init);
}

void Shape_floodFill(Shape* sh, Point init){
    Color current = Buffer_getColorAt(&sh->shape_buffer, init.i, init.j);
    Color black = Color_black();
    if(init.i < sh->shape_buffer.height && init.j < sh->shape_buffer.width && Color_compare(&current, &black)){
       Buffer_fillAt(&sh->shape_buffer, init.i, init.j, &sh->shape_color);
       Shape_floodFill(sh, point(init.i-1, init.j));
       Shape_floodFill(sh, point(init.i+1, init.j));
       Shape_floodFill(sh, point(init.i, init.j+1));
       Shape_floodFill(sh, point(init.i, init.j-1));
    }
}

Point Shape_findInsidePoint(Shape* sh){
    int j = (sh->leftmost_point + sh->rightmost_point)/2;
    int i = (sh->highest_point + sh->lowest_point)/2;
    Point init = point(i, j);

    if(!Shape_isPointInside(sh, init)){
        for(i = 0; i < sh->lowest_point; i++){
            int break_flag = 0;
            for(j = 0; j < sh->rightmost_point; j++){
                init = point(i, j);
                if(Shape_isPointInside(sh, init)){
                    break_flag = 1;
                    break;
                }
            }
            if(break_flag){
                break;
            }
        }
    }

    return init;
}   

//check if a point is inside
int Shape_isPointInside(Shape* sh, Point init){
    Color current = Buffer_getColorAt(&sh->shape_buffer, init.i, init.j);
    Color black = Color_black();

    //kalo titik yang dipilih berwarna return 0
    if(Color_compare(&current, &sh->shape_color)){
        return 0;
    }

    //periksa ke atas
    for(int i = init.i; Color_compare(&current, &black) ; i--){
        if(i < 0) return 0;
        current = Buffer_getColorAt(&sh->shape_buffer, i, init.j);
    }
    current = Buffer_getColorAt(&sh->shape_buffer, init.i, init.j);

    //periksa ke bawah
    for(int i = init.i; Color_compare(&current, &black) ; i++){
        if(i >= sh->shape_buffer.height) return 0;
        current = Buffer_getColorAt(&sh->shape_buffer, i, init.j);
    }
    current = Buffer_getColorAt(&sh->shape_buffer, init.i, init.j);

    //periksa ke kiri
    for(int j = init.j; Color_compare(&current, &black) ; j--){
        if(j < 0) return 0;
        current = Buffer_getColorAt(&sh->shape_buffer, init.i, j);
    }
    current = Buffer_getColorAt(&sh->shape_buffer, init.i, init.j);

    //periksa ke kanan
    for(int j = init.j; Color_compare(&current, &black) ; j++){
        if(j >= sh->shape_buffer.width) return 0;
        current = Buffer_getColorAt(&sh->shape_buffer, init.i, j);
    }

    return 1;
}

//fill shape row with color
void Shape_fillRow(Shape* sh, int i, Shape* dummy){
    int coloring = 0;
    int anomaly_value = 0;
    Color current;
    Color black = Color_black();

    for(int j = 0; j < sh->shape_buffer.width; j++){
        current = Buffer_getColorAt(&sh->shape_buffer, i, j);
        
        if(!Color_compare(&current, &black)){
            anomaly_value = Shape_checkAnomalyValue(dummy, i ,j);
            // printf("i %d j %d anom %d\n", i, j, anomaly_value);
            //ini handler kasus sangat khusus
            j += anomaly_value;
            coloring = !coloring != !anomaly_value;
        }

        if(coloring && j < sh->shape_buffer.width){
            Buffer_fillAt(&sh->shape_buffer, i, j, &sh->shape_color);
        }
    }
}

//check the "anomality" of a point
int Shape_checkAnomalyValue(Shape* sh, int i , int j){
    // printf("i %d j %d ", i, j);
    Color current = Buffer_getColorAt(&sh->shape_buffer, i, j);
    Color black = Color_black();
    int width = sh->shape_buffer.width;
    // int height = sh->shape_buffer.height;
    int point_length = 0;
    // int top;
    // int bot;

    int is_line_top = !Shape_isPointBlank(sh, i - 1, j - 1);
    int is_line_bot = !Shape_isPointBlank(sh, i + 1, j - 1);

    while(!Color_compare(&current, &black) && j < width){
        point_length++;
        is_line_top += !Shape_isPointBlank(sh, i - 1, j);
        is_line_bot += !Shape_isPointBlank(sh, i + 1, j);
        j++;
        current = Buffer_getColorAt(&sh->shape_buffer, i, j);
    }
    //mengembalikan j ke titik berwarna terakhir
    j--;

    is_line_top += !Shape_isPointBlank(sh, i - 1, j + 1);
    is_line_bot += !Shape_isPointBlank(sh, i + 1, j + 1);

    // printf("top %d bot %d\n", is_line_top, is_line_bot);

    if(is_line_bot && is_line_top){
        return point_length;
    } else {
        return 0;
    }
}

int Shape_isPointBlank(Shape* sh, int i , int j){
    Color black = Color_black();
    Color current;
    int width = sh->shape_buffer.width;
    int height = sh->shape_buffer.height;

    if(i < height && i >= 0 && j < width && j >= 0){
        current = Buffer_getColorAt(&sh->shape_buffer, i, j);
        return Color_compare(&current, &black);
    } else {
        return 1;
    }
}


/* Shape Transformation Functions */
// Translate
void Shape_translate(Shape* sh, int i, int j) {
    for (int i=0; i < sh->line_number; ++i) {
        Point_move(&sh->lines[i].p1, i, j);
        Point_move(&sh->lines[i].p2, i, j);
    }
}

// Dilate
void Shape_dilate(Shape* sh, Point ref_point, float factor) {
    Shape_translate(sh, -ref_point.i, -ref_point.j);
    for (int i=0; i < sh->line_number; ++i) {
        Point_scale(&sh->lines[i].p1, factor);
        Point_scale(&sh->lines[i].p2, factor);
    }
    Shape_translate(sh, ref_point.i, ref_point.j);
}

// Mirror
void Shape_mirror(Shape* sh, Line ref_line) {
    return;
}

// Rotate
void Shape_rotate(Shape* sh, float angle) {
    return;
}

Shape Shape_star(int scale, Color c) {
    Line* lines = (Line*)malloc(10*sizeof(Line));
    lines[0] = line(point(0, 60), point(60, 55));
    lines[1] = line(point(60, 55), point(74, 0));
    lines[2] = line(point(75, 0), point(90, 55));
    lines[3] = line(point(150, 60), point(90, 55));
    lines[4] = line(point(150, 60), point(105, 95));
    lines[5] = line(point(120, 150), point(105, 95));
    lines[6] = line(point(120, 150), point(75, 115));
    lines[7] = line(point(30, 150), point(75, 115));
    lines[8] = line(point(30, 150), point(45, 95));
    lines[9] = line(point(0, 60), point(45, 95));

    for(int k = 0; k < 10; k++){
        Point p1 = point(lines[k].p1.i * scale, lines[k].p1.j * scale);
        Point p2 = point(lines[k].p2.i * scale, lines[k].p2.j * scale);
        lines[k] = line(p1, p2);
    }

    return shape(lines, 10, &c);
}

Shape Shape_hexagon(int scale, Color c) {
    Line* lines = (Line*)malloc(6*sizeof(Line));
    lines[0] = line(point(scale * 24/2, scale * 0), point(scale * 0, scale * 49/2));
    lines[1] = line(point(scale * 24/2, scale * 96/2), point(scale * 0, scale * 49/2));
    lines[2] = line(point(scale * 24/2, scale * 96/2), point(scale * 72/2, scale * 96/2));
    lines[3] = line(point(scale * 96/2, scale * 49/2), point(scale * 72/2, scale * 96/2));
    lines[4] = line(point(scale * 96/2, scale * 49/2), point(scale * 72/2, scale * 0));
    lines[5] = line(point(scale * 24/2, scale * 0), point(scale * 72/2, scale * 0));
    
    return shape(lines, 6, &c);
}

Shape Shape_plane(int scale, Color c){
    Line* lines = (Line*)malloc(6*sizeof(Line));
    lines[0] = line(point(scale * 24,scale * 3), point(scale * 2,scale * 112));
    lines[1] = line(point(scale * 2,scale * 112), point(scale * 56,scale * 64));
    lines[2] = line(point(scale * 56,scale * 64), point(scale * 38,scale * 36));
    lines[3] = line(point(scale * 38,scale * 36), point(scale * 58,scale * 33));
    lines[4] = line(point(scale * 58,scale * 33), point(scale * 33,scale * 27));
    lines[5] = line(point(scale * 33,scale * 27), point(scale * 24,scale * 3));

    return shape(lines, 6, &c);
}

Shape Shape_cannon(int scale, Color c) {
    // printf("drawing cannon\n");
    Line* lines = (Line*)malloc(8*sizeof(Line));
    lines[0] = line(point(56, 0), point(110, 0));
    lines[1] = line(point(110, 0), point(110, 53));
    lines[2] = line(point(110, 53), point(56, 53));
    lines[3] = line(point(56, 53), point(56, 32));
    lines[4] = line(point(56, 32), point(0, 32));
    lines[5] = line(point(0, 32), point(0, 20));
    lines[6] = line(point(0, 20), point(56, 20));
    lines[7] = line(point(56, 20), point(56, 0));

    for(int k = 0; k < 8; k++){
        Point p1 = point(lines[k].p1.i * scale, lines[k].p1.j * scale);
        Point p2 = point(lines[k].p2.i * scale, lines[k].p2.j * scale);
        lines[k] = line(p1, p2);
    }

    return shape(lines, 8, &c);
}

Shape Shape_bullet(int scale, Color c) {
    Line* lines = (Line*)malloc(6*sizeof(Line));
    lines[0] = line(point(3, 0), point(0, 6));
    lines[1] = line(point(3, 12), point(0, 6));
    lines[2] = line(point(3, 12), point(9, 12));
    lines[3] = line(point(12, 6), point(9, 12));
    lines[4] = line(point(12, 6), point(9, 0));
    lines[5] = line(point(3, 0), point(9, 0));
    
    for(int k = 0; k < 6; k++){
        Point p1 = point(lines[k].p1.i * scale, lines[k].p1.j * scale);
        Point p2 = point(lines[k].p2.i * scale, lines[k].p2.j * scale);
        lines[k] = line(p1, p2);
    }

    return shape(lines, 6, &c);
}

Shape Shape_rectangle(int scale, Color c) {
    Line* lines = (Line*)malloc(4*sizeof(Line));
    lines[0] = line(point(0, 0), point(0, 3));
    lines[1] = line(point(0, 3), point(6, 3));
    lines[2] = line(point(6, 3), point(6, 0));
    lines[3] = line(point(6, 0), point(0, 0));

    for(int k = 0; k < 4; k++){
        Point p1 = point(lines[k].p1.i * scale, lines[k].p1.j * scale);
        Point p2 = point(lines[k].p2.i * scale, lines[k].p2.j * scale);
        lines[k] = line(p1, p2);
    }

    return shape(lines, 4, &c);
}