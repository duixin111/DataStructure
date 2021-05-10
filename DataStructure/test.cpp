#define _CRTDBG_MAP_ALLOC

#include<stdio.h>
#include <crtdbg.h>
#include"SeqList.h"

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SeqList s;
	SeqListInit(&s, 1);
	SeqListPrint(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	//SeqListDestroy(&s);

	return 0;
}
