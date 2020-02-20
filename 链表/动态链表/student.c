#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    int num;
    int math;
};
struct Node{
    struct student data;   //������
    struct Node* next;  //ָ����
};
struct Node* createList()   //����һ������ͷ
{
    struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
    //ͨ����̬�ڴ�����ʹ�ṹ��ָ��headNode��Ϊ�ṹ�����
    //����ʹ��ǰ�����ʼ��
    //headNode->data.num=1;
    headNode->next=NULL;
    return headNode;
}
struct Node* createNode(struct student data)   //����һ��������
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//��ӡ����
void printList(struct Node* headNode)
{
    struct Node* pMove=headNode->next;
    printf("name\tnum\tmath\n");
    while(pMove)
    {
        printf("%s\t%d\t%d\n",pMove->data.name,pMove->data.num,pMove->data.math);
        pMove=pMove->next;
    }
    printf("\n");
}
//�����㣬�����������Ǹ�����������������Ƕ���
void insertNodeByHead(struct Node* headNode,struct student data)
{
    //�����µĽ��
    struct  Node* newNode=createNode(data);
    newNode->next=headNode->next;
    headNode->next=newNode;
}
//����ָ��numɾ������
void deleteNodeByAppoinNum(struct Node* headNode,int num)
{
    struct Node* posNode=headNode->next;
    struct Node* posNodeFront=headNode;
    if(posNode==NULL)
        printf("�޷�ɾ��������Ϊ��\n");
    else
    {
        while(posNode->data.num!=num)
        {
            posNodeFront=posNode;
            posNode=posNodeFront->next;
            if(posNode==NULL)
            {
                printf("û���ҵ������Ϣ���޷�ɾ��\n");
                return;
            }
        }
        posNodeFront->next=posNode->next;
        free(posNode);



    }
}
int main()
{
    struct Node* list=createList();
    struct  student info;
    while(1)
    {
        printf("������ѧ��������    ѧ��    ��ѧ�ɼ���\n");
        scanf("%s %d %d",&info.name,&info.num,info.math);
        insertNodeByHead(list,info);
        printf("continue(Y/N)?\n"); 
        setbuf(stdin,NULL);
        int choice=getchar();
        if(choice=='N'||choice=='n')
            break;
    }
    printList(list);
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%d",&info.num);
    deleteNodeByAppoinNum(list,info.num);
    printList(list);
    system("pause");
    return 0;
}