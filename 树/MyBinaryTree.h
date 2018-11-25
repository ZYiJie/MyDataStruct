#include <iostream>
#include<vector>
using namespace std;
typedef struct TreeNode {
	TreeNode * left;
	TreeNode * right;
	int data;
};

TreeNode *InitTree() {
	//返回一个根节点（该树无头结点）
	TreeNode *root = new(TreeNode);
	root->left = root->right = NULL;
	cout << "Initialize successfully!" << endl;
	return root;
}

void PreCreateTree(TreeNode *&T) {
	//通过先序递归的方式创建树
	int item;
	cin >> item;
	if (item == 0)              //叶节点数据标志：其后根两个0 
		T = NULL;            //若某一节点为叶子结点，则其左右子树均为NULL，0表示建空树
	else
	{
		T = new(TreeNode);
		T->data = item;
		PreCreateTree(T->left);            //递归创建其左子树 
		PreCreateTree(T->right);            //递归创建其右子树 
	}
}

void PreTraverseTree(TreeNode *root) {
	//前序遍历
	if (root) {
		cout << root->data << " ";
		PreTraverseTree(root->left);
		PreTraverseTree(root->right);
	}
}
void InTraverseTree(TreeNode *root) {
	//中序遍历
	if (root) {
		InTraverseTree(root->left);
		cout << root->data << " ";
		InTraverseTree(root->right);
	}
}
void PostTraverseTree(TreeNode *root) {
	//后序遍历
	if (root) {
		PostTraverseTree(root->left);
		PostTraverseTree(root->right);
		cout << root->data << " ";
	}
}
void PreTraverseTree2(TreeNode *root) {
	//非递归的前序遍历（使用循环代替）
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
	//通过递归遍历的方式得到总节点的数目
	if (root) {
		return GetNodeNumber(root->left) + GetNodeNumber(root->right) + 1;
	}
	return 0;
}
int GetLeafNumber(TreeNode * root) {
	//通过递归遍历的方式得到叶的数目
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
	//通过递归遍历的方式得到非叶子节点的数目
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
	//通过递归算法求树高
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
	//遍历定位到第一个值为n的树的节点
	/*TreeNode *target = NULL;
	if (root) {
		if (root->data == n) target = root;
		target = FindTreeNode(root->left, n);
		target = FindTreeNode(root->right, n);

	}*/
	return 0;
}

void CreatTreeByIndex(TreeNode* root, string a, string b) {
	//通过前序+中序序列构造树

}

