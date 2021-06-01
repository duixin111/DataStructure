#pragma once

typedef int BDataType;

typedef struct BTNode
{
	BDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

/*     根结点层数为1    */

//申请结点
BTNode* BuyBinTreeNode(BDataType data);
//创建二叉树(通过前序遍历方式)
BTNode* CreateBinTree(BDataType array[], int size, BDataType invalid);
//前序遍历
void PreOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//层序遍历
void LevelOrder(BTNode* root);
//二叉树中节点个数
int BinaryTreeSize(BTNode* root);
//二叉树中叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树中第k层节点个数
int BinaryTreeKSize(BTNode* root, int k);
//求二叉树的深度
int BinaryTreeHeight(BTNode* root);
//以前序遍历方式寻找第一个值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BDataType data);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
//销毁二叉树
void DestroyBinTree(BTNode** root);