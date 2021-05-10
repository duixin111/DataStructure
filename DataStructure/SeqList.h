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

//��ʼ������
void SeqListInit(struct SeqList* ps, int initCap);
//�������
void SeqListDestroy(SeqList* ps);
//β��һ��data
void SeqListPushBack(SeqList* ps, DataType data);
//βɾһ��data
void SeqListPopBack(SeqList* ps);
//��posλ�ò���data
void SeqListInsert(SeqList* ps, int pos, DataType data);
//��posλֵɾ��data
void SeqListErase(SeqList* ps, int pos);
//��ȡԪ�ظ���
int SeqListSize(SeqList* ps);
//��ȡ����
int SeqListCapacity(SeqList* ps);
//�ж�˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* ps);
//����ĳ��Ԫ��
int SeqListFind(SeqList* ps, DataType data);
//���ݵ�capacity
void SeqListReserve(SeqList* ps, int capacity);

//��ʾ
void SeqListPrint(SeqList* ps);