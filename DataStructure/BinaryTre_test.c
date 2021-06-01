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
	printf("������ǰ��������: ");
	PreOrder(root);
	printf("\n");

	printf("����������������: ");
	InOrder(root);
	printf("\n");

	printf("����������������: ");
	PostOrder(root);
	printf("\n");

	printf("����������: ");
	LevelOrder(root);
	printf("\n");

	printf("���нڵ��ܵĸ���Ϊ:%d\n", BinaryTreeSize(root));
	printf("����Ҷ�ӽڵ��ܵĸ���Ϊ:%d\n", BinaryTreeLeafSize(root));
	printf("���е�%d��ڵ��ܵĸ���Ϊ:%d\n", 3, BinaryTreeKSize(root, 3));
	printf("���߶�Ϊ:%d\n", BinaryTreeHeight(root));
	printf("����%p\n", BinaryTreeFind(root, 5));
	printf("����%p\n", BinaryTreeFind(root, 10));

	printf("%d \n", BinaryTreeComplete(root));

	DestroyBinTree(&root);
	return 0;
}