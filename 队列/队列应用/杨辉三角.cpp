#include <iostream>
#include "MyLinkedQueue.h"
using namespace std;
int main()
{
	int n;
	int i; //�����������Ŀ
	QueueNode *yanghui = InitQueue();
	QueueNode *yanghui2 = InitQueue();
	cout << "Please input the height:" << endl;
	cin >> n;
	//EnqueueNum(yanghui, 1); //��ʼ����һ��ֵ
	//cout << "1" << endl;
	
	for (i=0;i<n; i++) {
		for (int j = 0; j < (n - i )/2; j++) cout << "   ";//����ո�
		int pre = 0;//��ǰһ����ֵ
		while (yanghui->p!=NULL) {
			int temp = Dequeue(yanghui);
			EnqueueNum(yanghui2, temp + pre);
			printf("%3d",pre+temp);
			pre = temp;
		}
		EnqueueNum(yanghui2, 1);
		cout << "  1"<<endl;
		while (yanghui2->p != NULL) {
			//��yanghui2�д��������ת�Ƶ�yanghui1���Ա���һ�����
			int temp = Dequeue(yanghui2);
			EnqueueNum(yanghui, temp);
		}
   	}
	getchar();
	getchar();
	return 0;
}