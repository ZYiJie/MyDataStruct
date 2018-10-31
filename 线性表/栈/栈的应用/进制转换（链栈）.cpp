#include <iostream>
#include "MyLinkedStack.h"
using namespace std;
int main() {
	int num, jinzhi;
	StackNode *top;
	cout << "Please choose radix: ";
	cin >> jinzhi;
	cout << "Please input number: ";
	cin >> num;
	cout << "The radix is: " << jinzhi << ", the number is: " << num << endl;
	top = InitStack();
	while (num) {
		PushNum(top, num%jinzhi);
		num /= jinzhi;
	}
	PushNum(top, num);
	cout << "Result:";
	TraverseStack(top);
	getchar();
	getchar();

}