#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*����һ��ѧ������*/
typedef struct student
{
    char stuid[16];//ѧ��
    char name[16];//ѧ������
    int num;//ѧ��ѧ��
    struct student* next;//��һ��ѧ����ָ��
}Stu;

Stu* students;//ѧ������
char* stuInfo="test.txt";//ѧ����Ϣ�洢���ļ�
int input = 0;//ѡ��
char tempInput[64];
char tempName[64];
char tempStuid[64];
int tempNum = 0;


void initFromTxt(void);//��ʼ��
void deleteInfo(char* stuid);//ɾ����Ϣ
void reWrite(void);//��д
void insert2txt(Stu* stu);//�����ı�
int addinfo(char* stuid, char* name, int num);//������Ϣ
void modify(char* stuid, char*name, int num);//�޸���Ϣ
int checkAdd(char* stuid);//�ж�ѧ������
void showInfo(void);//չʾ��Ϣ
Stu* findInfo(char* stuid);//������Ϣ
void view(void);//����
int checkInput(char* input, int begin, int end);//�ж������Ƿ��ٸ����ķ�Χ��

void initFromTxt(void)
{
    students = (Stu*)malloc(sizeof(Stu));//�������ͷ�ڵ�����ڴ�
    students->next = NULL;//ָ����Ϊ��
    FILE* file;
    file = fopen(stuInfo, "r");//����Ϣ�ļ�
    if (file == NULL)
    {
        printf("[initFromTxt]���ļ�ʧ��!");
        return;
    }
    Stu* s = students;//��ǰ���
    while (1)
    {
        Stu* stu = (Stu*)malloc(sizeof(Stu));
        //���ı�����ѧ����Ϣ�����stu��
        if (fscanf(file, "%s %s %d",&(stu->stuid) ,&(stu->name), &(stu->num)) == EOF)
        {
            //�������ΪEOF��Ҳ��˵Ϊ����Ϊ�գ���ô�ո��½���stu�Ͳ�Ҫ�ˣ��ͷŷ�����ڴ�
            free(stu);
            break;
        }   
        stu->next = NULL;

        s->next = stu;//����ǰ�ڵ���½��Ľڵ���������
        s = stu;//������ǰ�ڵ�Ϊ�½ڵ�
    }
    fclose(file);
}

void deleteInfo(char* stuid)
{
    Stu* stu = students->next;//��ǰ�ڵ�
    Stu* pre = students;//��ǰ�ڵ�ĸ��ڵ�
    int isFound = 0;//�Ƿ��ҵ�ѧ��
    while (stu != NULL)
    {
        if (strcmp(stu->stuid, stuid) == 0)//�ж�id�Ƿ���ͬ
        {
            pre->next = stu->next;
            free(stu);
            reWrite();//��д���ļ�
            isFound = 1;
            break;
        }
        pre = pre->next;
        stu = stu->next;
    }
    if (isFound)
    {
        printf("ɾ���ɹ�!\n");
    }
    else
    {
        printf("û���ҵ��ü�¼!\n");
    }
}

void reWrite(void)
{
    Stu* stu = students->next;
    FILE* file = fopen(stuInfo, "w");//����ļ�
    fclose(file);
    if (stu == NULL)//�������ǰû��ѧ����ֱ�ӷ���
    {
        return;
    }

    while (stu != NULL)
    {   
        insert2txt(stu);
        stu = stu->next;
    }

}
//����һ��ѧ����Ϣ�����ı��ļ�
void insert2txt(Stu* stu)
{
    FILE* file;
    file=fopen(stuInfo,"a");
    if (file == NULL)
    {
        printf("[insert2txt]�ļ�д�벻�ɹ�!");
        return;
    }
    fprintf(file, "%s %s %d\n", stu->stuid,stu->name, stu->num);
    fclose(file);
}

