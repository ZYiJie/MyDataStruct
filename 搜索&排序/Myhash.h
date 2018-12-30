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
