#include<stdio.h>
#include<string.h>

int main()
{
    char a[10]="abcdd";
    char b[10]="abc";
    char c[10];
    scanf("%s",c);
    printf("%s",c);
    if(strcmp(a,b)==0)
        printf("���");
    else 
        printf("�����");
    printf("%s",strcpy(a,b));
}