#include <iostream>
#define TRUE 1
#define QueueSIZE 100
using namespace std;
typedef struct QueueNode {
	int arr[QueueSIZE];
	int begin;
	int last;
};
QueueNode* InitQueue() {
	QueueNode *top;
	top = new(QueueNode);
	top->begin = top->last = 0;
	return top;
}
int CheckEmpty(QueueNode*top) {
	return (top->begin==top->last);
}
int CheckFull(QueueNode*top) {
	if (top->last == QueueSIZE - 1) return 1;
	return 0;
}
void EnqueueInput(QueueNode* top) {
	if (CheckFull(top)) { cout << "The Queue is full." << endl; return; }
	//if (CheckEmpty(top)) top->last++;
	cin >> top->arr[top->last];
	top->last++;
	//cout << top->p->data;
}
void EnqueueNum(QueueNode* top, int num) {
	if (CheckFull(top)) { cout << "The Queue is full." << endl; return; }
	//if (CheckEmpty(top)) top->last++;
	top->arr[top->last] = num;
	top->last++;
	//cout << top->p->data;
}
int Dequeue(QueueNode*top) {
	int result;
	if (CheckEmpty(top)) { cout << "The Queue is empty." << endl; return 0; }
	result = top->arr[top->begin];
	top->begin++;
	//if (top->begin == 1) top->begin--;
	return result;

}
void DeleteQueue(QueueNode*top) {
	top->begin = top->last = 0;
	cout << "Delete successfully!";
	cout << endl;
}

void TraverseQueue(QueueNode*top) {
	int i;
	for (i = top->begin ; i<top->last; i++) cout << top->arr[i] << " ";
	cout << endl;
}
