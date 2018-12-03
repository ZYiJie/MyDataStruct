#include <iostream>
#include<stack>
using namespace std;
int main() {
	char str[100] = { '\0' };
	char ch;
	stack <char> result;
	cout << "Please input(* means stopping)" << endl;
	while ((ch = getchar()) != '*') {
		if (ch == '#') result.pop();
		else if (ch == '@') {
			char temp=result.top();
			while (!result.empty()) {
				if (temp == '\n') break;
				result.pop();
				temp = result.top();
			}
			result.pop();
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