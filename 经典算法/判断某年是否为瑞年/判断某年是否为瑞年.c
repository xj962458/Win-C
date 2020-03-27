#include "stdio.h"
void main() 
{
	int year;
	scanf("%d",&year);
	if((year%400==0)||(year%4==0&&year%100!=0))
		printf("It is runnian");
	else
		printf("It is not runnian");

}
 



