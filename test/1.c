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
    int i, j, a, n, s;
    STU stu[10], *p;
    p = (STU *)malloc(sizeof(STU));
    printf("��������Ҫ�����ѧ����:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("������������");
        scanf("%s", &stu[i].name);
        printf("���������䣺");
        scanf("%d", &stu[i].age);
        printf("�����������");
        scanf("%f", &stu[i].score);
    }

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
    /*
    printf("%s\t",stu[0].name);
    printf("%d\t",stu[0].age);
    printf("%.1f\t",stu[0].score);
    printf("\n");
    printf("%s\t",stu[1].name);
    printf("%d\t",stu[1].age);
    printf("%.1f\t",stu[1].score);
    */
}