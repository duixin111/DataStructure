#pragma once

typedef int DataType;
typedef struct DListNode
{
	struct DListNode* next;
	struct DListNode* prev;
	DataType data;
}Node;

Node* BuyDListNode(DataType);
void DListInit(Node** head);
void DListPushFront(Node* head, DataType data);
void DListPopFront(Node* head);
void DListPushBack(Node* head, DataType data);
void DListPopBack(Node* head);
void DListInsert(Node* pos, DataType datda);
void DListErase(Node* pos);
Node* DListFind(Node* head, DataType data);
int DListSize(Node* head);
void DListDestroy(Node** head);

void DListPrint(Node* head);