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
void GetSingleResult(char  ch, StackNode *top) {
	//从符号栈中每弹出一个符号就从数字栈中弹出两个数字进行计算，并push该结果进数字栈
	int  result;
	if (isnum(ch)) PushNum(top, ch);
	else {
		int n2 = Pop(top);
		int n1 = Pop(top);
		result = Multi(n1 - '0', n2 - '0',ch) + '0';
		PushNum(top, result);
	}
}
int main()
{
	int result;
	StackNode *shuzi = InitStack();
	StackNode *fuhao = InitStack();
	char str1[LEN];
	cout << "Please input operation:";
	cin >> str1;
	int i = 0;
	for (i = 0;; i++) {
		if (isnum(str1[i])) PushNum(shuzi,str1[i]) ;
		else {
			if (str1[i] == '\0') {   //字符串结尾时，弹出符号栈中的所有元素并计算
				while (!CheckEmpty(fuhao))
				GetSingleResult(Pop(fuhao), shuzi);
				cout << Pop(shuzi)-'0' << endl;  //表达式到结尾且符号栈弹空后，数字栈中只剩下最后的result
				break;
			}
			if (CheckEmpty(fuhao) || str1[i] == '(' ||fuhao->arr[fuhao->begin - 1] == '(')
				PushNum(fuhao, str1[i]);
			else if (str1[i] == ')') { //遇到右括号时，弹出符号栈中所有并计算直到遇到左括号
				while (fuhao->arr[fuhao->begin - 1] != '(') 
					GetSingleResult(Pop(fuhao), shuzi);
				Pop(fuhao); //弹出左括号（不赋值）
			}
			else if (str1[i] != ')'&&str1[i] != '(' && !CheckEmpty(fuhao)) {
				while (CmpFuhao(fuhao->arr[fuhao->begin - 1], str1[i])&&!CheckEmpty(fuhao)) {
					//cout << '1' << endl;
					GetSingleResult(Pop(fuhao), shuzi);
				}
				PushNum(fuhao, str1[i]); //符号栈弹出至遇到比str[1]优先级小的符号后，把str[1]push进符号栈
			}
		}
	}

	//printf("%d %d %d %d", '+', '-', '*', '/');
	getchar();
	getchar();
	return 0;
}