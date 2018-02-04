all: pixel.c
	gcc -o pixel pixel.c -lm
	./pixel
	convert pixel.ppm pixel.png
clean:
	rm *.ppm
	rm pixel
	rm *.png
