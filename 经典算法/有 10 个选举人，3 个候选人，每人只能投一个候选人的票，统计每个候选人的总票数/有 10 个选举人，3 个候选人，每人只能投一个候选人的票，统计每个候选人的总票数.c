#include<stdio.h> 
#include<string.h> 
struct person
{
	char name[10]; 
	int count;
}leader[3]={"zhang",0,"wang",0,"li",0};
void main()
{
	int i,j;
	char leader_name[10]; 
	for(i=1;i<=10;i++)
	{
		scanf("%s",leader_name); 
		for(j=0;j<3;j++)
			if(strcmp(leader_name,leader[j].name)==0) 
				leader[j].count++;
	}
	for(j=0;j<3;j++)
		printf("%8s:%d\n",leader[j].name,leader[j].count);
}

