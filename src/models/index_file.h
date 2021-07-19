/**
 * @file index_file.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INDEX_FILE_H
#define INDEX_FILE

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ORDER 5 // greater than or equal to 5

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
    int key;
    int position;
    int leftChild;
    int rightChild;
}RegistryField;

typedef struct {
    int numberOfKeys;
	int key[ORDER - 1];
	int position[ORDER - 1];
	int children[ORDER];
}Registry;

enum offsetRegistryIndex {
    OFFSET_REGISTRY_NUM = offsetof(Registry, numberOfKeys),
    OFFSET_REGISTRY_KEYS = offsetof(Registry, key),
    OFFSET_REGISTRY_POS = offsetof(Registry, position),
    OFFSET_REGISTRY_CHILDS = offsetof(Registry, children)
};

int isEmptyIndex(FILE *indexFile);

FILE *makeIndexFile(char *indexFilePath);

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