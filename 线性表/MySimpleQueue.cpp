#include<stdio.h>
#include <stdlib.h>
#define LEN 20
int arr[LEN]={0,0,0,0,0,0,0,1,5,18,63,48,54,32,19,2,18,17};
int head=7,tail=18;
void enqueue(int *arr){
    if(tail==head) puts("will overwrite");
    else scanf("%d",&arr[tail]);
    if(tail==LEN-1) tail = 0;
    else tail++;
}
void dequeue(int *arr){
    if(tail==head) puts("overdelete");
    if(head==LEN-1) head = 0;
    else head++;
}
void print(int *arr){
    int temp;
    if(head<=tail) for(temp=head;temp<tail;temp++) printf("%d ",arr[temp]);
    else {
        for(temp=head;temp<LEN;temp++) printf("%d ",arr[temp]);
        for(temp=0;temp<tail;temp++) printf("%d ",arr[temp]);
    }
    putchar('\n');
}
int main()
{
    int i;
    print(arr);
    for(i=0;i<5;i++)enqueue(arr);
    print(arr);
    for(i=0;i<2;i++)dequeue(arr);
    print(arr);
}