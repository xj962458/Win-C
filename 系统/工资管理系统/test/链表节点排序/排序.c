#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct student
{
	struct student *ahead;
	float grade[10];
	char name[10];
	char x[10];
	struct student *next;
}*head, *end, *New, *get, *stu;
int input(int N, char **G)//��������
//����˵������N��Ϊ���ԵĿ�Ŀ�������˴�**GΪ�ַ���ָ�����飬���д洢�ſ��Կ�Ŀ��
{
	int i, c = 1, icount = 0, s[10], j, k, d;
	char r[10];
	for (j = 0; j < 10; j++)
		s[j] = 0;
	while (c)
	{
		New = (struct student *)malloc(sizeof(struct student));
		printf("\t\t�������ѧ������(�����밴��0��):");
		scanf("%s", New->name);
		if (New->name[0] != 48)
		{
			printf("\t\t�������ѧ��ѧ��:");
			scanf("%s", r);
			icount++;
			strcpy(New->x, r);
			New->grade[N] = 0;
			for (i = 0; i < N; i++)
			{
				printf("\t\t%s�ɼ�:", G[i]);
				scanf("%f", &New->grade[i]);
				if (New->grade[i] < 60)
					s[i]++;
				New->grade[N] = New->grade[N] + New->grade[i];
			}
			strcpy(New->mima, "1234");
			end->next = New;
			New->ahead = end;
			end = New;
			end->next = NULL;
		}
	}
	else
	{
		c = 0;
	}
}
int paixu(int N)//�ɼ�����
{
	int i;//�ڳ���ĺ������û�ѡ�������ǽ������򣬱���i�������Ǹ���i��ֵѡ������ʽ����iΪ1�������У�0����������
	struct student *min, *xunow, *uend;
	uend = (struct student *)malloc(sizeof(struct student));
	uend->grade[0] = -1;
	uend->next = NULL;
	uend->ahead = end;
	end->next = uend;
