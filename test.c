#include"BinaryTree.h"

int main()
{
	int a[] = { 1, 2, 3, '#', '#',4,'#', '#', 5, 6,'#' ,'#' ,'#' };
	int b[] = { 1, 2, 3, '#', 4, '#', '#', 5, 6,'#' ,'#' ,'#','#' };
	size_t index = 0;
	size_t pindex = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	BTNode* Tree = CreateBTree(b, &pindex, '#');

	printf("ǰ�����> ");
	BTreePrevOrder(tree);

	printf("\n");
	printf("�������> ");
	BTreeInOrder(tree);
	printf("\n");
	printf("�������> ");
	BTreeBackOrder(tree);
	printf("\n");
	printf("������--ǰ�����> ");
	BTreePrevOrderR(tree);
	printf("\n");
	printf("������--�������> ");
	BTreeInOrderR(tree);
	printf("\n");
	printf("������--�������> ");
	BTreeBackOrderR(tree);
	printf("\n");
	printf("���Ľڵ�>%d\n", BTreeSize(tree));
	printf("����Ҷ�ӽ�����%d\n", BTreeLeafSize(tree));
	printf("������--�������> ");
	BTreeLevelOrder(tree);
	printf("\n");
	printf("���ĵ�K�������%d\n", BTreeKLevelSize(tree,2));
	printf("�������%d\n", BTreeDepth(tree));
	printf("����ĳһ�ڵ�%d\n", BTreeFind(tree, 5)->_data);
	printf("�ж��Ƿ�Ϊ��ȫ������%d\n", IsCompleteBTree(tree));
	printf("�ж�tree��Tree�ṹ�Ƿ���ͬ(��ͬΪ0,��ͬΪ1)>%d\n", BTreeStructure(tree, Tree));
	printf("tree�ľ���>\n");
	BTNode* NewTree = MirrorTree(tree);
	printf("ǰ�����>");
	BTreePrevOrder(NewTree);
	printf("\n");
	printf("�������> ");
	BTreeInOrder(NewTree);
	printf("\n");
	//TestBSTree();
	system("pause");
	return 0;
}