#include"com.h"
double aver(stu* p)		//计算平均分
{
	int i;
	double sum = 0;
	for (i = 0; i < 3; ++i)
	{
		sum += p->score[i];
	}
	return sum / 3;
}