#include <stdio.h>
#include<stdlib.h>
typedef struct student
{
    char name[10];
    int age;
    float score;
} STU;

int main()
{
    int i, j,k, a, n, s;
    STU *p[9];
    printf("��������Ҫ�����ѧ����:");
    scanf("%d", &n);
    for(k=0;k<=n;k++)
        p[k] = (STU *)malloc(sizeof(STU));
    for (i = 0; i < n; i++)
    {
        printf("������������");
        scanf("%s",&p[i]->name);
        printf("���������䣺");
        scanf("%d", &p[i]->age);
        printf("�����������");
        scanf("%f",&p[i]->score);
    }
    /*
    printf("����");
    printf("\t����");
    printf("\t����\n");
    for (j = 0; j < n; j++)
    {
        printf("%s\t", stu[j].name);
        printf("%d\t", stu[j].age);
        printf("%.1f\t", stu[j].score);
        printf("\n");
    }
    */
    for(j=0;j<n;j++)
    {
        printf("%s\t",p[j]->name);
        printf("%d\t",p[j]->age);
        printf("%.1f\t",p[j]->score);
        printf("\n");
    }
    return 0;
}