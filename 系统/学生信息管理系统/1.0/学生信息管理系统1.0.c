#include<stdio.h>
#include<stdlib.h>
void main()
{
	char sno1,sno2;
	float score11,score12,score13,score21,score22,score23;	/*score��ͷ�ı����ֱ𴢴�Ϊ2Ϊѧ����3�ſγ̵ĳɼ�*/ 
	float tscore1=0,tscore2=0;	/*tscore��ͷ�ı����ֱ�洢2λѧ�����ſγ̵��ܷ�*/ 
	int m=2,n=3;	//mΪʵ��ѧ������nΪʵ�ʿγ��������������趨
	int i,j;
	int item;

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
	scanf("%d",&item);
	//�����û���ѡ�������Ӧ�Ĳ���������ֻ������롢����������ֺܷ��˳�������
	switch(item)
	{
		case 1:/*����ѧ����Ϣ*/
			printf("�������һλѧ����ѧ�ź����ſγ̵ĳɼ�:\n");
			scanf("%ld%f%f%f",&sno1,&score11,&score12,&score13);
			printf("������ڶ�λѧ����ѧ�ź����ſγ̵ĳɼ�:\n");
			scanf("%ld%f%f%f",&sno2,&score21,&score22,&score23);
			getchar();
			getchar();
			break;
		case 2:/*��������ѯѧ����Ϣ*/
			printf("����������\n");
			getchar();
			getchar();
			break;
		case 3:/* ����ѧ�����ܳɼ�*/
			tscore1=score11+score12+score13;
			tscore2=score21+score22+score23;
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
			if(tscore1==0||tscore2==0)//����û�м���ѧ�����ܳɼ��������
			{
				tscore1=score11+score12+score13;
				tscore2=score21+score22+score23;
			}
			printf("\tѧ��\t�γ�1\t�γ�2\t�γ�3\t�ܳɼ�\n");
			printf("\t%ld\t%.lf\t%.lf%\t%.lf\t%.lf\n",sno1,score11,score12,score13,tscore1);
			printf("\t%ld\t%.lf\t%.lf%\t%.lf\t%.lf\n",sno2,score21,score22,score23,tscore2);
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
	
			 
		 