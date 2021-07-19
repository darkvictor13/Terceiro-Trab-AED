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

/**
 * @brief Get the Canvas Position object
 * 
 * @param canvas 
 * @param x 
 * @param y 
 * @return char* 
 * @pre Nenhuma
 * @post Nenhuma
 */
char *getCanvasPosition(Canvas canvas, int x, int y);

/**
 * @brief 
 * 
 * @param width 
 * @param high 
 * @return char* 
 * @pre Nenhuma
 * @post Nenhuma
 */
char *allocCanvasMatrix(int width, int high);

/**
 * @brief 
 * 
 * @param canvas 
 * @pre Nenhuma
 * @post Nenhuma
 */
void clearCanvasMatrix(Canvas canvas);

/**
 * @brief Create a Canvas object
 * 
 * @param width 
 * @param high 
 * @return Canvas 
 * @pre Nenhuma
 * @post Nenhuma
 */
Canvas createCanvas(int width, int high);

/**
 * @brief 
 * 
 * @param canvas 
 * @param x 
 * @param y 
 * @param width 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasHorizontalLine(Canvas canvas, int x, int y, int width);

/**
 * @brief 
 * 
 * @param canvas 
 * @param x 
 * @param y 
 * @param high 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasVerticalLine(Canvas canvas, int x, int y, int high);

/**
 * @brief 
 * 
 * @param canvas 
 * @param x 
 * @param y 
 * @param width 
 * @param high 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasBox(Canvas canvas, int x, int y, int width, int high);

/**
 * @brief 
 * 
 * @param canvas 
 * @param text 
 * @param x 
 * @param y 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasText(Canvas canvas, char *text, int x, int y);

/**
 * @brief 
 * 
 * @param canvas 
 * @param num 
 * @param x 
 * @param y 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasNumber(Canvas canvas, int num, int x, int y);

/**
 * @brief 
 * 
 * @param canvas 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvas(Canvas canvas);

/**
 * @brief 
 * 
 * @param canvas 
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeCanvas(Canvas canvas);

#endif
