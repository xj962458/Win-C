# include <stdio.h>
# include <string.h>

typedef struct stu
{
	char num[10];
	int s;
}STU;

// 先按照学生分数从小到大排序，如果分数相同，则按照学号降序排序
void fun(STU *a)
{
	int i, j;
	for(i=0; i<=3; i++)
	{
		for(j=0; j<=3-i; j++)
		{
			// 先按照分数升序排序
			if(a[j].s > a[j+1].s)
			{
				STU  t;		// 务必记住：交换的不仅仅是两个学生的成绩，而是两个学生! 下同
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}

			// 如果分数相同则按学号降序排序
			if(a[j].s == a[j+1].s && strcmp(a[j].num,  a[j+1].num)== -1)	// 比较字符串大小只能用strcmp
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
