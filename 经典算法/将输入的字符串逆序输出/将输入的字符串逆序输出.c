#include<stdio.h> 
#include<string.h>
int fun (char *); 
int main()
{
	char a[256];
	printf("请输入字符串:\n"); 
	gets(a);
	fun(a);
	printf("逆序转换后的字符串是:\n"); 
	puts(a);
}
int fun(char *s)
{
	int n,i;
	char c; 
	n=strlen(s); 
	printf("%d",n);
	for(i=0;i<=(n/2-1);i++)
	{
		c=*(s+i);
		*(s+i)=*(s+n-1-i);
		*(s+n-1-i)=c;
	}
	return 0;
}

