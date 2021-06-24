/**
 * @file index_file.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 24/06/2021
 */

#include "index_file.h"

/**
 * @brief Verifica se a arvore está vazia
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmpty(FILE *dataFile) {
    return readIndexHeadField(OFFSET_ROOT_INDEX, dataFile) == -1;
}

/**
 * @brief Escreve o cabeçalho do arquivo
 * 
 * @param head 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHead(IndexHead *head, FILE *dataFile) {
    fseek(dataFile, 0, SEEK_SET);
    fwrite(head, sizeof(IndexHead), 1, dataFile);
}

/**
 * @brief Lê o cabeçalho do arquivo
 * 
 * @param dataFile 
 * @return IndexHead* 
 * @pre Nenhuma
 * @post Nenhuma
 */
IndexHead *readIndexHead(FILE *dataFile) {
    IndexHead *head = (IndexHead*) malloc(sizeof(IndexHead));
    fseek(dataFile, 0, SEEK_SET);
    fread(head, sizeof(IndexHead), 1, dataFile);
    return head;
}

/**
 * @brief Escreve o um campo do cabeçalho do arquivo
 * 
 * @param value 
 * @param offset Offset para o campo do cabeçalho
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeIndexHeadField(int value, int offset, FILE *dataFile) {
    fseek(dataFile, sizeof(int) * offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

/**
 * @brief Lê o um campo do cabeçalho do arquivo
 * 
 * @param offset Offset para o campo do cabeçalho
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readIndexHeadField(int offset, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(int) * offset, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}