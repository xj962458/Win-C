#include<stdio.h> 
#define N 100
void fun(char *strA, char *strB);
void main(void)
{
	char strA[N];	
	char strB[N];
	printf("请输入字符串:\n");
	gets(strA); fun(strA, strB);
	printf("复制后的字符串:\n");
	puts(strB);
}
void fun(char *strA, char *strB)
{
	int i;
	int k =0;
	for (i=0; strA[i] != '\0'; i++)
		if((strA[i] >= 'A')&&(strA[i]<='Z'))
			strB[k++] = strA[i];
	strB[k]='\0';
}

