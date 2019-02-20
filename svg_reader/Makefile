IDIR = /usr/include/libxml2/
IDIR2 = ../data_structures
LDIR = /usr/
DIRSVG = SVGReader
DIRPROCESS = PathDataProcessing
CC = gcc
CFLAGS =-I$(IDIR) -I$(IDIR2) -I$(DIRSVG) -I$(DIRPROCESS) -L$(LDIR)
COMPILEDIR = main.c $(DIRSVG)/svgReader.c $(DIRPROCESS)/pathToLines.c $(IDIR2)/Line/Line.c $(IDIR2)/Shape/Shape.c $(IDIR2)/Color/Color.c $(IDIR2)/Point/Point.c $(IDIR2)/Buffer/Buffer.c
LIB = -lxml2 -lm

all:
	$(CC) -Wall -g -o reader $(COMPILEDIR) $(CFLAGS) $(LIB)

clean: 
	rm $(OBJ)