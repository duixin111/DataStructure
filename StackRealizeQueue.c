typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, DataType data);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);


void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 8);
	if (ps->array == NULL)
	{
		assert(0);
		return;
	}
	ps->capacity = 8;
	ps->size = 0;
}

void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		ps->array = (DataType*)realloc(ps->array, sizeof(DataType) * ((ps->capacity) << 1));
		if (ps->array == NULL)
		{
			assert(0);
			return;
		}
		(ps->capacity) <<= 1;
	}
	ps->array[ps->size++] = data;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))
		return;
	ps->size--;
}

DataType StackTop(Stack* ps)
{
	assert(ps && !StackEmpty(ps));
	return ps->array[(ps->size) - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}

typedef struct {
	Stack inStack;
	Stack outStack;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* _stack = (MyQueue*)malloc(sizeof(MyQueue));
	if (_stack == NULL)
		return NULL;
	StackInit(&_stack->inStack);
	StackInit(&_stack->outStack);

	return _stack;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->inStack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->outStack))
	{
		while (!StackEmpty(&obj->inStack))
		{
			StackPush(&obj->outStack, StackTop(&obj->inStack));
			StackPop(&obj->inStack);
		}
	}

	int x = StackTop(&obj->outStack);
	StackPop(&obj->outStack);

	return x;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->outStack))
	{
		while (!StackEmpty(&obj->inStack))
		{
			StackPush(&obj->outStack, StackTop(&obj->inStack));
			StackPop(&obj->inStack);
		}
	}

	return StackTop(&obj->outStack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {

	return StackEmpty(&obj->inStack) && StackEmpty(&obj->outStack);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->inStack);
	StackDestroy(&obj->outStack);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/