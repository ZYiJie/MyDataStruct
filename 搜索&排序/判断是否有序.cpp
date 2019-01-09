#include <iostream>
using namespace std;
const int LEN = 10;
//�ж������Ƿ�����(1�������� 2�����ر��� 3����ȫ���)
int IsOrdered(int arr[], int n) {
	int direction = 0; //0�������� 1�������� 2������ 3����ȫ���
	for (int i = 0; i < n - 1; i++) {
		if (!(arr[i + 1] - arr[i])) {
			if (i == n - 2) return 3;
			else continue;
		}
		if (arr[i + 1] - arr[i] > 0) direction = 1;
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

int main() {
	int n, i;
	int arr[LEN]; 
	while (1) {
		cout << "Please input the number: ";
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		i = IsOrdered(arr, n);
		if (i == 1) cout << "����" << endl;
		else if (i == 2) cout << "����" << endl;
		else if (i == 3) cout << "ȫ���" << endl;
		else cout << "����" << endl;
	}
	

	getchar(); 
	getchar(); 
	return 0;
}
