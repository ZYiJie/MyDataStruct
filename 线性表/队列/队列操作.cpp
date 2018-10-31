#include <iostream>
#include "MyLinkedQueue.h"
#define TRUE 1
using namespace std;
int main()
{
	int n;
	QueueNode *top = InitQueue();
	while (TRUE) {
		cout << "1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\nPlease choose:  ";
		cin >> n;
		if (n == 1) { cout << "Please input:  "; EnqueueInput(top); }
		else if (n == 2) {
			int temp = Dequeue(top);
			cout << temp << endl;
		}
		else if (n == 3) TraverseQueue(top);
		else break;
	}
	return 0;
}