#include "SVGReader/svgReader.h"
#include "PathDataProcessing/pathToLines.h"
#include "../data_structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "../kbhit.c"

int screen_width = 1176;
int screen_height = 800;

int main(){
    
    int fb_fd = 0;
    
    int SCREEN_SIZE = screen_width * screen_height * 4;
    char *bf = (char*)malloc(SCREEN_SIZE);
    Buffer temp_buff = buffer(bf, 1176, 800);
    fb_fd = open("/dev/fb0", O_RDWR);
    char * fb = mmap(NULL,
					SCREEN_SIZE,
					PROT_READ | PROT_WRITE, MAP_SHARED,
					fb_fd,
					0);
    memset(fb, 0, SCREEN_SIZE);
    Buffer b = buffer(fb,screen_width, screen_height);

    Shape *listOfShapes = (Shape*) malloc (160*sizeof(Shape));
    char **layerNameList = (char**) malloc (6 * sizeof(char*)); 
    char** itbMap = streamFile("peta_itb.svg",layerNameList);
    printf("finished reading!");
    for(int i = 0; i < 143 ; i++) {  
        if (itbMap[i] != NULL) //NULL means a change in layer
        listOfShapes[i] = getShapeFromInstructions(itbMap[i], 3);
    }
    for(int i = 0; i < 143 ; i++) {
        Shape_drawTo(&(listOfShapes[i]),&b, point(0,0));
    }
    xmlCleanupParser();
    xmlMemoryDump();
    
}
