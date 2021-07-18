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