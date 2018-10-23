#include <iostream>
#include <stdlib.h>
#define step_b node->cishu = b_node->cishu;node->xishu = b_node->xishu;b_node = b_node->next;
#define step_a node->cishu = a_node->cishu;node->xishu = a_node->xishu;a_node = a_node->next;
#define step_ab node->cishu = b_node->cishu;node->xishu = a_node->xishu+b_node->xishu;a_node = a_node->next;b_node = b_node->next;
using namespace std;
typedef struct Polynomial{
    Polynomial *next;
    double xishu;
    int cishu;
};

Polynomial *InitPolyn(void){
    Polynomial *head,*tail,*node;
    int data;
    head = (Polynomial*)malloc(sizeof(Polynomial));
    head->next = NULL;
    return head;
}
int Insert(Polynomial *head,int n){
    int i,data2;
    double data1;
    Polynomial *node,*temp;
    for(i=0;i<n;i++){
        cout<<"Please input xishu(enter)cishu:"<<endl;
        cin>>data1;
        cin>>data2;
        node = (Polynomial*)malloc(sizeof(Polynomial));
        fflush(stdin);
        node->xishu = data1;
        node->cishu = data2;
        temp = head;
        while(1){
            if(temp->next==NULL) break;
            if(data2>temp->next->cishu) break;
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;

    }
}
Polynomial *AddPolyn(Polynomial *a,Polynomial *b){
    Polynomial *resulthead,*resulttail,*node,*a_node,*b_node;
    resulthead = (Polynomial*)malloc(sizeof(Polynomial));
    resulthead->next = NULL;
    resulttail = resulthead;
    a_node = a->next;
    b_node = b->next;
    while((a_node!=NULL)||(b_node!=NULL)){
        node = (Polynomial*)malloc(sizeof(Polynomial));
        if(a_node==NULL) {step_b}
        else if(b_node==NULL){step_a}
        else{
            if((a_node->cishu)<(b_node->cishu)){ step_b }
            else if((a_node->cishu)>(b_node->cishu)){ step_a }
            else{ step_ab }
        }
        node->next = resulttail->next;
        resulttail->next = node;
        resulttail = node;
    }
    return resulthead;
}
void TraversePalyn(Polynomial *head){
    Polynomial *temp=head->next;
    while (1) {
        if (temp->next == NULL) {//最后一项
            if(!temp->xishu) break;//系数为0不显示该项
            if(temp->cishu==0) {cout << temp->xishu<<endl;break;} //次数为0不显示x
            if(temp->cishu!=1){//次数不为1显示次数
                if(temp->xishu-1) cout << temp->xishu;
                if(temp->xishu == -1) cout<<"-";//系数为-1只显示-
                cout<< "x^"<<temp->cishu;
            } else{//次数为1
                cout << temp->xishu;
                cout<< "x";
            }
            cout << endl;
            break;
        } else {//中间项
            if(!temp->xishu) {temp = temp->next;continue;}
            if(temp->cishu!=1){
                if(temp->xishu-1) cout << temp->xishu;
                if(temp->xishu==-1) cout << temp->xishu;
                cout<< "x^"<<temp->cishu;
            } else{
                cout << temp->xishu;
                cout<< "x";
            }
            if(temp->next->xishu>0) cout << "+";
            temp = temp->next;
        }
    }
}
int main()
{
    Polynomial *a,*b,*c;
    int num;
    a = InitPolyn();
    b = InitPolyn();
    c = InitPolyn();
    cout<<"Please input the number of first one:";
    cin>>num;
    Insert(a,num);
    cout<<"Please input the number of second one:";
    cin>>num;
    Insert(b,num);
    c = AddPolyn(a,b);
    cout<<"F1(x)=";
    TraversePalyn(a);
    cout<<"F2(x)=";
    TraversePalyn(b);
    cout<<"F3(x)=";
    TraversePalyn(c);
    getchar();
    getchar();
    return 0;
}