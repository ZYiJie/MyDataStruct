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
	cout << "请输入前序序列：";//先序：ABCDEFG
	cin >> str1;
	cout << "请输入中序序列：";//中序：BDCAFEG
	cin >> str2;
	for ( ; str1[len]; len++) ;
	CreateTreeByIndex(root, str1, str2,len);
	cout << "前序遍历：";
	PreTraverseTree(root);
	cout << endl;
	cout << "中序遍历：";
	InTraverseTree(root);
	cout << endl;
	cout << "后序遍历：";
	PostTraverseTree(root);
	cout << endl;
	cout << endl;

	cout << "请输入中序序序列：";//中序：BDCAFEG 
	cin >> str1;
	cout << "请输入后序序列：";//后序：DCBFGEA
	cin >> str2;
	for (; str1[len]; len++);
	CreateTreeByIndex2(root, str1, str2, len);
	cout << "前序遍历：";
	PreTraverseTree(root);
	cout << endl;
	cout << "中序遍历：";
	InTraverseTree(root);
	cout << endl;
	cout << "后序遍历：";
	PostTraverseTree(root);
	cout << endl;
	getchar();
	getchar();
	return 0;
}