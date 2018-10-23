#include <iostream>
#define TRUE 1
using namespace std;
typedef struct StockNode {
	int data;
	StockNode *p;
};
StockNode* InitStock() {
	StockNode *top;
	top = new(StockNode);
	top->p = NULL;
	cout << "Initialize successfully!" << endl;
	return top;
}
int CheckEmpty(StockNode* top) {
	if (top->p == NULL) return 1;
	return 0;
}
void Push(StockNode*top) {
	StockNode *temp;
	temp = new(StockNode);
	cin >> temp->data;
	temp->p = top->p;
	top->p = temp;
	//cout << top->p->data;
}
void Pop(StockNode*top) {
	int result;
	StockNode *temp;
	if (!CheckEmpty(top)) {
		temp = top->p;
		result = temp->data;
		top->p = temp->p;
		delete(temp);
		cout<< result<<endl;
	}
	else {
		cout << "The stock is empty." << endl;
	}
	
}
void TraverseStock(StockNode*top) {
	StockNode *temp = top->p;
	int i = 1;
	while (temp != NULL) {
		cout << "NO." << i++ << " " << temp->data << endl;
		temp = temp->p;
	}
}
int main()
{
	int n;
	StockNode* top;
	top = InitStock();
	while (TRUE) {
		cout << "1.Push\n2.Pop\n3.Traverse\n4.Exit\nPlease choose:  ";
		cin >> n;
		if (n == 1) { cout << "Please input:  "; Push(top); }
		else if (n == 2) Pop(top);
		else if (n == 3) TraverseStock(top);
		else break;
	}
	return 0;
}