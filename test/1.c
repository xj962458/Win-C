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
    printf("请输入您要输入的学生数:");
    scanf("%d", &n);
    for(k=0;k<=n;k++)
        p[k] = (STU *)malloc(sizeof(STU));
    for (i = 0; i < n; i++)
    {
        printf("请输入姓名：");
        scanf("%s",&p[i]->name);
        printf("请输入年龄：");
        scanf("%d", &p[i]->age);
        printf("请输入分数：");
        scanf("%f",&p[i]->score);
    }
    /*
    printf("姓名");
    printf("\t年龄");
    printf("\t分数\n");
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