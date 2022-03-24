#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
	Item elem;
	struct QueueNode *next;
}QueueNode;

typedef QueueNode TcelQ;
typedef QueueNode *ACelQ;

typedef struct Queue{
	QueueNode *front;
	QueueNode *rear;
	long size;
}Queue;

typedef Queue TCoada;
typedef Queue *AQ;


Queue* createQueue(void){
	// TODO: Cerinta 2

	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;

	return q;

} 

int isQueueEmpty(Queue *q){
	// TODO: Cerinta 2
	if (q->front == NULL)
		return 1;
	return 0;
}

void enqueue(Queue *q, Item elem){
	// TODO: Cerinta 2

	QueueNode* nod = (QueueNode*)malloc(sizeof(QueueNode));
	nod->next = NULL;
	nod->elem = elem;

	if (q->front == NULL && q->rear == NULL) {
		q->front = nod;
		q->rear = q->front;
		q->size++;
		return;
	}

	q->rear->next = nod;
	q->rear = nod;
	q->size++;
	return;

}

Item front(Queue* q){
	// TODO: Cerinta 2
	return q->front->elem;
}

void dequeue(Queue* q){
	// TODO: Cerinta 2

	//scot prin front
	if (isQueueEmpty(q))
		return;

	QueueNode* nod = q->front;
	if (q->front == q->rear) {
		q->front = q->rear = NULL;
		q->size--;
		free(nod);
		return;
	}

	q->front = q->front->next;
	free(nod);
	q->size--;
	return;

}

void destroyQueue(Queue *q){
	// TODO: Cerinta 2

	while (!isQueueEmpty(q)) {
		dequeue(q);
	}
	free(q);
}

#endif
