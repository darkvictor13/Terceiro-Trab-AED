#include "index_file.h"

int isEmptyIndex(FILE *indexFile) {
    return readIndexHeadField(OFFSET_ROOT_INDEX, indexFile) == -1;
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