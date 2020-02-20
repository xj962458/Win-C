#include <stdio.h> 
int len(char* str)
{
	int i=0; 
	while(*str++)
		i++;
	return i;
}
void main()
{
	char s[80]; 
	int num; 
	gets(s); 
	num=len(s); 
	printf("%d",num);
}
