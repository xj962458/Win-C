//���������Ա���������
#include<x.h>
void Write(LinkList head, int n)
{
	printf("��������Ա��ţ����������۶�\n");
    LinkList p;
    int i;
    for(i=0;i<n;i++)
	{
		printf("��%dλ:",i+1);
        p=(LinkList)malloc(sizeof(Node));
        scanf("%s%s%f",p->no,p->name,&p->sales);
        p->link=head->link;
        head->link=p;
    }
}