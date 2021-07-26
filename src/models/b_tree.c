/**
 * @file b_tree.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "b_tree.h"

/**
 * @brief 
 * 
 * @param indexFilePath 
 * @param dataFilePath 
 * @return BTree 
 * @pre Nenhuma
 * @post Nenhuma
 */
BTree openBTreeFiles(char *indexFilePath, char *dataFilePath) {
    BTree bTree = (BTree)malloc(sizeof(NodeBTree));
    bTree->indexFile = fopen(indexFilePath, OPEN_MODE);
    bTree->dataFile = fopen(dataFilePath, OPEN_MODE);
    if(bTree->indexFile == NULL || bTree->dataFile == NULL) {
        bTree->indexFile = makeIndexFile(indexFilePath);
        bTree->dataFile = makeDataFile(dataFilePath);
    }
    setbuf(bTree->indexFile, NULL);
    setbuf(bTree->dataFile, NULL);
    return bTree;
}

/**
 * @brief 
 * 
 * @param bTree 
 * @pre Nenhuma
 * @post Nenhuma
 */
void closeBTreeFiles(BTree bTree) {
    fclose(bTree->indexFile);
    fclose(bTree->dataFile);
    free(bTree);
}

/**
 * @brief 
 * 
 * @param valueA 
 * @param valueB 
 * @pre Nenhuma
 * @post Nenhuma
 */
void swapIntegers(int *valueA, int *valueB) {
    int aux = (*valueA);
    (*valueA) = (*valueB);
    (*valueB) = aux;
}

/**
 * @brief 
 * 
 * @param bTree 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isEmptyBTree(BTree bTree) {
    return isEmptyIndex(bTree->indexFile);
}

/**
 * @brief 
 * 
 * @param registry 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isLeafBTree(Registry *registry) {
    return (registry->children[0] == -1);
}

/**
 * @brief 
 * 
 * @param registry 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isRegistryFull(Registry *registry) {
    return (registry->numberOfKeys == ORDER - 1);
}

/**
 * @brief 
 * 
 * @param registry 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isRegistryUnderFlow(Registry *registry) {
    return (registry->numberOfKeys < ORDER / 2);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param position 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool canRegistryBorrow(BTree bTree, int position) {
    return (readIndexRegistryField(OFFSET_REGISTRY_NUM, position, bTree->indexFile) > ORDER / 2);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param registryPosition 
 * @param key 
 * @param position 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchBTreeByCodeRec(BTree bTree, int registryPosition, int key, int *position) {
    Registry *registry = readIndexRegistry(registryPosition, bTree->indexFile);
    if(searchPositionBTRee(registry, key, position)) {
        (*position) = registry->position[(*position)];
        free(registry);
        return TRUE;
    }else if(isLeafBTree(registry)) {
        free(registry);
        return FALSE;
    }
    registryPosition = registry->children[(*position)];
    free(registry);
    return searchBTreeByCodeRec(bTree, registryPosition, key, position);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param key 
 * @param position 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchBTreeByCode(BTree bTree, int key, int *position) {
    int indexRoot = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    if(indexRoot == -1)
        return FALSE;
    return searchBTreeByCodeRec(bTree, indexRoot, key, position);
}

#if(ORDER < 10)
/**
 * @brief 
 * 
 * @param registry 
 * @param key 
 * @param position 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchPositionBTRee(Registry *registry, int key, int *position) {
    for((*position) = 0; (*position) < registry->numberOfKeys; (*position)++)
        if(key == registry->key[(*position)])
            return TRUE;
        else if(key < registry->key[(*position)])
            break;
    return FALSE;
}
#else
/**
 * @brief 
 * 
 * @param registry 
 * @param key 
 * @param position 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchPositionBTRee(Registry *registry, int key, int *position) {
    int first = -1, middle;
    (*position) = registry->numberOfKeys;
    while(first < (*position) - 1) {
        middle = (first + (*position)) / 2;
        if(registry->key[middle] < key)
            first = middle;
        else
            (*position) = middle;
    }
    if(registry->key[(*position)] == key)
        return TRUE;
    return FALSE;
}
#endif

/**
 * @brief 
 * 
 * @param registry 
 * @param registryField 
 * @pre Nenhuma
 * @post Nenhuma
 */
