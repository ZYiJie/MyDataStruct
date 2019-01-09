#include <iostream>
using namespace std;
const int LEN = 10;
//判断序列是否有序(1代表升序 2代返回表降序 3代表全相等)
int IsOrdered(int arr[], int n) {
	int direction = 0; //0代表无序 1代表升序 2代表降序 3代表全相等
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
		if (i == 1) cout << "升序" << endl;
		else if (i == 2) cout << "降序" << endl;
		else if (i == 3) cout << "全相等" << endl;
		else cout << "无序" << endl;
	}
	

	getchar(); 
	getchar(); 
	return 0;
}
