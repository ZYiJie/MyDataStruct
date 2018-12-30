#include <iostream>
#include "Sort_Search.h"
using namespace std;
const int LEN = 10;


int main() {
	int n,i,target;
	int arr[LEN]; 
	int arr1[LEN], arr2[LEN], arr3[LEN];
	cout << "Please input the number: ";
	cin >> n;
	for ( i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = arr1[i] = arr2[i] = arr3[i] = temp;
	}
	InsertSort(arr, n);
	BinarySort(arr1, n);
	HeapSort(arr2, n);
	QuickSort(arr3, 0, n - 1);

	cout << "After sorting:"<<endl;
	cout << "InsertSort: ";
	for (i = 0; i < n; i++) {
		cout<<" "<<arr[i];
	}
	cout << endl;
	cout << "BinarySort: ";
	for (i = 0; i < n; i++) {
		cout << " " << arr1[i];
	}
	cout << endl;
	cout << "HeapSort: ";
	for (i = 0; i < n; i++) {
		cout << " " << arr2[i];
	}
	cout << endl;
	cout << "QuickSort: ";
	for (i = 0; i < n; i++) {
		cout << " " << arr3[i];
	}
	getchar(); 
	getchar(); 
	return 0;
}
