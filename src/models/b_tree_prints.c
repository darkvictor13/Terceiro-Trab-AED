/**
 * @file b_tree_prints.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "b_tree_prints.h"

/**
 * @brief imprime os elementos de uma arbore b em ordem
 * 
 * @param bTree arvore b a ser imprimessa
 * @param position posicao atual do percorrimento da arvore
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief imprime o s elementos de uma arvore b em ordem
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeInOrder(BTree bTree) {
    int indexRoot = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    if(indexRoot == -1)
        return;
    printBTreeInOrderRec(bTree, indexRoot);
}

/**
 * @brief immprime os codigos de uma arvore b por niveis
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeByLevel(BTree bTree) {
    if(isEmptyBTree(bTree)) {
        printAlignedCenter("");
        printAlignedCenter("Arvore vazia.");
        printAlignedCenter("");
        return;
    }
    int next = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    Queue *queue = createQueue();
    insertQueue(queue, next, 1);
    int previous_height = 0;
    int current_height, read;
    while(!emptyQueue(queue)) {
        current_height = queue->head->tabs;
        next = removeQueue(queue);
        if(previous_height < current_height) {
            previous_height = current_height;
            printf("\n\tNivel %d: ", current_height);
        }
        Registry *registry = readIndexRegistry(next, bTree->indexFile);
        for(int i = 0; i < registry->numberOfKeys; i++)
            printf("  %d", registry->key[i]);
        if(!isLeafBTree(registry))
            for(int i = 0; i <= registry->numberOfKeys; i++)
                insertQueue(queue, registry->children[i], current_height + 1);
        free(registry);
    }
    printf("\n\n");
}

/**
 * @brief imprime um registro em um canvas
 * 
 * @param registry registro a ser impresso
 * @param position posicao na lista de registros do arquivo
 * @param canvas canvas on de sera impresso o registro
 * @param x posicao do registro no eixo x dentro do canvas
 * @param y posicao do registro no eixo y dentro do canvas
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeRegistry(Registry *registry, int position, Canvas canvas, int x, int y) {
    printCanvasNumber(canvas, position, x + 1, y + 1);
    printCanvasText(canvas, "P:", x + 1, y + 1);
    printCanvasNumber(canvas, registry->numberOfKeys, x + 9, y + 1);
    printCanvasText(canvas, "N:", x + 9, y + 1);
    if(registry->numberOfKeys >= ORDER)
        return;
    int i;
    for(i = 0; i < registry->numberOfKeys; i++) {
        printCanvasBox(canvas, i * 8 + 4, y + 2, 8, 3);
        printCanvasNumber(canvas, registry->key[i], i * 8 + 5, y + 3);
        printCanvasBox(canvas, i * 8 + 4, y + 4, 8, 3);
        printCanvasNumber(canvas, registry->position[i], i * 8 + 5, y + 5);
        printCanvasBox(canvas, i * 8, y + 6, 8, 3);
        printCanvasNumber(canvas, registry->children[i], i * 8 + 1, y + 7);
    }
    if(i != 0) {
        printCanvasBox(canvas, i * 8, y + 6, 8, 3);
        printCanvasNumber(canvas, registry->children[i], i * 8 + 1, y + 7);
    }
}

/**
 * @brief imprime uma lista de registros na saida estandar
 * 
 * @param bTree arvore b a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeRegistryList(BTree bTree) {
    int last = readIndexHeadField(OFFSET_LAST_INDEX, bTree->indexFile);
    Canvas canvas = createCanvas(ORDER * 15, last * 9);
    Registry *registry;
    printf("\n Total: %d\n", readIndexHeadField(OFFSET_LAST_INDEX, bTree->indexFile));
    printf(" Raiz: %d\n", readIndexHeadField(OFFSET_ROOT_INDEX, bTree->indexFile));
    printf(" Livre: %d\n", readIndexHeadField(OFFSET_FREE_INDEX, bTree->indexFile));
    for(int i = 0; i < last; i++) {
        registry = readIndexRegistry(i, bTree->indexFile);
        printBTreeRegistry(registry, i, canvas, 0, i * 9);
        free(registry);
    }
    printCanvas(canvas);
    printf("\n");
    freeCanvas(canvas);
}

/**
 * @brief imprime os registros dentro do arquivo de dados
 * 
 * @param bTree arvore b a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeProductList(BTree bTree) {
    int last = readDataHeadField(OFFSET_LAST_DATA, bTree->dataFile);
    Product *product;
    printf("\n Total: %d\n", readIndexHeadField(OFFSET_LAST_DATA, bTree->indexFile));
    printf(" Livre: %d\n", readIndexHeadField(OFFSET_FREE_DATA, bTree->indexFile));
    for(int i = 0; i < last; i++) {
        product = readDataRegistry(i, bTree->dataFile);
        printProduct(product);
        free(product);
    }
    printf("\n");
}

/**
 * @brief imprime a lista de regsitros libres no arquivo que representa a arvore
 * 
 * @param bTree arvore a ser impressa
 * @param position posicao atual na lista de registros
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeIndexRec(BTree bTree, int position) {
    if(position == -1)
        return;
    printf("  %d", position);
    printBTreeFreeIndexRec(
        bTree,
        readIndexRegistryField(OFFSET_REGISTRY_NUM, position, bTree->indexFile)
    );
}

/**
 * @brief imprime a lista de regsitros libres no arquivo que representa a arvore
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeIndex(BTree bTree) {
    printBTreeFreeIndexRec(
        bTree,
        readIndexHeadField(OFFSET_FREE_INDEX, bTree->indexFile)
    );
}

/**
 * @brief imprime a lista de registros libres no arquivo que contem os dados dos produtos
 * 
 * @param bTree arvore a ser impressa
 * @param position posicao atual na lista de dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeDataRec(BTree bTree, int position) {
    if(position == -1)
        return;
    printf("  %d", position);
    printBTreeFreeDataRec(
        bTree,
        readDataRegistryField(OFFSET_PRODUCT_CODE, position, bTree->dataFile)
    );
}

/**
 * @brief imprime a lista de registros libres no arquivo que contem os dados dos produtos
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeData(BTree bTree) {
    printBTreeFreeDataRec(
        bTree,
        readDataHeadField(OFFSET_FREE_DATA, bTree->dataFile)
    );
}
