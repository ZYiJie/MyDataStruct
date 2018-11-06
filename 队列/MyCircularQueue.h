#include <iostream>
#define TRUE 1
#define QUEUESIZE 3
using namespace std;
//采用数组队列的模式，在出入队列时使用取余操作实现数组空间的循环使用
//判断队列的空满有三种操作：1.记录上一次操作2.记录数组使用了的空间3.少用一个空间（我用了第二种方法）
typedef struct QueueNode {
	int arr[QUEUESIZE];
	int begin;
	int last;
	int num;
};
QueueNode* InitQueue() {
	QueueNode *top;
	top = new(QueueNode);
	top->begin = top->last = 0;
	top->num = 0;
	return top;
}
int CheckEmpty(QueueNode*top) {
	return (top->num == 0);
}
int CheckFull(QueueNode*top) {
	if (top->num == QUEUESIZE ) return 1;
	return 0;
}
void EnqueueInput(QueueNode* top) {
	if (CheckFull(top)) { cout << "The Queue is full." << endl; return; }
	//if (CheckEmpty(top)) top->last++;
	cin >> top->arr[top->last];
	top->last++;
	if (top->last > QUEUESIZE - 1) top->last = (top->last) % QUEUESIZE; //关键：假溢出(即last=3但num<SIZE)时 插入位置为 last%SIZE
	top->num++;
	//cout << top->p->data;
}
void EnqueueNum(QueueNode* top, int num) {
	if (CheckFull(top)) { cout << "The Queue is full." << endl; return; }
	//if (CheckEmpty(top)) top->last++;
	top->arr[top->last] = num;
	top->last++;
	if(top->last>QUEUESIZE-1) top->last = (top->last)%QUEUESIZE; //关键：假溢出时 插入位置为 last%SIZE
	top->num++;
	//cout << top->p->data;
}
int Dequeue(QueueNode*top) {
	int result;
	if (CheckEmpty(top)) { cout << "The Queue is empty." << endl; return 0; }
	result = top->arr[top->begin];
	top->begin++;
	top->begin = (top->begin)%QUEUESIZE; //关键：假溢出时 插入位置为 last%SIZE
	top->num--;
	//if (top->begin == 1) top->begin--;
	return result;

}
void DeleteQueue(QueueNode*top) {
	top->begin = top->last = 0;
	top->num = 0;
	cout << "Delete successfully!";
	cout << endl;
}

void TraverseQueue(QueueNode*top) {
	int i=top->begin,j;
	for (j = 0; j < top->num;j++) {
		cout << top->arr[i] << " ";
		i++;
		if (i > QUEUESIZE - 1) i = i  % QUEUESIZE; //关键：假溢出时 插入位置为 last%SIZE
	}
	cout << endl;
}
