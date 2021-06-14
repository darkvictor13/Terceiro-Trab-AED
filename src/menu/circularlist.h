/**
 * @file circularlist.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir todas as operações realizadas
 * sobre uma lista encadeada circular
 * @version 0.1
 * @date 14/06/2021
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa uma lista duplamente encadeada circular
 */
typedef struct node {
    int info;
    struct node *next;
    struct node *prev;
}List;

int isEmptyList(List *l);

List* allocNode();

List *insertAtEnd(List *head, int data);

void printList(List *head);
