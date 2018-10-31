#include <iostream>
#define TRUE 1
using namespace std;
typedef struct QueueNode {
	int data;
	QueueNode *p;
};
QueueNode* InitQueue() {
	QueueNode *top;
	top = new(QueueNode);
	top->p = NULL;
	//cout << "Initialize successfully!" << endl;
	return top;
}
int CheckEmpty(QueueNode* top) {
	if (top->p == NULL) return 1;
	return 0;
}
void EnqueueInput(QueueNode*top) {
	QueueNode *temp,*flag=top;
	temp = new(QueueNode);
	cin >> temp->data;
	temp->p = NULL;
	while ((flag->p) != NULL) flag = flag->p;
	flag->p = temp;
	//cout << top->p->data;
}
void EnqueueNum(QueueNode*top, int n) {
	QueueNode *temp,*flag=top;
	temp = new(QueueNode);
	temp->data = n;
	temp->p = NULL;
	while ((flag->p) != NULL) flag = flag->p;
	flag->p = temp;
	//cout << top->p->data;
}
int Dequeue(QueueNode*top) {
	int result;
	QueueNode *temp;
	if (CheckEmpty(top)) {
		cout << "The Queue is empty." << endl;
		return 0;
	}
	temp = top->p;
	result = temp->data;
	top->p = temp->p;
	delete(temp);
	return result;
}
void TraverseQueue(QueueNode*top) {
	QueueNode *temp = top->p;
	int i = 1;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->p;
	}
	cout << endl;
}
