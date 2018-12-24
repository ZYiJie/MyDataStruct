int UnorderSort(int arr[], int i, int target) {
	//对无序列表的搜索（设置哨兵）
	arr[0] = target;
	for (int j = i; ; j--) {
		if (arr[j] == target)
			return j;
	}
}

void BubbleSort(int arr[], int i) {
	for (int j = 1; j <= i; j++) {
		for (int k = 1; k < i - j; k++) {
			if (arr[k] > arr[k + 1]) {
				int temp = arr[k+1];
				arr[k + 1] = arr[k];
				arr[k] = temp;
			}
		}
	}
}

int OrderBinarySort(int arr[], int i,int j, int target) {
	//对有序列表的折半c=查找
	int temp = (i+j)/2;
	if (i == j && arr[i] != target) return 0;
	if (arr[temp] < target) return OrderBinarySort(arr, temp + 1, j, target);
	else if(arr[temp] > target) return OrderBinarySort(arr, i, temp, target);
	else 
		return temp;
}

//----------------------------以下为哈希表的相关操作--------------------------------//
#include "LinkedList.h"
const int LEN2 = 10;
const int YUSHU = 7;
Llist *arr[LEN2];

void InitHash() {
	for (int i = 0; i < LEN2; i++) {
		arr[i] = LlistInit();
	}
}

void InsertHashNum(int n) {
	//输入整数除7取余作为key值，用链表地址法处理冲突
	int key = n % YUSHU;
	PushLlist(arr[key], n);
}

int SearchHash(int n) {
	//返回n在arr中的下标及其在链表中的位置
	int key = n % YUSHU;
	return FindLlist2(arr[key], n);
}