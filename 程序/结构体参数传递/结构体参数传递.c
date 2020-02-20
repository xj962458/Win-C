# include <stdio.h>
typedef struct stu
{
	char name[10];
	char sex;
	float score[3];
}STU;

void fun1(STU *p)	// <=> (STU p[2]) <=> (STU p[])
// 参数传递：p = s
{
	p[1].score[0]=1;	// 根据教材P111第4种引用方式  p[1]<=>s[1]，改变了p[1]中score成员的值等价于改变了s[1]中score成员的值
	p[1].score[1]=2;
	p[1].score[2]=3;
}

void fun2(STU x)
// 参数传递：x = s[0]  此处不涉及到任何指针或者地址的参数传递，x和s[0]均是第一类中的普通STU类型结构体变量
{
	x.score[0]=50;	// x的成员的值发生改变，不会影响到实参变量s[0]的成员，下同
	x.score[1]=60;
	x.score[2]=70;
}

STU fun3(STU x)
{
	x.score[0]=555;	// x的成员的值发生改变，不会影响到实参变量s[0]的成员，下同
	x.score[1]=666;
	x.score[2]=777;
	return x;		// 将x的值返回至main函数并赋给了main函数中的变量s[0], 因此，虽然形参的改变没有影响到实参的改变，但是返回值影响了实参的改变。
}

void main()
{
	STU  s[2]={ {"Lucy", 'F', 90,80,70}, {"LiLei", 'M', 100,200,300}};

	fun1(s);
	printf("%g %g %g\n", s[0].score[0], s[0].score[1], s[0].score[2]);	// 输出：90  80  70
	printf("%g %g %g\n", s[1].score[0], s[1].score[1], s[1].score[2]);	// 输出：1  2  3		受到形参指针影响，实参发生改变  

	fun2(s[0]);
	printf("%g %g %g\n", s[0].score[0], s[0].score[1], s[0].score[2]);	// 输出：90  80  70		实参未受到形参变量改变的影响

	s[0] = fun3(s[0]);	// fun3函数返回值直接影响了s[0]
	printf("%g %g %g\n", s[0].score[0], s[0].score[1], s[0].score[2]);	// 输出：555  666  777	实参未受影响，但是返回值影响了s[0]

}