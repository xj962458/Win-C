#include <stdio.h>
void main()
{
	int strcmp(char *p1,char *p2); 
	int i;
	char str1[10],str2[10];
	puts("请输入两个字符串:");
	puts("字符串 1:"); gets(str1);
	puts("字符串 2:");
	gets(str2);
	printf("比较结果为: %d\n",strcmp(str1,str2));
}
	int strcmp(char *p1,char *p2)
	{
		int i=0;
		while(*(p1+i)==*(p2+i)&&*(p1+i)!=0) 
			i++; 
		return(*(p1+i)-*(p2+i));
	}

