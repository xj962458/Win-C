#include<stdio.h>
#include<string.h>
void main()
{
	int n=0,i;
	char s[81];
	gets(s);
	i=0;
	while(s[i]!='\0')
	{
		if(!(s[i]>='A'&&s[i]<='Z'))
			s[n++]=s[i];
		i++;
	}
	s[n]='\0';
	puts(s);
}

