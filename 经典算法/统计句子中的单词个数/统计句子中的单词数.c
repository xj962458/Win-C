#include<stdio.h>
#include<string.h>
void main()
{
	int i,l,n=1;
	char a[100];
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++)
		if(a[i]==' ')
			n++;
		printf("%d\n",n);
}

