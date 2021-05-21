#include<stdio.h>
#include"SList.h"

#include"SList.h"

#include<assert.h>
#include<stdlib.h>


#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
//初始化链表
void SListInit(SListNode** head)
{
	assert(head);
	*head = NULL;
}

void SListDestory(SListNode** head)
{
	assert(head);
	SListNode* delNode = NULL;
	while (*head != NULL)
	{
		delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}
 
SListNode* BuySListNode(DataType data)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	if (node == NULL)
	{
		printf("开辟失败！");
		return NULL;
	}
	node->data = data;
	node->next = NULL;

	return node;
}

void SListPushBack(SListNode** head, DataType data)
{
	assert(head);
	if (*head == NULL)
		*head = BuySListNode(data);
	else
	{
		//链表不为空，找到链表中的最后一个节点
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = BuySListNode(data);
	}
}

void SListPopBack(SListNode** head)
{
	assert(head);
	//表为空
	if (*head == NULL)
		return;
	//表中只有一个节点
	else if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	//表中有多个节点
	else
	{
		SListNode* cur = *head;
		SListNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next = NULL;
	}
}

void SListPushFront(SListNode** head, DataType data)
{
	assert(head);
	SListNode* NewNode = BuySListNode(data);
	NewNode->next = *head;
	*head = NewNode;
}

void SListPopFront(SListNode** head)
{
	assert(head);
	SListNode* delNode = NULL;
	if (*head == NULL)
		return;

	delNode = *head;
	*head = delNode->next;
	free(delNode);
}

void SListInsert(SListNode* pos, DataType data)
{
	SListNode* NewNode = NULL;
	if (pos == NULL)
		return;
	NewNode = BuySListNode(data);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

void SListErase(SListNode* pos)
{
	SListNode* delNode;
	if (pos == NULL || pos->next == NULL)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

int SListSize(SListNode* head)
{
	int count = 0;
	SListNode* cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}

	return count;
}

SListNode* SListFind(SListNode* head, DataType data)
{
	SListNode* cur = head;
	while (cur)
	{
		if (data == cur->data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void PrintSList(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

