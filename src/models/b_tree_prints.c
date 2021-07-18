#include "b_tree_prints.h"

void printBTreeInOrderRec(BTree bTree, int position) {
    Registry *registry = readIndexRegistry(position, bTree->indexFile);
    if(isLeafBTree(registry)) {
        for(int i = 0; i < registry->numberOfKeys; i++)
            printf("   %d", registry->key[i]);
    }else{
        int i;
        for(i = 0; i < registry->numberOfKeys; i++) {
            printBTreeInOrderRec(bTree, registry->children[i]);
            printf("   %d", registry->key[i]);
        }
        printBTreeInOrderRec(bTree, registry->children[i]);
    }
    free(registry);
}

void printBTreeInOrder(BTree bTree) {
    int indexRoot = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    if(indexRoot == -1)
        return;
    printBTreeInOrderRec(bTree, indexRoot);
}

void printBTreeByLevel(BTree bTree) {
    if(isEmptyBTree(bTree)) {
        printAlignedCenter("Arvore vazia.");
        return;
    }
    int next = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    Queue *queue = createQueue();
    insertQueue(queue, next, 1);
    int previous_height = 0;
    int current_height;
    int read;
    while(!emptyQueue(queue)) {
        current_height = queue->head->tabs;
        next = removeQueue(queue);
        if(previous_height < current_height) {
            previous_height = current_height;
            printf("\n\tNivel %d: ", current_height);
        }
        //printf("/t%d", readNodeField(OFFSET_NODE_CODE, next, dataFile));
        //if((read = readNodeField(OFFSET_NODE_LEFT, next, dataFile)) != -1)
        //    insertQueue(queue, read, current_height + 1);
        //if((read = readNodeField(OFFSET_NODE_RIGHT, next, dataFile)) != -1)
        //    insertQueue(queue, read, current_height + 1);
    }
    printf("\n\n");
}

void printBTreeRegistry(Registry *registry, int position, Canvas canvas, int x, int y) {
    printCanvasNumber(canvas, position, x + 1, y + 1);
    printCanvasText(canvas, "P:", x + 1, y + 1);
    printCanvasNumber(canvas, registry->numberOfKeys, x + 9, y + 1);
    printCanvasText(canvas, "N:", x + 9, y + 1);
    int i;
    for(i = 0; i < registry->numberOfKeys; i++) {
        printCanvasBox(canvas, i * 8 + 4, y + 2, 8, 3);
        printCanvasNumber(canvas, registry->key[i], i * 8 + 5, y + 3);
        printCanvasBox(canvas, i * 8 + 4, y + 4, 8, 3);
        printCanvasNumber(canvas, registry->position[i], i * 8 + 5, y + 5);
        printCanvasBox(canvas, i * 8, y + 6, 8, 3);
        printCanvasNumber(canvas, registry->children[i], i * 8 + 1, y + 7);
    }
    printCanvasBox(canvas, i * 8, y + 6, 8, 3);
    printCanvasNumber(canvas, registry->children[i], i * 8 + 1, y + 7);
}

void printBTreeRegistryList(BTree bTree) {
    int last = readIndexHeadField(OFFSET_LAST_INDEX, bTree->indexFile);
    Canvas canvas = createCanvas(ORDER * 15, last * 9);
    Registry *registry;
    printf("\n Raiz: %d\n", readIndexHeadField(OFFSET_ROOT_INDEX, bTree->indexFile));
    for(int i = 0; i < last; i++) {
        registry = readIndexRegistry(i, bTree->indexFile);
        if(registry->numberOfKeys == -1) {
            free(registry);
            continue;
        }
        printBTreeRegistry(registry, i, canvas, 0, i * 9);
        free(registry);
    }
    printCanvas(canvas);
    printf("\n");
    freeCanvas(canvas);
}

void printBTreeProductList(BTree bTree) {
    int last = readDataHeadField(OFFSET_LAST_DATA, bTree->dataFile);
    Product *product;
    printf("\n");
    for(int i = 0; i < last; i++) {
        product = readDataRegistry(i, bTree->dataFile);
        if(product->code == -1) {
            free(product);
            continue;
        }
        printProduct(product);
        free(product);
    }
    printf("\n");
}

void printBTreeFreeIndexRec(BTree bTree, int position) {
    if(position == -1)
        return;
    printf("  %d", position);
    printBTreeFreeIndexRec(
        bTree,
        readIndexRegistryField(OFFSET_REGISTRY_NUM, position, bTree->indexFile)
    );
}

void printBTreeFreeIndex(BTree bTree) {
    printBTreeFreeIndexRec(
        bTree,
        readIndexHeadField(OFFSET_FREE_INDEX, bTree->indexFile)
    );
}

void printBTreeFreeDataRec(BTree bTree, int position) {
    if(position == -1)
        return;
    printf("  %d", position);
    printBTreeFreeDataRec(
        bTree,
        readDataRegistryField(OFFSET_PRODUCT_CODE, position, bTree->dataFile)
    );
}

void printBTreeFreeData(BTree bTree) {
    printBTreeFreeDataRec(
        bTree,
        readDataHeadField(OFFSET_FREE_DATA, bTree->dataFile)
    );
}