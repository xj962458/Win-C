#include"com.h"
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
