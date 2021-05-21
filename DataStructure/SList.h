#pragma once

typedef int DataType;
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}SListNode;
//初始化链表
void SListInit(SListNode** head);
//清空链表
void SListDestory(SListNode** head);
//初始化一个头节点
SListNode* BuySListNode(DataType data);
//尾插一个data
void SListPushBack(SListNode** head, DataType data);
//尾删一个data
void SListPopBack(SListNode** head);
//头插一个data
void SListPushFront(SListNode** head, DataType data);
//头删一个data
void SListPopFront(SListNode** head);
// 任意位置插入
void SListInsert(SListNode* pos, DataType data);
// 任意位置删除
void SListErase(SListNode* pos);
// 链表大小
int SListSize(SListNode* head);
// 寻找data
SListNode* SListFind(SListNode* head, DataType data);
// 显示链表
void PrintSList(SListNode* head);
