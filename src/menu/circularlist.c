/**
 * @file circularlist.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir todas as operações realizadas
 * sobre uma lista encadeada circular
 * @version 0.1
 * @date 14/06/2021
 */

#include "circularlist.h"

/**
 * @brief 
 * 
 * @param l 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyList(List *l) {
    return l == NULL;
}

List* allocNode() {
    return (List*)malloc(sizeof(List));
}

List *insertAtEnd(List *head, int number, char *message, CallbackFunct *funct) {
    printf("Adicionando elemento %d\n", number);
    List *new_node = allocNode();
    new_node->number = number;
    new_node->funct = funct;
    strcpy(new_node->entryMessage, message);

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

/**
 * @brief Verifica se o número passado como argumento
 * está dentro dos limites da lista
 * 
 * @param head ponteiro para o inicio da lista
 * @param number número a ser analisado
 * @return int booleano
 * 
 * Verdadeiro quando o número está dentro dos limites;
 * Falso quando o número está fora dos limites;
 * @pre Lista carregada
 * @post Nenhuma
 */
int isInLimits(List *head, int number) {
    return number > 0 && number <= head->prev->number;
}

List *moveTo(List *item, int qnt, int side) {
    if (side == MOVE_FOWARD) {
        while(qnt--) item = item->next;
    }
    else {
        while(qnt--) item = item->prev;
    }
}

void printList(List *head) {
    /*
    List *p = head;
    for(; p->next != head; p = p->next) {
        printf("%d, ", p->info);
    }
    printf("%d\n", p->info);
    */
}
