/*  ��̬�ڴ�ֲ�������
    *   ����stdlib.h;
    *   malloc()Ϊһ��ָ�뿪��һ���ڴ�
    *   void* ��·���ӣ�size_t����Size);
    *       *����void*���� ��ָ�����Ϳ���ǿ��ת��Ϊ�����ָ������
    *       *size��С �ڴ�Ĵ�С���ֽڣ�
                Pstu=(STU*)malloc(sizeof(STU))��
                �ڶ��ڴ��п���STU����ṹ�����ʹ�С����ѵ������һ���ڴ�ĵ�ַ��ֵ��Pstu,������ʵ���ǿ���һ���ڵ�
    *free()
        �ͷ��ڴ�
        ջ�ڴ��ʹ�ú��ͷ���ϵͳ�Լ���ɵ�
        ���ڴ��ʹ�ú��ͷ��ǳ���Ա����ɵģ�����Ҫʹ�õ��ڴ�һ��Ҫ�ͷ�
*/
#include <stdio.h>
struct student
{
    char num[20];
    char name[20];
    int age;
    float score;
};
struct student stud[10] = {{"3190707121", "���¼�", 20, 99}, {"3200101121", "������", 20, 100}};
struct student *stu = &stud;
void main()
{
    int i, j;
    printf("������10��ѧ��������");
    for (i = 0; i < 10; i++)
        scanf("%d", &(stu + i)->age);
    for (j = 0; j < 10; j++)
        printf("%d ", (stu + j)->age);
    printf("%d\n", (stu + 1)->age);
    printf("%s\n", (stu + 1)->name);
    printf("%s\n", (stu + 1)->num);
    printf("%.2f\n", (stu + 1)->score);
}