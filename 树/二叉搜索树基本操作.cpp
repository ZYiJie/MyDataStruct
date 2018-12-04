#include<iostream>
#include<string>
#include"MyBinaryTree.h"
using namespace std;

int main()
{
	TreeNode *root=NULL;
	CreateSearchedTree(root);
	cout << "前序遍历：";
	PreTraverseTree(root);
	cout << endl;
	cout << "中序遍历：";
	InTraverseTree(root);
	cout << endl;
	cout << "后序遍历：";
	PostTraverseTree(root);
	cout << endl;
	cout << "非递归前序遍历：";
	PreTraverseTree2(root);
	cout << endl;
	cout << "叶的数目：" << GetLeafNumber(root) << endl;
	cout << "非叶的数目：" << GetNotLeafNumber(root) << endl;
	cout << "总结点的数目：" << GetNodeNumber(root) << endl;
	cout << "树的高度：" << GetTreeHeight(root) << endl;

	getchar();
	getchar();
	return 0;
}