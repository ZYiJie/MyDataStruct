#include<iostream>
#include<string>
#include"MyBinaryTree.h"
using namespace std;

int main()
{
	TreeNode *root=NULL;
	CreateSearchedTree(root);
	cout << "ǰ�������";
	PreTraverseTree(root);
	cout << endl;
	cout << "���������";
	InTraverseTree(root);
	cout << endl;
	cout << "���������";
	PostTraverseTree(root);
	cout << endl;
	cout << "��α�����";
	LevelTraverseTree(root);
	cout << endl;
	
	getchar();
	getchar();
	return 0;
}