/**
 * @file queue.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef QUEUE
#define QUEUE

#include <stdlib.h>

typedef struct queueNode {
	int position;
    int tabs;
	struct queueNode * prox;
}QueueNode;

typedef struct {
    int size;
    struct queueNode *head;
    struct queueNode *tail;
}Queue;

/**
 * @brief Informa se a fila está vazia
 * 
 * @param queue Uma fila válida
 * @return int (Booleano)
 * @pre uma fila válida
 * @post Nenhuma
 */
int emptyQueue(Queue *queue);

/**
 * @brief Cria a Queue
 * 
 * @return Queue* Ponteiro para a fila
 * @pre Nenhuma
 * @post Nenhuma
 */
Queue* createQueue();

/**
 * @brief Aloca o espaço de memória para uma
 * nova fila
 * 
 * @return QueueNode* Ponteiro para a fila
 * @pre Nenhuma
 * @post Nenhuma
 */
QueueNode* allocQueueNode();

/**
 * @brief Retorna o tamanho da fila
 * 
 * @param queue Uma fila válida
 * @return int 
 * @pre uma fila válida
 * @post Nenhuma
 */
int sizeQueue(Queue *queue);

/**
 * @brief Insere na fila um elemento da arvore B
 * 
 * @param queue Uma fila válida
 * @param position Qual a posição do elemento no arquivo
 * @param tabs Espacamentos equivalentes ao nível
 * em que o elemento estava na árvore
 * @pre uma fila válida
 * @post Nenhuma
 */
void insertQueue(Queue *queue, int position, int tabs);

/**
 * @brief Remove da fila um elemento da arvore B
 * 
 * @param queue Uma fila válida
 * @return int A posição em que o elemento estava na árvore
 * @pre uma fila válida
 * @post Nenhuma
 */
int removeQueue(Queue * queue);

#endif