#include <stdio.h>
void main()
{
 
	char str[80],*ch;
	int flag=1;
	printf("Please input a string:\n");
	gets(str);
	ch=str;
	while(*ch)
	{
		if (*ch==' ') 
			flag=1;
		else
		{
			if (flag==1&& *ch>='a' && *ch<='z')
					*ch=*ch-32;
			flag=0;
		}
		ch++;
	}
	printf("%s\n",str);
}
