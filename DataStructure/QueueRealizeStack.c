typedef char* DataType;
typedef struct QNode
{
	struct QNode* next;
	DataType data;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* back;
}Queue;

QNode* BuyQueueNode(DataType data);
void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);


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
		delNode = q->front;
	}
	q->back = q->front = NULL;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&ms->q1);
	QueueInit(&ms->q2);

	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret;
	if (!QueueEmpty(&obj->q1))
	{
		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		ret = QueueFront(&obj->q1);
		QueuePop(&obj->q1);
	}
	else
	{
		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		ret = QueueFront(&obj->q2);
		QueuePop(&obj->q2);
	}

	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/