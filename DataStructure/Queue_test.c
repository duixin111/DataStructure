#include"Queue.h"
#include<stdio.h>
#include <crtdbg.h>

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
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));

	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));

	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));


	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));

//	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	if (QueueEmpty(&q))
	{
		printf("EMPTY!!!\n");
	}
	else
	{
		printf("Error!!!\n");
	}

//	QueueDestroy(&q);
}