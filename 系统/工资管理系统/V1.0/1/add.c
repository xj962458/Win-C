//add.c
/*���Ӽ�¼*/
#pragma once
#include "preProcess.h"
void disp(ZGGZ tp[],int n);
void wrong();
void stringinput(char *t,int lens,char *notice);/*�����ַ����������г�����֤�������ȱ���С��lens��*/
float numberinput(char *notice);/*������ֵ������������ֵ����󷵻ظ�ֵ����ֵ������ڵ���0*/
int add(ZGGZ tp[],int n){
	char ch,num[10];
	int i,flag=0;
	system("cls");	/*����*/
	disp(tp,n);		/*��ʾ����Ա��������Ϣ*/
	while(1){		/*һ�ο����������¼��ֱ��������Ϊ0�ļ�¼�Ž������*/
		while(1){		/*����Ա����ţ���֤�ñ��û�б�ʹ�ã���������Ϊ0 �����˳���Ӳ���*/
			stringinput(num,10,"input number(press '0' return menu):");/*��ʽ�������Ų�����*/
			flag=0;
			if (strcmp(num,"0")==0)	/*����Ϊ0�����˳���Ӳ���������������*/
			{
				/* code */
				return n;
			}
			i=0;
			while(i<n){		/*��ѯ�ñ���Ƿ��Ѿ����ڣ������ڣ�����������һ��δ��ռ�õı��*/
				if (strcmp(tp[i].num,num)==0)
				{
					/* code */
					flag=1;
					break;
				}
				i++;
			}
			if (flag==1)	/*��ʾ�û��Ƿ���������*/
			{
				/* code */
				getchar();
				printf("======>The number %s is existing,try again?(y/n):", num);
				scanf("%c",&ch);
				if (ch=='y'||ch=='Y')
				{
					/* code */
					continue;
				}
				else
					return n;
			}
			else
				break;
		}
		strcpy(tp[n].num,num);		/*���ַ���num���Ƶ�tp[n].num��*/
		stringinput(tp[n].name,15,"Name:");		
		tp[n].jbgz=numberinput("jbgz:");			/*���벢У���������*/
		tp[n].jj=numberinput("jiangjin:");		/*���벢���齱��*/
		tp[n].kk=numberinput("koukuan:");		/*���벢����ۿ�*/
		tp[n].yfgz=tp[n].jbgz+tp[n].jj-tp[n].kk;	/*����Ӧ������*/
		tp[n].sk=tp[n].yfgz*0.12l;		/*����˰�𣬼ٶ�ȡӦ�����ʵ�12%*/
		tp[n].sfgz=tp[n].yfgz-tp[n].sk;			/*����ʵ������*/
		n++;
	}
	return n;
}