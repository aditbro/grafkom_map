all: main.c data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c
	gcc -g -Wall -o main main.c  data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c algorithm/down_scaling/down_scaling.c -ggdb
	   
	   

clean: 
	$(RM) main
