#include "queue.h"

int emptyQueue(Queue *queue) {
    return (queue->head == NULL);
}

Queue* createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = newQueue->tail = NULL;
    return newQueue;
}

QueueNode* allocQueueNode() {
    return (QueueNode *)malloc(sizeof(QueueNode));
}

int sizeQueue(Queue *queue) {
    return queue->size;
}

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
