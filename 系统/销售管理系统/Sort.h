#include<x.h>
//�Ƚϣ�����ֵ����
void Sort(LinkList head, int n)
{
	float sum;
	sum=0;
	int i;
    LinkList p=head->link;
    LinkList max=head->link;
    LinkList min=head->link;
    for(i=0;i<n;i++)
	{
    	sum+=(p->sales);
        if((max->sales)<=(p->sales)) max=p;
		if((min->sales)>=(p->sales)) min=p; 
        p=p->link;
    }
    printf("���۶������:\n���:%s  ����:%s  ���۶�:%f\n",max->no,max->name,max->sales);
    printf("���۶������:\n���:%s  ����:%s  ���۶�:%f\n",min->no,min->name,min->sales);
    printf("�����۶�:%f\n",sum);
}
