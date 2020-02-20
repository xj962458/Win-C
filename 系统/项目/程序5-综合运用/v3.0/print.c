#include"com.h"
void print(stu* p)	//输出
{
	int j;
	printf("%d\t", p->num);
	printf("%s\t", p->name);
	for (j = 0; j < 3; ++j) {
		printf("%d\t", p->score[j]);
	}
}