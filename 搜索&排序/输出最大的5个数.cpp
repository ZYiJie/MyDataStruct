#include <iostream>
#include "Sort_Search.h"
using namespace std;
const int LEN = 10;

int main() {
	int n, i;
	int arr[LEN]; 
	cout << "Please input the number: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 1; i <= 5; i++)
		cout<<FindNumberK(arr, 0, n - 1, i)<<" ";

	getchar(); 
	getchar(); 
	return 0;
}
