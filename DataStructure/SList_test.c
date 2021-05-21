#include<stdio.h>
#include <crtdbg.h>
#include"SList.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SListNode* head;
	SListInit(&head);
	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);

	PrintSList(head);

	SListInsert(SListFind(head, 2), 6);

	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);

	PrintSList(head);

	SListErase(SListFind(head, 2));
	PrintSList(head);
	SListDestory(&head);
	return 0;
}