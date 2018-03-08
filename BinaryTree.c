#include"BinaryTree.h"
#include"Stack.h"
#include"Queue.h"

BTNode* BuyBTNode(DataType x)//�������ڵ�
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

//����������
BTNode* CreateBTree(DataType* a, size_t* pIndex, DataType invalid)
{
	BTNode *root = NULL;
	if (a[*pIndex] != invalid) //����ֵ��Ϊ�Ƿ�ֵ�ʹ�����������
	{
		root = BuyBTNode(a[*pIndex]);//�ݹ齨�����ڵ�
		++(*pIndex);
		root->_left = CreateBTree(a, pIndex, invalid);//�ݹ齨��������
		++(*pIndex);
		root->_right = CreateBTree(a, pIndex, invalid);//�ݹ齨��������
	}
	else
		root = NULL;
	return root;
}
//ǰ�����
//�� �� ��
void BTreePrevOrder(BTNode* root)
{
	if (NULL == root)
		return;
	printf("%d ", root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}
void BTreePrevOrderR(BTNode* root)//������---->ջʵ��
{
	if (NULL == root)
		return;
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;
	while (StackEmpty(&s) || cur)
	{
		while (cur != NULL)//�Ȱ�������ȫ����ջ
		{
			printf("%d ", cur->_data);//��ӡ��ǰ��������������
			StackPush(&s, cur);//��ջ
			cur = cur->_left;
		}
		top = StackTop(&s);//��������ȫ����ջ��ȡջ��Ԫ��
		StackPop(&s);//ջ����ջ
		cur = top->_right;//ָ��ջ����������
	}
}
//�������
//�� �� ��
void BTreeInOrder(BTNode* root)
{
	if (NULL == root)
		return;
	BTreeInOrder(root->_left);
	printf("%d ", root->_data);
	BTreeInOrder(root->_right);
}
void BTreeInOrderR(BTNode* root)
{
	if (NULL == root)
		return;
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;
	while (StackEmpty(&s) || (NULL != cur))
	{
		while (cur != NULL)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		printf("%d ", top->_data);
		StackPop(&s);//ջ����ջ
		cur = top->_right;
	}
}
//�������
//�� �� ��
void BTreeBackOrder(BTNode* root)
{
	if (NULL == root)
		return;
	BTreeBackOrder(root->_left);
	BTreeBackOrder(root->_right);
	printf("%d ", root->_data);
}
void BTreeBackOrderR(BTNode* root)
{
	if (NULL == root)
		return;
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;
	BTNode* prev = NULL;
	while (StackEmpty(&s) || (NULL != cur))
	{
		while (NULL != cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		if (top->_right == NULL || top->_right == prev)//�ж�������Ϊ�ջ����Ƿ���ʹ�
		{
			printf("%d ", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
			cur = top->_right;
	}
}
//�������
void BTreeLevelOrder(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);
	BTNode* cur = root;
	QueuePush(&q, cur);
	while (QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", tmp->_data);
		if (tmp->_left != NULL)
			QueuePush(&q, tmp->_left);
		if (tmp->_right != NULL)
			QueuePush(&q, tmp->_right);
	}
}
size_t BTreeSize(BTNode* root)//�����Ľڵ�
{
	if (root == NULL)
		return 0;
	int sizeleft = BTreeSize(root->_left);
	int sizeright = BTreeSize(root->_right);
	return sizeleft + sizeright+1;
}
size_t BTreeLeafSize(BTNode* root)//������Ҷ�ӽ�����
{
	if (NULL == root)
		return 0;
	if ((NULL == root->_left) && (NULL == root->_right))
		return 1;
	int sizeleafleft = BTreeLeafSize(root->_left);
	int sizeleafright = BTreeLeafSize(root->_right);
	return sizeleafleft + sizeleafright;
}
size_t BTreeKLevelSize(BTNode* root, size_t k)//��K��ڵ���
{
	if (root == NULL || k<1)
		return 0;
	if (k == 1)
		return 1;
	int sizeleft = BTreeKLevelSize(root->_left, k - 1);
	int sizeright = BTreeKLevelSize(root->_right, k - 1);
	return sizeleft + sizeright;
}
size_t BTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int depthleft = BTreeDepth(root->_left);
	int depthright = BTreeDepth(root->_right);
	return depthleft > depthright ? (depthleft + 1) : (depthright + 1);
}
BTNode* BTreeFind(BTNode* root, DataType x)//����
{
	BTNode* leftNode, *rightNode;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	leftNode = BTreeFind(root->_left, x);
	if (leftNode)
		return leftNode;
	rightNode = BTreeFind(root->_right, x);
	if (rightNode)
		return rightNode;
}
// �ж���ȫ������ 
int IsCompleteBTree(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (cur == NULL)
			break;
		else
		{
			QueuePush(&q, cur->_left);
			QueuePush(&q, cur->_right);
		}
		QueuePop(&q);
	}
	while (QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (cur != NULL)
			return -1;
		QueuePop(&q);
	}
	return 1;
}
//��ͬ����1����ͬ����0
size_t BTreeStructure(BTNode* root1, BTNode* root2)//�ж��������Ľṹ�Ƿ���ͬ
{
	//1.��������Ϊ�գ�������ͬ
	//2.һ����Ϊ�գ�һ����Ϊ�գ����Բ���ͬ
	//3.����Ϊ�գ�����Ϊ�����⣬�ж������Һ����Ƿ���ͬ��ֱ��Ϊ��
	if ((root1 == NULL) && (root2 == NULL))
		return 1;
	if ((root1 == NULL) || (root2 == NULL))
		return 0;
	int _treeleft = BTreeStructure(root1->_left, root2->_left);
	int _treeright = BTreeStructure(root1->_right, root2->_right);
	return (_treeleft&&_treeright);
}
BTNode* MirrorTree(BTNode* root)//���ľ���
{
	if (NULL == root)
		return 0;
	BTNode* MLift = MirrorTree(root->_left);
	BTNode* MRight = MirrorTree(root->_right);
	root->_left = MRight;
	root->_right = MLift;
	return root;
}