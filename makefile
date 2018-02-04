all: pixel.c
	gcc -o pixel pixel.c -lm
	./pixel
clean:
	rm *.ppm
	rm pixel
	rm *.png
