#include <iostream>
#include "MyLinkedQueue.h"
using namespace std;
int main()
{
	int n;
	int i; //控制输出的数目
	QueueNode *yanghui = InitQueue();
	QueueNode *yanghui2 = InitQueue();
	cout << "Please input the height:" << endl;
	cin >> n;
	//EnqueueNum(yanghui, 1); //初始化第一个值
	//cout << "1" << endl;
	
	for (i=0;i<n; i++) {
		for (int j = 0; j < (n - i )/2; j++) cout << "   ";//输出空格
		int pre = 0;//先前一个数值
		while (yanghui->p!=NULL) {
			int temp = Dequeue(yanghui);
			EnqueueNum(yanghui2, temp + pre);
			printf("%3d",pre+temp);
			pre = temp;
		}
		EnqueueNum(yanghui2, 1);
		cout << "  1"<<endl;
		while (yanghui2->p != NULL) {
			//将yanghui2中储存的内容转移到yanghui1中以便下一次输出
			int temp = Dequeue(yanghui2);
			EnqueueNum(yanghui, temp);
		}
   	}
	getchar();
	getchar();
	return 0;
}