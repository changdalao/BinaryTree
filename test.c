#include"BinaryTree.h"

int main()
{
	int a[] = { 1, 2, 3, '#', '#',4,'#', '#', 5, 6,'#' ,'#' ,'#' };
	int b[] = { 1, 2, 3, '#', 4, '#', '#', 5, 6,'#' ,'#' ,'#','#' };
	size_t index = 0;
	size_t pindex = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	BTNode* Tree = CreateBTree(b, &pindex, '#');

	printf("前序遍历> ");
	BTreePrevOrder(tree);

	printf("\n");
	printf("中序遍历> ");
	BTreeInOrder(tree);
	printf("\n");
	printf("后序遍历> ");
	BTreeBackOrder(tree);
	printf("\n");
	printf("迭代法--前序遍历> ");
	BTreePrevOrderR(tree);
	printf("\n");
	printf("迭代法--中序遍历> ");
	BTreeInOrderR(tree);
	printf("\n");
	printf("迭代法--后序遍历> ");
	BTreeBackOrderR(tree);
	printf("\n");
	printf("树的节点>%d\n", BTreeSize(tree));
	printf("树的叶子结点个数%d\n", BTreeLeafSize(tree));
	printf("迭代法--层序遍历> ");
	BTreeLevelOrder(tree);
	printf("\n");
	printf("树的第K层结点个数%d\n", BTreeKLevelSize(tree,2));
	printf("树的深度%d\n", BTreeDepth(tree));
	printf("查找某一节点%d\n", BTreeFind(tree, 5)->_data);
	printf("判断是否为完全二叉树%d\n", IsCompleteBTree(tree));
	printf("判断tree和Tree结构是否相同(不同为0,相同为1)>%d\n", BTreeStructure(tree, Tree));
	printf("tree的镜像>\n");
	BTNode* NewTree = MirrorTree(tree);
	printf("前序遍历>");
	BTreePrevOrder(NewTree);
	printf("\n");
	printf("中序遍历> ");
	BTreeInOrder(NewTree);
	printf("\n");
	//TestBSTree();
	system("pause");
	return 0;
}