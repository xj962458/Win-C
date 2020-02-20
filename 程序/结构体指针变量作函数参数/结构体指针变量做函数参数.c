#include<stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
void fun1(struct date d)
{
	d.year=2014;
	d.month=9;
	d.day=27;
}
void fun2(struct date *pd)
{
	pd->year=2014;
	pd->month=9;
	pd->day=27;
}
void main()
{
	struct date a,b;
	a.year=2015;
	a.month=2;
	a.day=18;
	b=a;
	fun1(a);
	printf("d.year=%d,d.month=%d,d.day=%d\n,d.year,d.monyh,d.day);
	printf("a.year=%d a.month=%d a.day=%d\n",a.year,a.month,a.day);
	fun2(&b);
	printf("b.year=%d b.month=%d b.day=%d\n",b.year,b.month,b.day);
}
