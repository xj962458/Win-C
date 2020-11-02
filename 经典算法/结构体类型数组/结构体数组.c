#include<stdio.h>
struct student
{
	char name[20];
	long number;
	float score[4];
};
void aver(struct student s[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		s[i].score[3]=0;
		for(j=0;j<3;j++)
			s[i].score[3]+=s[i].score[j];
		s[i].score[3]=s[i].score[3]/3;
	}
}
void sort(struct student s[],int n)
{
	struct student temp;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(s[j].score[3]>s[j+1].score[3])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
}
void output(struct student s[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("%8s %3ld",s[i].name,s[i].number);
		for(j=0;j<4;j++)
			printf("%4.1f",s[i].score[j]);
		printf("\n");
	}
}
void main()
{
	struct student stu[4]={ {"Liping" ,01,67,72,65},
							{"Yaomin" ,02,77,73,80},
							{"Sunyang",03,81,79,90},
							{"Liudong",04,68,78,89}
							};
	printf("姓名 学号 英语 数学 物理 平均成绩\n");
	aver(stu,4);
	sort(stu,4);
	output(stu,4);
}
