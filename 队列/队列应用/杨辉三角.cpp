#include <iostream>
#include "MyLinkedQueue.h"
using namespace std;
int main()
{
	int n;
	int i = 0; //��������ո����Ŀ
	QueueNode *yanghui = InitQueue();
	QueueNode *yanghui2 = InitQueue();
	//EnqueueNum(yanghui, 1);
	cout << "Please input the height:" << endl;
	cin >> n;
	for (; n; n--) {
		int pre = 0;//��ǰһ����ֵ
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
		//while (true) {//���������������Ӻ��ֵ
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