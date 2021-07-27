/**
 * @file input_file.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INPUT_FILE_H
#define INPUT_FILE_H

#include <ctype.h>
#include <stdio.h>
#include "../models/b_tree.h"
#include "../models/product.h"
#include "../menu/print_menu.h"

/**
 * @brief Define o tamanho máximo para o caminho
 * do arquivo
 */
#define FILE_PATH_NAME 100

/**
 * @brief Define as operações possiveis de serem
 * feitas na arvore a partir do arquivo de entrada
 */
enum inputFileOperations {
    INPUT_FILE_INSERT = 'I',
    INPUT_FILE_MODIFY = 'A',
    INPUT_FILE_REMOVE = 'R',
};

/**
 * @brief realiza o carregamento dos dados a partir de um arquivo de entrada
 * 
 * @param inputPath cadeia de caraterres contendo o nome e o cominho do arquivo com os dados de entrada
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void loadInputFile(char *inputPath, BTree bTree);

/**
 * @brief realiza a insercao de um produto a partir de uma linha contendo os dados
 * 
 * @param line linha contendo os dados necessarios para a insercao
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertFromLine(char *line, BTree bTree);

/**
 * @brief modifica um produto existente no registro a partir dos dados especificados na linha
 * 
 * @param line linha contendo os dados a serem alterados na arvore
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void modifyFromLine(char *line, BTree bTree);

/**
 * @brief remove um produto da arvore b
 * 
 * @param line linha contendo o codigo do produto a ser removido da arvore
 * @param bTree a arvore em que serao alterados os dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeFromLine(char *line, BTree bTree);

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
void getFromLine(char *line, int *number, float *value, char *local);

/**
 * @brief percorre uma linha e retorna o conteudo desde o cameco ate o primeiro ponto e virgula
 * 
 * @param line linha de onde seraao lidos os caraters
 * @return char* enderco onde sera retornado o que foi lido
 * @pre Nenhuma
 * @post Nenhuma
 */
char *getInside(char *line);

/**
 * @brief cambia as virgulas por pontos numa linha
 * 
 * @param line linha a seer formatada
 * @pre Nenhuma
 * @post Nenhuma
 */
void formatLine(char *line);

/**
 * @brief elimina espacos exedentes na linha, tanto no comeco, no meio como no final
 * 
 * @param line linha a ser formatada
 * @return char* 
 * @pre Nenhuma
 * @post Nenhuma
 */
char *trim(char *line);

#endif
