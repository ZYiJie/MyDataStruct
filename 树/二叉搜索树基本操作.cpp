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
	cout << "�ǵݹ�ǰ�������";
	PreTraverseTree2(root);
	cout << endl;
	cout << "Ҷ����Ŀ��" << GetLeafNumber(root) << endl;
	cout << "��Ҷ����Ŀ��" << GetNotLeafNumber(root) << endl;
	cout << "�ܽ�����Ŀ��" << GetNodeNumber(root) << endl;
	cout << "���ĸ߶ȣ�" << GetTreeHeight(root) << endl;

	getchar();
	getchar();
	return 0;
}