#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
#include <stdio.h>
#include <crtdbg.h>

#include "BinaryTree.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	BDataType arr[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int NodeSize = 0;
	BTNode* root = CreateBinTree(arr, sizeof(arr) / sizeof(arr[0]), -1);
	printf("二叉树前序遍历结果: ");
	PreOrder(root);
	printf("\n");

	printf("二叉树中序遍历结果: ");
	InOrder(root);
	printf("\n");

	printf("二叉树后序遍历结果: ");
	PostOrder(root);
	printf("\n");

	printf("层序遍历结果: ");
	LevelOrder(root);
	printf("\n");

	printf("树中节点总的个数为:%d\n", BinaryTreeSize(root));
	printf("树中叶子节点总的个数为:%d\n", BinaryTreeLeafSize(root));
	printf("树中第%d层节点总的个数为:%d\n", 3, BinaryTreeKSize(root, 3));
	printf("树高度为:%d\n", BinaryTreeHeight(root));
	printf("查找%p\n", BinaryTreeFind(root, 5));
	printf("查找%p\n", BinaryTreeFind(root, 10));

	printf("%d \n", BinaryTreeComplete(root));

	DestroyBinTree(&root);
	return 0;
}