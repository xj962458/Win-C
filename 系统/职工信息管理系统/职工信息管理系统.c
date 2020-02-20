#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


// ְ����Ϣ�ṹ��
struct employee_Info
{
	char num;
	char name[20];
	char sex[20];
	int age;
	char xueli[30];
	int wage;
	char tel[20];
};
typedef struct employee_Info EMP;

// ����ṹ��ڵ�
struct message_Info
{
	EMP employee_data;
	struct message_Info *next;
};
typedef struct message_Info MES;

// ¼������ģ��
void Creat_linklist(MES * head)
{
	MES *tail, *pnew;
	int i, m;
	printf("��������Ҫ������Ϣ��ְ��������");
	scanf("%d", &m);

	tail = head;

	printf("������ְ���Ź���Ϣ��\n");
	for (i = 0; i < m; i++)
	{

		pnew = (MES *) malloc(sizeof(MES));
		if (head == NULL)
		{
			printf("no enough memory!\n");
			exit(0);
		}
		printf("������ְ���ţ�");
		scanf("%d", &pnew->employee_data.num);
		printf("������������");
		scanf("%s", &pnew->employee_data.name);
		printf("�������Ա�");
		scanf("%s", &pnew->employee_data.sex);
		printf("���������䣺");
		scanf("%d", &pnew->employee_data.age);
		printf("������ѧ����");
		scanf("%s", &pnew->employee_data.xueli);
		printf("�����빤�ʣ�");
		scanf("%d", &pnew->employee_data.wage);
		printf("������绰��");
		scanf("%s", &pnew->employee_data.tel);
		pnew->next = NULL;

		tail->next = pnew;
		tail = pnew;
	}
}


// �������
void Display_Linklist(MES * head)
{
	MES *p;
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("ְ���ţ�%d\n", p->employee_data.num);
		printf("������%s\n", p->employee_data.name);
		printf("�Ա�%s\n", p->employee_data.sex);
		printf("���䣺%d\n", p->employee_data.age);
		printf("ѧ����%s\n", p->employee_data.xueli);
		printf("���ʣ�%d\n", p->employee_data.wage);
		printf("�绰��%s\n", p->employee_data.tel);
	}
	printf("\n");
}


// ɾ������
void Delete_Linklist(MES * head)
{
	MES *p, *q;
	int i, j;

	printf("����������Ҫɾ����ְ���ţ�");
	scanf("%d", &i);
	if (i == 0)
		return;

	p = head;
	for (j = 1; j < i && p->next != NULL; j++)
		p = p->next;
	if (p->next == NULL)
	{
		printf("���޴�ְ���ţ�");
		exit(0);
	}

	q = p->next;
	p->next = q->next;
	free(q);
}

// �������
void Insert_Linklist(MES * head)
{
	MES *p, *pnew;

	p = head;
	pnew = (MES *) malloc(sizeof(MES));
	if (pnew == NULL)
	{
		printf("no enough memory!\n");
		exit(0);
	}

	printf("������ְ���ţ�");
	scanf("%d", &pnew->employee_data.num);
	printf("������������");
	scanf("%s", &pnew->employee_data.name);
	printf("�������Ա�");
	scanf("%s", &pnew->employee_data.sex);
	printf("���������䣺");
	scanf("%d", &pnew->employee_data.age);
	printf("������ѧ����");
	scanf("%s", &pnew->employee_data.xueli);
	printf("�����빤�ʣ�");
	scanf("%d", &pnew->employee_data.wage);
	printf("������绰��");
	scanf("%s", &pnew->employee_data.tel);
	pnew->next = NULL;

	pnew->next = p->next;
	p->next = pnew;
}


// �޸�����
void Modify(MES * head)
{
	MES *p;
	int a;
	printf("�����������޸ĵ�ְ���ţ�");
	scanf("%d", &a);

	for (p = head->next; p != NULL; p = p->next)
	{
		if (p->employee_data.num == a)
		{
			printf("���ҵ�ְ����Ϣ��\n");
			printf("ԭְ���ţ�%d,��ְ���ţ�", p->employee_data.num);
			scanf("%d", &p->employee_data.num);
			printf("ԭְ��������%s,��ְ��������",
				   p->employee_data.name);
			scanf("%s", &p->employee_data.name);
			printf("ԭְ�Ա�%s,��ְ�Ա�", p->employee_data.sex);
			scanf("%s", &p->employee_data.sex);
			printf("ԭְ�����䣺%d,��ְ�����䣺",
				   p->employee_data.age);
			scanf("%d", &p->employee_data.age);
			printf("ԭְ��ѧ����%s,��ְ��ѧ����",
				   p->employee_data.xueli);
			scanf("%s", &p->employee_data.xueli);
			printf("ԭְ�����ʣ�%d,��ְ�����ʣ�",
				   p->employee_data.wage);
			scanf("%d", &p->employee_data.wage);
			printf("ԭְ���绰��%s,��ְ���绰��",
				   p->employee_data.tel);
			scanf("%s", &p->employee_data.tel);
		}
		if (p == NULL)
			printf("�Բ�������Ҫ�޸ĵ���Ϣ�����ڣ�");
	}
}



