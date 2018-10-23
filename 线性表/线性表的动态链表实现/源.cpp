#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	int x;
	LlistInit(head);
	cout << "1.Create\n2.Find\n3.Insert\n4.Delete\n5.Traverse\n6.Destory\n7.Quit\n"<<endl;
	while (TRUE)
	{
		cout << "Please choose order : ";
		fflush(stdin);
		cin >> x;
		switch (x) {
			case 1:CreateLlist();break;
			case 2:FindLlist(); break;
			case 3:InsertLlist(); break;
			case 4:DeleteLlist();break;
			case 5:TraverseLlist(); break;
			case 6:DestroyLlist(); break;
		}
		if (x == 7) break;
	}
	return 0;

}
