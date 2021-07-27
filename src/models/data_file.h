/**
 * @file data_file.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DATA_FILE_H
#define DATA_FILE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "product.h"

/**
 * @brief Cabeçalho do arquivo de dados
 */
typedef struct {
    int regLast;
    int regFree;
}DataHead;

/**
 * @brief acessos a elementos especificos da estrutura DataHead
 */
enum offsetHeadData {
    OFFSET_HEAD_DATA = 0,
	OFFSET_LAST_DATA = offsetof(DataHead, regLast),
	OFFSET_FREE_DATA = offsetof(DataHead, regFree)
};

/**
 * @brief acessos a elementos especificos da estrutura Product
 */
enum offsetProductData {
    OFFSET_PRODUCT_CODE = offsetof(Product, code),
    OFFSET_PRODUCT_NAME = offsetof(Product, name),
    OFFSET_PRODUCT_NUMBER = offsetof(Product, number),
    OFFSET_PRODUCT_VALUE = offsetof(Product, value),
    OFFSET_PRODUCT_LOCAL = offsetof(Product, local)
};

/**
 * @brief cria um arquivo para o armazenamento dos dados dos produtos
 * 
 * @param dataFilePath cadeia de carateres contendo o nome e endereco do arquivo a ser criado
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeDataFile(char *dataFilePath);

/**
 * @brief 
 * 
 * @param head 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataHead(DataHead *head, FILE *dataFile);

/**
 * @brief 
 * 
 * @param dataFile 
 * @return DataHead* 
 * @pre Nenhuma
 * @post Nenhuma
 */
DataHead *readDataHead(FILE *dataFile);

/**
 * @brief 
 * 
 * @param value 
 * @param offset 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataHeadField(int value, int offset, FILE *dataFile);

/**
 * @brief 
 * 
 * @param offset 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readDataHeadField(int offset, FILE *dataFile);

/**
 * @brief 
 * 
 * @param product 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataRegistry(Product *product, int position, FILE *dataFile);

/**
 * @brief 
 * 
 * @param position 
 * @param dataFile 
 * @return Product* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Product *readDataRegistry(int position, FILE *dataFile);

/**
 * @brief 
 * 
 * @param value 
 * @param offset 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataRegistryField(int value, int offset, int position, FILE *dataFile);

/**
 * @brief 
 * 
 * @param offset 
 * @param position 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readDataRegistryField(int offset, int position, FILE *dataFile);

/**
 * @brief 
 * 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void clearDataRegistry(int position, FILE *dataFile);

/**
 * @brief 
 * 
 * @param product 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertDataRegistry(Product *product, FILE *dataFile);

/**
 * @brief 
 * 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeDataRegistry(int position, FILE *dataFile);

#endif