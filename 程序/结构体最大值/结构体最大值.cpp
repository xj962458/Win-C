# include <stdio.h>
typedef struct stu
{
	char num[10];
	int s;
}STU;

// �ҳ�������ߵ�ѧ�����ݣ����������δ���ṹ������b�У������ص���߷ֵ�ѧ������

int fun(STU a[5], STU *p)	// �β�a, p����һ��������STU���͵Ľṹ��ָ�����
// �������ݣ�a = s;  p = b;
{
	int max = a[0].s,  i=0, j=0;	// i: aָ���s�����±�  j��pָ���b�����±�
	// ����߷�
	for(i=0; i<5; i++)
	{
		if(max < a[i].s)
		{
			max = a[i].s;
		}
	}

	// �ҳ�����߷ֵ�ѧ��
	for(i=0; i<5; i++)
	{
		if(max == a[i].s)
		{
			p[j++] = a[i];
		}
	}
	return j;
}

void main()
{
	int i, n;
	STU s[5]={{"101", 85}, {"102", 90}, {"103", 95}, {"104", 77}, {"105", 95}},  b[5];
	n = fun(s, b);
	for(i=0; i<n; i++)
	{
		printf("%s, %d\n", b[i].num, b[i].s);
	}
}