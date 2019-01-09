#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//对无序列表的搜索（设置哨兵）
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

//对有序列表的折半查找
int OrderBinarySort(int arr[], int i, int j, int target) {
	int temp = (i + j) / 2;
	if (i == j && arr[i] != target) return 0;
	if (arr[temp] < target) return OrderBinarySort(arr, temp + 1, j, target);
	else if (arr[temp] > target) return OrderBinarySort(arr, i, temp, target);
	else
		return temp;
}
 
//判断序列是否有序(1代表升序 2代返回表降序 3代表全相等)
int IsOrdered(int arr[], int n) {
	int direction = 0; //0代表无序 1代表升序 2代表降序 3代表全相等
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

//---------------------------------以下为堆排序------------------------------------------

//构建大根堆
void MaxHeap(int arr[], int len, int i) {
	int left = 2 * i + 1, right = 2 * i + 2;
	int largest;
	if (left < len && arr[left] > arr[i])//最好将边界判断先于大小比较
		largest = left;
	else largest = i;
	if (right < len && arr[right] > arr[largest])//根节点与左节点比较完后，右节点再与其中的最大者比较
		largest = right;
	if (largest != i) {
		swap(arr[largest], arr[i]);
		MaxHeap(arr, len, largest);
	}
}
//堆排序
void HeapSort(int arr[], int len) {
	int i;
	for ( i = len / 2; i >= 0; i--) MaxHeap(arr, len, i);//构建大根堆（自下而上调整）
	for (i = len-1; i > 0; i--) {
		swap(arr[i], arr[0]);
		MaxHeap(arr, i, 0);//此处注意调整的数组范围递减
	}
}

//---------------------------以下为插入排序-----------------------

//单次插入
void Insert(int arr[], int len) {
	int i,target = arr[len];
	for (i = 0; i < len&&arr[i] <= target; i++);
	for (int j = len - 1; j >= i; j--) arr[j + 1] = arr[j]; //从len-1到i依次往后移1格
	arr[i] = target;
}

//直接插入排序
void InsertSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		Insert(arr, i);
	}
}

//折半插入排序
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

//---------------------------以下为快排---------------------------------------

//快排单次排序--左右指针法法
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

//快排单次排序--挖坑法 (无需额外储存空间)
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

//快排单次排序--前后指针法 (可以适用于链表的排序)
int PartSort3(int arr[], int p, int q) {
	int x = arr[q], cur, pre = p - 1;
	for (cur = p; cur <  q; cur++) {
		if (arr[cur] < x && ++pre != cur) //此处判断条件的次序：前者满足后，pre才能递增
			swap(arr[pre], arr[cur]);
	}
	swap(arr[pre + 1], arr[q]);
	return pre + 1;
}

//快速排序
void QuickSort(int arr[], int i, int j) {
	if (i < j) {
		int temp = PartSort1(arr, i, j);
		QuickSort(arr, i, temp-1);
		QuickSort(arr, temp+1, j);
	}
}


//基于快排的寻找序列第k大的算法(不改变数组的次序)
void FindNumberK(int arr[], int i, int j, int k) {
	int mid = PartSort1(arr, i, j);
	if (i <= j) {//注意i=j时也要有
		if (j - mid + 1 == k) {
			cout << arr[mid] << " ";
			return;
		}
		else if (j - mid + 1 > k) FindNumberK(arr, mid+1, j, k);
		else  FindNumberK(arr, i, mid-1, k-(j-mid+1));
	}
}



