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

int isEmptyArgStack(ArgStack head) {
    return head->top == NULL;
}

ArgStack createStack() {
    ArgStack newStack = (ArgStack)malloc(sizeof(ArgStackHead));
    newStack->top = NULL;
    return newStack;
}

void *readArgStack(ArgStack head) {
    void *arg = NULL;
    if(!isEmptyArgStack(head)) {
        arg = (void*)malloc(sizeof(void));
        arg = head->top->arg;
    }
    return arg;
}

void pushArgStack(ArgStack head, void *arg) {
    ArgNode* newArgNode = (ArgNode*)malloc(sizeof(ArgNode));
    newArgNode->arg = arg;
    newArgNode->next = head->top;
    head->top = newArgNode;

}

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

void freeArgStack(ArgStack head) {
    
}

void freeArgStackRec(ArgNode *head) {
    
}

void printArgStack(ArgStack head) {
    
}

void printArgStackRec(ArgNode *head) {
    
}
