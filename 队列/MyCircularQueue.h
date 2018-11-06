#include <iostream>
#define TRUE 1
#define QUEUESIZE 3
using namespace std;
//����������е�ģʽ���ڳ������ʱʹ��ȡ�����ʵ������ռ��ѭ��ʹ��
//�ж϶��еĿ��������ֲ�����1.��¼��һ�β���2.��¼����ʹ���˵Ŀռ�3.����һ���ռ䣨�����˵ڶ��ַ�����
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
	if (top->last > QUEUESIZE - 1) top->last = (top->last) % QUEUESIZE; //�ؼ��������(��last=3��num<SIZE)ʱ ����λ��Ϊ last%SIZE
	top->num++;
	//cout << top->p->data;
}
void EnqueueNum(QueueNode* top, int num) {
	if (CheckFull(top)) { cout << "The Queue is full." << endl; return; }
	//if (CheckEmpty(top)) top->last++;
	top->arr[top->last] = num;
	top->last++;
	if(top->last>QUEUESIZE-1) top->last = (top->last)%QUEUESIZE; //�ؼ��������ʱ ����λ��Ϊ last%SIZE
	top->num++;
	//cout << top->p->data;
}
int Dequeue(QueueNode*top) {
	int result;
	if (CheckEmpty(top)) { cout << "The Queue is empty." << endl; return 0; }
	result = top->arr[top->begin];
	top->begin++;
	top->begin = (top->begin)%QUEUESIZE; //�ؼ��������ʱ ����λ��Ϊ last%SIZE
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
		if (i > QUEUESIZE - 1) i = i  % QUEUESIZE; //�ؼ��������ʱ ����λ��Ϊ last%SIZE
	}
	cout << endl;
}
