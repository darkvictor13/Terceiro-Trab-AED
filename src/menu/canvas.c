/**
 * @file canvas.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "canvas.h"

char *getCanvasPosition(Canvas canvas, int x, int y) {
    return (canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x);
}

char *allocCanvasMatrix(int width, int high) {
    return (char*)malloc(sizeof(char) * (width + 1) * high);
}

void clearCanvasMatrix(Canvas canvas) {
    long unsigned int n = (canvas->width + 1) * canvas->high * sizeof(char);
    memset(canvas->matrix, ' ', n);
    unsigned long int step = (canvas->width + 1) * sizeof(char);
    char *line = canvas->matrix + canvas->width * sizeof(char);
    char *end = line + step * canvas->high;
    while(line < end) {
        memset(line, '\0', 1);
        line += step;
    }
}

Canvas createCanvas(int width, int high) {
    Canvas canvas = (Canvas)malloc(sizeof(CanvasStruct));
    canvas->matrix = allocCanvasMatrix(width, high);
    canvas->width = width;
    canvas->high = high;
    clearCanvasMatrix(canvas);
    return canvas;
}

void printCanvasHorizontalLine(Canvas canvas, int x, int y, int width) {
    char *line = canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x;
    memset(line, '-', width);
}

void printCanvasVerticalLine(Canvas canvas, int x, int y, int high) {
    unsigned long int step = sizeof(char) * (canvas->width + 1);
    char *line = canvas->matrix + (step * y)+ sizeof(char) * x;
    char *end = line + step * high;
    while(line < end) {
        memset(line, '|', 1);
        line += step;
    }
}

void printCanvasBox(Canvas canvas, int x, int y, int width, int high) {
    printCanvasHorizontalLine(canvas, x, y, width);
    printCanvasHorizontalLine(canvas, x, y + high - 1, width);
    printCanvasVerticalLine(canvas, x, y, high);
    printCanvasVerticalLine(canvas, x + width, y, high);
}

void printCanvasText(Canvas canvas, char *text, int x, int y) {
    char *line = canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x;
    memcpy(line, text, strlen(text));
}

void printCanvasNumber(Canvas canvas, int num, int x, int y) {
    char *line = canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x;
    char buffer[MAX_NUM];
    sprintf(buffer, "%6d", num);
    memcpy(line, buffer, strlen(buffer));
}

void printCanvas(Canvas canvas) {
    unsigned long int step = sizeof(char) * (canvas->width + 1);
    char *line = canvas->matrix;
    char *end = line + step * canvas->high;
    while(line < end) {
        printf(" %s\n", line);
        line += step;
    }
}

void freeCanvas(Canvas canvas) {
    free(canvas->matrix);
    free(canvas);
}
