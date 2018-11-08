#include <iostream>
#include "MyLinkedQueue.h"
using namespace std;
int main()
{
	int n;
	int i = 0; //控制输出空格的数目
	QueueNode *yanghui = InitQueue();
	QueueNode *yanghui2 = InitQueue();
	//EnqueueNum(yanghui, 1);
	cout << "Please input the height:" << endl;
	cin >> n;
	for (; n; n--) {
		int pre = 0;//先前一个数值
		while (yanghui->p != NULL) {
			int temp = Dequeue(yanghui);
			EnqueueNum(yanghui2, temp + pre);
			cout << temp;
			pre = temp;
		}
		EnqueueNum(yanghui2, 1);
		cout << 1<<endl;
		yanghui = yanghui2;
		DeleteQueue(yanghui2);
		//while (true) {//输出队列中两两相加后的值
		//	if (yanghui->p == NULL) {
		//		cout<< Dequeue(yanghui)<<endl;
		//		break;
		//	}
		//}
	}
	getchar();
	getchar();
	return 0;
}