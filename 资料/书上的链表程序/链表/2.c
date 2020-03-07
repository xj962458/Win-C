#include<stdio.h>   /*I/O����*/
#include<stdlib.h>  /*����˵��*/
#include<string.h>  /*�ַ�������*/
#define LEN 15      /* ѧ�ź���������ַ���,ʵ�������*/
#define N 200       /* ���ѧ������,ʵ�������*/
struct record
{
    char code[LEN+1]; /* ѧ��*/
    char name[LEN+1]; /* ����*/
    int age;          /* ����*/
    char sex;         /* �Ա�*/
    float score[3];   /* 3�ſγ̳ɼ�*/
}stu[N];        
int k=1,n=0, m=0;/*����ȫ�ֱ����� n����ǰ��¼��ѧ����������mΪ�����ӵ�ѧ������*/    
/* ��������*/
void help();         /* ��������*/
void readfile();    /* ��������*/
void seek();        /* ������Ϣ*/
void modify();       /* �޸�����*/
void insert();       /* ��������*/
void del();          /* ɾ������*/
void display();       /* ��ʾ��Ϣ*/
void save();          /* ������Ϣ*/
void menu();        /* �˵�*/
int main()          /* ������*/
{ 
    while(k)
    {
        menu();
    }
    system("pause");
    return 0;
} 
void help()      /* ������Ϣ*/
{ 
    printf("\n0.��ӭʹ��ϵͳ������\n");
    printf("\n1.���ν���ϵͳ��,����ѡ������ѧ����Ϣ;\n");
    printf("\n2.���ղ˵���ʾ�������ִ���;\n");
    printf("\n3.����ѧ����Ϣ��,�мǱ���;\n");
    printf("\n4.лл����ʹ�ã�\n");
    system("pause");         /* ����һ��DOS�����Ļ�����"�밴���������"*/
} 
void readfile()
{
    char filename[LEN+1];             /* �ļ���*/
    FILE *fp;                             /* �ļ�ָ��*/
    int i=0;
    printf("�������Դ���ѧ����Ϣ���ļ�����\n");    
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)         /* ��ֻ���ķ�ʽ��ָ���ļ�*/
    {
        printf("���ļ�%s����",filename);
        printf("����Ҫ��ѡ��˵�4����ѧ����Ϣ\n");
        system("pause");
        return;
    }
     /* ѭ������ѧ����Ϣ*/
    while(fscanf(fp,"%s%s%d%c%f%f%f",stu[i].code,stu[i].name,&stu[i].age,&stu[i].sex,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2])==7)
    {
        i++;
    }
    n=i;
    if(0==i)
        printf("�ļ�Ϊ�գ�����Ҫ��ѡ��˵�4����ѧ����Ϣ\n");
    else
        printf("����ɹ�\n");
    fclose(fp);
    system("pause");
}


void seek() /*����*/
{
    int i,item,flag;
    char s1[21]; /* ��������ѧ�������+1Ϊ׼*/
    printf("------------------\n");
    printf("-----1.��ѧ�Ų�ѯ-----\n");
    printf("-----2.��������ѯ-----\n");
    printf("-----3.�˳����˵�-----\n");
    printf("------------------\n");
    while(1)
    {
        printf("��ѡ���Ӳ˵����:");
        scanf("%d",&item);
        flag=0;
        switch(item)
        {
        case 1:
            printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(stu[i].code,s1)==0)
                {
                    flag=1;
                    printf("ѧ��ѧ��    ѧ������  ����   �Ա�  C���Գɼ�  �ߵ���ѧ  ��ѧӢ��ɼ�\n");             
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6c %9.1f %10.1f %10.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
                }
                if(0==flag)
                    printf("��ѧ�Ų����ڣ�\n"); break;
        case 2:
            printf("������Ҫ��ѯ��ѧ��������:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(stu[i].name,s1)==0)
                {
                    flag=1;
                    printf("ѧ��ѧ��    ѧ������  ����   �Ա�  C���Գɼ�  �ߵ���ѧ  ��ѧӢ��ɼ�\n");             
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6c %9.1f %10.1f %10.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
                }
                    if(0==flag)
                        printf("�����������ڣ�\n"); break;
        case 3:return;
        default:printf("����1-3֮��ѡ��\n");
        }
    }
} 


