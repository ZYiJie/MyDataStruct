#include <iostream>
#include"MyBinaryTree.h"
using namespace std;
int main() {
	TreeNode *root=NULL;
	char *str1,*str2;
	int len=0;
	const int LEN = 20;
	str1 = new char[LEN];
	str2 = new char[LEN];
	cout << "������ǰ�����У�";//����ABCDEFG
	cin >> str1;
	cout << "�������������У�";//����BDCAFEG
	cin >> str2;
	for ( ; str1[len]; len++) ;
	CreateTreeByIndex(root, str1, str2,len);
	cout << "ǰ�������";
	PreTraverseTree(root);
	cout << endl;
	cout << "���������";
	InTraverseTree(root);
	cout << endl;
	cout << "���������";
	PostTraverseTree(root);
	cout << endl;
	cout << endl;

	cout << "���������������У�";//����BDCAFEG 
	cin >> str1;
	cout << "������������У�";//����DCBFGEA
	cin >> str2;
	for (; str1[len]; len++);
	CreateTreeByIndex2(root, str1, str2, len);
	cout << "ǰ�������";
	PreTraverseTree(root);
	cout << endl;
	cout << "���������";
	InTraverseTree(root);
	cout << endl;
	cout << "���������";
	PostTraverseTree(root);
	cout << endl;
	getchar();
	getchar();
	return 0;
}