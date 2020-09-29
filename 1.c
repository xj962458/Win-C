#include<stdio.h>
int main()
{
    int i,count=0;
    char a[8];
    scanf("%s",a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='1')
            count++;
    }
    printf("%d",count);
    return 0;
}