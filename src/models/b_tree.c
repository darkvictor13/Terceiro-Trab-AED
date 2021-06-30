#include "b_tree.h"

BTree *openBTreeFiles(char *indexFilePath, char *dataFilePath) {
    BTree *bTree = (BTree*)malloc(sizeof(BTree));
    bTree->indexFile = fopen(indexFilePath, "r+b");
    bTree->dataFile = fopen(dataFilePath, "r+b");
    if(bTree->indexFile == NULL || bTree->dataFile == NULL) {
        bTree->indexFile = makeIndexFile(indexFilePath);
        bTree->dataFile = makeDataFile(dataFilePath);
    }
    setbuf(bTree->indexFile, NULL);
    setbuf(bTree->dataFile, NULL);
    return bTree;
}

FILE *makeIndexFile(char *indexFilePath) {
    FILE *indexFile = fopen(indexFilePath, "w+b");
    IndexHead head;
    head.regRoot = head.regFree = -1;
    head.regLast = 0;
    writeIndexHead(&head, indexFile);
    return indexFile;
}

FILE *makeDataFile(char *dataFilePath) {
    FILE *dataFile = fopen(dataFilePath, "w+b");
    DataHead head;
    head.regLast = 0;
    head.regFree = -1;
    writeDataHead(&head, dataFile);
    return dataFile;
}

void closeBTreeFiles(BTree *bTree) {
    fclose(bTree->indexFile);
    fclose(bTree->dataFile);
    free(bTree);
}

int insertBTree(BTree *bTree, Product *product) {
    
}

Product *getBTreeProduct(BTree *bTree, int position) {
    return readDataRegistry(position, bTree->dataFile);
}

void updateBTreeProduct(BTree *bTree, int position, Product *product) {
    writeDataRegistry(product, position, bTree->dataFile);
}

int removeBTree(BTree *bTree, int code) {

}

int searchBTreeByCode(BTree *bTree, int code) {
    
}

void printBTreeInOrder(BTree *bTree) {

}

void printBTreeInOrderRec(BTree *bTree) {

}

void printBTreeByLevel(BTree *bTree) {

}

void printBTreeByLevelRec(BTree *bTree) {

}

void printBTreeFree(BTree *bTree) {
    
}

void printBTreeFreeRec(BTree *bTree) {

}
