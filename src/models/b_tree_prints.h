#ifndef B_TREE_PRINTS_H
#define B_TREE_PRINTS_H

#include "b_tree.h"

void printBTreeInOrderRec(BTree bTree, int position);

void printBTreeInOrder(BTree bTree);

void printBTreeByLevelRec(BTree bTree);

void printBTreeByLevel(BTree bTree);

void printBTreeRegistry(Registry *registry, int position, Canvas canvas, int x, int y);

void printBTreeRegistryList(BTree bTree);

void printBTreeProductList(BTree bTree);

void printBTreeFreeIndexRec(BTree bTree, int position);

void printBTreeFreeIndex(BTree bTree);

void printBTreeFreeDataRec(BTree bTree, int position);

void printBTreeFreeData(BTree bTree);

#endif