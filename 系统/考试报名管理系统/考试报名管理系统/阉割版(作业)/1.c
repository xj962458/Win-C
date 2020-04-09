#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����һ�������ṹ��
typedef struct student
{
    char name[40];
    char no[18];
    int xb;
    int age;
    char tele[20];
    struct student *next;
}STU;

//����������������
void ListCreate(STU *L, int n);     //������������ڵ�
void LIstSearch(STU *L);            //���ҿ�����Ϣ
void ListModify(STU *L);            //�޸Ŀ�����Ϣ
void ListInsert(STU *L);            //���뿼����Ϣ
void ListDelete(STU *L);            //ɾ��������Ϣ
void Input(STU *p,int i);           //���뿼����Ϣ
void Menu();                        //���Ա�������ϵͳ�Ĳ˵�

//������������ϵͳ�����������
int main()
{
    int item,n;                       //item���ڽ�����������n���ڽ�������Ŀ�������      
    STU *L=NULL;                        //��ʼ��һ��ͷ�ڵ�
    L=(STU *)malloc(sizeof(STU));       //Ϊͷ�ڵ㿪���ڴ�ռ�
    L->next=NULL;                       //��ͷ�ڵ��ָ�����ÿ�4
    do
    {  
        Menu();                         //�˵�
        printf("��������Ӧ�����֣�������Ӧ�Ĳ���:\n");
        scanf("%d",&item);
        system("cls");
        switch(item)
        {
            case 1:
                printf("��������Ҫ¼��Ŀ�������:");
                scanf("%d",&n);
                ListCreate(L,n);                      //������������ڵ�
                getchar();
            	printf("\n�밴������������˵�\n");
				getchar();
				system("cls");
                break;
            case 2:
                LIstSearch(L);                        //���ҿ�����Ϣ
                getchar();
            	printf("\n�밴������������˵�\n");
				getchar();
				system("cls");
                break;                                             
            case 3:
                ListModify(L);                          //�޸Ŀ�����Ϣ
                getchar();
            	printf("\n�밴������������˵�\n");
				getchar();
				system("cls");
                break;
            case 4:
                ListDelete(L);                          //ɾ��������Ϣ
                getchar();
                printf("\n�밴������������˵�\n");
				getchar();
				system("cls");
                break;
            case 5:
                ListInsert(L);                          //���뿼����Ϣ
                getchar();
                printf("\n�밴������������˵�\n");
				getchar();
				system("cls");
                break;
            case 0:                                     //�˳����Ա�������ϵͳ
                printf("�����˳�������Ϣ����ϵͳ.....");
                exit(0);
            default:
                printf("�������ָ���ȷ������������");
        }
        printf("\n\n");
    }while(item);
    return 0;
}

//���������������ɵĽڵ���뵽����ı�ͷ
void ListCreate(STU *L, int n)
{
    int i; 
    for (i = 0; i<n; i++)
    {
        STU *p;
        //�������ɵĽڵ���뵽������
        p=NULL;
        p = (STU *)malloc(sizeof(STU));
        Input(p,i);
        p->next = L->next;
        L->next = p;
    }
}

//���ҿ�����Ϣ
void LIstSearch(STU *L)
{
    char n[40];
    STU *p=L->next;
    if (p == NULL)
        printf("����Ϊ�գ��޷����ң�");
    else
    {
        printf("��������Ҫ���ҵĿ�������:");
        scanf("%s",n);
        while (strcmp(p->name, n) != 0)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("û���ҵ������Ϣ\n");
                return;
            }
        }
        printf("�ÿ����������Ϣ����:\n");
        printf("����\t���֤��\t\t�Ա�\t����\t�绰����\n");
        printf("%s\t",p->name);
        printf("%s",p->no);
        printf("\t%d",p->xb);
        printf("\t%d",p->age);
        printf("\t%s",p->tele);
        printf("\n");
    }
}

