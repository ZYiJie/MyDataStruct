#include <iostream>
#include<queue>
#include<string>
using namespace std;
typedef struct TreeNode {
	TreeNode * left;
	TreeNode * right;
	int data;
};

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
void PreCreateTree_n(TreeNode *&T,int n) {
	//通过先序递归的方式创建树
	if (n == 0)              //叶节点数据标志：其后根两个0 
		T = NULL;            //若某一节点为叶子结点，则其左右子树均为NULL，0表示建空树
	else
	{
		T = new(TreeNode);
		T->data = n;
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

void LevelTraverseTree(TreeNode* root) {
	//使用队列实现层次遍历
	queue <TreeNode*>q;
	//树为空，直接返回
	if (root == NULL)
	{
		return;
	}
	//先将根节点入队
	q.push(root);
	while (!q.empty())
	{
		TreeNode* front = q.front();
		cout<<front->data<<" ";
		q.pop();
		if (front->left)
			q.push(front->left); 
		if (front->right)
			q.push(front->right);
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
	if ( root==NULL || (root->left == NULL && root->right == NULL) ) {
		return 0;
	}
	else {
		return GetNotLeafNumber(root->left) + GetNotLeafNumber(root->right)+1;
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

//void DeleteTree(TreeNode * &root,stack <TreeNode*>arr) {
//	//删除root底下所有分支(有问题)
//	while (root) {
//		if (root->left == NULL && root->right == NULL) {
//			TreeNode *temp = arr.top();
//			delete(root);
//			root = NULL;
//		}
//		else {
//			arr.push(root);
//			DeleteTree(root->left,arr);
//			DeleteTree(root->right,arr);
//		}
//		if (!root) {
//			root = arr.top();
//			arr.pop();
//		}
//	}
 //}

void FindTreeNode(TreeNode *&root, int n, TreeNode *&temp) {
	//遍历定位到第一个值为n的树的节点，返回到temp中
	if (root) {
		if (root->data == n) {
			temp = root;
		}
		else {
			FindTreeNode(root->right, n,temp);
			FindTreeNode(root->left, n,temp);
		}
	}
	//return NULL;
}

void CreateTreeByIndex(TreeNode *&T, char *pre, char * in, int n) {
	//通过前序+中序序列构造树
	int k = 0; char * p = in; //n为(子)树节点个数
	if (pre&&n) {
		T = new(TreeNode);
		T->data = pre[0];
		T->left = NULL;
		T->right = NULL;
		while (*(p++) != pre[0])k++;//得到左子树节点个数
		CreateTreeByIndex(T->left, pre + 1, in, k);
		CreateTreeByIndex(T->right, pre + k + 1, in + k + 1, n - k - 1);
	}
}

void CreateTreeByIndex2(TreeNode *&T, char *in, char * post, int n) {
	//通过中序+后序序列构造树
	int k = 0; char *p = in;
	if (post&&n) {
		T = new(TreeNode);
		T->data = post[n - 1]; 
		T->left = NULL;
		T->right = NULL;
		while (*(p++) != post[n - 1])k++;//得到左子树长度
		CreateTreeByIndex2(T->left, in, post, k);
		CreateTreeByIndex2(T->right, in + k + 1, post + k, n - k - 1);
	}
}

//-----------------------------------以下内容为二叉排序树------------------------------------------//
void InsertTreeNode(TreeNode * &root, int n) {
	//创造二叉搜索树的插入算法
	if (n < root->data) {
		if (root->left == NULL) {
			TreeNode *temp = new(TreeNode);
			temp->data = n;
			temp->left = NULL;
			temp->right = NULL;
			root->left = temp;
		}
		else InsertTreeNode(root->left, n);
	}
	else {
		if (root->right == NULL) {
			TreeNode *temp = new(TreeNode);
			temp->data = n;
			temp->left = NULL;
			temp->right = NULL;
			root->right = temp;
		}
		else InsertTreeNode(root->right, n);
	}
}

void CreateSearchedTree(TreeNode *&T) {
	int num,n;
	cout << "How many numbers do you want to insert: ";
	cin >> num;
	for (; num; num--) {
		cout << "请输入树的节点的值：" ;
		cin >> n;
		if (T == NULL) {
			T = new(TreeNode);
			T->data = n;
			T->left = NULL;
			T->right = NULL;
		}
		else {
			InsertTreeNode(T, n);
		}
	}
}

int FindSearchedTree(TreeNode *root, int n) {
	if (root == NULL) return 0;
	else {
		if (n == root->data) return 1;
			else if (n < root->data)  FindSearchedTree(root->left, n);
			else if (n > root->data)  FindSearchedTree(root->right, n);
	}
}

int DelRoot_x(TreeNode *&T, int x, int flag)
//递归删除二叉树中以x为根的子树，（flag为标志）
{
	if (T == NULL)
		return 0;
	else
	{
		if (T->data == x)    //如果当前节点的值为x，则更改标志位，在下面将向递归子函数中传递flag值
		{
			flag = 1;
		}
		int lef_ret = DelRoot_x(T->left, x, flag);  //递归左子树，lef_ret为从左子树中返回的信息
		int rig_ret = DelRoot_x(T->right, x, flag);  //递归右子树，rig_ret为从右子树中返回的信息
		if (1 == flag)       //如果标志为1，说明其祖父结点中有x，也就是说当前结点需要删除
		{
			if (T->data == x)    //如果是x结点，则需要向上层结点传递信息，以便其父节点将对应的指针域赋空
				return 1;
			delete T;
		}
		else
		{
			if (1 == lef_ret)    //从子结点接受收的信息，即如果其子结点为x，需要将其指针域赋空
				T->left = NULL;
			if (1 == rig_ret)   //从子结点接受收的信息，即如果其子结点为x，需要将其指针域赋空
				T->right = NULL;
		}
	}
	return  0;
}