#include"BinaryTree.h"
#include"Stack.h"
#include"Queue.h"

BTNode* BuyBTNode(DataType x)//创建树节点
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

//创建二叉树
BTNode* CreateBTree(DataType* a, size_t* pIndex, DataType invalid)
{
	BTNode *root = NULL;
	if (a[*pIndex] != invalid) //序列值不为非法值就创建左右子树
	{
		root = BuyBTNode(a[*pIndex]);//递归建立根节点
		++(*pIndex);
		root->_left = CreateBTree(a, pIndex, invalid);//递归建立左子树
		++(*pIndex);
		root->_right = CreateBTree(a, pIndex, invalid);//递归建立右子树
	}
	else
		root = NULL;
	return root;
}
//前序遍历
//根 左 右
void BTreePrevOrder(BTNode* root)
{
	if (NULL == root)
		return;
	printf("%d ", root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}
void BTreePrevOrderR(BTNode* root)//迭代法---->栈实现
{
	if (NULL == root)
		return;
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;
	while (StackEmpty(&s) || cur)
	{
		while (cur != NULL)//先把左子树全部入栈
		{
			printf("%d ", cur->_data);//打印当前的左子树，即根
			StackPush(&s, cur);//入栈
			cur = cur->_left;
		}
		top = StackTop(&s);//把左子树全部入栈后，取栈顶元素
		StackPop(&s);//栈顶出栈
		cur = top->_right;//指向栈顶的右子树
	}
}
//中序遍历
//左 根 右
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
		StackPop(&s);//栈顶出栈
		cur = top->_right;
	}
}
//后序遍历
//左 右 根
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
		if (top->_right == NULL || top->_right == prev)//判断右子树为空或者是否访问过
		{
			printf("%d ", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
			cur = top->_right;
	}
}
//层序遍历
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
size_t BTreeSize(BTNode* root)//求树的节点
{
	if (root == NULL)
		return 0;
	int sizeleft = BTreeSize(root->_left);
	int sizeright = BTreeSize(root->_right);
	return sizeleft + sizeright+1;
}
size_t BTreeLeafSize(BTNode* root)//求树的叶子结点个数
{
	if (NULL == root)
		return 0;
	if ((NULL == root->_left) && (NULL == root->_right))
		return 1;
	int sizeleafleft = BTreeLeafSize(root->_left);
	int sizeleafright = BTreeLeafSize(root->_right);
	return sizeleafleft + sizeleafright;
}
size_t BTreeKLevelSize(BTNode* root, size_t k)//第K层节点数
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
BTNode* BTreeFind(BTNode* root, DataType x)//查找
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
// 判断完全二叉树 
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
//相同返回1，不同返回0
size_t BTreeStructure(BTNode* root1, BTNode* root2)//判断两个树的结构是否相同
{
	//1.两个树都为空，绝对相同
	//2.一个树为空，一个不为空，绝对不相同
	//3.都不为空，叠加为子问题，判断其左右孩子是否相同，直到为空
	if ((root1 == NULL) && (root2 == NULL))
		return 1;
	if ((root1 == NULL) || (root2 == NULL))
		return 0;
	int _treeleft = BTreeStructure(root1->_left, root2->_left);
	int _treeright = BTreeStructure(root1->_right, root2->_right);
	return (_treeleft&&_treeright);
}
BTNode* MirrorTree(BTNode* root)//树的镜像
{
	if (NULL == root)
		return 0;
	BTNode* MLift = MirrorTree(root->_left);
	BTNode* MRight = MirrorTree(root->_right);
	root->_left = MRight;
	root->_right = MLift;
	return root;
}