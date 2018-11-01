#include <iostream>
#include "MyArrayStack.h"
#define TRUE 1
#define LEN 100
using namespace std;
int isnum(char n) {
	if (n >= '0'&&n <= '9') return 1;
	return 0;
}
int Multi(int m, int n, char fuhao) {
	if (fuhao == '+') return m + n;
	if (fuhao == '-') return m - n;
	if (fuhao == '*') return m * n;
	if (fuhao == '/') return m / n;
}
int main()
{
	int i, result;
	StackNode *top = InitStack();
	char str[LEN];
	cout << "Please input operation:";
	cin >> str;
	for (i = 0; ; i++) {
		if (isnum(str[i])) PushNum(top, str[i]);
		else {
			int n2 = Pop(top);
			int n1 = Pop(top);
			result = Multi(n1 - '0', n2 - '0', str[i]) + '0';
			if (str[i + 1] == '\0') {
				cout << result - '0' << endl;
				break;
			}
			else {
				PushNum(top, result);;
			}
		}
	}
	getchar();
	getchar();
	return 0;
}