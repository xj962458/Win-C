#include"com.h"
int excellect(stu* p)	//判断最高分,返回下标
{
	int i,j;
	double sum = 0;
	double max = 0;
	int record = 0;
	for (i = 0; i < N; ++i) {
		sum = 0;
		for (j = 0; j < 3; ++j) {
			sum += (p + i)->score[j];
		}
		if (max < sum) {
			max = sum;
			record = i;
		}
	}
	return record;
}
