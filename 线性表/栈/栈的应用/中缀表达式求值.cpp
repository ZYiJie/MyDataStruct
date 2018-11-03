#include <iostream>
#include "MyArrayStack.h"
#define TRUE 1
#define LEN 100
using namespace std;
int isnum(char n) {
	if (n >= '0'&&n <= '9') return 1;
	return 0;
}
int GiveLevel(char fuhao) {
	if (fuhao == '+') return 1;
	if (fuhao == '-') return 1;
	if (fuhao == '*') return 2;
	if (fuhao == '/') return 2;
	if (fuhao == '(') return 3;
}
int CmpFuhao(char a, char b) {
	//比较符号a、b的优先级，a优先级高返回1
	int x = GiveLevel(a);
	int y = GiveLevel(b);
	return x>=y;
}
int Multi(int m, int n, char fuhao) {
	if (fuhao == '+') return m + n;
	if (fuhao == '-') return m - n;
	if (fuhao == '*') return m * n;
	if (fuhao == '/') return m / n;
}

int GetResult(char *str, StackNode *top) {
	int i, result;
	for (i = 0; ; i++) {
		if (isnum(str[i])) PushNum(top, str[i]);
		else {
			int n2 = Pop(top);
			int n1 = Pop(top);
			result = Multi(n1 - '0', n2 - '0', str[i]) + '0';
			if (str[i + 1] == '\0') {
				return result - '0';
			}
			else {
				PushNum(top, result);
			}
		}
	}
}
int main()
{
	int result;
	StackNode *top = InitStack();
	StackNode *top2 = InitStack();
	char str1[LEN], str2[LEN];
	cout << "Please input operation:";
	cin >> str1;
	int i, j = 0;
	for (i = 0;; i++) {
		if (isnum(str1[i])) str2[j++] = str1[i];
		else {
			if (str1[i] == '\0') {   //字符串结尾时，弹出栈中的所有元素至目标数组
				while (!CheckEmpty(top))
					str2[j++] = Pop(top);
				str2[j] = '\0';
				break;
			}
			if (CheckEmpty(top) || str1[i] == '(' || top->arr[top->begin - 1] == '(')
				PushNum(top, str1[i]);
			else if (str1[i] == ')') { //遇到右括号时，弹出所有至目标数组直到遇到左括号
				while (top->arr[top->begin - 1] != '(') 
					str2[j++] = Pop(top);
				Pop(top); //弹出左括号（不赋值）
			}
			else if (str1[i] != ')'&&str1[i] != '(' && !CheckEmpty(top)) {
				while (CmpFuhao(top->arr[top->begin - 1], str1[i])&&!CheckEmpty(top)) {
					//cout << '1' << endl;
					str2[j++] = Pop(top);
				}
				PushNum(top, str1[i]);
			}
		}
	}
	result = GetResult(str2,top2);
	cout << result << endl;
	//printf("%d %d %d %d", '+', '-', '*', '/');
	getchar();
	getchar();
	return 0;
}