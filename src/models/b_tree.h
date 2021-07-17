#ifndef B_TREE_H
#define B_TREE_H

#include "index_file.h"
#include "data_file.h"
#include "product.h"

#define OPEN_MODE "r+b"

typedef enum {
    FALSE,
    TRUE
}Bool;

typedef struct {
    FILE *indexFile;
    FILE *dataFile;
}NodeBTree;

typedef NodeBTree* BTree;

BTree openBTreeFiles(char *indexFilePath, char *dataFilePath);

void closeBTreeFiles(BTree bTree);

Registry *createRegistry(int key, int position, int leftChild, int rightChild);

Bool isEmptyBTree(BTree bTree);

Bool isLeafBTree(Registry *registry);

Bool isRegistryFull(Registry *registry);

Bool searchBTreeByCodeRec(BTree bTree, int registryPosition, int code, int *position);

Bool searchBTreeByCode(BTree bTree, int code, int *position);

Bool searchPositionBTRee(Registry *registry, int key, int *position);

void simpleAddBTree(Registry *registry, RegistryField *registryField);

RegistryField *splitAddBTree(BTree bTree, Registry *registry, int position, RegistryField *registryField);

RegistryField *insertBTreeRec(BTree bTree, int position, Product *product);

void insertBTree(BTree bTree, Product *product);

Product *getBTreeProduct(BTree bTree, int position);

void updateBTreeProduct(BTree bTree, int position, Product *product);

Bool removeBTreeRec(BTree bTree, int code);

Bool removeBTree(BTree bTree, int code);

void printBTreeInOrderRec(BTree bTree, int position);

void printBTreeInOrder(BTree bTree);

void printBTreeByLevelRec(BTree bTree);

void printBTreeByLevel(BTree bTree);

void printBTreeFreeRec(BTree bTree);

void printBTreeFree(BTree bTree);

#endif
