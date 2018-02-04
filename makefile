all: pixel.c
	gcc -o pixel pixel.c
clean:
	rm a.out
	rm *~
	rm *.o
run: all
	./pixel
