#include <iostream>
#include<stack>
using namespace std;
int main() {
	char str[100] = { '\0' };
	char ch;
	stack <char> result;
	cout << "Please input(* means stopping)" << endl;
	while ((ch = getchar()) != '*') {
		//输入#删除前一个字符；输入@删除之前整行；输入*结束
		if (ch == '#') result.pop();
		else if (ch == '@') {
			char temp=result.top();
			while (!result.empty()) {
				if (temp == '\n') break;
				result.pop();
				temp = result.top();
			}
			result.pop();//用于删除多余的一个回车符
		}
		else result.push(ch);
	}
	int i,j;
	for(i = 0;!result.empty(); i++) {
		str[i] = result.top();
		result.pop();
	}
	cout << endl << "The result is:" << endl;
	for (j = i - 1; j > -1; j--) cout << str[j] ;
	getchar();
	getchar();
	return 0;
}