#include<stdio.h>
#include <crtdbg.h>
#include"Stack.h"

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);

	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);

	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackDestroy(&s);


	return 0;
}