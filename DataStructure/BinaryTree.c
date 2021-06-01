#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Queue.h"
//申请结点
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

//创建二叉树(通过前序遍历方式)
// index按照值的方式传递的---在递归过程中对index修改之后，不会将修改之后的结果带到上一层中
BTNode* _CrteateBinTree(BDataType array[], int size, int* index, BDataType invalid)
{
	BTNode* root = NULL;
	if (*index < size && invalid != array[*index])
	{
		// 创建根节点
		root = BuyBinTreeNode(array[*index]);

		// 创建根节点的左子树
		++(*index);
		root->left = _CrteateBinTree(array, size, index, invalid);

		// 创建根节点的右子树
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

//前序遍历
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

//层序遍历
void LevelOrder(BTNode* root) 
{
	Queue q;
	if (root == NULL)
		return;

	QueueInit(&q);
	QueuePush(&q, root);    //存入根节点
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);     //拿到队头
		printf("%d ", cur->data);
		if (cur->left)     //队头的左孩子入队
			QueuePush(&q, cur->left);
		if (cur->right)    //队头的右孩子入队
			QueuePush(&q, cur->right);
		QueuePop(&q);      //队头出队列
	}
	QueueDestroy(&q);
}

//二叉树中节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	//根节点+左子树+右子树
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//二叉树中叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)    //
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//二叉树中第k层节点个数
int BinaryTreeKSize(BTNode* root, int k)
{
	if (root == NULL || k <= 0)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeKSize(root->left, k - 1) + BinaryTreeKSize(root->right, k - 1);
}

//求二叉树的深度
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = BinaryTreeHeight(root->left);
	int rightHight = BinaryTreeHeight(root->right);

	return leftHeight > rightHight ? leftHeight + 1 : rightHight + 1;
}

//以前序遍历方式寻找第一个值为x的结点
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

//销毁二叉树
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

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return 1;
	Queue q;
	int flag = 0;   //第一个不包含右孩子结点的结点
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		  //如果找到第一个非叶子节点
		if (flag)   
		{
			// 如果有左孩子或者右孩子
			if (cur->left || cur->right)
			{
				QueueDestroy(&q);
				return 0;
			}
		}
		else
		{
			//找第一个非叶子节点(有左孩子和右孩子)
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