//insert.c
#pragma once
#include "preProcess.h"
 
void printheader();
void PRINTdata(ZGGZ pp);
void disp(ZGGZ tp[],int n);
void wrong();
void nofind();
void stringinput(char *t,int lens,char *notice);/*�����ַ����������г�����֤�������ȱ���С��lens��*/
float numberinput(char *notice);/*������ֵ������������ֵ����󷵻ظ�ֵ����ֵ������ڵ���0*/
extern int saveflag;				/*��Ҫ���̵ı�־����*/
/*�����¼*/
int insert(ZGGZ tp[],int n){
	char ch,num[10],s[10];	/*s���鱣������֮ǰ�ı�ţ�num���鱣��������¼�¼���*/
	ZGGZ newinfo;
	int flag=0,i=0,kkk=0;
	system("cls");
	disp(tp,n);
	while(1){
		stringinput(s,10,"Please input insert location after the Number:");
		flag=0;i=0;
		while(i<n){			/*��ѯ��flag=1Ϊ��ʾ�ñ�Ŵ���*/
			if (strcmp(tp[i].num,s)==0)
			{
				/* code */
				kkk=i;
				flag=1;
				break;
			}
			i++;
		}
		if (flag==1)
		{
			/* code */
			break;			/* ����Ŵ��ڣ�����в���֮ǰ���¼�¼�������*/
		}
		else{
			getchar();
			printf("\n=====>The Number %s is not existing,try again?(y/n):",s);
			scanf("%c",&ch);
			if (ch=='y'||ch=='Y')
			{
				/* code */
				continue;
			}
			else
				return n;
		}
	}
	/*�����¼�¼�Ĳ��������add()��ͬ*/
	while(1){
		stringinput(num,10,"input new employee Number:");
		i=0;flag=0;
		while(i<n){				/*��ѯ��flagΪ1ʱ��ʾ�ñ�Ŵ���*/
			if (strcmp(tp[i].num,num)==0)
			{
				/* code */
				flag=1;break;
			}
			i++;
		}
		if (flag==1)
		{
			/* code */
			getchar();
			printf("\n====>Sorry,The number %s is existing,try again(y/n)",num);
			scanf("%c",&ch);
			if (ch=='y'||ch=='Y')
			{
				/* code */
				continue;
			}else
				return n;
		}else
			break;
	}
	strcpy(newinfo.num,num);		/*���ַ���num���Ƶ�newinfo.num��*/
	stringinput(newinfo.name,15,"Name:");
	newinfo.jbgz=numberinput("jbgz:");		/* ���벢У���������*/
	newinfo.jj=numberinput("jiangjin");		/*���벢����jiangjing */
	newinfo.kk=numberinput("koukuan:");		/*���벢����koukuan*/
	newinfo.yfgz=newinfo.jbgz+newinfo.jj-newinfo.kk;
	newinfo.sk=newinfo.yfgz*0.12;
	newinfo.sfgz=newinfo.yfgz-newinfo.sk;
	saveflag=1;			/*��main()���жԸ�ȫ�ֱ������жϣ���Ϊ1�����*/
	for(i=n-1;i>kkk;i--){
		strcpy(tp[i+1].num,tp[i].num);
		strcpy(tp[i+1].name,tp[i].name);
		tp[i+1].jbgz=tp[i].jbgz;
		tp[i+1].jj=tp[i].jj;
		tp[i+1].kk=tp[i].kk;
		tp[i+1].yfgz=tp[i].yfgz;
		tp[i+1].sk=tp[i].sk;
		tp[i+1].sfgz=tp[i].sfgz;
	}
	strcpy(tp[kkk+1].num,newinfo.num);/*��tp[kkk]Ԫ��λ�ú�����¼�¼*/
	strcpy(tp[kkk+1].name,newinfo.name);
	tp[kkk+1].jbgz=newinfo.jbgz;
	tp[kkk+1].jj=newinfo.jj;
	tp[kkk+1].kk=newinfo.kk;
	tp[kkk+1].yfgz=newinfo.yfgz;
	tp[kkk+1].sk=newinfo.sk;
	tp[kkk+1].sfgz=newinfo.sfgz;
	n++;
	disp(tp,n);
	printf("\n\n");
	getchar();
	return n;
}