#include <stdio.h>
#define   NULL    0 
struct  student 
{
	long num;
	float  score; 
	struct  student *next; 
}; 
void main(  ) 
{
	struct   student  a,b,c,*head,*p;
	a.num=99101;
	a.score=89.5;
	b.num=99102;
	b.score=90; 
	c.num=99103;
	c.score=85;
	head=&a;
	a.next=&b;
	b.next=&c; 
	c.next=NULL;
	p=head; 
	do  { printf("%ld %5.1f\n",p->num,p->score); 
          p=p->next; 
        }while(p!=NULL); 
}
