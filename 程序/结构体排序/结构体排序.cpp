# include <stdio.h>
# include <string.h>

typedef struct stu
{
	char num[10];
	int s;
}STU;

// �Ȱ���ѧ��������С�����������������ͬ������ѧ�Ž�������
void fun(STU *a)
{
	int i, j;
	for(i=0; i<=3; i++)
	{
		for(j=0; j<=3-i; j++)
		{
			// �Ȱ��շ�����������
			if(a[j].s > a[j+1].s)
			{
				STU  t;		// ��ؼ�ס�������Ĳ�����������ѧ���ĳɼ�����������ѧ��! ��ͬ
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}

			// ���������ͬ��ѧ�Ž�������
			if(a[j].s == a[j+1].s && strcmp(a[j].num,  a[j+1].num)== -1)	// �Ƚ��ַ�����Сֻ����strcmp
			{
				STU t;
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

void main()
{
	int i;
	STU s[5]={{"101", 85}, {"102", 90}, {"103", 95}, {"104", 77}, {"105", 95}};
	fun(s);
	for(i=0; i<5; i++)
	{
		printf("%s, %d\n", s[i].num, s[i].s);
	}
}