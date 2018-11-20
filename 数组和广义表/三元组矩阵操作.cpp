#include <iostream>
#include "MyTripleArr.h"
using namespace std;
int main()
{
	int x;
	TripleArrNode *root;
	root = TripleArrNodeInit();
	cout << "1.Create\n2.Transposition\n3.Insert\n4.Delete\n5.Traverse\n6.Destory\n7.Quit\n" << endl;
	while (TRUE)
	{
		cout << "Please choose order : ";
		fflush(stdin);
		cin >> x;
		switch (x) {
		case 1:CreateTripleArrNode(root); break;
		case 2:Transposition(root); break;
		case 3:InsertTripleArrNode(root); break;
		case 4:DeleteTripleArrNode(root); break;
		case 5:TraverseTripleArrNode(root); break;
		case 6:DestroyTripleArrNode(root); break;
		}
		if (x == 7) break;
	}
	return 0;

}
