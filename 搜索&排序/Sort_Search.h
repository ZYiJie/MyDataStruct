#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//�������б�������������ڱ���
int UnorderSort(int arr[], int i, int target) {
	arr[0] = target;
	for (int j = i; ; j--) {
		if (arr[j] == target)
			return j;
	}
}

void BubbleSort(int arr[], int i) {
	for (int j = 1; j <= i; j++) {
		for (int k = 1; k < i - j; k++) {
			if (arr[k] > arr[k + 1])
				swap(arr[k], arr[k + 1]);
		}
	}
}

//�������б���۰����
int OrderBinarySort(int arr[], int i, int j, int target) {
	int temp = (i + j) / 2;
	if (i == j && arr[i] != target) return 0;
	if (arr[temp] < target) return OrderBinarySort(arr, temp + 1, j, target);
	else if (arr[temp] > target) return OrderBinarySort(arr, i, temp, target);
	else
		return temp;
}
 
//�ж������Ƿ�����(1�������� 2�����ر��� 3����ȫ���)
int IsOrdered(int arr[], int n) {
	int direction = 0; //0�������� 1�������� 2������ 3����ȫ���
	for (int i = 0; i < n - 1; i++) {
		if (!(arr[i + 1] - arr[i])) {
			if (i == n - 2) return 3;
			else continue;
		}
		if (arr[i + 1] - arr[i]>0) direction = 1;
		else direction = 2;
		break;
	}
	if (direction == 1) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i + 1] - arr[i] < 0) return 0;
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i + 1] - arr[i] > 0) return 0;
		}
	}
	return direction;
	
}

//---------------------------------����Ϊ������------------------------------------------

//���������
void MaxHeap(int arr[], int len, int i) {
	int left = 2 * i + 1, right = 2 * i + 2;
	int largest;
	if (left < len && arr[left] > arr[i])//��ý��߽��ж����ڴ�С�Ƚ�
		largest = left;
	else largest = i;
	if (right < len && arr[right] > arr[largest])//���ڵ�����ڵ�Ƚ�����ҽڵ��������е�����߱Ƚ�
		largest = right;
	if (largest != i) {
		swap(arr[largest], arr[i]);
		MaxHeap(arr, len, largest);
	}
}
//������
void HeapSort(int arr[], int len) {
	int i;
	for ( i = len / 2; i >= 0; i--) MaxHeap(arr, len, i);//��������ѣ����¶��ϵ�����
	for (i = len-1; i > 0; i--) {
		swap(arr[i], arr[0]);
		MaxHeap(arr, i, 0);//�˴�ע����������鷶Χ�ݼ�
	}
}

//---------------------------����Ϊ��������-----------------------

//���β���
void Insert(int arr[], int len) {
	int i,target = arr[len];
	for (i = 0; i < len&&arr[i] <= target; i++);
	for (int j = len - 1; j >= i; j--) arr[j + 1] = arr[j]; //��len-1��i����������1��
	arr[i] = target;
}

//ֱ�Ӳ�������
void InsertSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		Insert(arr, i);
	}
}

//�۰��������
void BinarySort(int arr[], int len) {
	int i, j, mid, x ;
	for (int k = 1; k < len; k++) {
		i = 0;
		j = k-1;
		x = arr[k];
		while (i <= j) {
			mid = (i + j) / 2;
			if (x > arr[mid]) i = mid + 1;
			else j = mid - 1;
		}
		for (int m = k; m > i; m--) arr[m] = arr[m-1];
		arr[i] = x;
	}
}

//---------------------------����Ϊ����---------------------------------------

//���ŵ�������--����ָ�뷨��
int PartSort1(int arr[], int p, int q) {
	int  x=q;
	while (p<q) {
		while (p < q && arr[p] <= arr[x]) p++;
		while (p < q && arr[q] >= arr[x]) q --;
		swap(arr[p], arr[q]);
	}
	swap(arr[x], arr[p]);
	return p;
}

//���ŵ�������--�ڿӷ� (������ⴢ��ռ�)
int PartSort2(int arr[], int p, int q) {
	int x = arr[q];
	while (p < q) {
		while (p < q && arr[p] <= x) p++;
		arr[q] = arr[p];
		while (p < q && arr[q] >= x) q--;
		arr[p] = arr[q];
	}
	arr[q] = x;
	return q;
}

//���ŵ�������--ǰ��ָ�뷨 (�������������������)
int PartSort3(int arr[], int p, int q) {
	int x = arr[q], cur, pre = p - 1;
	for (cur = p; cur <  q; cur++) {
		if (arr[cur] < x && ++pre != cur) //�˴��ж������Ĵ���ǰ�������pre���ܵ���
			swap(arr[pre], arr[cur]);
	}
	swap(arr[pre + 1], arr[q]);
	return pre + 1;
}

//��������
void QuickSort(int arr[], int i, int j) {
	if (i < j) {
		int temp = PartSort1(arr, i, j);
		QuickSort(arr, i, temp-1);
		QuickSort(arr, temp+1, j);
	}
}


//���ڿ��ŵ�Ѱ�����е�k����㷨(���ı�����Ĵ���)
void FindNumberK(int arr[], int i, int j, int k) {
	int mid = PartSort1(arr, i, j);
	if (i <= j) {//ע��i=jʱҲҪ��
		if (j - mid + 1 == k) {
			cout << arr[mid] << " ";
			return;
		}
		else if (j - mid + 1 > k) FindNumberK(arr, mid+1, j, k);
		else  FindNumberK(arr, i, mid-1, k-(j-mid+1));
	}
}



