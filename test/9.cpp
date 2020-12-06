#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef char ElemType;
typedef struct tnode{
    ElemType data;
    struct tnode *hp,*vp;
}TSBNode;

void CreatTree(TSBNode *&t)
{   
    char ch;
    scanf("%c", &ch);
    if (ch == char(-1))
    {
        t = NULL;
        return;
    }
    else
    {
        t = (TSBNode *)malloc(sizeof(TSBNode));
        t->data = ch;
        printf("\n����%c������:", ch);
        CreatTree(t->hp);
        printf("����%c���ֵ�:", ch);
        CreatTree(t->vp);
    }
    return;
}

int TreeHeight(TSBNode *t){
    TSBNode *p;
    int h,maxh=0;
    if(t==NULL)
        return 0;
    else{
        p=t->vp;
        while(p!=NULL){
            h=TreeHeight(p);
            if(maxh<h)
                maxh=h;
            p=p->hp;
        }
        return (maxh+1);
    }
}

int main(){
    TSBNode *T;
    printf("������ڵ㣺");
    CreatTree(T);
    printf("���Ϊ��%d", TreeHeight(T));
}