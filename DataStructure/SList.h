#pragma once

typedef int DataType;
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}SListNode;
//��ʼ������
void SListInit(SListNode** head);
//�������
void SListDestory(SListNode** head);
//��ʼ��һ��ͷ�ڵ�
SListNode* BuySListNode(DataType data);
//β��һ��data
void SListPushBack(SListNode** head, DataType data);
//βɾһ��data
void SListPopBack(SListNode** head);
//ͷ��һ��data
void SListPushFront(SListNode** head, DataType data);
//ͷɾһ��data
void SListPopFront(SListNode** head);
// ����λ�ò���
void SListInsert(SListNode* pos, DataType data);
// ����λ��ɾ��
void SListErase(SListNode* pos);
// �����С
int SListSize(SListNode* head);
// Ѱ��data
SListNode* SListFind(SListNode* head, DataType data);
// ��ʾ����
void PrintSList(SListNode* head);
