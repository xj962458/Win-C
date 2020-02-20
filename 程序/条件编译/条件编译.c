#include<stdio.h>
#include<math.h>
#define T 1000	
#define FYT(x,y) x*y*4*y
long xj(int n)
{
	int i,j;
	long a,s=0;
	for(i=1;i<=n;i++)
	{
	 a=i*pow(10,n-i);
	 s=s+a;		
	}
	 return(s);
}
void main()
{
	int i,j,n;
	int a,b,c;
	long sum=0;
	printf("please input n:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=xj(i);
		#ifdef T
		printf("%ld\n",xj(i));
		#else
		printf("fhyeghfygeufgygfyh\t\n\t");
		#endif
	}
	printf("sum=1+12+123+...=%ld",sum);
	scanf("%d,%d",&a,&b);
	c=FYT(a,b);
	printf("%d\n",c);
	printf("FYT(a,b)\n");
	printf("%d\n",FYT(a,b));

	
}