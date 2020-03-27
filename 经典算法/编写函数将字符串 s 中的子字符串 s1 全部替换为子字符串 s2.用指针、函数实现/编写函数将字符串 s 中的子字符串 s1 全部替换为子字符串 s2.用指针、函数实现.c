#include<stdio.h>
#include<string.h>
#define MAXLENGTH 100
void replace(char *s, char *s1, char *s2)
{
	int len1=strlen(s), len2=strlen(s1),len3=strlen(s2); 
	char buf[MAXLENGTH];
	int i,j,k,l;
	for(i=0,k=0;i<len1-len2+1;)
	{
		for(j=0;j<len2;j++)
		{
		if(*(s+i+j)!=*(s1+j))
			break;
		}
		if(j==len2)
		{
			l=0;
			while(l<len3) *(buf+k++)=*(s2+l++); 
				i+=len2;
			continue;
		}
		else
			*(buf+k++)=*(s+i++);

	}
	while(i<len1) 
		*(buf+k++)=*(s+i++);
	*(buf+k)='\0'; 
	strcpy(s, buf);
}
void main()
{
	char str[MAXLENGTH]={NULL}; 
	char str1[MAXLENGTH]={NULL}; 
	char str2[MAXLENGTH]={NULL};
	printf("请输入字符串 s: \n");
	gets(str); 
	fflush(stdin);
	printf("请输入字符串 s1: \n");
	gets(str1); 
	fflush(stdin);
	printf("请输入字符串 s2: \n");
	gets(str2);  
	replace(str, str1, str2);
	printf("替换后的字符串: %s\n",str);
}

