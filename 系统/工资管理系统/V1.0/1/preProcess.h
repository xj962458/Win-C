//preProcess.h
/*
*Դ�ļ�����Ԥ���������������ͷ�ļ�������ṹ�塢�����ͱ������������ǽ��г�ʼ��
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define HEADER1 "----------------------GongZi--------------------------------------------------\n"
#define HEADER2 "|number|	name	|	jbgz	|	jj	|	kk	|	yfgz	|	sk	|	sfgz	|\n"
#define HEADER3 "|------|-----------|-----------|-------|-------|-----------|-------|-----------|\n"
#define FORMAT "|%-5s|%-10s|%8.2f|%8.2f|%8.2f|%8.2f|%8.2f|%8.2f|\n"
#define DATA p->num, p->name, p->jbgz, p->jj, p->kk, p->yfgz, p->sk, p->sfgz
#define END "------------------------------------------------------------------------------\n"
#define N 60

//��ʵ�ϣ����saveflagȫ�ֱ�����Ȼ��ȫ��ʹ�ã�����Ӧ����Ԥ������
//int saveflag=0;				/*��Ҫ���̵ı�־����*/

/*����Ա�����ݽṹ������Ա�������ݿ���Ҳ��Ϊ�ֶ�*/
typedef struct employee
{
    /* data */
    char num[10];  /*Ա�����*/
    char name[15]; /*Ա������*/
    float jbgz;    /*��������*/
    float jj;      /*����*/
    float kk;      /*�ۿ�*/
    float yfgz;    /*Ӧ������*/
    float sk;      /*˰��*/
    float sfgz;    /*ʵ������*/
} ZGGZ;