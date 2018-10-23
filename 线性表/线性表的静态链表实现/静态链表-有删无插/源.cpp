#include <iostream>
#include "SLinkList.h"
#include <stdlib.h>
using namespace std;
int main()
{
	int arr[LEN], seq[LEN];
	int begin,begin2;
	begin = Init_SL(arr, seq);
	Traverse_SL(arr, seq, begin);
	Special_SL (arr, seq, &begin);
	Traverse_SL(arr, seq, begin);
	getchar(); getchar();
	return 0;
}