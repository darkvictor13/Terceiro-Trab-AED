#ifndef B_TREE_H
#define B_TREE_H

#include "index_file.h"
#include "data_file.h"
#include "product.h"

typedef struct {
    FILE *indexFile;
    FILE *dataFile;
}BTree;

BTree *openBTreeFiles(char *indexFilePath, char *dataFilePath);

FILE *makeIndexFile(char *indexFilePath);

FILE *makeDataFile(char *dataFilePath);

void closeBTreeFiles(BTree *bTree);

int insertBTree(BTree *bTree, Product *product);

Product *getBTreeProduct(BTree *bTree, int position);

void updateBTreeProduct(BTree *bTree, int position, Product *product);

int removeBTree(BTree *bTree, int code);

int searchBTreeByCode(BTree *bTree, int code);

void printBTreeInOrder(BTree *bTree);

void printBTreeInOrderRec(BTree *bTree);

void printBTreeByLevel(BTree *bTree);

void printBTreeByLevelRec(BTree *bTree);

void printBTreeFree(BTree *bTree);

void printBTreeFreeRec(BTree *bTree);

#endif
