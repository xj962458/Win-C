#include<iostream>
#include<string>
using namespace std;

typedef struct list{
    int data;
    struct list *next;
}List;

void InitList(List *&L){
    L=new List;
    L->next=NULL;
}

void CreateList(List *&L,int a[],int n){
    L=new List;
    L->next=NULL;
    List *p;
    for(int i=0;i<n;i++){
        p=new List;
        p->data=a[i];
        p->next=L->next;
        L->next=p;
    }
}

void InsertList(List *&L,int a){
    List *p=new List;
    p->data=a;
    p->next=L->next;
    L->next=p;
}

void PrintList(List *&L){
    List *p=L->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    List *L;
    int a[]={12,32,45,65,78};
    CreateList(L,a,5);
    PrintList(L);
    InsertList(L,89);
    PrintList(L);
    return 0;
}
