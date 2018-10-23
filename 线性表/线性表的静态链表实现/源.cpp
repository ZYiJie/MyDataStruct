#include <iostream>
#include "SLinkList.h"
#include <stdlib.h>
using namespace std;
int main()
{
	int arr[LEN], seq[LEN];
	int begin;
	begin = Init_SL(arr, seq);
	Traverse_SL(arr, seq, begin);
	Add_SL(arr,seq,begin);
	Traverse_SL(arr, seq, begin);
	Delete_SL(arr, seq, &begin);
	Traverse_SL(arr, seq, begin);
	getchar();
	getchar();
	return 0;
}