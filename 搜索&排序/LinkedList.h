#include <iostream>
#include <string>
#define TRUE 1
using namespace std;
//--------------------------------------------------
//定制个性化专属数据及其输入输出方式
typedef int mydata;
void InputData(mydata &data) {
	cin >>data;
}
void OutputData(mydata &data) {
	cout << data;
}
//---------------------------------------------------

typedef struct Llist
{
	mydata data;
	struct Llist *next;
};

Llist *LlistInit() {
	//初始化链表
	Llist  *head=NULL,*tail = NULL;
	if (head == NULL) {
		head = new(Llist);
		tail = new(Llist);
		head->next = NULL;
		tail = head;
		//cout << "Initialize Successfully!" << endl;
	}
	return head;
}
Llist *LocateLlist(Llist *head,int n) {
	Llist *flag=head ;
	for (; n > 1; n--) flag = flag->next;
	return flag;
}
void FindLlist(Llist *head) {
	int i;
	mydata ch;
	Llist *temp=head;
	cout << "Which data do you want to find:";
	InputData(ch);
	for (i = 0; ; i++) {
		if (temp->data == ch) { 
			cout << "The first position of target is:" << i << endl; break; 
		}else if (temp->next == NULL) {
			cout << "Can't find it!" << endl; break; }
		
		else temp = temp->next;
	}
}
int  FindLlist2(Llist *head,mydata n) {
	//返回n在链表中的位置
	int i;
	Llist *temp = head;
	for (i = 0; ; i++) {
		if (temp->data == n)
			return i;
		else if (temp->next == NULL) 
			return 0;
		else temp = temp->next;
	}
}

void CreateLlist(Llist *head) {
	//向链表中插入字符
	int i;
	Llist *xin,*tail=head;
	while (tail->next!= NULL) tail = tail->next;
	cout << "How many data do you want to add:";
	cin >> i;
	cout << "Input character:";
	for (; i > 0; i--) {
		xin = new(Llist);
		//cout << "Input character:";
		InputData(xin->data);
		tail->next = xin;
		xin->next = NULL;
		tail = xin;
		//putchar(head->next->data);
	}
}
void DeleteLlist(Llist *head) {
	int i;
	cout << "Which position do you want to delete:";
	cin >> i;
	Llist *temp = LocateLlist(head,i),*del;
	del = temp->next;
	temp->next = temp->next->next;
	free(del);
}

void InsertLlist(Llist *head) {
	int i;
	Llist *temp = new(Llist);
	cout << "Which position do you want to insert:";
	cin >> i;
	cout << "Input character:";
	InputData(temp->data);
	Llist *target = LocateLlist(head,i);
	temp->next = target->next;
	target->next = temp;
}

void PushLlist(Llist *&head,int m) {
	//把m插到链表前端
	Llist *temp = new(Llist);
	Llist *last = head->next;
	temp->data = m;
	temp->next = last;
	head->next = temp;
}

void TraverseLlist(Llist *head){
	//有头链表的遍历
    Llist *temp=head;
    while (temp->next!=NULL)
    {
		temp = temp->next;
		OutputData(temp->data);
    }
	cout << endl;
}

void DestroyLlist(Llist *head) {
	Llist *temp1=head,*temp2;
	while (temp1->next != NULL) {
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	cout << "Destroy successfully!" << endl;
}