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
	cout << "层次遍历：";
	LevelTraverseTree(root);
	cout << endl;
	
	getchar();
	getchar();
	return 0;
}