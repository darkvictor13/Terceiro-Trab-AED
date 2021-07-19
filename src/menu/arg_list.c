/**
 * @file arg_list.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "arg_list.h"

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyArgStack(ArgStack head) {
    return head->top == NULL;
}

/**
 * @brief Create a Stack object
 * 
 * @return ArgStack 
 * @pre Nenhuma
 * @post Nenhuma
 */
ArgStack createStack() {
    ArgStack newStack = (ArgStack)malloc(sizeof(ArgStackHead));
    newStack->top = NULL;
    return newStack;
}

/**
 * @brief 
 * 
 * @param head 
 * @return void* 
 * @pre Nenhuma
 * @post Nenhuma
 */
void *readArgStack(ArgStack head) {
    void *arg = NULL;
    if(!isEmptyArgStack(head)) {
        arg = (void*)malloc(sizeof(void));
        arg = head->top->arg;
    }
    return arg;
}

/**
 * @brief 
 * 
 * @param head 
 * @param arg 
 * @pre Nenhuma
 * @post Nenhuma
 */
void pushArgStack(ArgStack head, void *arg) {
    ArgNode* newArgNode = (ArgNode*)malloc(sizeof(ArgNode));
    newArgNode->arg = arg;
    newArgNode->next = head->top;
    head->top = newArgNode;

}

/**
 * @brief 
 * 
 * @param head 
 * @return void* 
 * @pre Nenhuma
 * @post Nenhuma
 */
void *popArgStack(ArgStack head) {
    void *arg = NULL;
    if(!isEmptyArgStack(head)) {
        arg = (void*)malloc(sizeof(void));
        ArgNode *auxArgNode = head->top;
        arg = head->top->arg;
        head->top = head->top->next;
        free(auxArgNode);
    }
    return arg;
}

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStack(ArgStack head) {
    
}

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStackRec(ArgNode *head) {
    
}

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printArgStack(ArgStack head) {
    
}

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printArgStackRec(ArgNode *head) {
    
}
