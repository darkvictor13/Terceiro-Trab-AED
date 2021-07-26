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
 * @brief 
 * 
 * @param queue 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyQueue(Queue *queue) {
    return (queue->head == NULL);
}

/**
 * @brief Create a Queue object
 * 
 * @return Queue* 
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
 * @brief 
 * 
 * @return QueueNode* 
 * @pre Nenhuma
 * @post Nenhuma
 */
QueueNode* allocQueueNode() {
    return (QueueNode *)malloc(sizeof(QueueNode));
}

/**
 * @brief 
 * 
 * @param queue 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int sizeQueue(Queue *queue) {
    return queue->size;
}

/**
 * @brief 
 * 
 * @param queue 
 * @param position 
 * @param tabs 
 * @pre Nenhuma
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
 * @brief 
 * 
 * @param queue 
 * @return int 
 * @pre Nenhuma
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
