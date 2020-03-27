#include<stdio.h> 
#include<string.h> 
void main()
{
	char a[100]; 
	int i,t; 
	gets(a);
	t=0;
	for(i=0;a[i]!='\0';i++)
		if(a[i]>='a'&&a[i]<='z'&&a[i-1]==' '||i==0)
			t++; 
		printf("t=%d\n",t);
}

