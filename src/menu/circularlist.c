/**
 * @file circularlist.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir todas as operações realizadas
 * sobre uma lista encadeada circular
 * @version 0.1
 * @date 14/06/2021
 */

#include "circularlist.h"

int isEmptyList(List *l) {
    return l == NULL;
}

List* allocNode() {
    return (List*)malloc(sizeof(List));
}

List *insertAtEnd(List *head, int data) {
    List *new_node = allocNode();
    new_node->info = data;
    if (isEmptyList(head)) {
        new_node->prev = new_node->next = new_node;
        return new_node;
    }
    new_node->next = head;
    new_node->prev = head->prev;

    head->prev->next = new_node;
    head->prev = new_node;

    return head;
}

void printList(List *head) {
    List *p = head;
    for(; p->next != head; p = p->next) {
        printf("%d, ", p->info);
    }
    printf("%d\n", p->info);
}
