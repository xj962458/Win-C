#include<stdio.h>
void main()
{
	char *alpha[6]={"a","bc","def","1","23","qq"},**p;
	int i;
	p=alpha;
	for(i=0;i<6;i++,p++)
		printf(" %s",*p);
	printf("\t"); 
	p=p-3; 
	for(i=0;i<6;i++,p++)
		printf("%c\t",**p);
	printf("\n");
}
