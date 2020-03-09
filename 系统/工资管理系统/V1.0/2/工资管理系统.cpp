#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct worker
{
    char no[12];         //ְ������
    char name[40];       //����
    int month[12];       //�·�
    float gz[12];        //�¹���
    float total;         //����ܹ���
    struct worker *next; //ָ����һ�ڵ��ָ��
} Worker;

//��صĺ�������
Worker *InitList(Worker *L);                        //��ʼ���������ڴ���ͷ�ڵ�
Worker *CreateList(Worker *L);                      //���������ְ�����������������ڵ�
void DeleteList(Worker *L, char n[]);               //ɾ���ڵ�
void LIstSearch(Worker *L, char n[]);               //����ְ��������Ϣ
void InsertInfo(Worker *L);                         //����ְ��������Ϣ
void SearchMonthSalary(Worker *L, char n[], int m); //����ĳ��ְ����ĳ���µĹ���
void input(Worker *p, int i);                       //Ϊ�ڵ��������ֵ
void output(Worker *L);                             //����������������
void Modify(Worker *L, char n[], int m[]);          //�޸�ĳ��ְ���Ĺ���
void menu();                                        //���ʹ���ϵͳ�Ĳ˵�
void Save(Worker *L);                               //��ְ���Ĺ�����Ϣ�������ļ�

//��ʼ���������ڴ���ͷ�ڵ�
Worker *InitList(Worker *L)
{
    Worker *head = NULL;
    head = (Worker *)malloc(sizeof(Worker));
    head->next = NULL;
    L = head;
    return L;
}

//���������ְ�����������������ڵ�
Worker *CreateList(Worker *L, int n) //nΪ�����ְ������
{
    int i;
    for (i = 0; i < n; i++)
    {
        Worker *p;
        //�������ɵĽڵ���뵽������
        p = NULL;
        p = (Worker *)malloc(sizeof(Worker));
        input(p, i); //Ϊ�ڵ��������ֵ
        p->next = L->next;
        L->next = p;
    }
    return L;
}

void DeleteList(Worker *L, char n[]) //������ɾ��ְ����Ϣ
{
    int i;
    Worker *p = L->next, *pre = L; //����pָ��ָ��ͷ�ڵ��ָ�򣬶���preָ��ͷ�ڵ㣬preʼ��ָ��p��ǰ���ڵ�
    if (p == NULL)
        printf("����Ϊ�գ��޷�ɾ����");
    else
    {
        while (strcmp(p->name, n) != 0)
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

//�������в���ְ��������Ϣ
void InsertInfo(Worker *L)
{
    int j, k;
    Worker *p = NULL;
    p = (Worker *)malloc(sizeof(Worker)); //����һ���½ڵ�p
    p->total = 0;
    printf("������Ҫ�����ְ����ְ������:");
    scanf("%s", &p->no);
    printf("������Ҫ�����ְ��������:");
    scanf("%s", &p->name);
    for (k = 0, j = 1; j <= 12, k < 12; j++, k++)
        p->month[k] = j;
    printf("������Ҫ�����ְ�����¹���(�ÿո����):");
    for (j = 0; j < 12; j++)
    {
        scanf("%f", &p->gz[j]); //����ÿ���µĹ���
        p->total += p->gz[j];   //�����ܹ���
    }
    p->next = L->next;
    L->next = p;
    printf("����ɹ�!");
}

void LIstSearch(Worker *L, char n[])
{
    int i;
    Worker *p = L->next;
    while (p != NULL)
    {
        if (strcmp(p->name, n) == 0)
        {
            printf("\n��ְ���Ĺ��ʵ���Ϣ����:\n");
            printf("ְ�����:");
            printf("%s\t\n", p->no);
            printf("����:");
            printf("%s\n", p->name);
            printf("��ְ��12���µ��¹�������:");
            for (i = 0; i < 12; i++)
                printf("%.2f ", p->gz[i]);
            printf("\n��ְ��������ܹ���Ϊ:");
            printf("%.2f", p->total);
            printf("\n\n");
            printf("\n");
            p = p->next;
        }
        else
            p = p->next;
    }
}

void SearchMonthSalary(Worker *L, char n[], int m)
{
    int i;
    Worker *p = L->next;
    while (p != NULL)
    {
        if (strcmp(p->name, n) == 0)
        {
            switch (m)
            {
            case 1:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[0], p->gz[0]);
                break;
            case 2:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[1], p->gz[1]);
                break;
            case 3:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[2], p->gz[2]);
                break;
            case 4:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[3], p->gz[3]);
                break;
            case 5:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[4], p->gz[4]);
                break;
            case 6:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[5], p->gz[5]);
                break;
            case 7:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[6], p->gz[6]);
                break;
            case 8:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[7], p->gz[7]);
                break;
            case 9:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[8], p->gz[8]);
                break;
            case 10:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[9], p->gz[9]);
                break;
            case 11:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[10], p->gz[10]);
                break;
            case 12:
                printf("��ְ��%d�µĹ���Ϊ%.2f", p->month[11], p->gz[11]);
                break;
            default:
                break;
            }
            p = p->next;
        }
        else
            p = p->next;
    }
}

