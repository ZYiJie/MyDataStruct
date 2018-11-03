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
	//�ȽϷ���a��b�����ȼ���a���ȼ��߷���1
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
	//�ӷ���ջ��ÿ����һ�����žʹ�����ջ�е����������ֽ��м��㣬��push�ý��������ջ
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
			if (str1[i] == '\0') {   //�ַ�����βʱ����������ջ�е�����Ԫ�ز�����
				while (!CheckEmpty(fuhao))
				GetSingleResult(Pop(fuhao), shuzi);
				cout << Pop(shuzi)-'0' << endl;  //���ʽ����β�ҷ���ջ���պ�����ջ��ֻʣ������result
				break;
			}
			if (CheckEmpty(fuhao) || str1[i] == '(' ||fuhao->arr[fuhao->begin - 1] == '(')
				PushNum(fuhao, str1[i]);
			else if (str1[i] == ')') { //����������ʱ����������ջ�����в�����ֱ������������
				while (fuhao->arr[fuhao->begin - 1] != '(') 
					GetSingleResult(Pop(fuhao), shuzi);
				Pop(fuhao); //���������ţ�����ֵ��
			}
			else if (str1[i] != ')'&&str1[i] != '(' && !CheckEmpty(fuhao)) {
				while (CmpFuhao(fuhao->arr[fuhao->begin - 1], str1[i])&&!CheckEmpty(fuhao)) {
					//cout << '1' << endl;
					GetSingleResult(Pop(fuhao), shuzi);
				}
				PushNum(fuhao, str1[i]); //����ջ������������str[1]���ȼ�С�ķ��ź󣬰�str[1]push������ջ
			}
		}
	}

	//printf("%d %d %d %d", '+', '-', '*', '/');
	getchar();
	getchar();
	return 0;
}