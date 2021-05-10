#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"SeqList.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

//初始化链表
void SeqListInit(struct SeqList* ps, int initCap)
{
	assert(ps);
	//1.开辟空间
	ps->array = (DataType*)malloc(sizeof(DataType) * initCap);
	assert(ps->array);
	if (ps->array == NULL)
	{
		printf("malloc fail");
		return;
	}
	//2.设置默认容量
	ps->capacity = initCap;
	//3.设置初始有效个数
	ps->size = 0;
}
//清空链表
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	//如果ps->aray有空间
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}
//尾插一个data
void SeqListPushBack(SeqList* ps, DataType data)
{
	assert(ps);
	if (ps->size >= ps->capacity)
		SeqListReserve(ps, SeqListCapacity(ps) << 1);
	ps->array[ps->size++] = data;
}
//尾删一个data
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (SeqListEmpty(ps))
	{
		printf("SeqList is NULL.\n");
		return;
	}
	ps->size--;
}
//在pos位置插入data
void SeqListInsert(SeqList* ps, int pos, DataType data)
{
	assert(ps);
	if (pos<0 || pos>ps->size)
	{
		printf("pos error!\n");
		return;
	}
	if (ps->size == ps->capacity)
		SeqListReserve(ps, SeqListCapacity(ps) << 1);

	for (int i = ps->size; i > pos; i--)
		ps->array[i] = ps->array[i - 1];

	ps->array[pos] = data;
	ps->size++;
}
//在pos位值删除data
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	if (pos<0 || pos>ps->size)
	{
		printf("pop error!\n");
		return;
	}
	for (int i = pos; i < ps->size; i++)
		ps->array[i] = ps->array[i + 1];

	ps->size--;
}
//获取元素个数
int SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->size;
}
//获取容量
int SeqListCapacity(SeqList* ps)
{
	assert(ps);
	return ps->capacity;
}
//判断顺序表是否为空
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->size == 0 ? 0 : ps->size;
}
//查找某个元素
int SeqListFind(SeqList* ps, DataType data)
{
	assert(NULL);
	for (int i = 0; i < ps->size; i++)
	{
		if (data == ps->array[i])
			return i;
	}
	return -1;
}
//扩容到capacity
void SeqListReserve(SeqList* ps, int capacity)
{
	assert(ps);
	if (ps->capacity >= capacity)
		return;
	ps->array = (DataType*)realloc(ps->array, sizeof(DataType) * capacity);
	assert(ps);
	ps->capacity <<= 1;
}

//显示
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->array[i]);
	putchar('\n');
}
