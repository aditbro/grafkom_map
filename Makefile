IDIR = /usr/include/libxml2/
IDIR2 = ./data_structures
LDIR = /usr/
DIRSVG = ./svg_reader/SVGReader
DIRPROCESS = ./svg_reader/PathDataProcessing
CC = gcc
CFLAGS =-I$(IDIR) -I$(IDIR2) -I$(DIRSVG) -I$(DIRPROCESS) -L$(LDIR)
LIB = -lxml2 -lm

all: main.c data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c
	gcc -g -Wall -o main main.c  data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c algorithm/down_scaling/down_scaling.c data_structures/Object/Object.c -ggdb
	   
layer: main_layer.c data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c svg_reader/PathDataProcessing/pathToLines.c svg_reader/SVGReader/svgReader.c data_structures/Letters/Letters.c
	$(CC) -g -Wall -o main main_layer.c  data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c algorithm/down_scaling/down_scaling.c data_structures/Object/Object.c svg_reader/PathDataProcessing/pathToLines.c svg_reader/SVGReader/svgReader.c data_structures/Letters/Letters.c -ggdb $(CFLAGS) $(LIB)
	   

clean: 
	$(RM) main
