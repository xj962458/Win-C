#include<stdio.h>
#define N 5

//�����һ��Ĵ��еĽṹ������
struct student1
{  
    int num;
    char name[20];
    int score;
};

//������������еĽṹ������
struct student2 
{
	int num;
	char name[30];
	int score[3];
};

//�Զ������������õ�����������
typedef struct student2 stu;

//���к�����ԭ���������ڴ˴�
void correct();		//��1��--�Ĵ�
void fill();		//��2��--���
void verification();	//��3��--��֤	
void program_1();		//��4��--���
void program_2();		//��5��--������txt�ļ�
void input(stu* p);		//����
void print(stu* p);		//���
void xprint(stu* p ,FILE *fp);	//������ı��ļ�
double aver(stu* p);			//����ƽ����
int excellect(stu* p);			//�ж���߷�,�����±�
void menu();                    //����˵�
