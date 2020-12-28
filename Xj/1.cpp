#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3 //�����˶����ѧԺ��Ŀ
//����һ���ṹ��
typedef struct project
{
    char xiangmu[40];     //������Ŀ����
    char name[N][40];     //ѧԺ����
    float score[N];       //����ɼ�
    int no[N];            //��������
    struct project *next; //ָ����һ�ڵ��ָ��
} Proj;

typedef struct sumno
{
    char name[40];
    float sum;
} SumNo;
//����������������
void ListCreate(Proj *L, int n); //��������ڵ�
void ListSearch(Proj *L);        //����ĳ���˶�����Ŀ��Ϣ
void ListModify(Proj *L);        //�޸�ĳ���˶�����Ŀ��Ϣ
void ListDelete(Proj *L);        //ɾ��ĳ���˶�����Ŀ��Ϣ
void Input(Proj *p, int i);      //�����˶�����Ŀ��Ϣ
void Output(Proj *L);            //���ÿ���˶�����Ŀ��ѧԺ�ɼ�������Ϣ
void PerRank(Proj *L);           //����ÿ���˶�����Ŀ��ѧԺ�ɼ����������
void SumRank(Proj *L);           //������Ŀÿ��ѧԺ���ܳɼ�������
void Menu();                     //У�˶�����Ŀ����ϵͳ�Ĳ˵�

//У�˶�����Ŀ����ϵͳ�����������
int main()
{
    int item, n;                      //item���ڽ�����������n���ڽ����������Ŀ��
    Proj *L = NULL;                   //��ʼ��һ��ͷ�ڵ�
    L = (Proj *)malloc(sizeof(Proj)); //Ϊͷ�ڵ㿪���ڴ�ռ�
    L->next = NULL;                   //��ͷ�ڵ��ָ�����ÿ�
    do
    {
        Menu(); //�˵�
        printf("��������Ӧ�����֣�������Ӧ�Ĳ���:\n");
        scanf("%d", &item);
        system("cls");
        switch (item)
        {
        case 1:
            printf("��������Ҫ¼�����Ŀ��Ŀ:");
            scanf("%d", &n);
            ListCreate(L, n); //������Ŀ����ڵ�
            getchar();
            printf("\n�밴������������˵�\n");
            getchar();
            system("cls");
            break;
        case 2:
            ListSearch(L); //������Ŀ�������Ϣ
            getchar();
            printf("\n�밴������������˵�\n");
            getchar();
            system("cls");
            break;
        case 3:
            ListModify(L); //�޸���Ŀ��Ϣ
            getchar();
            printf("\n�밴������������˵�\n");
            getchar();
            system("cls");
            break;
        case 4:
            ListDelete(L); //ɾ����Ŀ����Ϣ
            getchar();
            printf("\n�밴������������˵�\n");
            getchar();
            system("cls");
            break;
        case 5:
            PerRank(L); //����ÿ���˶�����Ŀ��ѧԺ�ɼ�����
            Output(L);  //���ÿ���˶�����Ŀ��ѧԺ�ɼ�������Ϣ
            getchar();
            printf("\n�밴������������˵�\n");
            getchar();
            system("cls");
            break;
        case 6:
            SumRank(L); //������Ŀÿ��ѧԺ���ܳɼ�������
            getchar();
            printf("\n�밴������������˵�\n");
            getchar();
            system("cls");
            break;
        case 0:
            printf("�����˳�У�˶�����Ŀ����ϵͳ....."); //�˳�У�˶�����Ŀ����ϵͳ
            exit(0);
        default:
            printf("�������ָ���ȷ������������");
        }
        printf("\n\n");
    } while (item);
    return 0;
}

//���������������ɵĽڵ���뵽����ı�ͷ
void ListCreate(Proj *L, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        Proj *p;
        //�������ɵĽڵ���뵽������
        p = NULL;
        p = (Proj *)malloc(sizeof(Proj));
        Input(p, i);
        p->next = L->next;
        L->next = p;
    }
}

