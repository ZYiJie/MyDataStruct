#include <iostream>
#include<queue>
#include<string>
using namespace std;
string str[26];
int path_len = 0;

typedef struct TreeNode {
	TreeNode *parent;
	TreeNode * left;
	TreeNode * right;
	int data;
	int n;
};

TreeNode * CreateHuffmanTree(int arr[26][2],int num) {
	vector <TreeNode*> forest;
	for (int j = 0; j < num; j++) {
		TreeNode *temp = new(TreeNode);
		temp->left = NULL;
		temp->right = NULL;
		temp->parent = NULL;
		temp->data = arr[j][0];
		temp->n = arr[j][1];
		forest.push_back(temp);
	}
	while (forest.size() != 1) {
		int min1=0, min2=1;
		if (forest[min1]->n > forest[min2]->n) {
			int temp;
			temp = min1;
			min1 = min2;
			min2 = temp;
		}
		for (int j = 0; j < forest.size(); j++) {
			//找到forest中根的权重最小的两棵树
			if (forest[j]->n < forest[min1]->n) {
				min2 = min1;
				min1 = j;
			}
			else if (forest[j]->n < forest[min2]->n) {
				min2 = j;
			}
			if (min1 == min2) min2++;
		}
		//以下将两棵权重最小的树合并
		TreeNode *t1 = forest[min1];
		TreeNode *t2 = forest[min2];
		TreeNode *new_root = new(TreeNode);
		new_root->left = t1;
		new_root->right = t2;
		new_root->parent = NULL;
		new_root->n = t1->n + t2->n;
		new_root->data = 0;
		forest.erase(forest.begin()+min1);
		if(min1>min2) forest.erase(forest.begin() + min2);
		else forest.erase(forest.begin() + min2-1);
		forest.push_back(new_root);
	}
	return forest[0];
}


void code(TreeNode* FBT, int len, int arr[26][2],int n)
{
	static int a[10];
	if (FBT != NULL)
	{
		if (FBT->left == NULL && FBT->right == NULL)
		{
			for (int j =0 ; j <n; j++) {
				if (FBT->n == arr[j][1]) {
					int flag =  0;
					char ch = arr[j][0];
					for (int k = 0; k < n; k++) { 
						if (str[k][0]==ch)  flag = 1; 
					}
					if (flag) continue;
					cout << "The code of [" << ch << "] is: ";
					str[path_len].push_back(ch);
					break;
				}
			}
			
			for (int i = 0; i < len; i++) {
				cout << a[i];
				str[path_len].push_back(a[i]+'0');
			}
			path_len++;
			cout << endl;
		}
		else
		{
			a[len] = 0;
			code(FBT->left, len + 1,arr,n);
			a[len] = 1;
			code(FBT->right, len + 1,arr,n);
		}
	}
}
