#include<stdio.h> 
struct dat
{
	int year,month,day;
};
void calculate(struct dat*); 
void main ()
{
	int n;
	struct dat date; 
	printf("please inp ut year:"); 
	scanf("%d",date.year); 
	printf("please inp ut year:"); 
	scanf("%d",date.month); 
	printf("please inp ut year:"); 
	scanf("%d",date.day); 
	calculate(&date);
}
void calculate(struct dat*date)
{
	int a,b,c,i; 
	int sum=0;
	a=date->year;
	b=date->month; 
	c=date->day;
	if((a%4==0)&&(a%100!=0)||(a%400==0))
	{
		for(i=0;i<b;i++)
		{
			if(i==1&&i==3&&i==5&&i==7&&i==8&&i==10) 
				sum+=31; 
			else
			{
				if(i==2)
					sum+=29;
				else
					sum+=30;
			}
		sum+=c;
		}
		if((a%4!=0)||(a%100==0)&&(a%400!=0))
		{
			for(i=0;i<b;i++)
			{
				if(i==1&&i==3&&i==5&&i==7&&i==8&&i==10) 
					sum+=31;
				else
				{
					if(i==2)
						sum+=28;
					else
						sum+=30;
				}
				sum=sum+c;
			}
		}
		printf("%d\n",sum);
	}
}


