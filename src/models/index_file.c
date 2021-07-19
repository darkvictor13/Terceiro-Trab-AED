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

int isEmptyIndex(FILE *indexFile) {
    return readIndexHeadField(OFFSET_ROOT_INDEX, indexFile) == -1;
}

FILE *makeIndexFile(char *indexFilePath) {
    FILE *indexFile = fopen(indexFilePath, "w+b");
    IndexHead head;
    head.regRoot = head.regFree = -1;
    head.regLast = 0;
    writeIndexHead(&head, indexFile);
    return indexFile;
}

void writeIndexHead(IndexHead *head, FILE *indexFile) {
    fseek(indexFile, OFFSET_HEAD_INDEX, SEEK_SET);
    fwrite(head, sizeof(IndexHead), 1, indexFile);
}

IndexHead *readIndexHead(FILE *indexFile) {
    IndexHead *head = (IndexHead*)malloc(sizeof(IndexHead));
    fseek(indexFile, OFFSET_HEAD_INDEX, SEEK_SET);
    fread(head, sizeof(IndexHead), 1, indexFile);
    return head;
}

void writeIndexHeadField(int value, int offset, FILE *indexFile) {
    fseek(indexFile, offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, indexFile);
}

int readIndexHeadField(int offset, FILE *indexFile) {
    int value;
    fseek(indexFile, offset, SEEK_SET);
    fread(&value, sizeof(int), 1, indexFile);
    return value;
}

void writeIndexRegistry(Registry *registry, int position, FILE *indexFile) {
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position, SEEK_SET);
    fwrite(registry, sizeof(Registry), 1, indexFile);
}

Registry *readIndexRegistry(int position, FILE *indexFile) {
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position, SEEK_SET);
    fread(registry, sizeof(Registry), 1, indexFile);
    return registry;
}

void writeIndexRegistryField(int value, int offset, int position, FILE *indexFile) {
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position + offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, indexFile);
}

int readIndexRegistryField(int offset, int position, FILE *indexFile) {
    int value;
    fseek(indexFile, sizeof(IndexHead) + sizeof(Registry) * position + offset, SEEK_SET);
    fread(&value, sizeof(int), 1, indexFile);
    return value;
}

void clearIndexRegistry(int position, FILE *indexFile) {
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    memset(registry, 0, sizeof(Registry));
    writeIndexRegistry(registry, position, indexFile);
}

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
