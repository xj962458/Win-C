#include<stdio.h>
#include<string.h>
void main()
{
	char a[50];
	int i,j,n,t,num=0;
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]>='a'&&a[i]<='y'||a[i]>='A'&&a[i]<='Y')
			a[i]=a[i]+2;
		else if(a[i]=='z'||a[i]=='Z')
			a[i]=a[i]-24;
	}
		puts(a);
}


