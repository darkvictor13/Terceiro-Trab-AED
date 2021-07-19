/**
 * @file canvas.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CANVAS_H
#define CANVAS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NUM 7

typedef struct {
    char *matrix;
    int width;
    int high;
}CanvasStruct;

typedef CanvasStruct* Canvas;

char *getCanvasPosition(Canvas canvas, int x, int y);

char *allocCanvasMatrix(int width, int high);

void clearCanvasMatrix(Canvas canvas);

Canvas createCanvas(int width, int high);

void printCanvasHorizontalLine(Canvas canvas, int x, int y, int width);

void printCanvasVerticalLine(Canvas canvas, int x, int y, int high);

void printCanvasBox(Canvas canvas, int x, int y, int width, int high);

void printCanvasText(Canvas canvas, char *text, int x, int y);

void printCanvasNumber(Canvas canvas, int num, int x, int y);

void printCanvas(Canvas canvas);

void freeCanvas(Canvas canvas);

#endif