void Modify(Worker *L, char n[], int m, float s)
{
    int i;
    Worker *p = L->next;
    while (p != NULL)
    {
        if (strcmp(p->name, n) == 0)
        {
            switch (m)
            {
            case 1:
                p->gz[0] = s;
                break;
            case 2:
                p->gz[1] = s;
                break;
            case 3:
                p->gz[2] = s;
                break;
            case 4:
                p->gz[3] = s;
                break;
            case 5:
                p->gz[4] = s;
                break;
            case 6:
                p->gz[5] = s;
                break;
            case 7:
                p->gz[6] = s;
                break;
            case 8:
                p->gz[7] = s;
                break;
            case 9:
                p->gz[8] = s;
                break;
            case 10:
                p->gz[9] = s;
                break;
            case 11:
                p->gz[10] = s;
                break;
            case 12:
                p->gz[11] = s;
                break;
            default:
                break;
            }
            p = p->next;
        }
        else
            p = p->next;
    }
    printf("�޸ĳɹ�!");
}
void input(Worker *p, int i)
{
    int j, k;
    p->total = 0;
    printf("�������%d��ְ����ְ������:", i + 1);
    scanf("%s", &p->no);
    printf("�������%d��ְ��������:", i + 1);
    scanf("%s", &p->name);
    for (k = 0, j = 1; j <= 12, k < 12; j++, k++)
        p->month[k] = j;
    printf("�������%d��ְ�����¹���(�ÿո����):", i + 1);
    for (j = 0; j < 12; j++)
    {
        scanf("%f", &p->gz[j]); //����ÿ���µĹ���
        p->total += p->gz[j];   //�����ܹ���
    }
}

void output(Worker *L)
{
    int i;
    Worker *p = L->next;
    while (p != NULL)
    {
        printf("ְ�����:");
        printf("%s\t\n", p->no);
        printf("����:");
        printf("%s\n", p->name);
        printf("��ְ��12���µ��¹�������:");
        for (i = 0; i < 12; i++)
            printf("%.2f ", p->gz[i]);
        printf("\n��ְ��������ܹ���Ϊ:");
        printf("%.2f", p->total);
        printf("\n\n");
        p = p->next;
    }
}

void Save(Worker *L)
{
    int i;
    Worker *p = L->next;
    FILE *fp = fopen("WorkerSalaryInfo.txt", "w");
    while (p != NULL)
    {
        fprintf(fp, "ְ�����:");
        fprintf(fp, "%s\t\n", p->no);
        fprintf(fp, "����:");
        fprintf(fp, "%s\n", p->name);
        fprintf(fp, "��ְ��12���µ��¹�������:");
        for (i = 0; i < 12; i++)
            fprintf(fp, "%.2f ", p->gz[i]);
        fprintf(fp, "\n��ְ��������ܹ���Ϊ:");
        fprintf(fp, "%.2f", p->total);
        fprintf(fp, "\n\n");
        p = p->next;
    }
    fclose(fp);
    printf("����ɹ����ѱ�������ǰĿ¼�µġ�WorkerSalaryInfo.txt���ļ���");
}

void menu()
{
    printf("��������������ӭ���빤�ʹ���ϵͳ������������\n");
    printf(" 1.¼��ְ��ÿ���µĹ�����Ϣ                \n");
    printf(" 2.����ĳ��Ա�����µĹ���                  \n");
    printf(" 3.����ĳ��ְ����ĳ���µĹ���              \n");
    printf(" 4.�޸�ĳ��ְ��ĳ���µĹ���                \n");
    printf(" 5.ɾ��ĳ��ְ���������Ϣ                  \n");
    printf(" 6.����ְ��������Ϣ                        \n");
    printf(" 7.ͳ��ĳ��ְ������ܹ���                  \n");
    printf(" 8.��ְ�����¹��ʻ��깤�ʽ�������           \n");
    printf(" 9.�������ְ��������Ϣ                    \n");
    printf(" 10��������ְ���Ĺ�����Ϣ�������ļ�         \n");
    printf(" 0.�˳�                                   \n");
    printf("-�x�x�x�x�x�x�x�x�xллʹ�èx�x�x�x�x�x�x�x�x\n");
}

int main()
{
    int item, n, m; //item���ڽ�����������n���ڽ��������ְ������
    float s;
    char nam[10];
    Worker *L = NULL;
    L = InitList(L);
    do
    {
        menu();
        printf("��������Ӧ�����֣�������Ӧ�Ĳ���:\n");
        scanf("%d", &item);
        switch (item)
        {
        case 1:
            printf("��������Ҫ¼���ְ������:");
            scanf("%d", &n);
            L = CreateList(L, n);
            break;
        case 2:
            printf("��������Ҫ���ҵ�ְ������:");
            scanf("%s", &nam);
            LIstSearch(L, nam);
            break;
        case 3:
            printf("��������Ҫ���ҵ�ְ��������:");
            scanf("%s", &nam);
            printf("��������Ҫ���Ҹ�ְ���ڼ����µĹ���(1��12):");
            scanf("%d", &m);
            SearchMonthSalary(L, nam, m);
            break;
        case 4:
            printf("��������Ҫ�޸ĵ�ְ������:");
            scanf("%s", &nam);
            printf("\n��������Ҫ�޸ĵ��·�:");
            scanf("%d", &m);
            printf("\n���������޸ĺ������:");
            scanf("%f", &s);
            Modify(L, nam, m, s);
            break;
        case 5:
            printf("��������Ҫɾ����ְ������:");
            scanf("%s", &nam);
            DeleteList(L, nam);
            break;
        case 6:
            InsertInfo(L);
            break;
        case 7:
            printf("����������!");
            break;
        case 8:
            printf("����������!");
            break;
        case 9:
            printf("ȫ��ְ������Ϣ����:\n\n");
            output(L);
            break;
        case 10:
            Save(L);
            break;
        case 0:
            printf("лл��ʹ�ù��ʹ���ϵͳ�������˳����ʹ���ϵͳ.....");
            exit(0);
            break;
        }
        printf("\n\n\n\n");
    } while (item);
    return 0;
}