void modify() /*�޸���Ϣ*/
{
    int i,item,num;                    /* item�����Ӳ˵��ı�ţ�num�Ǳ���Ҫ�޸���Ϣ��ѧ�������*/
    char sex1,s1[LEN+1],s2[LEN+1]; /* ��������ѧ�������+1Ϊ׼*/
    float score1;
    printf("������ҪҪ�޸ĵ�ѧ����ѧ��:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(stu[i].code,s1)==0) /*�Ƚ��ַ����Ƿ����*/
            num=i;
        printf("------------------\n");
        printf("1.�޸�����\n");
        printf("2.�޸�����\n");
        printf("3.�޸��Ա�\n");
        printf("4.�޸�C���Գɼ�\n");
        printf("5.�޸ĸߵ���ѧ�ɼ�\n");
        printf("6.�޸Ĵ�ѧӢ��ɼ�\n");
        printf("7.�˳����˵�\n");
        printf("------------------\n");
        while(1)
        {
            printf("��ѡ���Ӳ˵����:");
            scanf("%d",&item);
            switch(item)
            {
            case 1:
                printf("�������µ�����:\n");
                scanf("%s",s2);
                strcpy(stu[num].name,s2); break;
            case 2:
                printf("�������µ�����:\n");
                scanf("%d",stu[num].age);break;
            case 3:
                printf("�������µ��Ա�:\n");
                scanf("%c",&sex1);
                stu[num].sex=sex1; break;
            case 4:
                printf("�������µ�C���Գɼ�:\n");
                scanf("%f",&score1);
                stu[num].score[0]=score1; break;
            case 5:
                printf("�������µĸߵ���ѧ�ɼ�:\n");
                scanf("%f",&score1);
                stu[num].score[1]=score1; break;
            case 6:
                printf("�������µĴ�ѧӢ��ɼ�:\n");
                scanf("%f",&score1);
                stu[num].score[2]=score1; break;
            case 7: return;
            default:printf("����1-7֮��ѡ��\n");
            }
        }
} 


void sort()/*��ѧ������*/
{
    int i,j,k,*p,*q,s;
    char temp[LEN+1],ctemp;
    float ftemp;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
            if(strcmp(stu[j-1].code,stu[j].code)>0)       /*ͨ���Ƚ�����*/
            {
                strcpy(temp,stu[j-1].code);
                strcpy(stu[j-1].code,stu[j].code);
                strcpy(stu[j].code,temp);
                strcpy(temp,stu[j-1].name);
                strcpy(stu[j-1].name,stu[j].name);
                strcpy(stu[j].name,temp);
                ctemp=stu[j-1].sex;
            stu[j-1].sex=stu[j].sex;
                stu[j].sex=ctemp;
                p=&stu[j-1].age;
                q=&stu[j].age;
                s=*q;
                *q=*p;
                *p=s;
                for(k=0;k<3;k++)
                {
                    ftemp=stu[j-1].score[k];
                    stu[j-1].score[k]=stu[j].score[k];
                    stu[j].score[k]=ftemp;
                }
            }
    }
} 

void insert() /*���뺯��*/
{
    int j=n,i,flag;

    printf("����������ӵ�ѧ����:\n");
    scanf("%d",&m);
    if(m>0)
    {
       do
    {
        flag=1;
        while(flag)
        {
            flag=0;
            printf("�������%dλѧ����ѧ��:\n",j+1);
            scanf("%s",stu[j].code);
            for(i=0;i<j;i++)                     /*��֮ǰ��ѧ�űȽϣ�����ظ�������������*/
                if(strcmp(stu[j].code,stu[i].code)==0)
                {
                    printf("���и�ѧ�ţ�������¼��\n");
                    flag=1;
                    break;                       /*�����ظ����˳��ڲ�ѭ��*/
                }
        }
        printf("�������%d ��ѧ����ѧ��:\n",j+1);
        scanf("%s",stu[j].code);
        printf("�������%d ��ѧ��������:\n",j+1);
        scanf("%s",stu[j].name);
        printf("�������%d ��ѧ��������:\n",j+1);
        scanf("%d",&stu[j].age);
        printf("�������%d ��ѧ�����Ա�:\n",j+1);
        scanf(" %c",&stu[j].sex);
        printf("�������%d ��ѧ����C���Գɼ�\n",j+1);
        scanf("%f",&stu[j].score[0]);
        printf("�������%d ��ѧ���ĸߵ���ѧ�ɼ�:\n",j+1);
        scanf("%f",&stu[j].score[1]);
        printf("�������%d ��ѧ���Ĵ�ѧӢ��ɼ�:\n",j+1);
        scanf("%f",&stu[j].score[2]);
        if(0==flag)
        {
            j++;
        }
    }
    while(j<n+m);
    }
    n+=m;
    printf("��Ϣ������ϣ�\n\n");
    sort();
    system("pause");
} 

