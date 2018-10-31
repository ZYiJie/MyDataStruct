#include <iostream>
#define TRUE 1
using namespace std;
typedef struct StackNode {
	int data;
	StackNode *p;
};
StackNode* InitStack() {
	StackNode *top;
	top = new(StackNode);
	top->p = NULL;
	//cout << "Initialize successfully!" << endl;
	return top;
}
int CheckEmpty(StackNode* top) {
	if (top->p == NULL) return 1;
	return 0;
}
void PushInput(StackNode*top) {
	StackNode *temp;
	temp = new(StackNode);
	cin >> temp->data;
	temp->p = top->p;
	top->p = temp;
	//cout << top->p->data;
}
void PushNum(StackNode*top,int n) {
	StackNode *temp;
	temp = new(StackNode);
	temp->data = n;
	temp->p = top->p;
	top->p = temp;
	//cout << top->p->data;
}
int Pop(StackNode*top) {
	int result;
	StackNode *temp;
	if (CheckEmpty(top)) {
		cout << "The Stack is empty." << endl;
		return 0;
	}
		temp = top->p;
		result = temp->data;
		top->p = temp->p;
		delete(temp);
		return result;
}
void TraverseStack(StackNode*top) {
	StackNode *temp = top->p;
	int i = 1;
	while (temp != NULL) {
		cout  << temp->data <<" ";
		temp = temp->p;
	}
	cout<< endl;
}