//������Ŀ��Ϣ
void ListSearch(Proj *L)
{
    int k;
    char n[40];
    Proj *p = L->next;
    if (p == NULL)
        printf("����Ϊ�գ��޷����ң�");
    else
    {
        printf("��������Ҫ���ҵ���Ŀ����:");
        scanf("%s", n);
        while (strcmp(p->xiangmu, n) != 0)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("û���ҵ������Ϣ\n");
                return;
            }
        }
        PerRank(L);
        printf("����Ŀ�������Ϣ����:\n");
        printf("ѧԺ����\t����ɼ�\t��������\n\n");
        for (k = 0; k < N; k++)
        {
            printf("%s\t\t", *((p->name) + k));
            printf("%.2f\t\t", *((p->score) + k));
            printf("%d\t\n", *((p->no) + k));
        }
        printf("\n\n");
    }
}

//�޸���Ŀ�������Ϣ
void ListModify(Proj *L)
{
    int item, k, a;
    char n[40], m[40];
    Proj *p = L->next;
    if (p == NULL)
        printf("����Ϊ�գ��޷��޸ģ�");
    else
    {
        printf("��������Ҫ�޸ĵ���Ŀ����:");
        scanf("%s", n);
        while (strcmp(p->xiangmu, n) != 0)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("û���ҵ������Ϣ\n");
                return;
            }
        }
        printf("���Ƿ���Ҫ�޸���Ŀ����(������1����������0):");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("���������޸ĺ����Ŀ����:");
            scanf("%s", m);
            strcpy(p->xiangmu, m);
            printf("�޸ĳɹ���");
        }
        else if (a == 0)
        {
            printf("��������Ҫ�޸ĵ�ѧԺ:");
            scanf("%s", n);
            for (k = 0; k < N; k++)
            {
                if (strcmp(*((p->name) + k), n) == 0)
                    break;
            }
            printf("��������Ҫ�޸ĵ���Ŀ��Ϣ����:\n");
            printf("1��ѧԺ����\n2����ѧԺ����Ŀ�ĳɼ�\n");
            scanf("%d", &item);
            switch (item)
            {
            case 1:
                printf("�������޸ĺ��ѧԺ����:");
                scanf("%s", m);
                strcpy(*((p->name) + k), m);
                printf("�޸ĳɹ�");
                break;
            case 2:
                printf("���������޸ĺ�ĸ�ѧԺ����Ŀ�ĳɼ�:");
                scanf("%f", (p->score) + k);
                printf("�޸ĳɹ�");
                break;
            default:
                printf("�������ָ�����!");
                break;
            }
        }
        else
            printf("���������");
    }
}

//ɾ����Ŀ�������Ϣ
void ListDelete(Proj *L)
{
    char n[40];
    Proj *p = L->next, *pre = L; //����pָ��ָ��ͷ�ڵ��ָ�򣬶���preָ��ͷ�ڵ㣬preʼ��ָ��p��ǰ���ڵ�
    if (p == NULL)
        printf("����Ϊ�գ��޷�ɾ����");
    else
    {
        printf("��������Ҫɾ������Ŀ����:");
        scanf("%s", n);
        while (strcmp(p->xiangmu, n) != 0)
        {
            pre = p;
            p = pre->next;
            if (p == NULL)
            {
                printf("û���ҵ������Ϣ���޷�ɾ��\n");
                return;
            }
        }
        pre->next = p->next;
        free(p);
        printf("ɾ���ɹ�");
    }
}

//����ÿ���˶�����Ŀ��ѧԺ�ɼ�����
void PerRank(Proj *L)
{
    int i, j, k;
    float t;
    char na[40] = {' '};
    Proj *p = L->next;
    if (p == NULL)
        printf("����Ϊ�գ��޷�����");
    else
    {
        while (p != NULL)
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N - i - 1; j++)
                {
                    if (*((p->score) + j) < *((p->score) + j + 1))
                    {
                        t = *((p->score) + j);
                        *((p->score) + j) = *((p->score) + j + 1);
                        *((p->score) + j + 1) = t;
                        strcpy(na, *((p->name) + j));
                        strcpy(*((p->name) + j), *((p->name) + j + 1));
                        strcpy(*((p->name) + j + 1), na);
                    }
                }
            }
            for (k = 0; k < N; k++)
                *((p->no) + k) = k + 1;
            p = p->next;
        }
    }
}

