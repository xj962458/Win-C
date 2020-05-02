#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
    char a[3][40];
    int no[3];
    struct student *next;
}STU;
int main()
{
    int i,j,k;
    char b[3][40];
    STU *p=(STU*)malloc(sizeof(STU));
    for(i=0;i<3;i++)
    {
        printf("请输入姓名:");
        scanf("%s",(p->a)+i);
        printf("请输入年龄:");
        scanf("%d",(p->no)+i);
    }
    printf("\n\n信息如下:\n");
    printf("姓名\t年龄\n");
    for(j=0;j<3;j++)
    {
        printf("%s\t",*((p->a)+j));
        printf("%d",*((p->no)+j));
        printf("\n");
    }
    for(k=0;k<3;k++)
        strcpy(b[k],*((p->a)+k));
    for(j=0;j<3;j++)
    {
        printf("%s\t",b[j]);
        printf("\n");
    }
}