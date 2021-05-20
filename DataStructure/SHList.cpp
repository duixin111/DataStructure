#include"SHList.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
Node* BuySHListNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		exit(0);
		return 0;
	}
	node->next = NULL;
	node->data = data;

	return node;
}

void SHListInit(Node** head)
{
	assert(head);
	*head = BuySHListNode(0);
}

void SHListPushBack(Node* head, DataType data)
{
	assert(head);
	Node* cur = head;
	while (cur->next)
		cur = cur->next;
	cur->next = BuySHListNode(data);
}

void SHListPopBack(Node* head)
{
	assert(head);
	Node* cur = NULL;
	Node* prev = NULL;
	if (head->next == NULL)
		return;
	cur = head->next;
	prev = head;

	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}

	free(cur);
	prev->next = NULL;
}

void SHListPushFront(Node* head, DataType data)
{
	assert(head);
	if (head == NULL)
		return;
	Node* cur = BuySHListNode(data);
	cur->next = head->next;
	head->next = cur;
}

void SHListPopFront(Node* head)
{
	assert(head);
	if (head==NULL ||head->next == NULL)
		return;
	Node* cur = head->next;
	head->next = head->next->next;
	free(cur);
}

void SHListInsert(Node* pos, DataType data)
{
	if (pos == NULL)
		return;
	Node* NewNode = BuySHListNode(data);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

void SHListErase(Node* pos)
{
	if (pos == NULL || pos->next == NULL)
		return;
	Node* delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

Node* SHListFind(Node* head, DataType data)
{
	assert(head);
	Node* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
int SHListSize(Node* head)
{
	assert(head);
	Node* cur = head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

void SHListDestory(Node** head)
{
	assert(head);
	Node* delNode = NULL;
	while (*head != NULL)
	{
		delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}

void SHListPrint(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

