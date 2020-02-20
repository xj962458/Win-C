#include<stdio.h> 
#define N 100
void fun(char *strA, char *strB);
void main(void)
{
	char strA[N];	
	char strB[N];
	printf("ÇëÊäÈë×Ö·û´®:\n");
	gets(strA); fun(strA, strB);
	printf("¸´ÖÆºóµÄ×Ö·û´®:\n");
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
