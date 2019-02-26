all: main.c data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c
	gcc -g -Wall -o main main.c  data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c algorithm/down_scaling/down_scaling.c data_structures/Object/Object.c -ggdb
	   
layer: main_layer.c data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c data_structures/Letters/Letters.c
	gcc -g -Wall -o main main_layer.c  data_structures/Shape/Shape.c data_structures/Line/Line.c data_structures/Point/Point.c data_structures/Buffer/Buffer.c data_structures/Color/Color.c data_structures/Letters/Letters.c algorithm/down_scaling/down_scaling.c data_structures/Object/Object.c -ggdb
	   

clean: 
	$(RM) main
