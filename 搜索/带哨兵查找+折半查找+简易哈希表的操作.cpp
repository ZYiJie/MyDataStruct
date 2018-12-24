#include <iostream>
#include "Sort_Search.h"
using namespace std;
const int LEN = 100;
int main() {
	int n,i,target;
	int arr[LEN]; //为方便设置哨兵，数组下标从1开始使用
	cout << "Please input the number: ";
	cin >> n;
	for ( i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	BubbleSort(arr, i);
	cout << "After sorting:";
	for (i = 1; i <= n; i++) {
		cout<<" "<<arr[i];
	}
	cout <<endl<< "Please input target:";
	cin >> target;
	cout << OrderBinarySort(arr, 0, i, target)<<endl;

	//-----------------------------以下为哈希表------------------------------//
	cout << "Please input the number of Hash Table: ";
	cin >> n;
	InitHash();
	for (int i = 0; i < n; i++) {
		int temp;
		cout << "Please input data: ";
		cin >> temp;
		InsertHashNum(temp);
	}
	int target2,flag;
	while(1) {
		cout << "Please input what data do you want search( '<0' to exit ): ";
		cin >> target2;
		if (target2 <0) break;
		flag = SearchHash(target2);
		if (flag)
			cout << "The [" << target2 << "] is in the arr[" << target2 % YUSHU << "] and index of: " << flag << endl;
		else
			cout << "No Found!" << endl;
	}
	getchar(); 
	getchar(); 
	return 0;
}
