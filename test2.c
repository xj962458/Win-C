#include<stdio.h>
int main()
{
    char c1[100],c2[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a[26],i,j,k,n,max;
    for(i=0;i<=26;i++)
        a[i]=0;
    scanf("%d",&n);
    scanf("%s",c1);
    for(i=0;i<n;i++){
        for(j=0;j<=26;j++)
        {
            if(c1[i]==c2[j])
                a[j]++;
        }
    }
    max=a[0]; 
    for(i=1;i<=26;i++)
    {
        if(a[i]>max){
            max=a[i];
            k=i;
        }
    }
    printf("%d\n",max);
    printf("%c\n",k+65);
    return 0;
}