#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
//һ���ڵ������һ��ѧ����������Ϣ
typedef struct list
{
	int number;                //ѧ��
	char name[20];             //����
	char brithday[20];		   //����
	short major;			   //ѧԺ
	int grade1;				   //�γ�1�ĳɼ�(���޿�)
	int grade2;				   //�γ�2�ĳɼ�(ѡ�޿�)
	int grade3;				   //�γ�3�ĳɼ�(��ѡ��)
	struct list *last;
	struct list *next;
}list,*lt;

//��Ҫ�õ��ĺ���
lt add(lt H);					//��ĩβ���(�˺�������ֵ������ԭ����ͷ���)
void check(lt H);				//��ѯ����
void checkall(lt H);			//��ѯ����
void change(lt H);				//�޸�
void putin(lt H);				//���м����
lt dele(lt H);					//ɾ��(�˺�������ֵ���µ�ͷ���)
void ruin(lt H);				//����
void daima();					//רҵ������ձ�
//#######��ʼ����Ϣ��������С����
lt start()				
{
	lt T;
//�����Ļ�����Ϣ
	T=(list *)malloc(sizeof(list));
	strcpy(T->brithday,"1994,12,15");
	T->grade1=80;
	T->grade2=85;
	T->grade3=95;
	T->major=10;
	strcpy(T->name,"����");
	T->number=10;
//������ͷ��last����ָ��NULL
	T->last=NULL;
//��һ��
	T->next=    (list *)    malloc(sizeof(list));
	T->next->last=T;
	T=T->next;
//С���Ļ�����Ϣ
	strcpy(T->brithday,"1995,10,03");
	T->grade1=89;
	T->grade2=88;
	T->grade3=87;
	T->major=21;
	strcpy(T->name,"С��");
	T->number=11;
//����ĩβ��next����ָ��NULL
	T->next=NULL;
//����Tָ���������
	T=T->last;
	return T;
}
//�˺���������ʾ�˵�
void menu()
{
	system("cls");
	printf("��ӭʹ��ѧ������ϵͳV1.0\n\n");
	printf("��ѡ�������\n");
	printf("1����ĩβ�����Ϣ     2�����м������Ϣ      3���޸���Ϣ    \n4����ѯ������Ϣ       ");
	printf("5����ѯ������Ϣ     \n6��ɾ��һ��ͬѧ       7��������������        8���鿴רҵ������ձ�\n");
}
int main()
{
	srand(time(NULL));
	menu();
	lt H;	H=start();		//����ͷ��������
	int c;
	while(scanf("%d",&c)||scanf("%c",&c))//�����С����������ĸ֮���Ҳ��Ӱ��
	{
		switch (c)
		{
			case 1: H=add(H);		break;
			case 2: putin(H);		break;
			case 3: change(H);		break;
			case 4: check(H);		break;
			case 5: checkall(H);	break;
			case 6: H=dele(H);		break;
			case 7: ruin(H);H=NULL; break;
			case 8: daima();
			default :break;
		}
	}
}
//�����¼����ͬѧ����Ϣ
void xin(lt T)
{
	printf("�������¼���ͬѧ��ѧ��\n");
	scanf("%d",&T->number);
	printf("�������¼���ͬѧ������\n");
	scanf("%s",&T->name);
	printf("�������¼���ͬѧ�����գ���ʽ�ǣ��꣬�£���\n");
	scanf("%s",&T->brithday);
	printf("�������¼���ͬѧ��Ժϵ�������뿴רҵ������ձ�\n");
	scanf("%d",&T->major);
	printf("������Ϣ������ϣ�Ϊ�������뻷�ڣ�ϵͳ��������ɸ�ͬѧ�ĳɼ�\n");
	T->grade1=50+rand()%50;
	printf("���޿γɼ���%d\n",T->grade1);
	T->grade2=50+rand()%50;
	printf("ѡ�޿γɼ���%d\n",T->grade2);
	T->grade3=50+rand()%50;
	printf("��ѡ�γɼ���%d\n",T->grade3);
	printf("�ɼ��������,����������ز˵�\n");
	getch();
}
//�������ĩβ�����µ�����
lt add(lt T)
{
	lt Z;//��¼һ��ʼͷ����λ��
	Z=T;
	if(T!=NULL)//��������ﱾ������
	{
		while(T->next!=NULL)
		{T=T->next;}
		T->next=(list *)malloc(sizeof(list));
		T->next->last=T;
		T=T->next;
		T->next=NULL;
		//������Ϣ	
		xin(T);
		menu();
		return Z;
	}
	else//��������ǿյ�
	{
		T=(list *)malloc(sizeof(list));
		T->next=NULL;
		T->last=NULL;
		//������Ϣ	
		xin(T);
		menu();
		return T;
	}
}
//���ѧ����Ϣ���ڲ�ѯ������ʹ��
void output(lt T)
{
	printf("ѧ�ţ�%d\n",T->number);
	printf("������%s\n",T->name);
	printf("���գ�%s\n",T->brithday);
	printf("Ժϵ��");
	if(T->major/10==1)
	{
		printf("ͨ��ѧԺ��");
		switch(T->major-10)
		{
			case 0:printf("����רҵ");break;
			case 1:printf("����רҵ");break;
			default:printf("ͨ�Ŵ���");
		}
		printf("\n");
	}
	else if(T->major/10==2)
	{
		printf("���ѧԺ,");
		switch(T->major-20)
		{
			case 0:printf("�������רҵ");break;
			case 1:printf("�ֻ����רҵ");break;
			default:printf("���������רҵ");
		}
		printf("\n");
	}
	else
		{printf("��������\n");}
	printf("���޿γɼ�:%d\n",T->grade1);
	printf("ѡ�޿γɼ�:%d\n",T->grade2);
	printf("��ѡ�γɼ�:%d\n",T->grade3);
	printf("\n");
}
//��ѯ������Ϣ
void check(lt T)
{
	int k;
	printf("������Ҫ��ѯ��ͬѧ��ѧ�ţ�");
	scanf("%d",&k);
	while(T!=NULL)
	{
		if(T->number==k)
		{
			printf("\n�鵽��Ϣ����:\n");
			output(T);
			printf("�����Ǹ�ͬѧ��Ϣ�������������\n");
			getch();
			menu();
			return;
		}
		else {T=T->next;}
	}
	if(T==NULL)
		printf("\n���޴��ˣ�����������ز˵�");
	getch();
	menu();
}
//��ѯ������Ϣ
void checkall(lt T)
{
	printf("\n������Ϣ����:\n");
	while(T!=NULL)
	{
		output(T);
		T=T->next;
	}
	printf("������������Ϣ������������ز˵�\n");
	getch();
	menu();
}
void gai(lt T)
{
	//������Ϣ	
	printf("������ı�֮���ѧ��     ");
	scanf("%d",&T->number);
	printf("������ı�֮�������     ");
	scanf("%s",&T->name);
	printf("������ı�֮�������     ");
	scanf("%s",&T->brithday);
	printf("������ı�֮���Ժϵ�������뿴רҵ������ձ�\n");
	scanf("%d",&T->major);
	printf("������ı�֮��ı��޿γɼ���     ");
	scanf("%d",&T->grade1);
	printf("������ı�֮���ѡ�޿γɼ���     ");
	scanf("%d",&T->grade2);
	printf("������ı�֮�����ѡ�γɼ���     ");
	scanf("%d",&T->grade3);
	printf("�޸���ɣ������������\n");
	getch();
	menu();
}
//�޸�ѧ����Ϣ���Ȳ�ѯҪ�޸ĵ��˵�ѧ�ţ����޸�������Ϣ���޸ĵĺ���������
void change(lt T)
{
	int k;
	printf("������Ҫ�޸ĵ�ͬѧ��ѧ�ţ�");
	scanf("%d",&k);
	while(T!=NULL)
	{
		if(T->number==k)
		{
			printf("���ҵ����ˣ������޸�������Ϣ\n");
			gai(T);
			return;
		}
		else {T=T->next;}
	}
	if(T==NULL)
		printf("\n���޴��ˣ�����������ز˵�");
	getch();
	menu();
}
//���м����ͬѧ����Ϣ��������xin()����
void putin(lt T)
{
	int k;
	lt F;
	printf("������Ҫ�ں�������µ�ͬѧ��ͬѧ��ѧ�ţ�");
	scanf("%d",&k);
	while(T!=NULL)
	{	
		if(T->number==k)
		{
			printf("���ҵ�����λ�ã����������ͬѧ����Ϣ\n");
			if(T->next!=NULL)//���Ҫ�����ͬѧ��������
			{
				F=(list*)malloc(sizeof(list));
				F->next=T->next;
				T->next->last=F;
				F->last=T;
				T->next=F;
			}
			else if(T->next==NULL)//���Ҫ�����ͬѧ����û��
			{
				F=(list*)malloc(sizeof(list));
				T->next=F;
				F->last=T;			
				F->next=NULL;
			}
			xin(F);
			menu();
			return;
		}
		else {T=T->next;}
	}
	if(T==NULL)
		printf("\n���޴��ˣ��޷������ͬѧ������������ز˵�");
	getch();
	menu();
}
//ɾ��һ��ָ����ͬѧ����ɾ��ǰ������output()��չʾ��ͬѧ����Ϣ
lt dele(lt T)
{
	int k;
	char z;
	lt N;		//��ɾ���ڵ�ʱ��ʱ�洢�µ�ͷ����λ��
	N=T;
	printf("������Ҫɾ����ͬѧ��ѧ�ţ�");
	scanf("%d",&k);
	while(T!=NULL)
	{
		if(T->number==k)
		{
			printf("���ҵ���ͬѧ��������Ϣ����:\n");
			output(T);
			printf("�Ƿ�ɾ������Y/N\n");
			while(scanf("%c",&z))
			{
				if(z=='Y'||z=='y')
				{
						if(T->last!=NULL&&T->next!=NULL)//���Ҫɾ����ͬѧǰ������
						{
							T->last->next=T->next;
							T->next->last=T->last;
							free(T);
						}
						else if(T->last==NULL&&T->next==NULL)//�����ʱ������ֻ��һ����
						{
							N=NULL;
							free(T);
						}
						else if(T->last==NULL)//���Ҫɾ����ͬѧ�������е�һ����
						{
							T->next->last=NULL;
							N=T->next;
							free(T);
						}
						else if(T->next==NULL)//���Ҫɾ����ͬѧ�����������һ����
						{							
							T->last->next=NULL;
							free(T);
						}
					printf("��ͬѧ��ɾ��������������ز˵�\n");
					getch();
					menu();
					return N;
				}
				else if(z=='n'||z=='N')
				{
					printf("��ɾ����ͬѧ������������ز˵�\n");
					getch();
					menu();
					return T;
				}
			}
		}
		else {T=T->next;}
	}
	if(T==NULL)
		printf("\n���޴��ˣ�����������ز˵�");
	getch();
	menu();
	return T;
}
//ɾ����������
void ruin(lt T)
{
	printf("ȷ��Ҫ��������������Y/N\n");
	char z;
	while(scanf("%c",&z))
	{
		if(z=='Y'||z=='y')
		{
			if(T!=NULL)//�������������
			{
				while(T->next!=NULL)
				{	
					T=T->next;
					free(T->last);
				}	
			}
			else{}//��������Ѿ��ǿյ�
			printf("���������٣�����������ز˵�\n");
			getch();
			menu();
			return;
		}
		else if(z=='n'||z=='N')
		{	printf("����������������������ز˵�\n");
			getch();
			menu();
			return;
		}
	}
}
//רҵ������ձ�(�������)
void daima()
{
	printf("רҵ������ձ����£�\n\n");
	printf("10----ͨ��ѧԺ������רҵ\n");
	printf("11----ͨ��ѧԺ������רҵ\n");
	printf("12----ͨ��ѧԺ��ͨ�Ŵ���\n\n");
	printf("20----���ѧԺ���������רҵ\n");
	printf("21----���ѧԺ���ֻ����רҵ\n");
	printf("22----���ѧԺ�����������רҵ\n\n");
	printf("˵���������λ������0��1��2��ϵͳ�Ὣ����Ϊ2������\n");
	printf("      �����ʽ���������淶�������ϵͳ����Ϊ��������\n");
	printf("      �������ѧ���ظ��������ϵͳ�ڲ�ѯʱ��ֻ���ҵ��������ǰ���д�ѧ�ŵ�ͬѧ\n\n");
	printf("����������ز˵�\n");
	getch();
	menu();
	return;
}