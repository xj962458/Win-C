#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,i,j,k,n;
    printf("��������Ҫ��ӡ������n(nΪ������17������):");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a=fabs(n-i-n/2);
        b=fabs(n-a-n/2);
        for(j=1;j<=n;j++)
        {
            for(k=1;k<n;k++)
            {
                if(j==(a+1)||j==(n-a))
                    printf("%d",b);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}