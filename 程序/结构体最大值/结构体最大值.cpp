# include <stdio.h>
typedef struct stu
{
	char num[10];
	int s;
}STU;

// 找出分数最高的学生数据，并将其依次存入结构体数组b中，并返回得最高分的学生人数

int fun(STU a[5], STU *p)	// 形参a, p类型一样，均是STU类型的结构体指针变量
// 参数传递：a = s;  p = b;
{
	int max = a[0].s,  i=0, j=0;	// i: a指向的s数组下标  j：p指向的b数组下标
	// 求最高分
	for(i=0; i<5; i++)
	{
		if(max < a[i].s)
		{
			max = a[i].s;
		}
	}

	// 找出得最高分的学生
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
