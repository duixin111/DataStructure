#pragma once
#include<stdbool.h>
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
