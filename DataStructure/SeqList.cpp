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

//��ʼ������
void SeqListInit(struct SeqList* ps, int initCap)
{
	assert(ps);
	//1.���ٿռ�
	ps->array = (DataType*)malloc(sizeof(DataType) * initCap);
	assert(ps->array);
	if (ps->array == NULL)
	{
		printf("malloc fail");
		return;
	}
	//2.����Ĭ������
	ps->capacity = initCap;
	//3.���ó�ʼ��Ч����
	ps->size = 0;
}
//�������
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	//���ps->aray�пռ�
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}
//β��һ��data
void SeqListPushBack(SeqList* ps, DataType data)
{
	assert(ps);
	if (ps->size >= ps->capacity)
		SeqListReserve(ps, SeqListCapacity(ps) << 1);
	ps->array[ps->size++] = data;
}
//βɾһ��data
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
//��posλ�ò���data
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
//��posλֵɾ��data
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
//��ȡԪ�ظ���
int SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->size;
}
//��ȡ����
int SeqListCapacity(SeqList* ps)
{
	assert(ps);
	return ps->capacity;
}
//�ж�˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->size == 0 ? 0 : ps->size;
}
//����ĳ��Ԫ��
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
//���ݵ�capacity
void SeqListReserve(SeqList* ps, int capacity)
{
	assert(ps);
	if (ps->capacity >= capacity)
		return;
	ps->array = (DataType*)realloc(ps->array, sizeof(DataType) * capacity);
	assert(ps);
	ps->capacity <<= 1;
}

//��ʾ
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->array[i]);
	putchar('\n');
}
