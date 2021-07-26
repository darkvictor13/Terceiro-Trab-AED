/**
 * @file index_file.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "index_file.h"

/**
 * @brief 
 * 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyIndex(FILE *indexFile) {
    return readIndexHeadField(OFFSET_ROOT_INDEX, indexFile) == -1;
}

/**
 * @brief 
 * 
 * @param indexFilePath 
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeIndexFile(char *indexFilePath) {
    FILE *indexFile = fopen(indexFilePath, "w+b");
    IndexHead head;
    head.regRoot = head.regFree = -1;
    head.regLast = 0;
    writeIndexHead(&head, indexFile);
    return indexFile;
}

/**
 * @brief Create a Registry object
 * 
 * @param key 
 * @param position 
 * @param leftChild 
 * @param rightChild 
 * @return Registry* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Registry *createRegistry(int key, int position, int leftChild, int rightChild) {
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    registry->key[0] = key;
    registry->position[0] = position;
    registry->children[0] = leftChild;
    registry->children[1] = rightChild;
    registry->numberOfKeys = 1;
    return registry;
}

/**
 * @brief Create a Registry Field object
 * 
 * @param key 
 * @param position 
 * @param leftChild 
 * @param rightChild 
 * @return RegistryField* 
 * @pre Nenhuma
 * @post Nenhuma
 */
RegistryField *createRegistryField(int key, int position, int leftChild, int rightChild) {
    RegistryField *registryField = (RegistryField*)malloc(sizeof(RegistryField));
    registryField->key = key;
    registryField->position = position;
    registryField->leftChild = leftChild;
    registryField->rightChild = rightChild;
    return registryField;
}

/**
 * @brief 
 * 
 * @param head 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHead(IndexHead *head, FILE *indexFile) {
    fseek(indexFile, OFFSET_HEAD_INDEX, SEEK_SET);
    fwrite(head, sizeof(IndexHead), 1, indexFile);
}

/**
 * @brief 
 * 
 * @param indexFile 
 * @return IndexHead* 
 * @pre Nenhuma
 * @post Nenhuma
 */
IndexHead *readIndexHead(FILE *indexFile) {
    IndexHead *head = (IndexHead*)malloc(sizeof(IndexHead));
    fseek(indexFile, OFFSET_HEAD_INDEX, SEEK_SET);
    fread(head, sizeof(IndexHead), 1, indexFile);
    return head;
}

/**
 * @brief 
 * 
 * @param value 
 * @param offset 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHeadField(int value, int offset, FILE *indexFile) {
    fseek(indexFile, offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, indexFile);
}

/**
 * @brief 
 * 
 * @param offset 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readIndexHeadField(int offset, FILE *indexFile) {
    int value;
    fseek(indexFile, offset, SEEK_SET);
    fread(&value, sizeof(int), 1, indexFile);
    return value;
}

/**
 * @brief 
 * 
 * @param registry 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexRegistry(Registry *registry, int position, FILE *indexFile) {
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position, SEEK_SET);
    fwrite(registry, sizeof(Registry), 1, indexFile);
}

/**
 * @brief 
 * 
 * @param position 
 * @param indexFile 
 * @return Registry* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Registry *readIndexRegistry(int position, FILE *indexFile) {
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position, SEEK_SET);
    fread(registry, sizeof(Registry), 1, indexFile);
    return registry;
}

/**
 * @brief 
 * 
 * @param value 
 * @param offset 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexRegistryField(int value, int offset, int position, FILE *indexFile) {
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position + offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, indexFile);
}

/**
 * @brief 
 * 
 * @param offset 
 * @param position 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readIndexRegistryField(int offset, int position, FILE *indexFile) {
    int value;
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position + offset, SEEK_SET);
    fread(&value, sizeof(int), 1, indexFile);
    return value;
}

/**
 * @brief 
 * 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void clearIndexRegistry(int position, FILE *indexFile) {
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    memset(registry, 0, sizeof(Registry));
    writeIndexRegistry(registry, position, indexFile);
}

/**
 * @brief 
 * 
 * @param registry 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertIndexRegistry(Registry *registry, FILE *indexFile) {
    int free = readIndexHeadField(OFFSET_FREE_INDEX, indexFile);
    if(free == -1) {
        int last;
        writeIndexRegistry(
            registry,
            (last = readIndexHeadField(OFFSET_LAST_INDEX, indexFile)),
            indexFile
        );
        writeIndexHeadField(last + 1, OFFSET_LAST_INDEX, indexFile);
        return last;
    }else{
        writeIndexHeadField(
            readIndexRegistryField(OFFSET_REGISTRY_NUM, free, indexFile),
            OFFSET_FREE_INDEX,
            indexFile
        );
        writeIndexRegistry(registry, free, indexFile);
        return free;
    }
}

/**
 * @brief 
 * 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeIndexRegistry(int position, FILE *indexFile) {
    clearIndexRegistry(position, indexFile);
    writeIndexRegistryField(
        readIndexHeadField(
            OFFSET_FREE_INDEX,
            indexFile
        ),
        OFFSET_REGISTRY_NUM,
        position,
        indexFile
    );
    writeIndexHeadField(position, OFFSET_FREE_INDEX, indexFile);
}
