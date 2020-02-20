#include <stdio.h> /*�Ľ���*/
#include <stdlib.h>
int n;
struct student
{
    long num;
    float score;
    struct student *next;
};
struct student *creat()
{
    struct student *head;
    struct student *p1, *p2;
    float s;
    n = 0;
    p1 = p2 = (struct student *)malloc(sizeof(struct student));
    scanf("%ld,%f", &p1->num, &s);
    p1->score = s;
    head = NULL;
    while (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct student *)malloc(sizeof(struct student));
        scanf("%ld ,%f", &p1->num, &s);
        p1->score = s;
    }
    p2->next = NULL;
    return (head);
}

struct student *del(struct student *head, long num)
{
    struct student *p1, *p2;
    if (head == NULL)
        printf("\n  list  null ! \n");
    p1 = head;
    while (num != p1->num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)
    {
        if (p1 == head)
            head = p1->next;
        else
            p2->next = p1->next;
        printf("delete: %d\n", num);
        n = n - 1;
    }
    else
        printf("%ld  not  been  found ! \n", num);
    return (head);
}
struct student *insert(struct student *head, struct student *stud)
{
    struct student *p0, *p1, *p2;
    p1 = head;        /*ʹp1ָ���һ�����*/
    p0 = stud;        /*p0ָ��Ҫ����Ľ��*/
    if (head == NULL) /*ԭ���������ǿձ�*/
    {
        head = p0;
        p0->next = NULL;
    } /*ʹp0ָ��Ľ����Ϊͷ���*/
    else
    {
        while ((p0->num > p1->num) && (p1->next != NULL))
        {
            p2 = p1; /*ʹp2ָ��ղ�p1ָ��Ľ��*/
            p1 = p1->next;
        } /*p1����һ�����*/
        if (p0->num <= p1->num)
        {
            if (head == p1)
                head = p0; /*�嵽ԭ����һ�����֮ǰ */
            else
                p2->next = p0; /*�嵽p2ָ��Ľ��֮��*/
            p0->next = p1;
        }
        else
        {
            p1->next = p0;
            p0->next = NULL;
        } /*�嵽���Ľ��֮��*/
    }
    n = n + 1; /*�������1*/
    return (head);
}

void main()
{
    struct student *head, *stu;
    long del_num;
    printf("input  records: \n");
    head = creat(); /*������������ͷָ��*/
    print(head);    /*���ȫ�����*/
    printf("\n input  delete  number:");
    scanf("%ld", &del_num); /*����Ҫɾ����ѧ��*/
    while (del_num != 0)
    {
        head = del(head, del_num); /*ɾ���������ͷ��ַ*/
        print(head);               /*���ȫ�����*/
        printf("input  the  delete  number:");
        scanf("%ld, &del_num"); /*����Ҫɾ����ѧ��*/
    }
    printf("\n  input  the  inserted  record:");
    stu = (struct student *)malloc(sizeof(struct student));
    scanf("%ld,%f", &stu->num, &stu->score); /*����Ҫ����Ľ��*/
    while (stu->num != 0)
    {
        head = insert(head, stu); /*�����½�㣬���ص�ַ*/
        print(head);              /*���ȫ�����*/
        printf("input  the  inserted  record:");
        stu = (struct student *)malloc(sizeof(struct student));
        scanf("%ld,%f", &stu->num, &stu->score);
    }
}
