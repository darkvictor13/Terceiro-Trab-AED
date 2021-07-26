/**
 * @file input_file.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "input_file.h"

/**
 * @brief realiza o carregamento dos dados a partir de um arquivo de entrada
 * 
 * @param inputPath cadeia de caraterres contendo o nome e o cominho do arquivo com os dados de entrada
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void loadInputFile(char *inputPath, BTree bTree) {
    FILE *inputFile = fopen(inputPath, "r");
    system(CLEAR);
    if (inputFile == NULL) {
        printWaitMenuWhitMessage("Arquivo de entrada nao encontrado.");
        return;
    }
    char *line = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    while(fgets(line, MAX_ENTRY_LINE, inputFile) != NULL) {
        line = trim(line);
        formatLine(line);
        switch(line[0]) {
            case INPUT_FILE_INSERT: insertFromLine(line, bTree);
                break;
            case INPUT_FILE_MODIFY: modifyFromLine(line, bTree);
                break;
            case INPUT_FILE_REMOVE: removeFromLine(line, bTree);
                break;
        }
    }
    printWaitMenuWhitMessage("Arquivo carregado com sucesso.");
    free(line);
    fclose(inputFile);
}

/**
 * @brief realiza a insercao de um produto a partir de uma linha contendo os dados
 * 
 * @param line linha contendo os dados necessarios para a insercao
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertFromLine(char *line, BTree bTree) {
    Product *product = (Product*)malloc(sizeof(Product));
    sscanf(line, "%*c;%d;%[^;];%d;%f;%[^\n]",
        &(product->code),
        product->name,
        &(product->number),
        &(product->value),
        product->local
    );
    int position;
    if(!searchBTreeByCode(bTree, product->code, &position))
        insertBTree(bTree, product);
    free(product);
}

/**
 * @brief modifica um produto existente no registro a partir dos dados especificados na linha
 * 
 * @param line linha contendo os dados a serem alterados na arvore
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void modifyFromLine(char *line, BTree bTree) {
    Product *product;
    int code, position;
    char *buffer = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    sscanf(line, "%*c;%d;%[^\n]", &code, line);
    if(!searchBTreeByCode(bTree, code, &position))
        return;
    product = readDataRegistry(position, bTree->dataFile);
    getFromLine(
        line,
        &product->number,
        &product->value,
        product->local
    );
    writeDataRegistry(product, position, bTree->dataFile);
    free(product);
}

/**
 * @brief remove um produto da arvore b
 * 
 * @param line linha contendo o codigo do produto a ser removido da arvore
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeFromLine(char *line, BTree bTree) {
    int code;
    sscanf(line, "%*c;%d", &code);
    removeBTree(bTree, code);
}

/**
 * @brief le os valores de numero em estoque, valor do produto e local onde se encontra a partir de uma linhha
 * 
 * @param line linha contendo os campos relativos ao numero em estoque, o valor do produto e o local onde se encontra
 * @param number endereco onde sera colocado o numero em estoque do produto
 * @param value endereco onde sera colocado o valor do produto
 * @param local endereco onde sera colocado o novo local do produto
 * @pre Nenhuma
 * @post Nenhuma
 */
void getFromLine(char *line, int *number, float *value, char *local) {
    char *buffer = getInside(line);
    if (buffer[0] != '\0')
        sscanf(buffer, "%d", number);
    line += (strlen(buffer) + 1);
    free(buffer);

    buffer = getInside(line);
    if (buffer[0] != '\0')
        sscanf(buffer, "%f", value);
    line += (strlen(buffer) + 1);
    free(buffer);

    if (line[0] != '\0')
        strcpy(local, line);
}

/**
 * @brief percorre uma linha e retorna o conteudo desde o cameco ate o primeiro ponto e virgula
 * 
 * @param line linha de onde seraao lidos os caraters
 * @return char* enderco onde sera retornado o que foi lido
 * @pre Nenhuma
 * @post Nenhuma
 */
char *getInside(char *line) {
    char *buffer = (char *)malloc(sizeof(char) * MAX_ENTRY_LINE);
    int i = 0;
    while(line[i] != ';' && line[i] != '\n' && line[i] != '\0') {
        buffer[i] = line[i];
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}

/**
 * @brief cambia as virgulas por pontos numa linha
 * 
 * @param line linha a seer formatada
 * @pre Nenhuma
 * @post Nenhuma
 */
void formatLine(char *line) {
    for(; *line; line++)
        if(*line == ',')
            *line = '.';
}

/**
 * @brief elimina espacos exedentes na linha, tanto no comeco, no meio como no final
 * 
 * @param line linha a ser formatada
 * @return char* 
 * @pre Nenhuma
 * @post Nenhuma
 */
char *trim(char *line) {
    char *newLine = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    int i_new;
    int i_old = 0;
    while(isspace(line[i_old])) {
        i_old++;
    }
    for(i_new = 0; line[i_old]; i_old++) {
        if (!((isspace(line[i_old]) && isspace(line[i_old - 1])) ||
              (isspace(line[i_old]) && isspace(line[i_old + 1])) ||
              (line[i_old + 1] == ';' && isspace(line[i_old])) ||
              (line[i_old - 1] == ';' && isspace(line[i_old]))
        )) {
            newLine[i_new++] = line[i_old];
        }
    }
    newLine[i_new] = 0;
    free(line);
    return newLine;
}
