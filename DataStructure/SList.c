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
//��ʼ������
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
		printf("����ʧ�ܣ�");
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
		//����Ϊ�գ��ҵ������е����һ���ڵ�
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
	//��Ϊ��
	if (*head == NULL)
		return;
	//����ֻ��һ���ڵ�
	else if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	//�����ж���ڵ�
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

