#include<stdio.h>
#include<stdlib.h>
#include<test1.h>
void main( ) 
{ 
    struct  student  *head, *stu; 
    long  del_num;
    printf("input  records: \n"); 
    head=creat();        /*������������ͷָ��*/
    print(head);          /*���ȫ�����*/
    printf("\n input  delete  number:");  
    scanf("%ld", &del_num);            /*����Ҫɾ����ѧ��*/
    while(del_num !=0) 
    {
        head=del(head,del_num);      /*ɾ���������ͷ��ַ*/  
        print(head);              /*���ȫ�����*/
        printf("input  the  delete  number:"); 
        scanf("%ld, &del_num"); /*����Ҫɾ����ѧ��*/
    }
    printf("\n  input  the  inserted  record:"); 
    stu=(struct  student *) malloc(sizeof (struct   student));
    scanf("%ld,%f", &stu->num, &stu->score);     /*����Ҫ����Ľ��*/ 
    while(stu->num !=0) 
    { 
        head=insert(head,stu);   /*�����½�㣬���ص�ַ*/   
        print(head);                    /*���ȫ�����*/
        printf("input  the  inserted  record:"); 
        stu=(struct  student *) malloc(sizeof (struct   student)); 
        scanf("%ld,%f", &stu->num, &stu->score);
    } 
}
