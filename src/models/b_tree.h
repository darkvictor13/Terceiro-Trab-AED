/**
 * @file b_tree.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef B_TREE_H
#define B_TREE_H

#include "../menu/canvas.h"
#include "index_file.h"
#include "data_file.h"
#include "product.h"
#include "queue.h"

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

Bool isRegistryUnderFlow(Registry *registry);

Bool canRegistryBorrow(Registry *registry);

Bool searchBTreeByCodeRec(BTree bTree, int registryPosition, int code, int *position);

Bool searchBTreeByCode(BTree bTree, int code, int *position);

Bool searchPositionBTRee(Registry *registry, int key, int *position);

void simpleAddBTree(Registry *registry, RegistryField *registryField);

RegistryField *splitAddBTree(BTree bTree, Registry *registry, int position, RegistryField *registryField);

RegistryField *insertBTreeRec(BTree bTree, int position, Product *product);

void insertBTree(BTree bTree, Product *product);

Product *getBTreeProduct(BTree bTree, int position);

void updateBTreeProduct(BTree bTree, int position, Product *product);

void simpleRemoveBTree(Registry *registry, int position);

Bool removeBTreeRec(BTree bTree, int *position, int code);

Bool removeBTree(BTree bTree, int code);

#endif
