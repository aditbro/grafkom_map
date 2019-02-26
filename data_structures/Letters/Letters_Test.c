#include "Letters.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "../../kbhit.c"

int main(){

    int fb_fd = 0;
    int SCREEN_SIZE = 800 * 1176 * 4;
    fb_fd = open("/dev/fb0", O_RDWR);
    char * fb = mmap(NULL,
					SCREEN_SIZE,
					PROT_READ | PROT_WRITE, MAP_SHARED,
					fb_fd,
					0);
    memset(fb, 0, SCREEN_SIZE);
    Buffer b = buffer(fb,1176, 800);
    Color c = color(255,0,0);

    Shape s1  = drawA(0,0,c);
    Shape s2  = drawB(0,0,c);
    Shape s3  = drawC(0,0,c);
    Shape s4  = drawD(0,0,c);
    Shape s5  = drawE(0,0,c);
    Shape s6  = drawF(0,0,c);
    Shape s7  = drawG(0,0,c);
    Shape s8  = drawH(0,0,c);
    Shape s9  = drawI(0,0,c);
    Shape s10 = drawJ(0,0,c);
    Shape s11 = drawK(0,0,c);
    Shape s12 = drawL(0,0,c);
    Shape s13 = drawM(0,0,c);
    Shape s14 = drawN(0,0,c);
    Shape s15 = drawO(0,0,c);
    Shape s16 = drawP(0,0,c);
    Shape s17 = drawR(0,0,c);
    Shape s18 = drawS(0,0,c);
    Shape s19 = drawT(0,0,c);
    Shape s20 = drawU(0,0,c);
    Shape s21 = drawV(0,0,c);
    Shape s22 = drawW(0,0,c);
    Shape s23 = drawX(0,0,c);
    Shape s24 = drawY(0,0,c);
    Shape s25 = drawZ(0,0,c);
    
    
    Shape_drawTo(&s1,&b,point(0,0));
    Shape_drawTo(&s2,&b,point(0,100));
    Shape_drawTo(&s3,&b,point(0,200));
    Shape_drawTo(&s4,&b,point(0,300));
    Shape_drawTo(&s5,&b,point(0,400));
    Shape_drawTo(&s6,&b,point(0,500));
    Shape_drawTo(&s7,&b,point(0,600));
    Shape_drawTo(&s8,&b,point(0,700));

    Shape_drawTo(&s9,&b,point(100,0));
    Shape_drawTo(&s10,&b,point(100,100));
    Shape_drawTo(&s11,&b,point(100,200));
    Shape_drawTo(&s12,&b,point(100,300));
    Shape_drawTo(&s13,&b,point(100,400));
    Shape_drawTo(&s14,&b,point(100,500));
    Shape_drawTo(&s15,&b,point(100,600));
    Shape_drawTo(&s16,&b,point(100,700));

    Shape_drawTo(&s17,&b,point(200,0));
    Shape_drawTo(&s18,&b,point(200,100));
    Shape_drawTo(&s19,&b,point(200,200));
    Shape_drawTo(&s20,&b,point(200,300));
    Shape_drawTo(&s21,&b,point(200,400));
    Shape_drawTo(&s22,&b,point(200,500));
    Shape_drawTo(&s23,&b,point(200,600));
    Shape_drawTo(&s24,&b,point(200,700));

    Shape_drawTo(&s25,&b,point(300,600));

    
}
