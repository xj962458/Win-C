#include<stdio.h>
#define N 2
struct student {
	int num;
	char name[30];
	int score[3];
};
typedef struct student stu;
void input(stu* p) {//输入                                 
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
void print(stu* p,FILE *fp) {//输出
	int j;
	fprintf(fp,"%d\t", p->num);
	fprintf(fp,"%s\t", p->name);
	for (j = 0; j < 3; ++j) {
		fprintf(fp,"%d\t", p->score[j]);
	}
}
double aver(stu* p) {//计算平均分
	int i;
	double sum = 0;
	for (i = 0; i < 3; ++i) {
		sum += p->score[i];
	}
	return sum / 3;
}
int excellect(stu* p) {//判断最高分,返回下标
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
void main() {
	FILE *fp;
	int i,n;
	stu a[N];
	stu* p = a;
	fp=fopen("xjt.txt","w");
	input(p);
	fprintf(fp,"学号\t姓名\t成绩1\t成绩2\t成绩3\t平均\n");
	for (i = 0; i < N; i++) {
		print(p + i,fp);
		fprintf(fp,"%.1f\n", aver(p + i));
	}
	fprintf(fp,"最高分的学生数据如下\n学号\t姓名\t成绩1\t成绩2\t成绩3\t平均\n");
	n = excellect(p);
	print(p + n,fp);
	fprintf(fp,"%.1f\n", aver(p + n));
	fclose(fp);
}

																							
