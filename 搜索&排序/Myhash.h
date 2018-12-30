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
	//����������7ȡ����Ϊkeyֵ���������ַ�������ͻ
	int key = n % YUSHU;
	PushLlist(arr[key], n);
}

int SearchHash(int n) {
	//����n��arr�е��±꼰���������е�λ��
	int key = n % YUSHU;
	return FindLlist2(arr[key], n);
}
