int UnorderSort(int arr[], int i, int target) {
	//�������б�������������ڱ���
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
	//�������б���۰�c=����
	int temp = (i+j)/2;
	if (i == j && arr[i] != target) return 0;
	if (arr[temp] < target) return OrderBinarySort(arr, temp + 1, j, target);
	else if(arr[temp] > target) return OrderBinarySort(arr, i, temp, target);
	else 
		return temp;
}

//----------------------------����Ϊ��ϣ�����ز���--------------------------------//
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