void del()
{
    int i,j,flag=0;         /* flagΪ0��ʾ����ʧ�ܣ�Ϊ1��ʾ���ҳɹ�*/
    char s1[LEN+1];
    printf("������Ҫɾ��ѧ����ѧ��:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(stu[i].code,s1)==0)  /*�ҵ�Ҫɾ����ѧ����¼*/
        {
            flag=1;                   /*���ҳɹ�*/
            for(j=i;j<n-1;j++)
            stu[j]=stu[j+1];

        }
        if(flag==0)                /*����ʧ��*/
            printf("��ѧ�Ų����ڣ�\n");
        if(flag==1)
        {
            printf("ɾ���ɹ�,��ʾ�����ѡ��˵�\n");
            n--;
        }
    system("pause");
} 


void display()
{
    int i;
    printf("����%dλѧ������Ϣ:\n",n);
    if(0!=n)
    {
        printf("ѧ��ѧ��  ѧ������ ����  �Ա�  C���Գɼ�  �ߵ���ѧ  ��ѧӢ��ɼ�\n");             
        printf("--------------------------------------------------------------------\n");
        for(i=0;i<n;i++)
        { 
            printf("%7s %7s %6d %6c %9.1f %10.1f %10.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
        }
    }
    system("pause");
} 

void save()
{
    int i;
    FILE *fp;
    char filename[LEN+1];
    printf("������Ҫ�������Ϣ���ļ���:\n");      /*����Ҫ������ļ�������*/
    scanf("%s",filename);
    fp=fopen(filename,"w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s%s%d%c%.1f%.1f%.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    printf("����ɹ�\n");
    fclose(fp);
    system("pause");
}


void menu()/* ����*/
{
    int num;
    printf(" \n\n                    \n\n");
    printf("  ******************************************************\n\n");
    printf("  *                ѧ����Ϣ����ϵͳ                    *\n \n");
    printf("  ******************************************************\n\n"); 
    printf("*********************ϵͳ���ܲ˵�*************************       \n");
    printf("     ----------------------   ----------------------   \n");
    printf("     *********************************************     \n");
    printf("     * 0.ϵͳ������˵��  * *  1.ˢ��ѧ����Ϣ   *     \n");
    printf("     *********************************************     \n"); 
    printf("     * 2.��ѯѧ����Ϣ    * *  3.�޸�ѧ����Ϣ   *     \n");
    printf("     *********************************************     \n");
    printf("     * 4.����ѧ����Ϣ    * *  5.��ѧ��ɾ����Ϣ *     \n");
    printf("     *********************************************     \n");
    printf("     * 6.��ʾ��ǰ��Ϣ    * *  7.���浱ǰѧ����Ϣ*     \n");
    printf("     ********************** **********************     \n");
    printf("     * 8.�˳�ϵͳ        *                            \n");
    printf("     **********************                            \n");
    printf("     ----------------------   ----------------------                           \n");
    printf("��ѡ��˵����:");
    scanf("%d",&num);
    switch(num)
    { 
    case 0:help();break;
    case 1:readfile();break;
    case 2:seek();break;
    case 3:modify();break;
    case 4:insert();break;
    case 5:del();break;
    case 6:display();break;
    case 7:save();break;
    case 8:k=0;break;
    default:printf("����0-8֮��ѡ��\n");
    }
}