// �����Ų�������
void Search_num(MES * head)
{
	MES *p;
	int a;
	printf("��������Ҫ��ѯ��ְ���ţ�");
	scanf("%d", &a);

	for (p = head->next; p != NULL; p = p->next)
	{
		if (p->employee_data.num == a)
			printf("���ҵ������¼Ϊ��\n");
		printf("���ţ�%d\n", p->employee_data.num);
		printf("������%s\n", p->employee_data.name);
		printf("�Ա�%s\n", p->employee_data.sex);
		printf("���䣺%d\n", p->employee_data.age);
		printf("ѧ����%s\n", p->employee_data.xueli);
		printf("���ʣ�%d\n", p->employee_data.wage);
		printf("�绰��%s\n", p->employee_data.tel);
	}

	if (p == NULL)
		printf("�Բ��𣬲��޴��ˣ�");

}


// ��������������
void Search_name(MES * head)
{
	MES *p;
	char name[20];
	printf("��������Ҫ��ѯ��ְ��������");
	scanf("%s", &name);

	for (p = head->next; p != NULL; p = p->next)
	{
		if (p->employee_data.num == name)
			printf("���ҵ������¼Ϊ��\n");
		printf("���ţ�%d\n", p->employee_data.num);
		printf("������%s\n", p->employee_data.name);
		printf("�Ա�%s\n", p->employee_data.sex);
		printf("���䣺%d\n", p->employee_data.age);
		printf("ѧ����%s\n", p->employee_data.xueli);
		printf("���ʣ�%d\n", p->employee_data.wage);
		printf("�绰��%s\n", p->employee_data.tel);
	}

	if (p == NULL)
		printf("�Բ��𣬲��޴��ˣ�");

}





// д���ļ�
void Write_file(MES * head)
{
	MES *p;
	FILE *fp;

	if ((fp = fopen("ְ������ϵͳ.dat", "wb")) == NULL)
	{
		printf("�޷����ļ���");
		exit(0);
	}

	for (p = head->next; p != NULL; p = p->next)
	{
		fprintf(fp, "%d,%s,%s,%d,%s,%d,%s", p->employee_data.num,
				p->employee_data.name, p->employee_data.sex,
				p->employee_data.age, p->employee_data.xueli,
				p->employee_data.wage, p->employee_data.tel);

	}
	fclose(fp);
}

// ��ʾ����
void Read_file(MES * head)
{
	MES *p;
	FILE *fp;

	if ((fp = fopen("ְ������ϵͳ.dat", "rb")) == NULL)
	{
		printf("�޷����ļ���");
		exit(0);
	}

	for (p = head->next; p != NULL; p = p->next)
		fscanf(fp, "%d,%s,%s,%d,%s,%d,%s", &p->employee_data.num,
			   p->employee_data.name, p->employee_data.sex,
			  &p->employee_data.age, p->employee_data.xueli,
			   &p->employee_data.wage, p->employee_data.tel);

	if (p = NULL)
		fscanf(fp, "%d,%s,%s,%d,%s,%d,%s", &p->employee_data.num,
			   p->employee_data.name, p->employee_data.sex,
			  &p->employee_data.age, p->employee_data.xueli,
			   &p->employee_data.wage, p->employee_data.tel);

	fclose(fp);

	for (p = head->next; p != NULL; p = p->next)
	{
		printf("���ţ�%d\n", p->employee_data.num);
		printf("������%s\n", p->employee_data.name);
		printf("�Ա�%s\n", p->employee_data.sex);
		printf("���䣺%d\n", p->employee_data.age);
		printf("ѧ����%s\n", p->employee_data.xueli);
		printf("���ʣ�%d\n", p->employee_data.wage);
		printf("�绰��%s\n", p->employee_data.tel);
	}
}






// ������
void main()
{
	MES *head;
	int n;

	head = (MES *) malloc(sizeof(MES));
	if (head == NULL)
	{
		printf("no enough memory!\n");
		exit(0);
	}
	head->next = NULL;

	while (1)
	{
		printf
			("��������������ӭ����ְ����Ϣ����ϵͳ������������\n");
		printf("              1.¼��ְ����Ϣ\n");
		printf("              2.���ְ����Ϣ\n");
		printf("              3.ɾ��ְ����Ϣ\n");
		printf("              4.���ְ����Ϣ\n");
		printf("              5.�޸�ְ����Ϣ\n");
		printf("              6.�����Ų�ѯְ����Ϣ\n");
		printf("              7.��������ѯְ����Ϣ\n");
		printf("              8.�˳�\n");
		printf("              9.�ļ���ʾְ����Ϣ\n");
		printf
			("���x�x�x�x�x�x�x�x�xллʹ�èx�x�x�x�x�x�x�x�x��\n");


		printf("����������Ҫִ�еĹ��ܴ��ţ�");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Creat_linklist(head);
			Write_file(head);
			break;
		case 2:
			Display_Linklist(head);
			break;
		case 3:
			Delete_Linklist(head);
			break;
		case 4:
			Insert_Linklist(head);
			break;
		case 5:
			Modify(head);
			break;
		case 6:
			Search_num(head);
			break;
		case 7:
			Search_name(head);
			break;
		case 8:
			printf("ллʹ�ã�");
			break;
		case 9:
			Read_file(head);
			break;
		}

	}
}

