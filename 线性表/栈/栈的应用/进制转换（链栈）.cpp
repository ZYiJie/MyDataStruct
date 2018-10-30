#include <iostream>
#include "MyLinkedStack.h"
using namespace std;
int main(){
	int num,jinzhi;
	StockNode *top;
	cout << "Please choose radix: ";
	cin >> jinzhi;
	cout << "Please input number: ";
	cin >> num;
	cout << "The radix is: " << jinzhi << ", the number is: " << num << endl;
	top = InitStock();
	while (num) {
		Push2(top, num%jinzhi);
		num /= jinzhi;
	}
	Push2(top, num);
	cout << "Result:";
	TraverseStock(top);
	getchar();
	getchar();

}