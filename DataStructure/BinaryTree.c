#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Queue.h"
//������
BTNode* BuyBinTreeNode(BDataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		assert(0);
		return NULL;
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//����������(ͨ��ǰ�������ʽ)
// index����ֵ�ķ�ʽ���ݵ�---�ڵݹ�����ж�index�޸�֮�󣬲��Ὣ�޸�֮��Ľ��������һ����
BTNode* _CrteateBinTree(BDataType array[], int size, int* index, BDataType invalid)
{
	BTNode* root = NULL;
	if (*index < size && invalid != array[*index])
	{
		// �������ڵ�
		root = BuyBinTreeNode(array[*index]);

		// �������ڵ��������
		++(*index);
		root->left = _CrteateBinTree(array, size, index, invalid);

		// �������ڵ��������
		++(*index);
		root->right = _CrteateBinTree(array, size, index, invalid);
	}

	return root;
}

BTNode* CreateBinTree(BDataType array[], int size, BDataType invalid)
{
	int index = 0;
	return _CrteateBinTree(array, size, &index, invalid);
}

//ǰ�����
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//�������
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

//�������
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

//�������
void LevelOrder(BTNode* root) 
{
	Queue q;
	if (root == NULL)
		return;

	QueueInit(&q);
	QueuePush(&q, root);    //������ڵ�
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);     //�õ���ͷ
		printf("%d ", cur->data);
		if (cur->left)     //��ͷ���������
			QueuePush(&q, cur->left);
		if (cur->right)    //��ͷ���Һ������
			QueuePush(&q, cur->right);
		QueuePop(&q);      //��ͷ������
	}
	QueueDestroy(&q);
}

//�������нڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	//���ڵ�+������+������
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//��������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)    //
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//�������е�k��ڵ����
int BinaryTreeKSize(BTNode* root, int k)
{
	if (root == NULL || k <= 0)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeKSize(root->left, k - 1) + BinaryTreeKSize(root->right, k - 1);
}

//������������
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = BinaryTreeHeight(root->left);
	int rightHight = BinaryTreeHeight(root->right);

	return leftHeight > rightHight ? leftHeight + 1 : rightHight + 1;
}

//��ǰ�������ʽѰ�ҵ�һ��ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BDataType data)
{
	if (root == NULL)
		return NULL;

	if (root->data == data)
		return root;

	BTNode* ret = NULL;

	if (ret == BinaryTreeFind(root->left, data))
		return ret;

	return BinaryTreeFind(root->right, data);
}

//���ٶ�����
void DestroyBinTree(BTNode** root)
{
	assert(root);
	if (*root == NULL)
		return;
	DestroyBinTree(&(*root)->left);
	DestroyBinTree(&(*root)->right);
	free(*root);
	*root = NULL;
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return 1;
	Queue q;
	int flag = 0;   //��һ���������Һ��ӽ��Ľ��
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		  //����ҵ���һ����Ҷ�ӽڵ�
		if (flag)   
		{
			// ��������ӻ����Һ���
			if (cur->left || cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
		}
		else
		{
			//�ҵ�һ����Ҷ�ӽڵ�(�����Ӻ��Һ���)
			if (cur->left && cur->right)
			{
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
			//else
			//{
			//	flag = 1;
			//}
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 1;
}