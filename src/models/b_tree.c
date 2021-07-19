#include "b_tree.h"

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

void closeBTreeFiles(BTree bTree) {
    fclose(bTree->indexFile);
    fclose(bTree->dataFile);
    free(bTree);
}

Registry *createRegistry(int key, int position, int leftChild, int rightChild) {
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    registry->key[0] = key;
    registry->position[0] = position;
    registry->children[0] = leftChild;
    registry->children[1] = rightChild;
    registry->numberOfKeys = 1;
    return registry;
}

Bool isEmptyBTree(BTree bTree) {
    return isEmptyIndex(bTree->indexFile);
}

Bool isLeafBTree(Registry *registry) {
    return (registry->children[0] == -1);
}

Bool isRegistryFull(Registry *registry) {
    return (registry->numberOfKeys == ORDER - 1);
}

Bool searchBTreeByCodeRec(BTree bTree, int registryPosition, int key, int *position) {
    Registry *registry = readIndexRegistry(registryPosition, bTree->indexFile);
    if(searchPositionBTRee(registry, key, position)) {
        free(registry);
        return TRUE;
    }else if(isLeafBTree(registry)) {
        free(registry);
        return FALSE;
    }
    registryPosition = registry->position[(*position)];
    free(registry);
    return searchBTreeByCodeRec(bTree, registryPosition, key, position);
}

Bool searchBTreeByCode(BTree bTree, int key, int *position) {
    int indexRoot = readIndexHeadField(OFFSET_HEAD_INDEX, bTree->indexFile);
    if(indexRoot == -1)
        return FALSE;
    return searchBTreeByCodeRec(bTree, indexRoot, key, position);
}

#if(ORDER < 10)
Bool searchPositionBTRee(Registry *registry, int key, int *position) {
    for((*position) = 0; (*position) < registry->numberOfKeys; (*position)++)
        if(key == registry->key[(*position)])
            return TRUE;
        else if(key < registry->key[(*position)])
            break;
    return FALSE;
}
#else
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
    registry->numberOfKeys++;
}

RegistryField *splitAddBTree(BTree bTree, Registry *registry, int position, RegistryField *registryField) {
    RegistryField *promotedRegistry = (RegistryField*)malloc(sizeof(RegistryField));
    Registry *newRegistry = (Registry*)malloc(sizeof(Registry));
    int middle = registry->numberOfKeys / 2;
    newRegistry->numberOfKeys = registry->numberOfKeys - middle - 1;
    registry->numberOfKeys = middle;
    promotedRegistry->key = registry->key[middle];
    promotedRegistry->position = registry->position[middle];
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

RegistryField *insertBTreeRec(BTree bTree, int position, Product *product) {
    Registry *registry = readIndexRegistry(position, bTree->indexFile);
    if(isLeafBTree(registry)) {
        RegistryField *registryField = (RegistryField*)malloc(sizeof(RegistryField));
        registryField->key = product->code;
        registryField->position = insertDataRegistry(product, bTree->dataFile);
        registryField->leftChild = -1;
        registryField->rightChild = -1;
        if(isRegistryFull(registry)) {
            return splitAddBTree(bTree, registry, position, registryField);
        }else{
            simpleAddBTree(registry, registryField);
            writeIndexRegistry(registry, position, bTree->indexFile);
            free(registry);
            return NULL;
        }
    }else{
        searchPositionBTRee(registry, product->code, &position);
        int registryPosition = registry->position[position];
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

Product *getBTreeProduct(BTree bTree, int position) {
    return readDataRegistry(position, bTree->dataFile);
}

void updateBTreeProduct(BTree bTree, int position, Product *product) {
    writeDataRegistry(product, position, bTree->dataFile);
}

Bool removeBTreeRec(BTree bTree, int code) {

}

Bool removeBTree(BTree bTree, int code) {

}
