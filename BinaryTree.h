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
// ���������� 
BTNode* CreateBTree(DataType* a, size_t* pIndex, DataType invalid);
void BTreePrevOrder(BTNode* root);//ǰ��
void BTreeInOrder(BTNode* root);//����
void BTreeBackOrder(BTNode* root);//����

void BTreePrevOrderR(BTNode* root);//�ǵݹ�ǰ��
void BTreeInOrderR(BTNode* root);//��������
void BTreeBackOrderR(BTNode* root);//��������

size_t BTreeSize(BTNode* root);//�����Ľڵ�
size_t BTreeLeafSize(BTNode* root);//������Ҷ�ӽ�����
size_t BTreeKLevelSize(BTNode* root, size_t k);//��K��ڵ���
size_t BTreeDepth(BTNode* root);//���������
BTNode* BTreeFind(BTNode* root, DataType x);
void BTreeLevelOrder(BTNode* root);//�������
// �ж���ȫ������ 
int IsCompleteBTree(BTNode* root);
size_t BTreeStructure(BTNode* root1, BTNode* root2);//�ж��������Ľṹ�Ƿ���ͬ
BTNode* MirrorTree(BTNode* root);//�����ľ���