//������Ŀÿ��ѧԺ���ܳɼ�������;
void SumRank(Proj *L)
{
    int i, j, k;
    float t;
    SumNo s[N],s0;
    Proj *p = L->next;
    for (i = 0; i < N; i++)
    {
        strcpy(s[i].name, *((p->name) + N - i - 1));
        s[i].sum = 0;
    }
    if (p == NULL)
        printf("����Ϊ�գ�");
    else
    {
        while (p != NULL)
        {
            for(i=0;i<N;i++)
                s[i].sum += *((p->score) + i);
            p = p->next;
        }
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N - j - 1; k++)
            {
                if(s[k].sum>s[k+1].sum){
                    s0 = s[k];
                    s[k] = s[k + 1];
                    s[k + 1]= s0;
                }
            }
        }
        p = L->next;
        printf("ѧԺ����\t�ܳɼ�\t\t������\n");
        for (i = N - 1; i >= 0; i--)
        {
            printf("%s\t\t", s[i].name);
            printf("%.2f\t\t", s[i].sum);
            printf("%d\t\t", N - i);
            printf("\n");
        }
    }
}
//������Ŀ�������Ϣ
void Input(Proj *p, int i)
{
    int j;
    printf("�������%d��������Ŀ����:", i + 1);
    scanf("%s", p->xiangmu);
    for (j = 0; j < N; j++)
    {
        printf("�������%d��ѧԺ������:", j + 1);
        scanf("%s", (p->name) + j);
        printf("�������ѧԺ�ĸ���Ŀ�ĳɼ�:");
        scanf("%f", (p->score) + j);
    }
}

//���ȫ����Ŀ��Ϣ
void Output(Proj *L)
{
    int k;
    Proj *p = L->next;
    while (p != NULL)
    {
        printf("\t\t��Ŀ:%s\n\n", p->xiangmu);
        printf("ѧԺ����\t����ɼ�\t��������\n\n");
        for (k = 0; k < N; k++)
        {
            printf("%s\t\t", *((p->name) + k));
            printf("%.2f\t\t", *((p->score) + k));
            printf("%d\t\n", *((p->no) + k));
        }
        printf("\n\n");
        p = p->next;
    }
}
//У�˶�����Ŀ����ϵͳ�Ĳ˵�
void Menu()
{
    printf("\n\n");
    printf("\t\t\t===================У�˶�����Ŀ����ϵͳ==================\n");
    printf("\t\t\t* ����:XXX  �༶:�˹�����XXXX  ѧ��:XXXXXXXXX            *\n");
    printf("\t\t\t*                                                       *\n");
    printf("\t\t\t*          1>. ¼���˶�����Ŀ��Ϣ                       *\n");
    printf("\t\t\t*          2>. ����ĳ���˶�����Ŀ��Ϣ                   *\n");
    printf("\t\t\t*          3>. �޸�ĳ���˶�����Ŀ��Ϣ                   *\n");
    printf("\t\t\t*          4>. ɾ��ĳ���˶�����Ŀ��Ϣ                   *\n");
    printf("\t\t\t*          5>. ÿ���˶�����Ŀ��ѧԺ�ɼ�����             *\n");
    printf("\t\t\t*          6>. ������Ŀÿ��ѧԺ���ܳɼ�������           *\n");
    printf("\t\t\t*          0>. �˳�����ϵͳ                             *\n");
    printf("\t\t\t*                                        ��ӭʹ�ñ�ϵͳ!*\n");
    printf("\t\t\t=========================================================\n");
    printf("\t\t\t����ѡ����س�����ѡ��:                                \n");
}