//�޸Ŀ�����Ϣ
void ListModify(STU *L)
{
    int x,a,item;
    char nam[40],no[18],tel[20],n[40];
    STU *p=L->next;
    if (p == NULL)
        printf("����Ϊ�գ��޷��޸ģ�");
    else
    {
        printf("��������Ҫ�޸ĵĿ�������:");
        scanf("%s",n);
        while(strcmp(p->name, n) != 0)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("û���ҵ������Ϣ\n");
                return;
            }
        }
        printf("��ѡ����Ҫ�޸ĵĿ�����Ϣ����:\n");
        printf("1:����\t 2:���֤��\t 3:�Ա�\t 4:����\t 5:�绰����\n");
        scanf("%d",&item);
        switch(item)
        {
            case 1:
                printf("���������޸ĺ������:");
                scanf("%s",nam);
                strcpy(p->name,nam);
                break;
            case 2:
                printf("���������޸ĺ�����֤��:");
                scanf("%s",no);
                strcpy(p->no,no);
                break;
            case 3:
                printf("���������޸ĺ���Ա�:");
                scanf("%d",&x);
                p->xb=x;
                break;
            case 4:
                printf("���������޸ĺ������:");
                scanf("%d",&a);
                p->age=a;
                break;
            case 5:
                printf("���������޸ĺ�ĵ绰����:");
                scanf("%s",tel);
                strcpy(p->tele,tel);
                break;
            default:
                printf("�������ָ���ȷ!\n");
        }
        printf("�޸ĳɹ�!");
    }
}

//ɾ��������Ϣ
void ListDelete(STU *L)
{
    char n[40];
    STU *p=L->next,*pre=L;  //����pָ��ָ��ͷ�ڵ��ָ�򣬶���preָ��ͷ�ڵ㣬preʼ��ָ��p��ǰ���ڵ�
    if(p==NULL)
        printf("����Ϊ�գ��޷�ɾ����");
    else
    {
        printf("��������Ҫɾ���Ŀ�������:");
        scanf("%s",n);
        while(strcmp(p->name,n)!=0)
        {
            pre=p;
            p=pre->next;
            if(p==NULL)
            {
                printf("û���ҵ������Ϣ���޷�ɾ��\n");
                return;
            }
        }
        pre->next=p->next;
        free(p);
        printf("ɾ���ɹ�");
    }
}

//���뿼����Ϣ
void ListInsert(STU *L)
{
    STU *s = NULL;              //����һ���½ڵ�s
    s = (STU *)malloc(sizeof(STU));
    printf("��������Ҫ����Ŀ���������:");
    scanf("%s",s->name);
    printf("��������Ҫ����Ŀ��������֤��:");
    scanf("%s",s->no);
    printf("��������Ҫ����Ŀ������Ա�Ů��Ϊ0������Ϊ1��:");
    scanf("%d",&s->xb);
    printf("��������Ҫ����Ŀ���������:");
    scanf("%d",&s->age);
    printf("��������Ҫ����Ŀ����ĵ绰����:");
    scanf("%s",s->tele);
    s->next = L->next;
    L->next = s;
}

//���뿼����Ϣ
void Input(STU *p,int i)
{
    printf("�������%d������������:",i+1);
    scanf("%s",p->name);
    printf("�������%d�����������֤��:",i+1);
    scanf("%s",p->no);
    printf("�������%d���������Ա�Ů��Ϊ0������Ϊ1��:",i+1);
    scanf("%d",&p->xb);
    printf("�������%d������������:",i+1);
    scanf("%d",&p->age);
    printf("�������%d�������ĵ绰����:",i+1);
    scanf("%s",p->tele);
}

//������Ϣ����ϵͳ�Ĳ˵�
void Menu()
{
    printf("\n\n");
	printf("\t\t\t===================���Ա�������ϵͳ==================\n");
	printf("\t\t\t* ����:���¼�  �༶:�˹�����191  ѧ��:3190707121    *\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*          1>. ¼�뿼����Ϣ                         *\n");
	printf("\t\t\t*          2>. ���ҿ�����Ϣ                         *\n");
	printf("\t\t\t*          3>. �޸Ŀ�����Ϣ                         *\n");
	printf("\t\t\t*          4>. ɾ��������Ϣ                         *\n");
	printf("\t\t\t*          5>. ���뿼����Ϣ                         *\n");
	printf("\t\t\t*          0>. �˳�����ϵͳ                         *\n");
	printf("\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t����ѡ����س�����ѡ��:                             \n");
}
