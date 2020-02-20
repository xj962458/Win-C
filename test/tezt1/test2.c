#include<test1.h>
struct student *creat() 
{ 
    struct student  *head;  
    struct student  *p1, *p2; 
    float  s; 
    n=0; 
    p1=p2=(struct student *) malloc(sizeof (struct   student)); 
    scanf("%ld,%f",&p1->num,&s); 
    p1 -> score=s; 
    head=NULL; 
    while(p1->num!=0) 
    {
        n=n+1; 
        if(n==1)
            head=p1; 
        else  
            p2->next=p1; 
        p2=p1; 
        p1=(struct  student *)malloc (sizeof (struct   student)); 
       scanf("%ld ,%f",&p1 -> num,&s); 
       p1 -> score=s; 
    } 
    p2 -> next=NULL;  
    return(head); 
}

void  print(struct  student  *head) 
{ 
    struct  student *p; 
    printf("\n Now, these  %d  records  are :\n",n); 
    p=head; 
    if(head!=NULL) 
    do 
    {
        printf("%ld, %5.2f\n",p->num, p->score); 
        p=p->next; 
      } 
    while(p !=NULL); 
}

struct  student  *del(struct student *head,long num)
{ 
    struct  student   *p1,*p2; 
    if(head==NULL) 
        printf("\n  list  null ! \n"); 
    p1=head; 
    while(num !=p1 -> num && p1 -> next != NULL) 
    {
        p2=p1; 
        p1=p1->next;
    } 
    if(num==p1->num) 
    {
        if(p1==head) 
        head=p1->next; 
        else p2->next=p1->next; 
        printf("delete: %d\n",num); 
        n=n-1; 
    } 
    else 
        printf("%ld  not  been  found ! \n",num); 
    return(head); 
}
struct  student  *insert(struct student *head, struct student *stud)
{ 
    struct  student  *p0, *p1, *p2; 
    p1=head;          /*使p1指向第一个结点*/ 
    p0=stud;           /*p0指向要插入的结点*/  
    if(head==NULL)       /*原来的链表是空表*/ 
    {
        head=p0; 
        p0->next=NULL; 
    }   /*使p0指向的结点作为头结点*/
    else 
    {
         while((p0->num > p1->num) && (p1->next != NULL)) 
        { p2=p1;                   /*使p2指向刚才p1指向的结点*/
           p1=p1 -> next; }    /*p1后移一个结点*/
       if(p0->num <= p1->num) 
         { if(head == p1) head=p0;     /*插到原来第一个结点之前 */
            else p2->next=p0;                /*插到p2指向的结点之后*/
            p0->next = p1; } 
       else {p1->next=p0; p0->next=NULL; } /*插到最后的结点之后*/
     } 
  n=n+1;             /*结点数加1*/
  return(head); 
}