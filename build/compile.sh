#!/bin/sh

# gcc main.c ./menu/*.c -o ../build/main.x -lm
gcc ../src/main.c ../src/menu/*.c -o main.x -lm

exit 0
