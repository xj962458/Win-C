#include<stdio.h>
void mystrcat(char *s,char *ct)
{
	while(*(s++)); 
	s--;
	while(*ct)
		*(s++)=*(ct++);
	*s = '\0';
}
int main()
{
	char na[100],nb[100]; 
	gets(na);
	gets(nb);
	mystrcat(na,nb); 
	printf("%s\n",na); 
	return 0;
}

