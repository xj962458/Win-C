#include<stdio.h>
#include<stdlib.h>

#define STU_NUM 40 //���ѧ������
#define COURSE_NUM 3 //���γ�����
#define NAME_LEN 15 //������������ַ���Ŀ
//���к�����ԭ���������ڴ˴�
//���� 1:����ѧ����Ϣ
void InputStuInfor(long sno[], char sname[][NAME_LEN],float score[][COURSE_NUM],int m, int n);
//���� 2:��������ѯѧ����Ϣ
void QueryByName(long sno[], char sname[][NAME_LEN],float score[][COURSE_NUM],float tscore[],int m,int n);
//���� 3:����ѧ�����ܳɼ�
void StuTotalScore(float score[][COURSE_NUM],float tscore[],int m,int n);
//���� 4:������ſγ̵�ƽ����
void CourseAverageScore(float score[][COURSE_NUM], float avecourse[], int m, int n);
//���� 5:��ѧ���ܳɼ��ɸߵ�������
void SortbyTotalScore(long sno[],char sname[][NAME_LEN],float score[][COURSE_NUM], float tscore[],int m,int n);
//���� 6:���ѧ����Ϣ
void DisplayStuInfor(long sno[],char sname[][NAME_LEN],float score[][COURSE_NUM],float tscore[],int m,int n);
//�˵�����:��ʾ�˵�,����ȡ�������û�ѡ��Ĺ�������
int Menu(void);

void main()
{
	long sno[STU_NUM];//sno����洢ѧ��ѧ��
	char sname[STU_NUM][NAME_LEN];//sname����洢ѧ������
	float score[STU_NUM][COURSE_NUM];//score����洢ѧ���ɼ�
	float avecourse[COURSE_NUM]={0};//avercourse����洢�γ�ƽ����
	float tscore[STU_NUM]={0};/*tscore����洢ÿλѧ���ɼ����ܷ֣�
								����tscore�ĳ�ֵ�趨Ϊ0��������Ϊ�Ƿ�����ܳɼ������ı�־*/

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
			InputStuInfor(sno,sname,score,m,n);
			getchar(); //����ѧ����Ϣ
			getchar();
			break;
		case 2:
			QueryByName(sno,sname,score,tscore,m,n); //��������ѯѧ����Ϣ
			getchar();
			getchar();
			break;
		case 3:
			StuTotalScore(score,tscore,m,n); //����ѧ�����ܳɼ�
			getchar(); getchar();
			break;
		case 4:
			CourseAverageScore(score,avecourse,m,n); // ������ſγ̵�ƽ����
			getchar();getchar();
			break;
		case 5:
			SortbyTotalScore(sno,sname,score,tscore,m,n); //���ܳɼ�������
			getchar();getchar();
			break;
		case 6:
			DisplayStuInfor(sno,sname,score,tscore,m,n); //���ѧ����Ϣ
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
void InputStuInfor(long sno[],char sname[][NAME_LEN],float score[][COURSE_NUM],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		printf("�������%dλѧ����ѧ�š������͸��ſγ̳ɼ�\n",i+1);
		printf("ѧ ��:");
		scanf("%ld",&sno[i]);
		getchar(); //���˵��س���
		printf("�� ��:");
		gets(sname[i]);
		for(j=0;j<n;j++)
		{
			printf("�γ�%d�ɼ�:",j+1);
			scanf("%f",&score[i][j]);
		}
	}
}

//���� 2:��������ѯѧ����Ϣ
void QueryByName(long sno[],char sname[][NAME_LEN],float score[][COURSE_NUM],float tscore[],int m,int n)
{
	printf("����ʵ����!!\n");
}
//���� 3;����ѧ�����ܳɼ�
void StuTotalScore(float score[][COURSE_NUM],float tscore[],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		tscore[i]=0;
		for(j=0;j<n;j++)
			tscore[i]+=score[i][j];
	}
	printf("����ѧ�����ܳɼ��������!\n");
}
//���� 4:������ſγ̵�ƽ����
void CourseAverageScore(float score[][COURSE_NUM],float avecourse[], int m,int n)
{
	printf("����ʵ����!\n");
}
//���� 5����ѧ���ܳɼ��ɸߵ�������
void SortbyTotalScore(long sno[],char sname[][NAME_LEN],float score[][COURSE_NUM],float tscore[],int m,int n)
{
	printf("����ʵ����!!\n");
}
//���� 6:���ѧ����Ϣ
void DisplayStuInfor (long sno[],char sname[][NAME_LEN],float score[][COURSE_NUM],float tscore[],int m,int n)
{
	int i,j;
	if(tscore[0]==0)//����û�м���ѧ�����ܳɼ�������� StuTotalScore( )�������м���
		StuTotalScore(score,tscore,m,n);
	printf("\tѧ��\t����\t\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\n");
	for(i=0;i<m;i++)
	{ 
		printf("\t%ld%-8s",sno[i],sname[i]);//���ѧ��������
		for(j=0;j<m;j++)//���n�ſγ̵ĳɼ�
			printf("\t%.1f",score[i][j]);
		printf("\t%.1f\n",tscore[i]);//����ܳɼ�
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

