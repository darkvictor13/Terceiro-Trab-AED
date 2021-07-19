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

Product* allocProduct();

void printProduct(Product *product);

void printBasicProduct(Product *product);

Product* scanProduct();

void reset(char *str, int size);

#endif
