#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	int x;
	Llist *head;
	head = LlistInit();
	cout << "1.Create\n2.Find\n3.Insert\n4.Delete\n5.Traverse\n6.Destory\n7.Quit\n" << endl;
	while (TRUE)
	{
		cout << "Please choose order : ";
		fflush(stdin);
		cin >> x;
		switch (x) {
		case 1:CreateLlist(head); break;
		case 2:FindLlist(head); break;
		case 3:InsertLlist(head); break;
		case 4:DeleteLlist(head); break;
		case 5:TraverseLlist(head); break;
		case 6:DestroyLlist(head); break;
		}
		if (x == 7) break;
	}
	return 0;

}
