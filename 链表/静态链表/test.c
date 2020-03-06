/*  动态内存分布（链表）
    *   包含stdlib.h;
    *   malloc()为一个指针开辟一块内存
    *   void* 马路咯从（size_t——Size);
    *       *返回void*类型 空指针类型可以强制转化为任意的指针类型
    *       *size大小 内存的大小（字节）
                Pstu=(STU*)malloc(sizeof(STU))；
                在堆内存中开辟STU这个结构体类型大小的内训，把这一块内存的地址赋值给Pstu,这是其实就是开辟一个节点
    *free()
        释放内存
        栈内存的使用和释放是系统自己完成的
        堆内存的使用和释放是程序员来完成的，不需要使用的内存一定要释放
*/
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