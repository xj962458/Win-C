# include <stdio.h>
typedef struct stu
{
	char name[10];
	char sex;
	float score[3];
}STU;

void fun1(STU *p)	// <=> (STU p[2]) <=> (STU p[])
// �������ݣ�p = s
{
	p[1].score[0]=1;	// ���ݽ̲�P111��4�����÷�ʽ  p[1]<=>s[1]���ı���p[1]��score��Ա��ֵ�ȼ��ڸı���s[1]��score��Ա��ֵ
	p[1].score[1]=2;
	p[1].score[2]=3;
}

void fun2(STU x)
// �������ݣ�x = s[0]  �˴����漰���κ�ָ����ߵ�ַ�Ĳ������ݣ�x��s[0]���ǵ�һ���е���ͨSTU���ͽṹ�����
{
	x.score[0]=50;	// x�ĳ�Ա��ֵ�����ı䣬����Ӱ�쵽ʵ�α���s[0]�ĳ�Ա����ͬ
	x.score[1]=60;
	x.score[2]=70;
}

STU fun3(STU x)
{
	x.score[0]=555;	// x�ĳ�Ա��ֵ�����ı䣬����Ӱ�쵽ʵ�α���s[0]�ĳ�Ա����ͬ
	x.score[1]=666;
	x.score[2]=777;
	return x;		// ��x��ֵ������main������������main�����еı���s[0], ��ˣ���Ȼ�βεĸı�û��Ӱ�쵽ʵ�εĸı䣬���Ƿ���ֵӰ����ʵ�εĸı䡣
}

void main()
{
	STU  s[2]={ {"Lucy", 'F', 90,80,70}, {"LiLei", 'M', 100,200,300}};

	fun1(s);
	printf("%g %g %g\n", s[0].score[0], s[0].score[1], s[0].score[2]);	// �����90  80  70
	printf("%g %g %g\n", s[1].score[0], s[1].score[1], s[1].score[2]);	// �����1  2  3		�ܵ��β�ָ��Ӱ�죬ʵ�η����ı�  

	fun2(s[0]);
	printf("%g %g %g\n", s[0].score[0], s[0].score[1], s[0].score[2]);	// �����90  80  70		ʵ��δ�ܵ��βα����ı��Ӱ��

	s[0] = fun3(s[0]);	// fun3��������ֱֵ��Ӱ����s[0]
	printf("%g %g %g\n", s[0].score[0], s[0].score[1], s[0].score[2]);	// �����555  666  777	ʵ��δ��Ӱ�죬���Ƿ���ֵӰ����s[0]

}