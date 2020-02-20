#include<stdio.h> 
#define NUM 20 
struct mem
{
	char name[20]; 
	char phone[10]; 
	char addr[100];
};
void main()
{
	struct mem man[NUM]; 
	int i; 
	for(i=0;i<NUM;i++)
	{
		printf("inp ut name:\n"); 
		gets(man[i].name); 
		printf("input phone:\n"); 
		gets(man[i].phone); 
		printf("input address:\n"); 
		gets(man[i].addr);
	}
	printf("name\t\tphone\n\n"); 
	for(i=0;i<NUM;i++)
		printf("%s\t\t%s\t\t%s\n",man[i].name,man[i].phone, man[i].addr);
}
