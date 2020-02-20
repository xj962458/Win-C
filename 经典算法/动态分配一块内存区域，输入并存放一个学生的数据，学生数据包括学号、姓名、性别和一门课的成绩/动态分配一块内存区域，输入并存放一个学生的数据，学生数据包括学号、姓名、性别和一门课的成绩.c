#include<malloc.h> 
void main()
{
	struct stu
	{
		int num; 
		char *name; 
		char sex; 
		float score;
	}*ps;
	ps=(struct stu *)malloc(sizeof(struct stu)); 
	ps->num=101;
	ps->name="zhang ming"; 
	ps->sex='M';
	ps->score=85.5;
	printf("Number=%d\nName=%s\nSex=%c\nScore=%.1f\n",ps->num,ps->name, ps->sex,ps->score);
	free(ps);
}
