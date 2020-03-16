#include<stdio.h>
#include<string.h>
void main()
{
	int i,j=0,l1,l2;
	char a[100],b[100];
	gets(a);
	gets(b);
	l1=strlen(a);
	l2=strlen(b);
	for(i=l1;i<l1+l2;i++)
	{
		a[i]=b[j];
		j++;
	}
	a[l1+l2]='\0';
	puts(a);
}

