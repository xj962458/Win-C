#include <stdio.h>
struct student
{
    char num[20];
    char name[20];
    int age;
    float score;
};
struct student stud[10] = {{"3190707121", "武新纪", 20, 99}, {"3200101121", "付玉婷", 20, 100}};
struct student *stu = &stud;
void main()
{
    int i, j;
    printf("请输入10个学生的年龄");
    for (i = 0; i < 10; i++)
        scanf("%d", &(stu + i)->age);
    for (j = 0; j < 10; j++)
        printf("%d ", (stu + j)->age);
    printf("%d\n", (stu + 1)->age);
    printf("%s\n", (stu + 1)->name);
    printf("%s\n", (stu + 1)->num);
    printf("%.2f\n", (stu + 1)->score);
}