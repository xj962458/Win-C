#include <stdio.h>
void main()
{
	char c;
	int a=0,flag=1,i=0,input_error=1,d_num=0; 
	float b=0.1,y=0;
	while((c=getchar())!='\n')
	{		
		input_error=0;
		if('0'<=c&&c<='9')
		{
			if(flag==1)
				a=a*10+(c-'0');
			else if(flag==0&&i<=6)
			{
				y=y+(c-'0')*b;
				b=b*0.1;
				i++;
			}
		}
		else if(c=='.')
		{
			flag=0;        
			input_error=1; 
			d_num++;

		}
		else
		{
			input_error=1;
			break;
		}
	}
	if(input_error==1||d_num>1) 
		printf("input error");
	else	
		printf("%f",a+y);
}
