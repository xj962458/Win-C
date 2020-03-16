#include<stdio.h> 
#include<string.h> 
void main()
{
	char a[100],b[50]; 
	int i,j,t;
	gets(a);
	gets(b); 
	t=strlen(a);
	for(i=0;b[i]!='\0';i++,t++)	
		a[t]=b[i];
	a[t]='\0';
	puts(a);
}

