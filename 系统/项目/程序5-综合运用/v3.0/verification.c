#include<stdio.h>
#include"com.h"
void verification()		//第3题--验证
{
	
	    int a,b;
	    a=2,b=3;
	    printf("%d\n",a^b>>2);
		a=a>>2;
	    b=b<<3;
	    printf("%d,%d \n",a,b);
}
