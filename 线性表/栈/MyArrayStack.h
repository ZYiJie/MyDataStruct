#include <iostream>
#define TRUE 1
#define STACKSIZE 100
using namespace std;
typedef struct StackNode {
	int arr[STACKSIZE];
	int begin;
};
StackNode* InitStack() {
	StackNode *top;
	top = new(StackNode);
	top->begin = 0;
	return top;
}
int CheckEmpty(StackNode*top) {
	return !(top->begin);
}
int CheckFull(StackNode*top) {
	if (top->begin == STACKSIZE-1) return 1;
	return 0;
}
void PushInput(StackNode* top) {
	if (CheckFull(top)) { cout << "The Stack is full." << endl; return; }
	if (CheckEmpty(top)) top->begin++;
	cin >> top->arr[top->begin];
	top -> begin++;
	//cout << top->p->data;
}
void PushNum(StackNode* top,int num) {
	if (CheckFull(top)) { cout << "The Stack is full." << endl; return; }
	if (CheckEmpty(top)) top->begin++;
	top->arr[top->begin] = num;
	top->begin++;
	//cout << top->p->data;
}
int Pop(StackNode*top) {
	int result; 
	if (CheckEmpty(top)) { cout << "The Stack is empty." << endl; return 0; }
	top->begin--;
	result = top->arr[top->begin];
	if(top->begin==1) top->begin--;
	return result;

}
void TraverseStack(StackNode*top) {
	int i;
	for (i = top->begin-1; i; i--) cout << top->arr[i]<<" ";
	cout << endl;
}
