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

int emptyQueue(Queue *queue);

Queue* createQueue();

QueueNode* allocQueueNode();

int sizeQueue(Queue *queue);

void insertQueue(Queue *queue, int position, int tabs);

int removeQueue(Queue *queue);

#endif