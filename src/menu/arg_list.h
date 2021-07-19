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
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyArgStack(ArgStack head);

/**
 * @brief Create a Stack object
 * 
 * @return ArgStack 
 * @pre Nenhuma
 * @post Nenhuma
 */
ArgStack createStack();

/**
 * @brief 
 * 
 * @param head 
 * @return void* 
 * @pre Nenhuma
 * @post Nenhuma
 */
void *readArgStack(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @param arg 
 * @pre Nenhuma
 * @post Nenhuma
 */
void pushArgStack(ArgStack head, void *arg);

/**
 * @brief 
 * 
 * @param head 
 * @return void* 
 * @pre Nenhuma
 * @post Nenhuma
 */
void *popArgStack(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStack(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStackRec(ArgNode *head);

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printArgStack(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printArgStackRec(ArgNode *head);

#endif