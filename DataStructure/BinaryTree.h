#pragma once

typedef int BDataType;

typedef struct BTNode
{
	BDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

/*     ��������Ϊ1    */

//������
BTNode* BuyBinTreeNode(BDataType data);
//����������(ͨ��ǰ�������ʽ)
BTNode* CreateBinTree(BDataType array[], int size, BDataType invalid);
//ǰ�����
void PreOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//�������
void LevelOrder(BTNode* root);
//�������нڵ����
int BinaryTreeSize(BTNode* root);
//��������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
//�������е�k��ڵ����
int BinaryTreeKSize(BTNode* root, int k);
//������������
int BinaryTreeHeight(BTNode* root);
//��ǰ�������ʽѰ�ҵ�һ��ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BDataType data);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
//���ٶ�����
void DestroyBinTree(BTNode** root);