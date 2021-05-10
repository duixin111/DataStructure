#pragma once

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
typedef int DataType;
typedef struct SeqList
{
	DataType* array;
	int capacity;
	int size;
}SeqList;

//初始化链表
void SeqListInit(struct SeqList* ps, int initCap);
//清空链表
void SeqListDestroy(SeqList* ps);
//尾插一个data
void SeqListPushBack(SeqList* ps, DataType data);
//尾删一个data
void SeqListPopBack(SeqList* ps);
//在pos位置插入data
void SeqListInsert(SeqList* ps, int pos, DataType data);
//在pos位值删除data
void SeqListErase(SeqList* ps, int pos);
//获取元素个数
int SeqListSize(SeqList* ps);
//获取容量
int SeqListCapacity(SeqList* ps);
//判断顺序表是否为空
int SeqListEmpty(SeqList* ps);
//查找某个元素
int SeqListFind(SeqList* ps, DataType data);
//扩容到capacity
void SeqListReserve(SeqList* ps, int capacity);
//显示
void SeqListPrint(SeqList* ps);
