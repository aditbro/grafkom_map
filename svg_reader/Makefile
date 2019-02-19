IDIR = libxml2/include
LDIR = libxml2/lib
DIR = SVG_PathData_Parser
CC = gcc
CFLAGS =-I$(IDIR) -L$(LDIR)
OBJ = reader.exe
TARGET = $(DIR)/reader1.c
LIB = -lxml2 -lm -l../bin/libxml2-2

all: 
	$(CC) -o $(OBJ) $(TARGET) $(CFLAGS) $(LIB)

clean: 
	rm $(OBJ)