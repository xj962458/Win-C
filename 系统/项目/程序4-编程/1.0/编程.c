#include<stdio.h>
#define N 2
struct student
{
	int num;
	char name[30];
	int score[3];
};
typedef struct student stu;
void input(stu* p) 
{//����
	int i,j;
	for (i = 0; i < N;++i)                                                   						
	{		
		printf("�������%d��ѧ������Ϣ\n", i + 1);
		printf("������num\n");
		scanf("%d", &(p + i)->num);
		printf("����������\n");
		scanf("%s", &(p + i)->name);
		for (j = 0; j < 3; ++j) 
		{
			printf("������score%d\n", j + 1);
			scanf("%d", &(p + i)->score[j]);
		}
	}
}
void print(stu* p) 
{//���
	int j;
	printf("%d\t", p->num);
	printf("%s\t", p->name);
	for (j = 0; j < 3; ++j) 
	{
		printf("%d\t", p->score[j]);
	}
}
double ave(stu* p) {//����ƽ����
	int i;
	double sum = 0;
	for (i = 0; i < 3; ++i) {
		sum += p->score[i];
	}
	return sum / 3;
}
int max(stu* p) {//�ж���߷�,�����±�
	int i,j;
	double sum = 0;
	double top = 0;
	int record = 0;
	for (i = 0; i < N; ++i) {
		sum = 0;
		for (j = 0; j < 3; ++j) {
			sum += (p + i)->score[j];
		}
		if (top< sum) {
			top= sum;
			record = i;
		}
	}
	return record;
}
int main() 
{
	int i,n;
	stu a[N];
	stu* p = a;
	input(p);
	printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	for (i = 0; i < N; i++) {
		print(p + i);
		printf("%.1f\n", ave(p + i));
	}
	printf("��߷ֵ�ѧ����������\nѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	n=max(p);
	print(p + n);
	printf("%.1f\n", ave(p + n));
}
