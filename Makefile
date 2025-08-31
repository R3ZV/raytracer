CC=gcc
CFLAGS=-std=c23 -lm
CFILES=src/main.c src/vec3.c src/colors.c

run: main
	./main > img.ppm

main:
	gcc $(CFLAGS) $(CFILES) -o main

.PHONY: main
