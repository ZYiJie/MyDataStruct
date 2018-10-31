#include <iostream>
#include "MyLinkedStack.h"
#define TRUE 1
using namespace std;
int main()
{
	int n;
	StackNode *top = InitStack();
	while (TRUE) {
		cout << "1.Push\n2.Pop\n3.Traverse\n4.Exit\nPlease choose:  ";
		cin >> n;
		if (n == 1) { cout << "Please input:  "; PushInput(top); }
		else if (n == 2) {
			int temp = Pop(top);
			cout << temp << endl;
		}
		else if (n == 3) TraverseStack(top);
		else break;
	}
	return 0;
}