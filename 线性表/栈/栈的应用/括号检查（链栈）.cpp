#include <iostream>
#include <stdio.h>
#include "MyLinkedStack.h"
#define LEN 100
void Tvs(StackNode*top) {
	StackNode *temp = top->p;
	int i = 1;
	while (temp != NULL) {
		printf("%c", temp->data);
		temp = temp->p;
	}
}
void P(StackNode*top) {
	int result;
	StackNode *temp;
	if (!CheckEmpty(top)) {
		temp = top->p;
		result = temp->data;
		top->p = temp->p;
		delete(temp);
	}
	else {
		cout << "The Stack is empty." << endl;
	}
}
using namespace std;

int main() {
	char kuohao[LEN];
	int i;
	StackNode *top;
	top = InitStack();
	cout << "Please input string: ";
	scanf_s("%s", kuohao, LEN);
	for (i = 0; kuohao[i] != '\0'; i++) {
		if (kuohao[i] == ']'&&top->p->data == '[')  P(top);
		else if (kuohao[i] == ')'&&top->p->data == '(')P(top);
		else PushNum(top, kuohao[i]);
		//Tvs(top);
	}
	if (CheckEmpty(top)) cout << "Correct!";
	else cout << "Wrong!";

	getchar();
	getchar();

}