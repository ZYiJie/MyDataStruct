#include<iostream>
#include<stack>
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

	int num;
	cout << "��������֣�";
	cin >> num;
	if (FindSearchedTree(root,num) == 1) cout << "TRUE" << endl;
	else cout << "False" << endl;

	int num2,flag=0;
	stack <TreeNode*> arr;
	cout << "��ɾ�������֣�";
	cin >> num2;
	TreeNode *temp;
	FindTreeNode(root, num2, temp);
	DelRoot_x(root, num2, flag);
	cout << "���������";
	InTraverseTree(root);
	cout << endl;
	getchar();
	getchar();
	return 0;
}