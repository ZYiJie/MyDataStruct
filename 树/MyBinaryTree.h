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
void PreCreateTree_n(TreeNode *&T,int n) {
	//ͨ������ݹ�ķ�ʽ������
	if (n == 0)              //Ҷ�ڵ����ݱ�־����������0 
		T = NULL;            //��ĳһ�ڵ�ΪҶ�ӽ�㣬��������������ΪNULL��0��ʾ������
	else
	{
		T = new(TreeNode);
		T->data = n;
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

void LevelTraverseTree(TreeNode* root) {
	//ʹ�ö���ʵ�ֲ�α���
	queue <TreeNode*>q;
	//��Ϊ�գ�ֱ�ӷ���
	if (root == NULL)
	{
		return;
	}
	//�Ƚ����ڵ����
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
	if ( root==NULL || (root->left == NULL && root->right == NULL) ) {
		return 0;
	}
	else {
		return GetNotLeafNumber(root->left) + GetNotLeafNumber(root->right)+1;
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

//void DeleteTree(TreeNode * &root,stack <TreeNode*>arr) {
//	//ɾ��root�������з�֧(������)
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
	//������λ����һ��ֵΪn�����Ľڵ㣬���ص�temp��
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
	//ͨ��ǰ��+�������й�����
	int k = 0; char * p = in; //nΪ(��)���ڵ����
	if (pre&&n) {
		T = new(TreeNode);
		T->data = pre[0];
		T->left = NULL;
		T->right = NULL;
		while (*(p++) != pre[0])k++;//�õ��������ڵ����
		CreateTreeByIndex(T->left, pre + 1, in, k);
		CreateTreeByIndex(T->right, pre + k + 1, in + k + 1, n - k - 1);
	}
}

void CreateTreeByIndex2(TreeNode *&T, char *in, char * post, int n) {
	//ͨ������+�������й�����
	int k = 0; char *p = in;
	if (post&&n) {
		T = new(TreeNode);
		T->data = post[n - 1]; 
		T->left = NULL;
		T->right = NULL;
		while (*(p++) != post[n - 1])k++;//�õ�����������
		CreateTreeByIndex2(T->left, in, post, k);
		CreateTreeByIndex2(T->right, in + k + 1, post + k, n - k - 1);
	}
}

//-----------------------------------��������Ϊ����������------------------------------------------//
void InsertTreeNode(TreeNode * &root, int n) {
	//��������������Ĳ����㷨
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
		cout << "���������Ľڵ��ֵ��" ;
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
//�ݹ�ɾ������������xΪ������������flagΪ��־��
{
	if (T == NULL)
		return 0;
	else
	{
		if (T->data == x)    //�����ǰ�ڵ��ֵΪx������ı�־λ�������潫��ݹ��Ӻ����д���flagֵ
		{
			flag = 1;
		}
		int lef_ret = DelRoot_x(T->left, x, flag);  //�ݹ���������lef_retΪ���������з��ص���Ϣ
		int rig_ret = DelRoot_x(T->right, x, flag);  //�ݹ���������rig_retΪ���������з��ص���Ϣ
		if (1 == flag)       //�����־Ϊ1��˵�����游�������x��Ҳ����˵��ǰ�����Ҫɾ��
		{
			if (T->data == x)    //�����x��㣬����Ҫ���ϲ��㴫����Ϣ���Ա��丸�ڵ㽫��Ӧ��ָ���򸳿�
				return 1;
			delete T;
		}
		else
		{
			if (1 == lef_ret)    //���ӽ������յ���Ϣ����������ӽ��Ϊx����Ҫ����ָ���򸳿�
				T->left = NULL;
			if (1 == rig_ret)   //���ӽ������յ���Ϣ����������ӽ��Ϊx����Ҫ����ָ���򸳿�
				T->right = NULL;
		}
	}
	return  0;
}