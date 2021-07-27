/**
 * @file product.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include "../menu/print_menu.h"

#define MAX_NAME 51

#define MAX_LOCAL 101

#define MAX_ENTRY_LINE 251

typedef struct {
    int code;
    char name[MAX_NAME];
    int number;
    float value;
    char local[MAX_LOCAL];
}Product;

/**
 * @brief Aloca o espaço de memória para um novo Produto
 * 
 * @return Product* Ponteiro para o Produto
 * @pre Nenhuma
 * @post Nenhuma
 */
Product *allocProduct();

/**
 * @brief Imprime na tela as informações do Produto
 * 
 * @param product Um produto válido
 * @pre Nenhuma
 * @post Nenhuma
 */
void printProduct(Product *product);

/**
 * @brief Imprime de forma simplificada, somente 2 informações
 *  - o código do produto
 *  - o nome do produto
 * 
 * @param product Um produto válido
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBasicProduct(Product *product);

/**
 * @brief Lê do teclado as informações de um produto
 * 
 * @return Product* Ponteiro para o Produto
 * @pre Nenhuma
 * @post Nenhuma
 */
Product* scanProduct();

/**
 * @brief Deixa a string de entrada com todos
 * os caracteres nulos, com 0 absoluto
 * 
 * @param str uma string de entrada válida
 * @param size o tamanho da string
 * @pre uma string válida
 * @post Nenhuma
 */
void reset(char *str, int size);

#endif
