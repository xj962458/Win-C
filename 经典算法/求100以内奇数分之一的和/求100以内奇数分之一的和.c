#include <stdio.h> 
void main()
{
	int  i;
	float s=0;
	for(i=1;i<=99;i+=2)
	s=s+1.0/i;
	printf("s=%f\n",s);
}
