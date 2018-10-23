#include <iostream>
#include <string.h>
#include <stdio.h>
#define LEN 50
#define TRUE 1
using namespace std;

typedef struct NameList
{
    char name[LEN];
    int length;
};

void ListInit(NameList *list1){
    //初始化链表数组
    cout<<"what's your name?"<<endl;
    scanf_s("%s",list1->name,LEN);
    list1->length = strlen(list1->name);
}

void FindList(NameList *list1){
    //查找链表中的指定内容
    NameList target;
    int i,j,flag;
    cout<<"what do you want to find?"<<endl;
    scanf_s("%s",target.name,LEN);
    target.length = strlen(target.name);
    for(i=0;i<list1->length;i++){
        flag = 0;
        if(list1->name[i]==target.name[0]) {
//            printf("1\n");
            for (j = 0; j < target.length; j++) {
//                printf("2\n");
                if (list1->name[j + i] == target.name[j]) flag++;
                else break;
                if (flag == target.length) {
                    cout << "find the first position in array is:" << i + 1 << endl;
                    return;
                }
            }
        }
//        puts("ok");
        if((i+1)==(list1->length)) cout<<"never found!"<<endl;
    }
}

void InsertList(NameList *list1){
    //向链表中插入字符
    int n,i;
    char ch;
    cout<<"which position do you want to insert:"<<endl;
    cin>>n;
    n--;
    if(n>list1->length||n<0) {cout<<"out of range!!"<<endl;return;}//检查是否越界
    cout<<"which character do you want to insert:"<<endl;
    cin>>ch;
    //以下是插入操作
    for(i=list1->length-1;i>=n;i--) list1->name[i+1] = list1->name[i];
    list1->name[n] = ch;
    list1->length++;
}

void DeleteList(NameList *list1){
    //向链表中删除字符
    int n,i;
    if(list1->length==0) {cout<<"null error!!"<<endl;return;}//检查是否为空链表
    cout<<"which position do you want to delete:"<<endl;
    cin>>n;
    if(n>list1->length||n<0) {cout<<"out of range!!"<<endl;return;}//检查是否越界
    n--;
    //以下是删除操作
    for(i=n;i<list1->length;i++) list1->name[i] = list1->name[i+1];
    list1->length--;
}

void TraverseList(NameList *list1){
    int i;
    for(i=0;i<list1->length;i++) cout<<list1->name[i];
    cout<<endl;
}