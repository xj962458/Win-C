#include<stdio.h>
int main()
{
    int i,count[26];
    char ch;
    for(i=0;i<26;i++)
    count[i]=0;
    while((ch=getchar())!='\0')
    {
    if(ch>='a'&&ch<='z')
        count[ch-'a']++;
    if(ch>='A'&&ch<='Z')
        count[ch-'A']++;
    }
    for(i=0;i<26;i++)
        printf("%c=%d\n",'A'+i,count[i]);
}