#include<stdio.h>
#include"com.h"
void main()	//������
{
	int item;
	while(1)
	{
		int item;
        menu();
		printf("��������Ӧ�����֣�������Ӧ�ĳ���\n");
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
				printf("�������\n");
				getchar();getchar();
				break;
			default :
				printf("\n\n����������,����������!!\n");
				getchar();getchar();
				break;
			
		}
	}
}
