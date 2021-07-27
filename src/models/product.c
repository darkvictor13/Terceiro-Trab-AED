/**
 * @file product.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "product.h"

/**
 * @brief Aloca o espaço de memória para um novo Produto
 * 
 * @return Product* Ponteiro para o Produto
 * @pre Nenhuma
 * @post Nenhuma
 */
Product *allocProduct() {
    Product *product = (Product *)malloc(sizeof(Product));
    product->code = 0;
    reset(product->name, MAX_NAME);
    product->number = 0;
    product->value = 0;
    reset(product->local, MAX_LOCAL);
    return product;
}

/**
 * @brief Imprime na tela as informações do Produto
 * 
 * @param product Um produto válido
 * @pre Nenhuma
 * @post Nenhuma
 */
void printProduct(Product *product) {
    printLine();
    printf("\n\tNome: ");
    printString(product->name);
    printf(".\n\tCódigo do produto: %d.\n", product->code);
    printf("\tQuantidade em estoque: %d.\n", product->number);
    printf("\tValor: %.2f.\n", product->value);
    printf("\tLocal: ");
    printString(product->local);
    printf(".\n\n");
    printLine();
}

/**
 * @brief Imprime de forma simplificada, somente 2 informações
 *  - o código do produto
 *  - o nome do produto
 * 
 * @param product Um produto válido
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBasicProduct(Product *product) {
    char buffer[19 + 10 + MAX_NAME + 1];
    sprintf(buffer, "    %10d -> %s ", product->code, product->name);
    printAlignedLeft(buffer);
}

/**
 * @brief Lê do teclado as informações de um produto
 * 
 * @return Product* Ponteiro para o Produto
 * @pre Nenhuma
 * @post Nenhuma
 */
Product* scanProduct() {
    Product* product = (Product *)malloc(sizeof(Product));
    printf("\n\tNome: ");
    scanf("%[^\n]%*c", product->name);
    printf("\tCódigo do produto: ");
    scanf("%d", &product->code);
    printf("\tQuantidade em estoque: ");
    scanf("%d", &product->number);
    printf("\tValor: ");
    scanf("%f%*c", &product->value);
    printf("\tLocal: ");
    scanf("%[^\n]%*c", product->local);
    printf("\n");
    return product;
}

/**
 * @brief Deixa a string de entrada com todos
 * os caracteres nulos, com 0 absoluto
 * 
 * @param str uma string de entrada válida
 * @param size o tamanho da string
 * @pre uma string válida
 * @post Nenhuma
 */
void reset(char *str, int size) {
    int i;
    for(i = 0; i < size; i++)
        str[i] = '\0';
}
