#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "NameList.h"
using namespace std;
NameList *list1;
int main()
{
    int x;
    list1 = (NameList*)malloc(sizeof(NameList));
    ListInit(list1);
    while(TRUE)
    {
        cout<<"1.Find\n2.Insert\n3.Delete\n4.Traverse\n5.Quit\nPlease choose order:";
        fflush(stdin);
        cin>>x;
        switch(x){
            case 1:FindList(list1);break;
            case 2:InsertList(list1);break;
            case 3:DeleteList(list1);break;
            case 4:TraverseList(list1);break;
        }
        if(x==5) break;
    }
    return 0;
}
