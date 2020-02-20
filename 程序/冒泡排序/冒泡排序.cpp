# include <stdio.h>

void main()
{
	// 升序排序
	int s[7]={4,3,0,7,2,10,9}, i, j, t;
	// 冒泡排序算法必须用两层嵌套for来实现，外层控制轮次，内层控制每一轮的比较次数

	for(i=0; i<=5; i++)
	{
		for(j=0; j<=5-i; j++)
		{
			if(s[j]>s[j+1])
			{
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
		}
	}

	// 输出结果
	for(i=0; i<=6; i++)
	{
		printf("%d  ", s[i]);
	}
}