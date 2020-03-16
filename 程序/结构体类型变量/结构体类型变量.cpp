#include<stdio.h>
int main()
{
	struct date
	{
		int year;
		int month;
		int day;
	};
	struct student_type
	{
		int num;
		char name[20];
		char sex;
		struct date birthday;
		int score;
	};
	struct date today={1999,12,31};
	struct student_type s1={1,"wxj",'m',today,99};
	printf("%d\n",s1.num);
	printf("%s\n",s1.name);
	printf("%c\n",s1.sex);
	printf("%d-%d\n",s1.birthday.month,s1.birthday.day);
	printf("%d\n",s1.score);
}


