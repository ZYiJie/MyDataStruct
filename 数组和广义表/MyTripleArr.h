#include <iostream>
#define TRUE 1
#define TRIPLE_LEN 10
using namespace std;
typedef struct TripleArrNode
{
	int data;
	int x;
	int y;
	struct TripleArrNode *next;
};

TripleArrNode *TripleArrNodeInit() {
	//初始化三元组链表
	TripleArrNode  *head = NULL, *tail = NULL;
	if (head == NULL) {
		head = new(TripleArrNode);
		tail = new(TripleArrNode);
		head->next = NULL;
		tail = head;
		cout << "Initialize Successfully!" << endl;
	}
	return head;
}
TripleArrNode *LocateTripleArrNode(TripleArrNode *head, int n) {
	TripleArrNode *flag = head;8
	for (; n > 1; n--) flag = flag->next;
	return flag;
}
void Transposition(TripleArrNode *head) {
	TripleArrNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		int t;
		t = temp->x;
		temp->x = temp->y;
		temp->y = t;
	}
}

void CreateTripleArrNode(TripleArrNode *head) {
	//向链表中插入字符
	int i;
	TripleArrNode *xin, *tail = head;
	while (tail->next != NULL) tail = tail->next;
	cout << "How many data do you want to add:";
	cin >> i;

	for (; i > 0; i--) {
		xin = new(TripleArrNode);
		cout << "Input data:";
		cin >> xin->data;
		cout << "Input x:";
		cin >> xin->x;
		cout << "Input y:";
		cin >> xin->y;
		tail->next = xin;
		xin->next = NULL;
		tail = xin;
		//putchar(head->next->data);
	}
}
void DeleteTripleArrNode(TripleArrNode *head) {
	int i;
	cout << "Which position do you want to delete:";
	cin >> i;
	TripleArrNode *temp = LocateTripleArrNode(head, i), *del;
	del = temp->next;
	temp->next = temp->next->next;
	free(del);
}

void InsertTripleArrNode(TripleArrNode *head) {
	int i = 1;   //i为三元组插入的位置
	TripleArrNode *temp = new(TripleArrNode);
	cout << "Input character:";
	cin >> temp->data;
	TripleArrNode *target = LocateTripleArrNode(head, i);
	temp->next = target->next;
	target->next = temp;
}

void TraverseTripleArrNode(TripleArrNode *head) {
	TripleArrNode *temp = head;
	int arr[TRIPLE_LEN][TRIPLE_LEN] = { 0 };
	while (temp->next != NULL) {
		temp = temp->next;
		int n = temp->data, a = temp->x, b = temp->y;
		cout << "[" << n << ", " << a << ", " << b << "] " << endl;
		arr[a][b] = n;
	}
	for (int i = 0; i < TRIPLE_LEN; i++) {
		for (int j = 0; j < TRIPLE_LEN; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}
}

void DestroyTripleArrNode(TripleArrNode *head) {
	cout << "Destroy successfully!" << endl;
}