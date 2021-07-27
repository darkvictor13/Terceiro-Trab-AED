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

/**
 * @brief Ordem da árvore B
 */
#define ORDER 5 // greater than or equal to 5

/**
 * @brief Cabeçalho do arquivo de índices
 */
typedef struct {
    int regRoot;
    int regLast;
    int regFree;
}IndexHead;

/**
 * @brief acessos a elementos especificos da estrutura IndexHead
 */
enum offsetHeadIndex {
    OFFSET_HEAD_INDEX = 0,
	OFFSET_ROOT_INDEX = offsetof(IndexHead, regRoot),
	OFFSET_LAST_INDEX = offsetof(IndexHead, regLast),
	OFFSET_FREE_INDEX = offsetof(IndexHead, regFree)
};

/**
 * @brief Um elemento de um registro com seus filhos
 * no arquivo de índices
 */
typedef struct {
    int key;
    int position;
    int leftChild;
    int rightChild;
}RegistryField;

/**
 * @brief Registro de elementos da árvore B
 */
typedef struct {
    int numberOfKeys;
	int key[ORDER - 1];
	int position[ORDER - 1];
	int children[ORDER];
}Registry;

/**
 * @brief acessos a elementos especificos da estrutura Registry
 */
enum offsetRegistryIndex {
    OFFSET_REGISTRY_NUM = offsetof(Registry, numberOfKeys),
    OFFSET_REGISTRY_KEYS = offsetof(Registry, key),
    OFFSET_REGISTRY_POS = offsetof(Registry, position),
    OFFSET_REGISTRY_CHILDS = offsetof(Registry, children)
};

/**
 * @brief 
 * 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyIndex(FILE *indexFile);

/**
 * @brief 
 * 
 * @param indexFilePath 
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeIndexFile(char *indexFilePath);

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
Registry *createRegistry(int key, int position, int leftChild, int rightChild);

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
RegistryField *createRegistryField(int key, int position, int leftChild, int rightChild);

/**
 * @brief 
 * 
 * @param head 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHead(IndexHead *head, FILE *indexFile);

/**
 * @brief 
 * 
 * @param indexFile 
 * @return IndexHead* 
 * @pre Nenhuma
 * @post Nenhuma
 */
IndexHead *readIndexHead(FILE *indexFile);

/**
 * @brief 
 * 
 * @param value 
 * @param offset 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHeadField(int value, int offset, FILE *indexFile);

/**
 * @brief 
 * 
 * @param offset 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readIndexHeadField(int offset, FILE *indexFile);

/**
 * @brief 
 * 
 * @param registry 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexRegistry(Registry *registry, int position, FILE *indexFile);

/**
 * @brief 
 * 
 * @param position 
 * @param indexFile 
 * @return Registry* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Registry *readIndexRegistry(int position, FILE *indexFile);

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
void writeIndexRegistryField(int value, int offset, int position, FILE *indexFile);

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
int readIndexRegistryField(int offset, int position, FILE *indexFile);

/**
 * @brief 
 * 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void clearIndexRegistry(int position, FILE *indexFile);

/**
 * @brief 
 * 
 * @param registry 
 * @param indexFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertIndexRegistry(Registry *registry, FILE *indexFile);

/**
 * @brief 
 * 
 * @param position 
 * @param indexFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeIndexRegistry(int position, FILE *indexFile);

#endif