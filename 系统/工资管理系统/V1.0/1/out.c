//out.c
#pragma once
#include "preProcess.h"
/*printheader()������������Ļ���Ա����ʽ��ʾ��¼����¼����ʾ����Ҫ���У���˵�������
printheader()��������������ģ����ã����ٴ�����ظ�
*/
void printheader(){
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}
 
void PRINTdata(ZGGZ pp){/*��ʽ�������������*/
	ZGGZ *p;
	p=&pp;
	printf(FORMAT,DATA);
}
void disp(ZGGZ tp[],int n){/*��ʾ����tp[]�д洢�ļ�¼������Ϊ*/
	int i;
	if (n==0)
	{
		/* code */
		printf("\n========>No employees record!\n");
		getchar();
		return ;
	}
	printf("\n\n");
	printheader();		/*������ͷ��*/
	i=0;
	while(i<n){	/*������������д洢��Ա����Ϣ*/
		PRINTdata(tp[i]);
		i++;
		printf(HEADER3);
	}
	getchar();
}
 
void wrong(){	/*�������������Ϣ*/
	printf("\n\n\n\n*******Error:input has wrong!press any key to continue*******\n");
	getchar();
}
void nofind(){	/*���δ���ҵ���Ա������Ϣ*/
	printf("\n====>Not find this employee record!\n");
}