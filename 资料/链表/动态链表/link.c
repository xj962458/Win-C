#include<stdio.h>
#include<stdlib.h>

//����
struct  Data
{
    int x;      //��������
    int y;
};

//���
struct Node
{
    struct Data data;  //����
    struct Node *pnext; //ָ��
};

//����
struct List
{
    struct Node* pfront;    //��һ���ڵ��ָ��
    struct Node* prear;     //���һ���ڵ��ָ��
    struct Node  const;     //�ж��ٸ����


};

int main()
{
    int age;
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(j=i;j<=9;j++)
            printf("%d*%d=%d ",i,j,i*j);
        printf("\n");
    }
}
struct student
{
    char name[20];
    char num[20];
    float chinese;
    float math;
    float enlinsh;
};
printf("%d\n");
printf("%d\b=n 0 ");
printf("%f\")