int addinfo(char* stuid, char* name,int num)
{
    if (!checkAdd(stuid))
    {
        printf("ѧ���ظ����������!\n");
        return 0;
    }
    Stu* newinfo = (Stu*)malloc(sizeof(Stu));//�½�һ���½ڵ�
    newinfo->next = NULL;
    //���½ڵ㸳ֵ
    strcpy(newinfo->stuid, stuid);
    strcpy(newinfo->name, name);
    newinfo->num = num;
    //����p�����һ���ڵ�
    Stu* p = students;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    //p�����½ڵ�
    p->next = newinfo;
    //��������Ϣ
    insert2txt(newinfo);
    return 1;
}
/*�޸�ѧ����Ϣ*/
void modify(char* stuid,char*name,int num)
{
    //�޸���Ϣ����ɾ�������
    deleteInfo(stuid);
    if(addinfo(stuid,name,num))
        printf("�޸ĳɹ�!");
    else
        printf("�޸�ʧ��!");
}

/*�ж�ѧ���Ƿ��ظ�*/
int checkAdd(char* stuid)
{
    Stu* stu = students->next;
    while (stu != NULL)
    {
        if (strcmp(stu->stuid, stuid) == 0)
            return 0;
        stu = stu->next;
    }
    return 1;
}

/*��ӡ������Ϣ*/
void showInfo(void)
{
    Stu* stu = students->next;
    while (stu!=NULL)
    {
        printf("%s %s, %d\n",stu->stuid ,stu->name, stu->num);
        stu = stu->next;
    }
    getchar();
    getchar();
}

/*����ѧ����Ϣ����ѧ��*/
Stu* findInfo(char* stuid)
{
    Stu* stu = students->next;
    while (stu != NULL)
    {
        if (strcmp(stu->stuid, stuid) == 0)
            return stu;
        stu = stu->next;
    }
    return NULL;
}

void main(void)
{
    initFromTxt();
    view(); 
}

/*�ж������Ƿ��ٷ�Χ�ڣ������ж�*/
int checkInput(char* input,int begin,int end)
{
    //�������һ���ַ���ֱ�ӷ���
    if (strlen(input) != 1)
    {
        return -1;
    }
    //�ж������ǲ��ڷ�Χ��
    if (input[0]<'0' + begin || input[0]>'0' + end)
    {
        return -1;
    }
    return input[0] - '0';
}

void view(void)
{

    while (1)
    {
        system("cls");
        printf("****************************\n");
        printf("1.����ѧ����Ϣ\n");
        printf("2.ɾ��ѧ����Ϣ\n");
        printf("3.�ı�ѧ����Ϣ\n");
        printf("4.��ѯѧ����Ϣ\n");
        printf("5.չʾѧ����Ϣ\n");
        printf("6.�˳�\n");
        printf("****************************\n");
        scanf("%s", tempInput);
        input = checkInput(tempInput,1,6);
        switch (input)
        {
        case 1:
            printf("������ѧ��,����,����(����:20151111 ���� 0)�����Կո����:\n");
            scanf("%s%s%d",tempStuid,tempName,&tempNum);
            addinfo(tempStuid, tempName, tempNum);
            break;
        case 2:
            printf("������ѧ��:");
            scanf("%s", tempStuid);
            deleteInfo(tempStuid);
            break;
        case 3:
            printf("������ѧ��:");
            break;
        case 4:
            printf("������ѧ��:");
            scanf("%s", tempStuid);
            Stu* stu= findInfo(tempStuid);
            if (stu != NULL)
            {
                printf("ѧ��:%s\n����:%s\n����:%d\n", stu->stuid, stu->name, stu->num);
            }   
            else
            {
                printf("ѧ�Ų�����!�����������");
                getchar(); getchar();
            }   
            break;
        case 5:
            showInfo();
            break;
        case 6:
            return;
            break;
        default:
            printf("�������!�����������\n");
            getchar();getchar();
            break;
        }
    }

}