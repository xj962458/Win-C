#include"com.h"
void xprint(stu* p ,FILE *fp)	//输出至文本文件
{
	int j;
	fprintf(fp,"%d\t", p->num);
	fprintf(fp,"%s\t", p->name);
	for (j = 0; j < 3; ++j) 
    {
		fprintf(fp,"%d\t", p->score[j]);
	}
}
