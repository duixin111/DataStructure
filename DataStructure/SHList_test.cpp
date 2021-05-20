
#include"SHList.h"
#include <crtdbg.h>
#include<stdio.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Node* head = NULL;
	SHListInit(&head);
	SHListPushBack(head, 1);
	SHListPushBack(head, 2);
	SHListPushBack(head, 3);
	SHListPushBack(head, 4);
	SHListPushBack(head, 5);
	SHListPushBack(head, 6);
	int SIZE = SHListSize(head);
	printf("%d\n", SIZE);
	SHListPrint(head);
	SHListPushFront(head, 7);
	SHListPushFront(head, 8);
	SHListPushFront(head, 9);
	SHListPushFront(head, 10);
	SIZE = SHListSize(head);
	printf("%d\n", SIZE);
	SHListPrint(head);
	SHListPopBack(head);
	SHListPopBack(head);
	SHListPopBack(head);
	SIZE = SHListSize(head);
	printf("%d\n", SIZE);
	SHListPrint(head);
	SHListPopFront(head);
	SHListPopFront(head);
	SHListPopFront(head);
	SHListPopFront(head);
	SIZE = SHListSize(head);
	printf("%d\n", SIZE);
	SHListPrint(head);
	SHListInsert(SHListFind(head, 3), 5);
	SHListPrint(head);
	SHListErase(SHListFind(head, 3));
	SHListPrint(head);
	SHListDestory(&head);

	return 0;
}