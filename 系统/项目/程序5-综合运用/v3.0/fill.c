#include<stdio.h>
#include"com.h"
void fill()		//第2题--填空
{ 
    union un
   {   
       int i;
       char c[2];
    };
    union un a;
	printf("请输入两个字符\n");
    scanf("%c,%c",&a.c[0],&a.c[1]);
    printf("%x\n",a.i);
    printf("%x%x\n",a.c[1],a.c[0]);
}