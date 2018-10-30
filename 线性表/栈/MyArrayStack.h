#include <iostream>
#define TRUE 1
#define STACKSIZE 100
using namespace std;
typedef struct StackNode {
	int arr[STACKSIZE];
	int head;
	int tail;
};
StackNode* InitStack() {
	StackNode *top;
	top = new(StackNode);
	top->head = top->tail = 0;
	return top;
}
int CheckEmpty(StackNode*top) {
	if (top->head == top->tail) return 1;
	return 0;
}
void Push(StackNode* top) {
	cin >> top->arr[top->tail];
	top -> tail++;
	//cout << top->p->data;
}

int Pop(StackNode*top) {
	int result;
	if (!CheckEmpty(top)) {
		top->head++;
		return (top->arr[top->head-1]);
	}
	else {
		cout << "The Stack is empty." << endl;
	}
}
void TraverseStack(StackNode*top) {
	int i;
	for (i = top->head; i < top->tail; i++) cout << top->arr[i]<<" ";
	cout << endl;
}
