//save.c
#pragma once
#include "preProcess.h"
extern int saveflag;				/*��Ҫ���̵ı�־����*/
/*�洢��¼*/
void save(ZGGZ tp[],int n){
	FILE *fp;
	int i=0;
	fp=fopen("E:\zggz\gzgl.data","wb");
	if (fp==NULL)
	{
		/* code */
		printf("\n=======>open file error!\n");;
		getchar();
		return ;
	}
	for (i = 0; i < n; ++i)
	{
		/* code */
		if (fwrite(&tp[i],sizeof(ZGGZ),1,fp)==1)	/*ÿ��дһ����¼��һ���ṹ����Ԫ�ص��ļ��в�ҩ*/
		{
			/* code */
			continue;
		}
		else
			break;
	}
	if (i>0)
	{
		/* code */
		getchar();
		printf("\n\n===========>save file complete,total saved's record number is :%d\n",i);
		getchar();
		saveflag=0;
	}
	else
	{
		system("cls");
		printf("the current link is empty,no employee record is saved!\n");
		getchar();
	}
	fclose(fp);
}