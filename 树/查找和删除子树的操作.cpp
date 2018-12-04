#include<iostream>
#include<stack>
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

	int num;
	cout << "待查的数字：";
	cin >> num;
	if (FindSearchedTree(root,num) == 1) cout << "TRUE" << endl;
	else cout << "False" << endl;

	int num2,flag=0;
	stack <TreeNode*> arr;
	cout << "待删除的数字：";
	cin >> num2;
	TreeNode *temp;
	FindTreeNode(root, num2, temp);
	DelRoot_x(root, num2, flag);
	cout << "中序遍历：";
	InTraverseTree(root);
	cout << endl;
	getchar();
	getchar();
	return 0;
}