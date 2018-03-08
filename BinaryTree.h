#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;


typedef struct BinaryTreeNode
{
	DataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


BTNode* BuyBTNode(DataType x);
// 创建二叉树 
BTNode* CreateBTree(DataType* a, size_t* pIndex, DataType invalid);
void BTreePrevOrder(BTNode* root);//前序
void BTreeInOrder(BTNode* root);//中序
void BTreeBackOrder(BTNode* root);//后序

void BTreePrevOrderR(BTNode* root);//非递归前序
void BTreeInOrderR(BTNode* root);//迭代中序
void BTreeBackOrderR(BTNode* root);//迭代后序

size_t BTreeSize(BTNode* root);//求树的节点
size_t BTreeLeafSize(BTNode* root);//求树的叶子结点个数
size_t BTreeKLevelSize(BTNode* root, size_t k);//第K层节点数
size_t BTreeDepth(BTNode* root);//求树的深度
BTNode* BTreeFind(BTNode* root, DataType x);
void BTreeLevelOrder(BTNode* root);//层序遍历
// 判断完全二叉树 
int IsCompleteBTree(BTNode* root);
size_t BTreeStructure(BTNode* root1, BTNode* root2);//判断两棵树的结构是否相同
BTNode* MirrorTree(BTNode* root);//求树的镜像