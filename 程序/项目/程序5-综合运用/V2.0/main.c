#include<stdio.h>
#include"com.h"
void main()	//主函数
{
	int item;
	while(1)
	{
		int item;
        menu();
		printf("请输入相应的数字，运行相应的程序\n");
		scanf("%d",&item);
	  	switch(item)
		{
			case 1:
				correct();
				getchar();getchar();
				break; 
			case 2:
				fill();
				getchar();getchar();
				break;
			case 3:
				verification();
				getchar();getchar();
				break;
			case 4:
				program_1();
				getchar();getchar();
				break;
			case 5:
				program_2();
				getchar();getchar();
				break; 
			case 0:
				exit(0);
				printf("程序结束\n");
				getchar();getchar();
				break;
			default :
				printf("\n\n输入的命令不对,请重新输入!!\n");
				getchar();getchar();
				break;
			
		}
	}
}

