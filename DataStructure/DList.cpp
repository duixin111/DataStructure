#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"DList.h"
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
Node* BuyDListNode(DataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;

	return NewNode;
}

void DListInit(Node** head)
{
	assert(head);
	*head = BuyDListNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DListPushFront(Node* head, DataType data)
{
	assert(head);
	DListInsert(head->next, data);
}

void DListPopFront(Node* head)
{
	assert(head);
	DListErase(head->next);
}

void DListPushBack(Node* head, DataType data)
{
	assert(head);
	DListInsert(head->prev, data);
}

void DListPopBack(Node* head)
{
	assert(head);
	DListErase(head->prev);
}

void DListInsert(Node* pos, DataType data)
{
	if (pos == NULL)
		return;
	Node* NewNode = BuyDListNode(data);
	NewNode->prev = pos->prev;
	NewNode->next = pos;
	NewNode->prev->next = NewNode;
	pos->prev = NewNode;
}

void DListErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

Node* DListFind(Node* head, DataType data)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		if (cur->data != data)
			cur = cur->next;
		return cur;
	}
	return NULL;
}

int DListSize(Node* head)
{
	assert(head);
	Node* cur = head->next;
	int Size = 0;
	while (cur != head)
	{
		Size++;
		cur = cur->next;
	}
	return Size;
}

void DListDestroy(Node** head)
{
	assert(head);
	Node* cur = (*head)->next;
	while (cur != (*head))
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}

	free(*head);
	*head = NULL;
}

void DListPrint(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}