#include<stdio.h>
#include<stdlib.h>
#include<test1.h>
void main( ) 
{ 
    struct  student  *head, *stu; 
    long  del_num;
    printf("input  records: \n"); 
    head=creat();        /*建立链表，返回头指针*/
    print(head);          /*输出全部结点*/
    printf("\n input  delete  number:");  
    scanf("%ld", &del_num);            /*输入要删除的学号*/
    while(del_num !=0) 
    {
        head=del(head,del_num);      /*删除后链表的头地址*/  
        print(head);              /*输出全部结点*/
        printf("input  the  delete  number:"); 
        scanf("%ld, &del_num"); /*输入要删除的学号*/
    }
    printf("\n  input  the  inserted  record:"); 
    stu=(struct  student *) malloc(sizeof (struct   student));
    scanf("%ld,%f", &stu->num, &stu->score);     /*输入要插入的结点*/ 
    while(stu->num !=0) 
    { 
        head=insert(head,stu);   /*插入新结点，返回地址*/   
        print(head);                    /*输出全部结点*/
        printf("input  the  inserted  record:"); 
        stu=(struct  student *) malloc(sizeof (struct   student)); 
        scanf("%ld,%f", &stu->num, &stu->score);
    } 
}
