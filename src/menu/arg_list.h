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

int isEmptyArgStack(ArgStack head);

ArgStack createStack();

void *readArgStack(ArgStack head);

void pushArgStack(ArgStack head, void *arg);

void *popArgStack(ArgStack head);

void freeArgStack(ArgStack head);

void freeArgStackRec(ArgNode *head);

void printArgStack(ArgStack head);

void printArgStackRec(ArgNode *head);

#endif