#include <iostream>
#define TRUE 1
using namespace std;
typedef struct Llist
{
	int data;
	struct Llist *next;
};
Llist *head = NULL;
Llist *tail = NULL;
void LlistInit() {
	//初始化链表
	if (head == NULL) {
		head = (Llist*)malloc(sizeof(Llist));
		tail = (Llist*)malloc(sizeof(Llist));
		head->next = NULL;
		tail = head;
		cout << "Initialize Successfully!" << endl;
	}
}


void CreateLlist() {
	//向链表中插入字符
	int i;
	Llist *xin;
	cout << "How many data do you want to add:";
	cin >> i;
	for (; i > 0; i--) {
		cout << "Input character:";
		xin = (Llist*)malloc(sizeof(Llist));
		//cout << "Input character:";
		cin >> xin->data;
		tail->next = xin;
		xin->next = NULL;
		tail = xin;
		//putchar(head->next->data);
	}
}

void TraverseLlist(){
    Llist *temp=head;
    while (temp->next!=NULL)
    {
		temp = temp->next;
        cout<<temp->data<<" ";
    }
	cout << endl;
}

void SpecialInsertLlist() {
	int ch,n;
	cout << "How many numbers do you want to insert:";
	cin >> n;
	while (n) {
		Llist *temp = head;
		cout << "Which data:";
		cin >> ch;
		while (1) {
			if (temp->next == NULL && temp->data!=ch) {
				Llist *xin;
				xin = (Llist*)malloc(sizeof(Llist));
				xin->data = ch;
				tail->next = xin;
				xin->next = NULL;
				temp->next = xin;
				cout << "Insert successfully!" << endl;
				n--;
				break;
			}
			else if (temp->next->data == ch) {
				Llist  *del;
				del = temp->next;
				temp->next = temp->next->next;
				free(del);
				cout << "Delete Successfully!" << endl;
				n--;
				break;
			}
			else temp = temp->next;
		}
	}
}
	
