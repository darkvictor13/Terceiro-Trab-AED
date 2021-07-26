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

/**
 * @brief realiza o calculo da posicao em memoria de um ponto dadas as suas coordenadas
 * 
 * @param canvas estrutura contendo os dados de um canvas
 * @param x posicao em relacao ao eixo x
 * @param y posicao em relacao ao eixo y
 * @return char* ponteiro para o endereco em memoria que se corresponde com as coordenadas pasadas
 * @pre Nenhuma
 * @post Nenhuma
 */
char *getCanvasPosition(Canvas canvas, int x, int y) {
    return (canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x);
}

/**
 * @brief reservas espaco em memoria para a matriz de um canvas
 * 
 * @param width tamanho da matris no eixo x
 * @param high tamanho da matriz no eixo y
 * @return char* ponteiro para o inicio da matriz
 * @pre Nenhuma
 * @post Nenhuma
 */
char *allocCanvasMatrix(int width, int high) {
    return (char*)malloc(sizeof(char) * (width + 1) * high);
}

/**
 * @brief limpa a matriz de dados de um canvas
 * 
 * @param canvas canvas a ser limpado
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief crea e inicia um canvas
 * 
 * @param width tamanho do canvas no eixo x
 * @param high tamanho do canvas no eixo y
 * @return Canvas o canvas recen gerado
 * @pre Nenhuma
 * @post Nenhuma
 */
Canvas createCanvas(int width, int high) {
    Canvas canvas = (Canvas)malloc(sizeof(CanvasStruct));
    canvas->matrix = allocCanvasMatrix(width, high);
    canvas->width = width;
    canvas->high = high;
    clearCanvasMatrix(canvas);
    return canvas;
}

/**
 * @brief imprime uma linha horizontal no canvas
 * 
 * @param canvas canvas onde sera impressa a linha horizontal
 * @param x posicao do ponto inicial da linha no eixo x
 * @param y posicao do ponto inicial da linha no eixo y
 * @param width tamanho da linha horizontal
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasHorizontalLine(Canvas canvas, int x, int y, int width) {
    char *line = canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x;
    memset(line, '-', width);
}

/**
 * @brief imprime uma linha vertical no canvas
 * 
 * @param canvas canvas onde sera impressa a linha verticas
 * @param x posicao do ponto inicial da linha no eixo x
 * @param y posicao do ponto inicial da linha no eico y
 * @param high tamanho da linha vertical
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasVerticalLine(Canvas canvas, int x, int y, int high) {
    unsigned long int step = sizeof(char) * (canvas->width + 1);
    char *line = canvas->matrix + (step * y)+ sizeof(char) * x;
    char *end = line + step * high;
    while(line < end) {
        memset(line, '|', 1);
        line += step;
    }
}

/**
 * @brief imprime uma caixa dentro de um canvas
 * 
 * @param canvas canvas onde sera impressa a caixa
 * @param x posicao no eixo x da caixa
 * @param y posicao no eixo y da caixa
 * @param width tamanho no eixo x da caixa
 * @param high tamanho no eixo y da caixa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasBox(Canvas canvas, int x, int y, int width, int high) {
    printCanvasHorizontalLine(canvas, x, y, width);
    printCanvasHorizontalLine(canvas, x, y + high - 1, width);
    printCanvasVerticalLine(canvas, x, y, high);
    printCanvasVerticalLine(canvas, x + width, y, high);
}

/**
 * @brief imprime um texto em um canvas
 * 
 * @param canvas o canvas a recever o texto
 * @param text o texto a ser inserido no canvas
 * @param x posicao no eixo x do texto
 * @param y posicao no eixo y do texto
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasText(Canvas canvas, char *text, int x, int y) {
    char *line = canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x;
    memcpy(line, text, strlen(text));
}

/**
 * @brief imprime um numero em um canvas
 * 
 * @param canvas o canvas a recever o numero
 * @param num o numero a ser colocado dentro do canvas
 * @param x posicao no eixo x do numero
 * @param y posicao no eixo y do numero
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvasNumber(Canvas canvas, int num, int x, int y) {
    char *line = canvas->matrix + sizeof(char) * (canvas->width + 1) * y + sizeof(char) * x;
    char buffer[MAX_NUM];
    sprintf(buffer, "%6d", num);
    memcpy(line, buffer, strlen(buffer));
}

/**
 * @brief imprime um canvas na saida estandar
 * 
 * @param canvas canvas a ser impresso
 * @pre Nenhuma
 * @post Nenhuma
 */
void printCanvas(Canvas canvas) {
    unsigned long int step = sizeof(char) * (canvas->width + 1);
    char *line = canvas->matrix;
    char *end = line + step * canvas->high;
    while(line < end) {
        printf(" %s\n", line);
        line += step;
    }
}

/**
 * @brief libera o espaco ocupado por um canvas
 * 
 * @param canvas canvas a ser liberado
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeCanvas(Canvas canvas) {
    free(canvas->matrix);
    free(canvas);
}
