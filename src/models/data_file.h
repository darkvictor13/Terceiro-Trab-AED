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

void writeDataHead(DataHead *dataHead, FILE *dataFile);

DataHead *readDataHead(FILE *dataFile);

void writeDataHeadField(int value, int offset, FILE *dataFile);

int readDataHeadField(int offset, FILE *dataFile);

void writeDataRegistry(Product *product, int position, FILE *dataFile);

Product* readDataRegistry(int position, FILE *dataFile);

#endif