#include <stdio.h>
#include <string.h>
#include <process.h>
struct
{
   char name[20];
   double tel;
}person[200];
int N=1;
void Built()   
{
      int flag;
	  for(;N<200;)
      {   
		  printf("\t�������%d����ϵ�������͵绰���루�Իس�����Ϊ�����:\n",N);
          scanf("%s",person[N].name);  scanf("%lf",&person[N].tel);
		  N=N+1;
		  printf("\t�������������롰0��,�������������������������:"); scanf("%d",&flag);
		  if(flag==0) break;
	  }
	  printf("\n\t*******��ϵ�˴����ɹ�********\n");
}
void Alter()    
{
	int i;
	printf("�������޸���ϵ�˵����:");     
	scanf("%d",&i);
	if(person[i].tel==0) 
		printf("\n\t**********�޴���ϵ��!**********\n");
    else
	{
	    printf("�������޸ĺ�Ĵ���ϵ�������͵绰���루�Իس�����Ϊ�����:\n");
        scanf("%s",person[i].name);  scanf("%lf",&person[i].tel);
        printf("\n\t*******��ϵ���޸ĳɹ�********\n");
    }
}		
   
void Delete()   
{   int i,j;
	printf("������ɾ����ϵ�˵����:");     scanf("%d",&i);
	if(N==1||person[i].tel==0) 
		printf("\n\t**********�޴���ϵ��!**********\n");
	else
	{
		N=N-1;
		for(;i<=N;i++)
	      for(j=0;j<20;j++) 
		  {
			 person[i].name[j]=person[i+1].name[j];
	         person[i].tel=person[i+1].tel;
		  }
 	    printf("\n\t*******��ϵ��ɾ���ɹ�********\n");
	}
}
void Num_Inquire()
{
	int i,flag=0;double x;
	printf("�������ѯ�ĵ绰����:"); scanf("%lf",&x);    
	for(i=1;i<N;i++)
    {   
		if(x==person[i].tel)
		{
			flag=1;
			printf("----%d. %-20s\t%.0lf\n",i,person[i].name,person[i].tel);
		}
	}
	if(N==1||flag==0) printf("\n\t**********�޴���ϵ��!**********\n");
}
void Name_Inquire()
{
	int i,flag=0;char x[20];
	printf("�������ѯ����ϵ������:");     
	scanf("%s",x);
    for(i=1;i<N;i++)	
	{  
	    if(strcmp(person[i].name,x)==0)
		{
			flag=1;
			printf("----%d. %-20s\t%.0lf\n",i,person[i].name,person[i].tel);
		}
	}
	if(N==1||flag==0) printf("\n\t**********�޴���ϵ��!**********\n");
}
void Show()
{
    int i;
	if(N==0||N==1) 
	{
		printf("\n\t**********δ����ϵ��,ͨѶ¼Ϊ��!**********\n");
	}
	if(N!=1) 
	{
		printf("\t____________________________________________________\n");
	    printf("\t����ũ�      ��ϵ��        ��       �绰����      ��\n");
        printf("\t____________________________________________________\n");
	    for(i=1;i<N;i++)
		{   
          printf("\t����%d.��%-20s��%-20.0lf ��\n",i,person[i].name,person[i].tel);
          printf("\t____________________________________________________\n");
		}
    }
}
void start(int i)
{int flag=2;
 switch (i)
 {
  case 1:Built();break;
  case 2:Alter();break;
  case 3:Delete();break;
  case 4:Num_Inquire();break;
  case 5:Name_Inquire();break;
  case 6:Show();;break;
  case 7:if(N==1)  printf("\n\t**********δ����ϵ��,�������!**********\n");
		 else     
		 {
			printf("\t***ȷ�����ͨѶ¼��***\n\t1.ȷ��\t2.��\t*** ��ѡ��:");
	        scanf("%d",&flag);
			if(flag==1) N=1,printf("\n\t**********ͨѶ¼�����!**********\n");
			else if(flag==2) ;
		         else printf("ѡ�����!\n"),start(7);
		 }
		 break;
  default:printf("ѡ������,");break; 
 };
}
int main()
{
	int i;FILE*fp;
    printf("\n\t**********************��ӭʹ��200��ͨѶ¼**********************\n\n");
    printf("***����:*.�绰������ò�Ҫ����16λ�Ҳ���Ϊ��0�����ҿ�ͷ������һ����\n");
	printf("\t  �ϵġ�0��������ϵͳ;���������⣻\n");
	printf("\t*.���绰���뿪ͷֻ��һ����0����������ʱ�á�-�����桰0������\n");
	printf("\t  ϵͳ�Դ˷�ʽ��ʾ��\n\n");
    printf("***�˵�:\n");
	printf("\t1.�½���ϵ����Ϣ;\n");
    printf("\t2.�޸�ͨѶ¼;\n");
    printf("\t3.ɾ��ͨѶ¼����ϵ����Ϣ;\n");
    printf("\t4.���ݵ绰�����ѯ;\n");
    printf("\t5.����������ѯ;\n");
    printf("\t6.��ʾͨѶ¼;\n");
    printf("\t7.���ͨѶ¼;\n");
    printf("\t8.��ͨѶ¼������ĵ����˳�ϵͳ.\n");
	printf("��ѡ��˵�:");
    while (1) 
	{	
        scanf("%d",&i);
		if(i==8) 
		{ 
			if((fp=fopen("d:\\ͨѶ¼.txt","w"))==NULL)
			{
		       printf("�ļ��򿪴���!\n");
		       exit(1);
			}
     	    else
			{
			   if(N==1) printf("\n\t******************����ϵ��,����ʧ��!*********************\n");
	           if(N!=1) 
			   {
				   fprintf(fp,"\t____________________________________________________\n");
	               fprintf(fp,"\t����ũ�      ��ϵ��        ��       �绰����      ��\n");
                   fprintf(fp,"\t____________________________________________________\n");
	               for(i=1;i<N;i++)
				   {   
                      fprintf(fp,"\t����%d.��%-20s��%-20.0lf ��\n",i,person[i].name,person[i].tel);
                      fprintf(fp,"\t____________________________________________________\n");
				   }
	               printf("\n\t**********ͨѶ¼�ѱ�����D�̵ġ�ͨѶ¼.txt���ĵ��С�************\n");
               }
			   fclose(fp);
	           printf("\n\t\t************�˳��ɹ�,ллʹ��!************\n\n");
			   break;
			}
		}
		start(i);	
		printf("�ɼ���ѡ��˵�:");

	}
}