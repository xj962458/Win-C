#include<stdio.h>
#include<stdlib.h>

#define STU_NUM 40 //���ѧ������
#define COURSE_NUM 3 //���γ�����
#define NAME_LEN 15 //������������ַ���Ŀ
void main()
{
	long sno[STU_NUM];//sno����洢ѧ��ѧ��
	char sname[STU_NUM][NAME_LEN];//sname����洢ѧ������
	float score[STU_NUM][COURSE_NUM];//score����洢ѧ���ɼ�
	float avecourse[COURSE_NUM]={0};//avercourse����洢�γ�ƽ����
	float tscore[STU_NUM]={0};/*tscore����洢ÿλѧ���ɼ����ܷ֣�
								����tscore�ĳ�ֵ�趨Ϊ0��������Ϊ�Ƿ�����ܳɼ������ı�־*/

	int m=2,n=3;	//mΪʵ��ѧ������nΪʵ�ʿγ��������������趨
	int i,j;
	int item;
	printf("������ѧ����������");
	scanf("%d",&m);
	while(1)
	{
		//������˵�
		system("cls");/*��������*/
		printf("\n\t���ǰ༶����ϵͳ����ѡ����Ҫ�Ĳ���:\n\n");
		printf("\t\t1:����ѧ����Ϣ\n");
		printf("\t\t2:��������ѯѧ����Ϣ\n");
		printf("\t\t3:����ѧ�����ܳɼ�\n");
		printf("\t\t4:������ſγ̵�ƽ����\n");
		printf("\t\t5:��ѧ���ܳɼ��ɸߵ�������\n");
		printf("\t\t6:���ѧ����Ϣ\n");
		printf("\t\t0:�˳�\n");

		//��ʾ�û�ѡ��˵����������û�ѡ��
		printf("\n\n����������:");
		scanf("%d",&item);/*����ѡ������*/
		//�����û���ѡ�������Ӧ�Ĳ���������ֻ������롢����������ֺܷ��˳�������
		switch(item)
		{
			case 1:/*����ѧ����Ϣ*/
				for(i=0;i<m;i++)
				{
					printf("�������%dλѧ����ѧ�š������͸��ſγ̵ĳɼ�:\n",i+1);
					printf("ѧ��");
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
					getchar();
					getchar();
					break;
			case 2:/*��������ѯѧ����Ϣ*/
				printf("����������\n");
				getchar();
				getchar();
				break;
			case 3:/* ����ѧ�����ܳɼ�*/
				for(i=0;i<m;i++)
				{
					tscore[i]=0;
					for(j=0;j<n;j++)
						tscore[i]+=score[i][j];
				}
				printf("����ѧ�����ܳɼ��������!\n");
				getchar();getchar();
				break;
			case 4:/*������ſγ̵�ƽ����*/
				printf("����������\n");
				getchar();getchar();
				break;
			case 5:/*��ѧ���ܳɼ��ɸߵ�������*/
			 	printf("����������\n");
				getchar();getchar();
				break;
			case 6:/*����ѧ����Ϣ*/
				if(tscore[0]=0)//����û�м���ѧ�����ܳɼ��������
				{
					for(i=0;i<m;i++)
					{
						tscore[i]=0;
						for(j=0;j<n;j++)
							tscore[i]+=score[i][j];
					}
			    }
				printf("\tѧ��\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\n");
				for(i=0;i<m;i++)
				{
					printf("\t%ld%-8s",sno[i],sname[i]);//���ѧ��������
					for(j=0;j<n;j++)//���n�ſγ̵ĳɼ�
						printf("\t%.1f\n",tscore[i]);
					printf("\t%.1f\n",tscore[i]);//����ܳɼ�
				}
				getchar();getchar(); 
				break;
			case 0:/*�˳�*/
				exit(0);
				printf("�������\n");
				getchar();getchar();
				break;
			default:
				printf("\n\n���������ԣ�����������!!\n");
				getchar();getchar();
				break;
			
		}
	}
}
	
			 
		 