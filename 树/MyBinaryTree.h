#include <iostream>
#include<vector>
using namespace std;
typedef struct TreeNode {
	TreeNode * left;
	TreeNode * right;
	int data;
};

TreeNode *InitTree() {
	//����һ�����ڵ㣨������ͷ��㣩
	TreeNode *root = new(TreeNode);
	root->left = root->right = NULL;
	cout << "Initialize successfully!" << endl;
	return root;
}

void PreCreateTree(TreeNode *&T) {
	//ͨ������ݹ�ķ�ʽ������
	int item;
	cin >> item;
	if (item == 0)              //Ҷ�ڵ����ݱ�־����������0 
		T = NULL;            //��ĳһ�ڵ�ΪҶ�ӽ�㣬��������������ΪNULL��0��ʾ������
	else
	{
		T = new(TreeNode);
		T->data = item;
		PreCreateTree(T->left);            //�ݹ鴴���������� 
		PreCreateTree(T->right);            //�ݹ鴴���������� 
	}
}

void PreTraverseTree(TreeNode *root) {
	//ǰ�����
	if (root) {
		cout << root->data << " ";
		PreTraverseTree(root->left);
		PreTraverseTree(root->right);
	}
}
void InTraverseTree(TreeNode *root) {
	//�������
	if (root) {
		InTraverseTree(root->left);
		cout << root->data << " ";
		InTraverseTree(root->right);
	}
}
void PostTraverseTree(TreeNode *root) {
	//�������
	if (root) {
		PostTraverseTree(root->left);
		PostTraverseTree(root->right);
		cout << root->data << " ";
	}
}
void PreTraverseTree2(TreeNode *root) {
	//�ǵݹ��ǰ�������ʹ��ѭ�����棩
	vector <TreeNode *>arr;
	arr.push_back(root);
	while (!arr.empty()) {
		TreeNode *temp = arr.back();
		cout << temp->data << " ";
		arr.pop_back();
		if (temp->right) arr.push_back(temp->right);
		if (temp->left) arr.push_back(temp->left);
	}
}
int GetNodeNumber(TreeNode * root) {
	//ͨ���ݹ�����ķ�ʽ�õ��ܽڵ����Ŀ
	if (root) {
		return GetNodeNumber(root->left) + GetNodeNumber(root->right) + 1;
	}
	return 0;
}
int GetLeafNumber(TreeNode * root) {
	//ͨ���ݹ�����ķ�ʽ�õ�Ҷ����Ŀ
	if (root) {
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		else {
			return GetLeafNumber(root->left) + GetLeafNumber(root->right);
		}
	}
	return 0;
}
int GetNotLeafNumber(TreeNode * root) {
	//ͨ���ݹ�����ķ�ʽ�õ���Ҷ�ӽڵ����Ŀ
	if (root) {
		if (root->left == NULL && root->right == NULL) {
			return 0;
		}
		else {
			return GetNotLeafNumber(root->left) + GetNotLeafNumber(root->right)+1;
		}
	}
}

int GetTreeHeight(TreeNode * root) {
	//ͨ���ݹ��㷨������
	int left, right;
	if (root) {
		left = 1 + GetTreeHeight(root->left);
		right = 1 + GetTreeHeight(root->right);
		return left > right ? left : right;
	}
	return 0;
}

void DeleteTree(TreeNode * root) {
	if (root) {
		PostTraverseTree(root->left);
		PostTraverseTree(root->right);
		delete(root);
	}
}

TreeNode *FindTreeNode(TreeNode * root, int n) {
	//������λ����һ��ֵΪn�����Ľڵ�
	/*TreeNode *target = NULL;
	if (root) {
		if (root->data == n) target = root;
		target = FindTreeNode(root->left, n);
		target = FindTreeNode(root->right, n);

	}*/
	return 0;
}

void CreatTreeByIndex(TreeNode* root, string a, string b) {
	//ͨ��ǰ��+�������й�����

}

