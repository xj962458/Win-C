#include"com.h"
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