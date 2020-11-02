#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int a;
    struct list *next;
}List;

void CreateNodeH(List *&L,int n,int a[]){
    List *p;
    L=(List *)malloc(sizeof(List));
    L->next=NULL;
    for(int i=0;i<n;i++){
        p=(List *)malloc(sizeof(List));
        p->next=L->next;
        p->a=a[i];
        L->next=p;
    }
}

void CreateNodeT(List *&L,int n,int a[]){
    List *p,*q;
    L=(List *)malloc(sizeof(List));
    L->next=NULL;
    q=L;
    for(int i=0;i<n;i++){
        p=(List *)malloc(sizeof(List));
        p->a=a[i];
        q->next=p;
        q=p;
    }
    q->next=NULL;
}

int LocateList(List *L,int a){
    List *p=L->next;
    int i=1;
    while(p!=NULL&&p->a!=a){
        i++;
        p=p->next;
    }
    return p==NULL?0:i;
}

int LengthList(List *L){
    int n=0;
    List *p=L->next;
    while(p!=NULL){
        p=p->next;
        n++;
    }
    return n;
}

int GetElem(List *&L,int i){
    List *p=L->next;
    int j=1;
    while(p!=NULL){
        if(j==i)
            return p->a;
        else
        {
            p=p->next;
            j++;
        }
    }
    return -1;
}
bool EmptyList(list *L){
    return (L->next==NULL);
}
void PrintList(List *&L){
    List *p=L->next;
    while(p!=NULL){
        printf("%d ",p->a);
        p=p->next;
    }
    printf("\n");
}

int main(){
    List *L,*h;
    int a[10]={43,54,23,21,34,23,56,98,89,453};
    CreateNodeH(L,10,a);
    PrintList(L);
    CreateNodeT(h,10,a);
    PrintList(h);
    printf("21是第%d个元素\n",LocateList(L,21));
    printf("L中一共有%d个元素\n",LengthList(L));
    printf("第8号元素是%d\n",GetElem(h,8));
    return 0;
}