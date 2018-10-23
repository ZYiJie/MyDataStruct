#include <iostream>
#define TRUE 1
using namespace std;
typedef struct Llist
{
	char data;
	struct Llist *next;
};
Llist *head = NULL;
Llist *tail = NULL;
void LlistInit(Llist *list1) {
	//初始化链表
	if (head == NULL) {
		head = (Llist*)malloc(sizeof(Llist));
		tail = (Llist*)malloc(sizeof(Llist));
		head->next = NULL;
		tail = head;
		cout << "Initialize Successfully!" << endl;
	}
}
Llist *LocateLlist(int n) {
	Llist *flag=head ;
	for (; n > 1; n--) flag = flag->next;
	return flag;
}
void FindLlist() {
	int i;
	char ch;
	Llist *temp=head;
	cout << "Which data do you want to find:";
	cin >> ch;
	for (i = 0; ; i++) {
		if (temp->data == ch) { 
			cout << "The first position of target is:" << i << endl; break; 
		}else if (temp->next == NULL) {
			cout << "Can't find it!" << endl; break; }
		
		else temp = temp->next;
	}
}
void CreateLlist() {
	//向链表中插入字符
	int i;
	Llist *xin;
	cout << "How many data do you want to add:";
	cin >> i;
	cout << "Input character:";
	for (; i > 0; i--) {
		xin = (Llist*)malloc(sizeof(Llist));
		//cout << "Input character:";
		cin >> xin->data;
		tail->next = xin;
		xin->next = NULL;
		tail = xin;
		//putchar(head->next->data);
	}
}
void DeleteLlist() {
	int i;
	cout << "Which position do you want to delete:";
	cin >> i;
	Llist *temp = LocateLlist(i),*del;
	del = temp->next;
	temp->next = temp->next->next;
	free(del);
}

void InsertLlist() {
	int i;
	Llist *temp = (Llist*)malloc(sizeof(Llist));
	cout << "Which position do you want to insert:";
	cin >> i;
	cout << "Input character:";
	cin >> temp->data;
	Llist *target = LocateLlist(i);
	temp->next = target->next;
	target->next = temp;
}

void TraverseLlist(){
    Llist *temp=head;
    while (temp->next!=NULL)
    {
		temp = temp->next;
        cout<<temp->data;
    }
	cout << endl;
}

void DestroyLlist() {
	Llist *temp1=head,*temp2;
	while (temp1->next != NULL) {
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	cout << "Destroy successfully!" << endl;
}