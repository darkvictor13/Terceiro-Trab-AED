/**
 * @file arg_list.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ARG_LIST_H
#define ARG_LIST_H

#include "menu_defines.h"

/**
 * @brief indica se uma lista de argumentos se encontra vacia ou nao
 * 
 * @param head cabeca da lista de argumentos
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyArgStack(ArgStack head);

/**
 * @brief crria uma nova lista de argumentos
 * 
 * @return ArgStack 
 * @pre Nenhuma
 * @post Nenhuma
 */
ArgStack createStack();

/**
 * @brief le um elemento da lista de argumentos sem remove-lo
 * 
 * @param head cabeca da lista de argumentos
 * @return void* 
 * @pre Nenhuma
 * @post Nenhuma
 */
void *readArgStack(ArgStack head);

/**
 * @brief realiza a insercao de um novo elemento na lista de argumentos do programa
 * 
 * @param head cabeca da lista de argumentos
 * @param arg argumento a ser inserido na lista de argumentos
 * @pre Nenhuma
 * @post Nenhuma
 */
void pushArgStack(ArgStack head, void *arg);

/**
 * @brief realiza a leitura de um elemento na lista de argumentos e o remove dela
 * 
 * @param head cabeca da lista de argumentos
 * @return void* o argumento que foi extraido da lista
 * @pre Nenhuma
 * @post Nenhuma
 */
void *popArgStack(ArgStack head);

/**
 * @brief realiza a liberacao do espaco de uma lista de argumentos
 * 
 * @param head cabeca da lista de argumentos
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStack(ArgStack head);

/**
 * @brief realiza a liberacao recursiva do espaco dos nodos de uma lista de argumentos
 * 
 * @param head cabeca da lista de argumentos
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStackRec(ArgNode *head);

#endif