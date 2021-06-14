#ifndef DEFINE_MENU_H
#define DEFINE_MENU_H

/**
 * @file definemenu.h
 * @author Victor Emanuel Almeida 
 * @brief Arquivo responsável por definir todas as constantes necessárias
 * para o funcionamento do menu, bem como o que é um menu
 * @version 0.1
 * @date 13/06/2021
 */

#include <stdio.h>

#ifdef __gnu_linux__

/**
 * @brief Indica qual o valor ascii da tecla enter no sistema operacional Linux
 */
#define ENTER 10

/**
 * @brief Indica qual o comando para "limpar a tela" no sistema operacional Linux
 */
#define CLEAR "clear"

#else //__gnu_linux__

/**
 * @brief Indica qual o valor ascii da tecla enter no sistema operacional Windows
 */
#define ENTER 13

/**
 * @brief Indica qual o comando para "limpar a tela" no sistema operacional Windows
 */
#define CLEAR "cls"

#endif //__gnu_linux__

/**
 * @brief Define o tamanho máximo da mensagem impressa no menu
 */
#ifndef MESSAGE_SIZE
#define MESSAGE_SIZE 101
#endif //MESSAGE_SIZE

/**
 * @brief Define a quantidade de caracteres antes da mensagem
 * somado aos 2 "pipes" (|)
 */
#define SELECT_SIZE 7

/**
 * @brief Define o tamanho de uma linha do menu
 */
#define SIZE_LINE MESSAGE_SIZE + SELECT_SIZE

/**
 * @brief Indica qual tecla quando pressionada move a opção selecionada
 * uma para cima
 */
#define UP 'w'

/**
 * @brief Indica qual tecla quando pressionada move a opção selecionada
 * uma para baixo
 */
#define DOWN 's'

/**
 * @brief Ponteiro para uma função chamada pelo menu
 */
typedef int CallbackFunct(FILE *dataFile);

/**
 * @brief Ponteiro para uma função que imprime um header
 */
typedef void HeaderFunct();

/**
 * @brief Ponteiro para uma função que imprime um footer
 */
typedef void FooterFunct();

/**
 * @brief Estrutura nó para os itens da fila entryQueue dentro do Menu
 */
typedef struct entryNode {
	char entryMessage[MESSAGE_SIZE];
    CallbackFunct *funct;
	struct entryNode * prox;
}EntryNode;

/**
 * @brief Estrutura para fila, implementada como uma
 * lista encadeada com cabeça e cauda
 */
typedef struct entryQueue{
    int size;
    struct entryNode *head;
    struct entryNode *tail;
}EntryQueue;

/**
 * @brief estrutura para fila de itens do menu
 */
typedef struct {
    int options;
    int thisOption;
    FooterFunct *footer;
    HeaderFunct *header;
    struct entryQueue *queue;
}Menu;

#endif //DEFINE_MENU_H