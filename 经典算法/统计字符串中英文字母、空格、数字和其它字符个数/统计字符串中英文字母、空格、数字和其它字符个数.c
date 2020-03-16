#include <stdio.h>
void main()
{
	char c; 
	int letter=0,space=0,digtal=0,other=0; 
	while((c=getchar())!='\n')
	{
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
			letter++;
		else if(c==' ')
			space++;
		else if(c>='0'&&c<='9')
			digtal++;
		else
			other++;

	}
	printf("letter=%d,space=%d,digtal=%d,other=%d",letter,space,digtal,other);
}