void simpleAddBTree(Registry *registry, RegistryField *registryField) {
    int position;
    searchPositionBTRee(registry, registryField->key, &position);
    for(int i = registry->numberOfKeys; i > position; i--) {
        registry->key[i] = registry->key[i - 1];
        registry->position[i] = registry->position[i - 1];
        registry->children[i + 1] = registry->children[i];
    }
    registry->key[position] = registryField->key;
    registry->position[position] = registryField->position;
    registry->children[position + 1] = registryField->leftChild;
    if(registryField->rightChild == -1) {
        registry->children[position + 1] = registryField->leftChild;
    }else{
        registry->children[position] = registryField->leftChild;
        registry->children[position + 1] = registryField->rightChild;
    }
    registry->numberOfKeys++;
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param registry 
 * @param position 
 * @param registryField 
 * @return RegistryField* 
 * @pre Nenhuma
 * @post Nenhuma
 */
RegistryField *splitAddBTree(BTree bTree, Registry *registry, int position, RegistryField *registryField) {
    Registry *newRegistry = (Registry*)malloc(sizeof(Registry));
    int middle = registry->numberOfKeys / 2;
    newRegistry->numberOfKeys = registry->numberOfKeys - middle - 1;
    registry->numberOfKeys = middle;
    RegistryField *promotedRegistry = createRegistryField(registry->key[middle], registry->position[middle], -1, -1);
    newRegistry->children[0] = registry->children[middle + 1];
    for(int i = 0; i < newRegistry->numberOfKeys; i++) {
        newRegistry->key[i] = registry->key[middle + i + 1];
        newRegistry->position[i] = registry->position[middle + i + 1];
        newRegistry->children[i + 1] = registry->children[middle + i + 2];
        registry->key[middle + i + 1] = registry->position[middle + i + 1] = registry->children[middle + i + 2] = 0;
    }
    if(registryField->key < promotedRegistry->key)
        simpleAddBTree(registry, registryField);
    else
        simpleAddBTree(newRegistry, registryField);
    promotedRegistry->leftChild = position;
    promotedRegistry->rightChild = insertIndexRegistry(newRegistry, bTree->indexFile);
    writeIndexRegistry(registry, position, bTree->indexFile);
    free(registryField);
    free(newRegistry);
    free(registry);
    return promotedRegistry;
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param position 
 * @param product 
 * @return RegistryField* 
 * @pre Nenhuma
 * @post Nenhuma
 */
RegistryField *insertBTreeRec(BTree bTree, int position, Product *product) {
    Registry *registry = readIndexRegistry(position, bTree->indexFile);
    RegistryField *returnedRegistryField;
    if(isLeafBTree(registry)) {
        RegistryField *registryField = createRegistryField(product->code, insertDataRegistry(product, bTree->dataFile), -1, -1);
        if(isRegistryFull(registry)) {
            return splitAddBTree(bTree, registry, position, registryField);
        }else{
            simpleAddBTree(registry, registryField);
            writeIndexRegistry(registry, position, bTree->indexFile);
            free(registry);
            return NULL;
        }
    }else{
        int registryPosition;
        searchPositionBTRee(registry, product->code, &registryPosition);
        registryPosition = registry->children[registryPosition];
        RegistryField *promotedRegistry = insertBTreeRec(bTree, registryPosition, product);
        if(promotedRegistry != NULL) {
            if(isRegistryFull(registry)) {
                return splitAddBTree(bTree, registry, position, promotedRegistry);
            }else{
                simpleAddBTree(registry, promotedRegistry);
                writeIndexRegistry(registry, position, bTree->indexFile);
                free(promotedRegistry);
                free(registry);
                return NULL;
            }
        }
    }
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param product 
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertBTree(BTree bTree, Product *product) {
    if(isEmptyBTree(bTree)) {
        int position = insertDataRegistry(product, bTree->dataFile);
        Registry *registry = createRegistry(product->code, position, -1, -1);
        writeIndexHeadField(
            insertIndexRegistry(registry, bTree->indexFile),
            OFFSET_HEAD_INDEX,
            bTree->indexFile
        );
        free(registry);
    }else{
        int position = readIndexHeadField(OFFSET_ROOT_INDEX, bTree->indexFile);
        RegistryField *promotedRegistry = insertBTreeRec(bTree, position, product);
        if(promotedRegistry != NULL) {
            Registry *registry = createRegistry(
                promotedRegistry->key,
                promotedRegistry->position,
                promotedRegistry->leftChild,
                promotedRegistry->rightChild
            );
            writeIndexHeadField(
                insertIndexRegistry(registry, bTree->indexFile),
                OFFSET_ROOT_INDEX,
                bTree->indexFile
            );
            free(promotedRegistry);
            free(registry);
        }
    }
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param position 
 * @return Product* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Product *getBTreeProduct(BTree bTree, int position) {
    return readDataRegistry(position, bTree->dataFile);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param position 
 * @param product 
 * @pre Nenhuma
 * @post Nenhuma
 */
void updateBTreeProduct(BTree bTree, int position, Product *product) {
    writeDataRegistry(product, position, bTree->dataFile);
}

/**
 * @brief 
 * 
 * @param registry 
 * @param position 
 * @pre Nenhuma
 * @post Nenhuma
 */
void simpleRemoveBTree(Registry *registry, int position) {
    registry->numberOfKeys--;
    int i;
    for(i = position; i < registry->numberOfKeys; i++) {
        registry->key[i] = registry->key[i + 1];
        registry->position[i] = registry->position[i + 1];
        registry->children[i + 1] = registry->children[i + 2];
    }
    registry->key[i] = registry->position[i] = registry->children[i + 1] = 0;
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param registry 
 * @param position 
 * @pre Nenhuma
 * @post Nenhuma
 */
void overwriteBTree(BTree bTree, Registry *registry, int position) {
    Registry *rightChild = readIndexRegistry(registry->children[position + 1], bTree->indexFile);
    registry->key[position] = rightChild->key[0];
    registry->position[position] = rightChild->position[0];
    free(rightChild);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param lendTo 
 * @param father 
 * @param position 
 * @pre Nenhuma
 * @post Nenhuma
 */
void lendBTreeChildren(BTree bTree, int lendTo, Registry *father, int position) {
    Registry *leftChild = readIndexRegistry(father->children[position], bTree->indexFile);
    Registry *rightChild = readIndexRegistry(father->children[position + 1], bTree->indexFile);
    RegistryField *registryField = createRegistryField(
        father->key[position],
        father->position[position],
        leftChild->children[leftChild->numberOfKeys],
        rightChild->children[0]
    );
    if(lendTo == LEND_TO_LEFT) {
        simpleAddBTree(leftChild, registryField);
        father->key[position] = rightChild->key[0];
        father->position[position] = rightChild->position[0];
        simpleRemoveBTree(rightChild, 0);
    }else{
        simpleAddBTree(rightChild, registryField);
        father->key[position] = leftChild->key[leftChild->numberOfKeys - 1];
        father->position[position] = leftChild->position[leftChild->numberOfKeys - 1];
        simpleRemoveBTree(leftChild, leftChild->numberOfKeys - 1);
    }
    writeIndexRegistry(leftChild, father->children[position], bTree->indexFile);
    writeIndexRegistry(rightChild, father->children[position + 1], bTree->indexFile);
    free(registryField);
    free(leftChild);
    free(rightChild);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param father 
 * @param position 
 * @pre Nenhuma
 * @post Nenhuma
 */
void concatenateBTreeChildren(BTree bTree, Registry *father, int position) {
    Registry *leftChild = readIndexRegistry(father->children[position], bTree->indexFile);
    Registry *rightChild = readIndexRegistry(father->children[position + 1], bTree->indexFile);
    leftChild->key[leftChild->numberOfKeys] = father->key[position];
    leftChild->position[leftChild->numberOfKeys] = father->position[position];
    leftChild->numberOfKeys++;
    for(int i = 0; i < rightChild->numberOfKeys; i++) {
        leftChild->key[leftChild->numberOfKeys] = rightChild->key[i];
        leftChild->position[leftChild->numberOfKeys] = rightChild->position[i];
        leftChild->children[leftChild->numberOfKeys] = rightChild->children[i];
        leftChild->numberOfKeys++;
    }
    leftChild->children[leftChild->numberOfKeys] = rightChild->children[rightChild->numberOfKeys];
    removeIndexRegistry(father->children[position + 1], bTree->indexFile);
    simpleRemoveBTree(father, position);
    writeIndexRegistry(leftChild, father->children[position], bTree->indexFile);
    free(leftChild);
    free(rightChild);
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param position 
 * @param code 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool removeBTreeRec(BTree bTree, int *position, int code) {
    Registry *registry = readIndexRegistry((*position), bTree->indexFile);
    int positionInRegistry;
    Bool hasFound = searchPositionBTRee(registry, code, &positionInRegistry);
    if(isLeafBTree(registry)) {
        if(hasFound) {
            removeDataRegistry(registry->position[positionInRegistry], bTree->dataFile);
            simpleRemoveBTree(registry, positionInRegistry);
            writeIndexRegistry(registry, (*position), bTree->indexFile);
        }
    }else{
        int nextRegistryPosition;
        if(hasFound) {
            removeDataRegistry(registry->position[positionInRegistry], bTree->dataFile);
            overwriteBTree(bTree, registry, positionInRegistry);
            nextRegistryPosition = registry->children[positionInRegistry + 1];
            writeIndexRegistry(registry, (*position), bTree->indexFile);
            removeBTreeRec(bTree, &nextRegistryPosition, registry->key[positionInRegistry]);
        }else{
            nextRegistryPosition = registry->children[positionInRegistry];
            hasFound = removeBTreeRec(bTree, &nextRegistryPosition, code);
        }
        if(hasFound && nextRegistryPosition != -1) {
            if(positionInRegistry == registry->numberOfKeys)
                positionInRegistry--;
            if(canRegistryBorrow(bTree, registry->children[positionInRegistry]))
                lendBTreeChildren(bTree, LEND_TO_RIGHT, registry, positionInRegistry);
            else if(canRegistryBorrow(bTree, registry->children[positionInRegistry + 1]))
                lendBTreeChildren(bTree, LEND_TO_LEFT, registry, positionInRegistry);
            else
                concatenateBTreeChildren(bTree, registry, positionInRegistry);
            writeIndexRegistry(registry, (*position), bTree->indexFile);
        }
    }
    if(!isRegistryUnderFlow(registry))
        (*position) = -1;
    free(registry);
    return hasFound;
}

/**
 * @brief 
 * 
 * @param bTree 
 * @param code 
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool removeBTree(BTree bTree, int code) {
    if(isEmptyBTree(bTree))
        return FALSE;
    int indexRoot = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    Registry *registry = readIndexRegistry(indexRoot, bTree->indexFile);
    if(registry->numberOfKeys == 1 && registry->key[0] == code && !isLeafBTree(registry)) {
        int nextRegistryPosition = registry->children[1];
        Registry *nextRegistry = readIndexRegistry(nextRegistryPosition, bTree->indexFile);
        free(registry);
        registry = nextRegistry;
        while(!isLeafBTree(registry)) {
            nextRegistryPosition = registry->children[0];
            nextRegistry = readIndexRegistry(nextRegistryPosition, bTree->indexFile);
            free(registry);
            registry = nextRegistry;
        }
        registry = readIndexRegistry(indexRoot, bTree->indexFile);
        registry->key[0] = nextRegistry->key[0];
        code = nextRegistry->key[0] = registry->key[0] + 1;
        swapIntegers(&registry->position[0], &nextRegistry->position[0]);
        writeIndexRegistry(registry, indexRoot, bTree->indexFile);
        writeIndexRegistry(nextRegistry, nextRegistryPosition, bTree->indexFile);
        free(nextRegistry);
    }
    free(registry);
    if(removeBTreeRec(bTree, &indexRoot, code)) {
        if(indexRoot != -1 && readIndexRegistryField(OFFSET_REGISTRY_NUM, indexRoot, bTree->indexFile) == 0) {
            int newIndexRoot = readIndexRegistryField(OFFSET_REGISTRY_CHILDS, indexRoot, bTree->indexFile);
            writeIndexHeadField(newIndexRoot, OFFSET_HEAD_INDEX, bTree->indexFile);
            removeIndexRegistry(indexRoot, bTree->indexFile);
        }
        return TRUE;
    }
    return FALSE;
}
