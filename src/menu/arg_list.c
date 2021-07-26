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
 * @brief indica se uma lista de argumentos se encontra vacia ou nao
 * 
 * @param head cabeca da lista de argumentos
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyArgStack(ArgStack head) {
    return head->top == NULL;
}

/**
 * @brief crria uma nova lista de argumentos
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
 * @brief le um elemento da lista de argumentos sem remove-lo
 * 
 * @param head cabeca da lista de argumentos
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
 * @brief realiza a insercao de um novo elemento na lista de argumentos do programa
 * 
 * @param head cabeca da lista de argumentos
 * @param arg argumento a ser inserido na lista de argumentos
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
 * @brief realiza a leitura de um elemento na lista de argumentos e o remove dela
 * 
 * @param head cabeca da lista de argumentos
 * @return void* o argumento que foi extraido da lista
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
 * @brief realiza a liberacao do espaco de uma lista de argumentos
 * 
 * @param head cabeca da lista de argumentos
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStack(ArgStack head) {
    if(!isEmptyArgStack(head))
        freeArgStackRec(head->top);
}

/**
 * @brief realiza a liberacao recursiva do espaco dos nodos de uma lista de argumentos
 * 
 * @param head cabeca da lista de argumentos
 * @pre Nenhuma
 * @post Nenhuma
 */
void freeArgStackRec(ArgNode *head) {
    if(head == NULL)
        return;
    freeArgStackRec(head->next);
    free(head);
}
