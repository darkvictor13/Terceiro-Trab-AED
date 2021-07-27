/**
 * @file data_file.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "data_file.h"

/**
 * @brief cria um arquivo para o armazenamento dos dados dos produtos
 * 
 * @param dataFilePath cadeia de carateres contendo o nome e endereco do arquivo a ser criado
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeDataFile(char *dataFilePath) {
    FILE *dataFile = fopen(dataFilePath, "w+b");
    DataHead head;
    head.regLast = 0;
    head.regFree = -1;
    writeDataHead(&head, dataFile);
    return dataFile;
}

/**
 * @brief 
 * 
 * @param head 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataHead(DataHead *head, FILE *dataFile) {
    fseek(dataFile, OFFSET_HEAD_DATA, SEEK_SET);
    fwrite(head, sizeof(DataHead), 1, dataFile);
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return DataHead* 
 * @pre Nenhuma
 * @post Nenhuma
 */
DataHead *readDataHead(FILE *dataFile) {
    DataHead *head = (DataHead*)malloc(sizeof(DataHead));
    fseek(dataFile, OFFSET_HEAD_DATA, SEEK_SET);
    fread(head, sizeof(DataHead), 1, dataFile);
    return head;
}

/**
 * @brief 
 * 
 * @param value 
 * @param offset 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataHeadField(int value, int offset, FILE *dataFile) {
    fseek(dataFile, offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

/**
 * @brief 
 * 
 * @param offset 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readDataHeadField(int offset, FILE *dataFile) {
    int value;
    fseek(dataFile, offset, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

/**
 * @brief 
 * 
 * @param product 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeDataRegistry(Product *product, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position, SEEK_SET);
    fwrite(product, sizeof(Product), 1, dataFile);
}

/**
 * @brief 
 * 
 * @param position 
 * @param dataFile 
 * @return Product* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Product *readDataRegistry(int position, FILE *dataFile) {
    Product *product = (Product*)malloc(sizeof(Product));
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position, SEEK_SET);
    fread(product, sizeof(Product), 1, dataFile);
    return product;
}

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
void writeDataRegistryField(int value, int offset, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position + offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

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
int readDataRegistryField(int offset, int position, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position + offset, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

/**
 * @brief 
 * 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void clearDataRegistry(int position, FILE *dataFile) {
    Product *product = (Product*)malloc(sizeof(Product));
    memset(product, 0, sizeof(Product));
    writeDataRegistry(product, position, dataFile);
}

/**
 * @brief 
 * 
 * @param product 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertDataRegistry(Product *product, FILE *dataFile) {
    int free = readDataHeadField(OFFSET_FREE_DATA, dataFile);
    if(free == -1) {
        int last;
        writeDataRegistry(
            product,
            (last = readDataHeadField(OFFSET_LAST_DATA, dataFile)),
            dataFile
        );
        writeDataHeadField(last + 1, OFFSET_LAST_DATA, dataFile);
        return last;
    }else{
        writeDataHeadField(
            readDataRegistryField(OFFSET_PRODUCT_CODE, free, dataFile),
            OFFSET_FREE_DATA,
            dataFile
        );
        writeDataRegistry(product, free, dataFile);
        return free;
    }
}

/**
 * @brief 
 * 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeDataRegistry(int position, FILE *dataFile) {
    clearDataRegistry(position, dataFile);
    writeDataRegistryField(
        readDataHeadField(
            OFFSET_FREE_DATA,
            dataFile
        ),
        OFFSET_PRODUCT_CODE,
        position,
        dataFile
    );
    writeDataHeadField(position, OFFSET_FREE_DATA, dataFile);
}
