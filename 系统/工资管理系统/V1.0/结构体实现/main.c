//main.c
#pragma once
#include "preProcess.h"
int saveflag = 0; /*��Ҫ���̵ı�־����*/
int main()
{

    ZGGZ gz[N]; /*����ZGGZ�ṹ��*/
    FILE *fp;
    int select;    /*����ѡ��������*/
    char ch;       /**/
    int count = 0; /*���屣���¼��*/

    void menu(); /*���˵�����*/
    void printheader();
    void PRINTdata(ZGGZ pp);
    void disp(ZGGZ tp[], int n);
    void wrong();
    void nofind();
    void stringinput(char *t, int lens, char *notice); /*�����ַ����������г�����֤�������ȱ���С��lens��*/
    float numberinput(char *notice);                   /*������ֵ������������ֵ����󷵻ظ�ֵ����ֵ������ڵ���0*/
    void save(ZGGZ tp[], int n);                       /*�洢��¼*/
    int add(ZGGZ tp[], int n);                         /*���Ӽ�¼*/
    int insert(ZGGZ tp[], int n);                      /*�����¼*/

    fp = fopen("E:\zggz\gzgl.data", "ab+"); /*׷�ӷ�ʽ�򿪶������ļ����ɶ�/д�����ļ������������½�*/
    if (fp == NULL)
    {
        /* code */
        printf("\n Can not open file!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        if (fread(&gz[count], sizeof(ZGGZ), 1, fp) == 1)
            count++;
    }
    fclose(fp);
    printf("\n==>open file success,the total records number is:%d.\n", count);
    getchar();

    //system("pause");
    menu();
    while (1)
    {
        system("cls");
        menu(); //�������˵�
        printf("\n 	Please Enter your choice(0~9):");
        scanf("%d", &select);
        if (select == 0)
        {
            /* code */
            if (saveflag == 1) /*���������������޸Ĺ���δ���̣���˱�־Ϊ1*/
            {
                /* code */
                getchar();
                printf("\n==>Whether save the modified records to file?(y/n)");
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                    save(gz, count);
                    /* code */
                }
            }
            printf("\n===>Thank you for useness!\n");
            getchar();
            break;
        }
        switch (select)
        {
        case 1:
            count = add(gz, count);
            break; /*���Ӽ�¼*/
        //case 2:count=del(gz,count);break;			/*ɾ����¼*/
        //case 3:qur(gz,count);break;					/*��ѯ��¼*/
        //case 4:modify(gz,count);break;				/*�޸ļ�¼*/
        case 5:
            count = insert(gz, count);
            break; /*�����¼*/

        default:
            wrong();
            getchar();
            break; /*�������󣬻��ܻ�δʵ��*/
        }
    }
    system("pause");
    return 0;
}