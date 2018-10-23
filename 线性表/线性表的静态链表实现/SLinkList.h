#include <iostream>
#define LEN 1000
using namespace std;

int Init_SL(int arr[], int seq[])
{
	int i, bengin = 1, n;
	for (i = 0; i < LEN; i++) seq[i] = i + 1;
	cout << "How many numbers do you want to add:";
	cin >> n;
	for (i = bengin; n; n--, i++) cin >> arr[i];
	seq[0] = i;
	seq[i - 1] = 0;
	return bengin;
}

void Add_SL(int arr[], int seq[],int begin) {
	int i = seq[0], j, n;
	for (j = seq[begin]; seq[j]; j = seq[j]) ;
	seq[j] = i;
	cout << "How many numbers do you want to add:";
	cin >> n;
	for (; n; n--) {
		cin >> arr[i];
		if (n == 1) { seq[0] = i; seq[i] = 0; }
		i = seq[i];
	}
}

void Delete_SL(int arr[], int seq[], int *begin) {
	int n, i, target;
	cout << "How many numbers do you want to delete:";
	cin >> n;
	while (n) {
		cout << "Which number do you want to delete:";
		cin >> target;
		for (i = *begin; ; i = seq[i]) {
			//if (!i) { cout << "No Found!" << endl; break; }
			if (target == arr[*begin]) {
				int temp = *begin;
				*begin = seq[*begin];
				seq[temp] = seq[0];
				seq[0] = temp;
				n--;
				break;
			}
			if (arr[seq[i]] == target) {
				/*cout << "ok";*/
				int temp = seq[i];
				seq[i] = seq[seq[i]];
				seq[temp] = seq[0];
				seq[0] = temp;
				n--;
				break;
			}
		}
	}
}

void Traverse_SL(int arr[], int seq[], int begin) {
	int i = begin;
	while (i) {
		cout << arr[i] << " ";
		i = seq[i];
	}
	cout << "\n";
}