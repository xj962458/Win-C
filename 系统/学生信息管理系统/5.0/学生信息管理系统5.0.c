#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#define STU_NUM 40 //���ѧ������
#define COURSE_NUM 3 //���γ�����
#define NAME_LEN 15 //������������ַ���Ŀ


//����ѧ���ṹ�����ͣ���ʾѧ����¼Ӧ���е���ʽ
struct student
{
	long sno;		/*ѧ��*/
	char sname[NAME_LEN];	/*����*/
	float score[COURSE_NUM];	/*���ſγ̳ɼ�*/
	float total;	/*�ܷ�*/
	//struct student *next;		/*������ṹʹ�ã��ṹ���������ô����*/
};

int flag=0;	//��Ϊ�ܳɼ��Ƿ�����һ����־��flagΪ0ʱ��ʾû�м���

//���к�����ԭ���������ڴ˴�
//���� 1:����ѧ����Ϣ
void InputStuInfor(struct student stu[],int m, int n);
//���� 2:��������ѯѧ����Ϣ
void QueryByName(struct student stu[],int m,int n);
//���� 3:����ѧ�����ܳɼ�
void StuTotalScore(struct student stu[],int m,int n);
//���� 4:������ſγ̵�ƽ����
void CourseAverageScore(struct student stu[],float avecourse[],int m, int n);
//���� 5:��ѧ���ܳɼ��ɸߵ�������
void SortbyTotalScore(struct student stu[],int m,int n);
//���� 6:���ѧ����Ϣ
void DisplayStuInfor(struct student stu[],int m,int n);
//�˵�����:��ʾ�˵�,����ȡ�������û�ѡ��Ĺ�������
int Menu(void);

int main()
{
	struct student stu[STU_NUM];		//����ѧ����¼�����ֻ��STU_NUM��ͬѧ
	float avecourse[COURSE_NUM]={0};	 //avecourse ����洢ÿ�ſγ̵�ƽ����


	int m=2,n=3;	//mΪʵ��ѧ������nΪʵ�ʿγ��������������趨n=3
	int i,j;
	int item;


	printf("������ѧ����������");
	scanf("%d",&m);
	while(1)
	{
		item=Menu();//�˵���ʾ������ȡ�û�ѡ��Ĳ˵���������
	

		//�����û���ѡ�������Ӧ�Ĳ���������ֻ������롢����������ֺܷ��˳�������
		switch(item)
		{
		case 1:
			InputStuInfor(stu,m,n);
			getchar(); //����ѧ����Ϣ
			getchar();
			break;
		case 2:
			QueryByName(stu,m,n); //��������ѯѧ����Ϣ
			getchar();
			getchar();
			break;
		case 3:
			StuTotalScore(stu,m,n); //����ѧ�����ܳɼ�
			flag=1;
			getchar(); getchar();
			break;
		case 4:
			CourseAverageScore(stu,avecourse,m,n); // ������ſγ̵�ƽ����
			getchar();getchar();
			break;
		case 5:
			SortbyTotalScore(stu,m,n); //���ܳɼ�������
			getchar();getchar();
			break;
		case 6:
			DisplayStuInfor(stu,m,n); //���ѧ����Ϣ
			getchar();getchar();
			break;
		case 0:/*�˳�*/
			exit(0);
			printf("�������\n");
			getchar();getchar();
			break;
		default:
			printf("\n\n����������,����������!!\n");
			getchar();getchar();
			break;
		}
	}
}




//���������к����ľ���ʵ��
//����1:����ѧ����Ϣ
void InputStuInfor(struct student stu[],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		printf("�������%dλѧ����ѧ�š������͸��ſγ̳ɼ�\n",i+1);
		printf("ѧ ��:");
		scanf("%ld",&stu[i].sno);
		getchar();		 //���˵��س���
		printf("�� ��:");
		gets(stu[i].sname);
		for(j=0;j<n;j++)
		{
			printf("�γ�%d�ɼ�:",j+1);
			scanf("%f",&stu[i].score[j]);
		}
	}
}

//���� 2:��������ѯѧ����Ϣ
void QueryByName(struct student stu[],int m,int n)
{
	printf("����ʵ����!!\n");
}
//���� 3;����ѧ�����ܳɼ�
void StuTotalScore(struct student stu[],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		stu[i].total=0;
		for(j=0;j<n;j++)
			stu[i].total+=stu[i].score[i];
	}
	printf("����ѧ�����ܳɼ��������!\n");
}
//���� 4:������ſγ̵�ƽ����
void CourseAverageScore(struct student stu[],float avecourse[],int m,int n)
{
	printf("����ʵ����!\n");
}
//���� 5����ѧ���ܳɼ��ɸߵ�������
void SortbyTotalScore(struct student stu[],int m,int n)
{
	printf("����ʵ����!!\n");
}
//���� 6:���ѧ����Ϣ
void DisplayStuInfor (struct student stu[],int m,int n)
{
	int i,j;
	if(flag==0)//����û�м���ѧ�����ܳɼ�������� StuTotalScore( )�������м���
		StuTotalScore(stu,m,n);
	printf("\tѧ��\t����\t\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\n");
	for(i=0;i<m;i++)
	{ 
		printf("\t%ld%-8s",stu[i].sno,stu[i].sname);//���ѧ��������
		for(j=0;j<m;j++)//���n�ſγ̵ĳɼ�
			printf("\t%.1f",stu[i].score[j]);
		printf("\t%.1f\n",stu[i].total);//����ܳɼ�
	}
}
//�˵���������ʾ�˵�����ȡ�������û�ѡ��Ĺ�������š�
int Menu(void)
{ //�û��˵�
	int item;
	system("cls");/*��������*/
	printf("\n\t���ǰ༶����ϵͳ����ѡ����Ҫ�Ĳ���:\n\n");
	printf("\t\t1:����ѧ����Ϣ\n");
	printf("\t\t2:��������ѯѧ����Ϣ\n");
	printf("\t\t3:����ѧ�����ܳɼ�\n");
	printf("\t\t4:������ſγ̵�ƽ����\n");
	printf("\t\t5:��ѧ���ܳɼ��ɸߵ�������\n");
	printf("\t\t6:���ѧ����Ϣ\n");
	printf("\t\t0:�˳�\n");


	printf("\n\n����������:");
	scanf("%d",&item); /*���û�ѡ�������*/
	return item;
}

