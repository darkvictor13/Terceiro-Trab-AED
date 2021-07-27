/**
 * @file queue.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "queue.h"

/**
 * @brief Informa se a fila está vazia
 * 
 * @param queue Uma fila válida
 * @return int (Booleano)
 * @pre uma fila válida
 * @post Nenhuma
 */
int emptyQueue(Queue *queue) {
    return (queue->head == NULL);
}

/**
 * @brief Cria a Queue
 * 
 * @return Queue* Ponteiro para a fila
 * @pre Nenhuma
 * @post Nenhuma
 */
Queue* createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = newQueue->tail = NULL;
    return newQueue;
}

/**
 * @brief Aloca o espaço de memória para uma
 * nova fila
 * 
 * @return QueueNode* Ponteiro para a fila
 * @pre Nenhuma
 * @post Nenhuma
 */
QueueNode* allocQueueNode() {
    return (QueueNode *)malloc(sizeof(QueueNode));
}

/**
 * @brief Retorna o tamanho da fila
 * 
 * @param queue Uma fila válida
 * @return int 
 * @pre uma fila válida
 * @post Nenhuma
 */
int sizeQueue(Queue *queue) {
    return queue->size;
}

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
void insertQueue(Queue *queue, int position, int tabs) {
    QueueNode *newTail = allocQueueNode();
    newTail->position = position;
    newTail->tabs = tabs;
    newTail->prox = NULL;
    if (emptyQueue(queue))
        queue->head = newTail;
    else
        queue->tail->prox = newTail;
    queue->size++;
    queue->tail = newTail;
}

/**
 * @brief Remove da fila um elemento da arvore B
 * 
 * @param queue Uma fila válida
 * @return int A posição em que o elemento estava na árvore
 * @pre uma fila válida
 * @post Nenhuma
 */
int removeQueue(Queue * queue) {
    QueueNode *head = queue->head;
    int position = head->position;
    if (head == queue->tail)
        queue->tail = NULL;
    queue->head = queue->head->prox;
    free(head);
    queue->size--;
    return position;
}
