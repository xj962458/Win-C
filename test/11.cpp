#include<stdio.h>
#include<malloc.h>
#define MaxSize 4
typedef char ElemType;

typedef struct node{
    ElemType data;
    struct node *son[MaxSize];
}TSonNode;

void CreateTree(TSonNode *T){
    
}