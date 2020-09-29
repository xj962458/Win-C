#include<stdio.h>
#include<string.h>
# define N 1000
int dp[N];
int main()
{
	int n;
   while(scanf("%d",&n)!=EOF)
   {
     memset(dp,0,sizeof(dp));
	 dp[1]=3;dp[2]=7;
	 for(int i=3;i<=n;i++)
		 dp[i]=2*dp[i-1]+dp[i-2];
	 printf("%d\n",dp[n]);
   }
   return 0;
}