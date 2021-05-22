#include<stdio.h>
#include"Stack.h"
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

#define CAPACITY 3

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * CAPACITY);
	if (ps->array == NULL)
	{
		assert(0);
		return;
	}
	ps->capacity = CAPACITY;
	ps->size = 0;
}

void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		ps->array = (DataType*)realloc(ps->array, sizeof(DataType)*((ps->capacity) << 1));
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