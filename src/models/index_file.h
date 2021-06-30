#ifndef INDEX_FILE_H
#define INDEX_FILE

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ORDER 5

typedef struct {
    int regRoot;
    int regLast;
    int regFree;
}IndexHead;

enum offsetHeadIndex {
    OFFSET_HEAD_INDEX = 0,
	OFFSET_ROOT_INDEX = offsetof(IndexHead, regRoot),
	OFFSET_LAST_INDEX = offsetof(IndexHead, regLast),
	OFFSET_FREE_INDEX = offsetof(IndexHead, regFree)
};

typedef struct {
	int key[ORDER];
	int registers[ORDER];
	int children[ORDER];
}Registry;

enum offsetRegistryIndex {
    OFFSET_REGISTRY_KEYS = offsetof(Registry, key),
    OFFSET_REGISTRY_REGS = offsetof(Registry, registers),
    OFFSET_REGISTRY_CHILDS = offsetof(Registry, children)
};

int isEmptyIndex(FILE *indexFile);

void writeIndexHead(IndexHead *indexHead, FILE *indexFile);

IndexHead *readIndexHead(FILE *indexFile);

void writeIndexHeadField(int value, int offset, FILE *indexFile);

int readIndexHeadField(int offset, FILE *indexFile);

void writeIndexRegistry(Registry *registry, int position, FILE *indexFile);

Registry* readIndexRegistry(int position, FILE *indexFile);

void writeIndexRegistryField(int value, int offset, int position, FILE *indexFile);

int readIndexRegistryField(int offset, int position, FILE *indexFile);

void clearIndexRegistry(int position, FILE *indexFile);

int insertIndexRegistry(Registry *registry, FILE *indexFile);

void removeIndexRegistry(int position, FILE *indexFile);

#endif