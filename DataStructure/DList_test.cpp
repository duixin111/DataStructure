#include<stdio.h>

#include"DList.h"
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Node* head = NULL;
	DListInit(&head);

	DListPushBack(head, 1);
	DListPushBack(head, 2);
	DListPushBack(head, 3);
	DListPushBack(head, 4);
	DListPushBack(head, 5);
	DListPushBack(head, 6);
	DListPrint(head);

	DListPushFront(head, 0);
	DListPrint(head);

	DListPopFront(head);
	DListPrint(head);

	DListPopBack(head);
	DListPopBack(head);
	DListPopBack(head);
	DListPrint(head);

	DListDestroy(&head);

}

