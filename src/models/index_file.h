/**
 * @file index_file.h
 * @author Victor Emanuel Almeida
 * @brief 
 * @version 0.1
 * @date 24/06/2021
 */

#ifndef INDEX_FILE
#define INDEX_FILE

#include "product.h"
#include <stddef.h> /* offsetof */

#define ORDER 5

/**
 * @brief Estrutura de cabeçalho de um arquivo
 */
typedef struct {
    int regRoot;
    int regLast;
    int regFree;
}IndexHead;

/**
 * @brief Offsets para acessar determinados campos do cabeçalho
 */
enum offsetHeadIndex {
	OFFSET_ROOT_INDEX = offsetof(IndexHead, regRoot),
	OFFSET_LAST_INDEX = offsetof(IndexHead, regLast),
	OFFSET_FREE_INDEX = offsetof(IndexHead, regFree)
};

/**
 * @brief Estrutura que representa um único nó
 * da arvore binária implementada em arquivo
 */
typedef struct {
	int key[ORDER];
	int registers[ORDER];
	int children[ORDER];
}Registry;

/**
 * @brief Offsets para acessar determinados campos do nó do Product
 */
enum offsetRegistryIndex {
    OFFSET_REGISTRY_CODE = offsetof(Registry, key),
    OFFSET_REGISTRY_RIGHT = offsetof(Registry, registers),
    OFFSET_REGISTRY_LEFT = offsetof(Registry, children)
};

/**
 * @brief Verifica se a arvore está vazia
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmpty(FILE *dataFile);

/**
 * @brief Escreve o cabeçalho do arquivo
 * 
 * @param indexHead 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHead(IndexHead *indexHead, FILE *dataFile);

/**
 * @brief Lê o cabeçalho do arquivo
 * 
 * @param dataFile 
 * @return IndexHead* 
 * @pre Nenhuma
 * @post Nenhuma
 */
IndexHead *readIndexHead(FILE *dataFile);

/**
 * @brief Escreve o um campo do cabeçalho do arquivo
 * 
 * @param value 
 * @param offset Offset para o campo do cabeçalho
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHeadField(int value, int offset, FILE *dataFile);

/**
 * @brief Lê o um campo do cabeçalho do arquivo
 * 
 * @param offset Offset para o campo do cabeçalho
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readIndexHeadField(int offset, FILE *dataFile);

#endif