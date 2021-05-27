#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

QNode* BuyQueueNode(DataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		assert(0);
		return NULL;
	}
	node->data = data;
	node->next = NULL;

	return node;
}

void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->back = NULL;
}

void QueuePush(Queue* q, DataType data)
{
	assert(q);
	QNode* cur = BuyQueueNode(data);
	if (QueueEmpty(q))
	{
		q->front = q->back = cur;
	}
	else
	{
		q->back->next = cur;
		q->back = cur;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
		return;
	QNode* delNode = q->front->next;
	if (delNode == NULL) 
	{
		free(q->front);
		q->front = q->back = NULL;
	}
	else
	{
		free(q->front);
		q->front = delNode;
	}
	
}

DataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}

DataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->back->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* cur = q->front;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* delNode = q->front;
	while (delNode)
	{
		q->front = delNode->next;
		free(delNode);
		delNode = delNode->next;
	}
	q->back = q->front = NULL;
}