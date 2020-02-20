#include<stdio.h>
#include"com.h"
void correct()	//第1题--改错
{
	struct student1 stud[5];
	int i,n=0;
	for(i=0;i<5;i++)
	{
      printf("Input NO.%d num: ",i+1);
      scanf("%d",&stud[i].num);
      printf("Input NO.%d name: ",i+1);
      scanf("%s",stud[i].name);
      printf("Input NO.%d score: ",i+1);
      scanf("%d",&stud[i].score);
	}
    printf("num\tname\t\tscore\n");
    i=0;
    while(i<5)
    {
        if(stud[i].score<60)
        {
            printf("%d\t%-15s\t%d\n",stud[i].num,stud[i].name,stud[i].score);
            n++;
        }
        i++;
    }
    printf("n=%d\n",n);
}

void fill()		//第2题--填空
{ 
    union un
   {   
       int i;
       char c[2];
    };
    union un a;
	printf("请输入两个字符\n");
    scanf("%c,%c",&a.c[0],&a.c[1]);
    printf("%x\n",a.i);
    printf("%x%x\n",a.c[1],a.c[0]);
}

void verification()		//第3题--验证
{
	
	    int a,b;
	    a=2,b=3;
	    printf("%d\n",a^b>>2);
		a=a>>2;
	    b=b<<3;
	    printf("%d,%d \n",a,b);
}

void program_1()	//第4题--编程
{
	int i,n;
	stu a[N];
	stu* p = a;
	input(p);
	printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t平均\n");
	for (i = 0; i < N; i++) 
	{
		print(p + i);
		printf("%.1f\n", aver(p + i));
	}
	printf("最高分的学生数据如下\n学号\t姓名\t成绩1\t成绩2\t成绩3\t平均\n");
	n = excellect(p);
	print(p + n);
	printf("%.1f\n", aver(p + n));
}

void program_2()	//第5题--编程输出txt文件
{
	FILE *fp;
	int i,n;
	stu a[N];
	stu* p = a;
	fp=fopen("xjt.txt","w");
	input(p);
	fprintf(fp,"学号\t姓名\t成绩1\t成绩2\t成绩3\t平均\n");
	for (i = 0; i < N; i++) {
		xprint(p + i,fp);
		fprintf(fp,"%.1f\n", aver(p + i));
	}
	fprintf(fp,"最高分的学生数据如下\n学号\t姓名\t成绩1\t成绩2\t成绩3\t平均\n");
	n =excellect(p);
	xprint(p + n,fp);
	fprintf(fp,"%.1f\n", aver(p + n));
	fclose(fp);
}

void input(stu* p)	//输入
{
	int i,j;
	for (i = 0; i < N; ++i) {
		printf("请输入第%d个学生的信息\n", i + 1);
		printf("请输入num\n");
		scanf("%d", &(p + i)->num);
		printf("请输入姓名\n");
		scanf("%s", &(p + i)->name);
		for (j = 0; j < 3; ++j) {
			printf("请输入score%d\n", j + 1);
			scanf("%d", &(p + i)->score[j]);
		}
	}
}

void print(stu* p)	//输出
{
	int j;
	printf("%d\t", p->num);
	printf("%s\t", p->name);
	for (j = 0; j < 3; ++j) {
		printf("%d\t", p->score[j]);
	}
}


void xprint(stu* p ,FILE *fp)	//输出至文本文件
{
	int j;
	fprintf(fp,"%d\t", p->num);
	fprintf(fp,"%s\t", p->name);
	for (j = 0; j < 3; ++j) {
		fprintf(fp,"%d\t", p->score[j]);
	}
}


double aver(stu* p)		//计算平均分
{
	int i;
	double sum = 0;
	for (i = 0; i < 3; ++i)
	{
		sum += p->score[i];
	}
	return sum / 3;
}


int excellect(stu* p)	//判断最高分,返回下标
{
	int i,j;
	double sum = 0;
	double max = 0;
	int record = 0;
	for (i = 0; i < N; ++i) {
		sum = 0;
		for (j = 0; j < 3; ++j) {
			sum += (p + i)->score[j];
		}
		if (max < sum) {
			max = sum;
			record = i;
		}
	}
	return record;
}

void menu()
{
    system("cls");
		printf("窗口菜单:\n");
		printf("第1题--改错\n");
		printf("第2题--填空\n");
		printf("第3题--验证\n");
		printf("第4题--编程\n");
		printf("第5题--编程输出文本文件\n");
}








