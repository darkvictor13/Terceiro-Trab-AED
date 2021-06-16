#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

/**
 * @file circularlist.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir todas as operações realizadas
 * sobre uma lista encadeada circular
 * @version 0.1
 * @date 14/06/2021
 */

#include "definemenu.h"
#include <string.h>

enum {MOVE_BACKWARD, MOVE_FOWARD};

int isEmptyList(List *head);

List* allocNode();

List *insertAtEnd(List *head, int number, char *message, CallbackFunct *funct);

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
int isInLimits(List *head, int number);

void printList(List *head);

List *moveTo(List *item, int qnt, int side);

#endif