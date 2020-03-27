#include "stdio.h"
void main()
{
	char a; 
	scanf("%c",&a);
	if(a>='0'&&a<='9')
	{
		a=a-'0';
		printf("%d",a);
	}
	else
		printf("%d",a);

}
 

