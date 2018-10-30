#include <iostream>
#include <stdio.h>
#include "MyLinkedStack.h"
#define LEN 100
void Tvs(StockNode*top) {
	StockNode *temp = top->p;
	int i = 1;
	while (temp != NULL) {
		printf("%c", temp->data);
		temp = temp->p;
	}
}
void P(StockNode*top) {
	int result;
	StockNode *temp;
	if (!CheckEmpty(top)) {
		temp = top->p;
		result = temp->data;
		top->p = temp->p;
		delete(temp);
	}
	else {
		cout << "The stock is empty." << endl;
	}
}
using namespace std;

int main(){
	char kuohao[LEN];
	int i;
	StockNode *top;
	top = InitStock();
	cout <<"Please input string: ";
	scanf_s("%s",kuohao,LEN);
	for (i = 0; kuohao[i] != '\0'; i++) {
		if (kuohao[i] == ']'&&top->p->data == '[')  P(top);
		else if (kuohao[i] == ')'&&top->p->data == '(')P(top);
		else Push2(top, kuohao[i]);
		//Tvs(top);
	}
	if (CheckEmpty(top)) cout << "Correct!";
	else cout << "Wrong!";

	getchar();
	getchar();
	
}