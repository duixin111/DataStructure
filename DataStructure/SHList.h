#pragma once

typedef int DataType;

typedef struct SHListNode
{
	struct SHListNode* next;
	DataType data;
}Node;

Node* BuySHListNode(DataType data);
void SHListInit(Node** head);
void SHListPushBack(Node* head, DataType data);
void SHListPopBack(Node* head);
void SHListPushFront(Node* head, DataType data);
void SHListPopFront(Node* head);
void SHListInsert(Node* pos, DataType data);
void SHListErase(Node* pos);
Node* SHListFind(Node* head, DataType data);
int SHListSize(Node* head);
void SHListDestory(Node** head);

void SHListPrint(Node* head);

