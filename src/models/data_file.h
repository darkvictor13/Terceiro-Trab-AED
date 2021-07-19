/**
 * @file data_file.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DATA_FILE_H
#define DATA_FILE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "product.h"

typedef struct {
    int regLast;
    int regFree;
}DataHead;

enum offsetHeadData {
    OFFSET_HEAD_DATA = 0,
	OFFSET_LAST_DATA = offsetof(DataHead, regLast),
	OFFSET_FREE_DATA = offsetof(DataHead, regFree)
};

enum offsetProductData {
    OFFSET_PRODUCT_CODE = offsetof(Product, code),
    OFFSET_PRODUCT_NAME = offsetof(Product, name),
    OFFSET_PRODUCT_NUMBER = offsetof(Product, number),
    OFFSET_PRODUCT_VALUE = offsetof(Product, value),
    OFFSET_PRODUCT_LOCAL = offsetof(Product, local)
};

FILE *makeDataFile(char *dataFilePath);

void writeDataHead(DataHead *dataHead, FILE *dataFile);

DataHead *readDataHead(FILE *dataFile);

void writeDataHeadField(int value, int offset, FILE *dataFile);

int readDataHeadField(int offset, FILE *dataFile);

void writeDataRegistry(Product *product, int position, FILE *dataFile);

Product* readDataRegistry(int position, FILE *dataFile);

void writeDataRegistryField(int value, int offset, int position, FILE *dataFile);

int readDataRegistryField(int offset, int position, FILE *dataFile);

void clearDataRegistry(int position, FILE *dataFile);

int insertDataRegistry(Product *product, FILE *dataFile);

void removeDataRegistry(int position, FILE *dataFile);

#endif