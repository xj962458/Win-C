#include <stdio.h>
#include <stdlib.h>
struct node
{ //������
    int data;
    struct node *next;
};
//��������
struct node *create(int Array[])
{
    int i;
    struct node *p, *pre, *head;                       //pre���浱ǰ�Ӵ����ǰ���ڵ㣬headΪͷ���
    head = (struct node *)malloc(sizeof(struct node)); //����ͷ���
    head->next = NULL;                                 //ͷ��㲻��Ҫ������ָ�����ʼֵΪNULL
    pre = head;                                        //��¼preΪhead
    for (i = 0; i <= 5; i++)
    {
        p = (struct node *)malloc(sizeof(struct node)); //�½����
        //��Array[i]�����½��Ľ����Ϊ������Ҳ������scanf����
        p->data = Array[i];
        p->next = NULL; //�½���ָ����ΪNULL
        pre->next = p;  //ǰ������ָ������Ϊ��ǰ�½��ڵ�ĵ�ַ
        pre = p;        //��pre��Ϊp,��Ϊ�¸�����ǰ�����
    }
    return head; //����ͷ���ָ��
};

//����Ԫ��
int search(struct node *head, int x)
{
    int count = 0;               //������
    struct node *p = head->next; //�ӵ�һ����㿪ʼ
    while (p != NULL)            //ֻҪû�е������β
    {
        if (p->data == x)
            count++; //��ǰ�ڵ�������Ϊx��count++
        p = p->next; //ָ���ƶ�����һ�ڵ�
    }
    return count; //���ؼ�����count
}

//������
//��a������headΪͷ���������pos��λ����
void insert(struct node *head, int pos, int a)
{
    struct node *p = head;
    for (int i = 0; i < pos - 1; i++)
        p = p->next;                                             //Pos-1��Ϊ�˵�����λ�õ�ǰһ�����
    struct node *q = (struct node *)malloc(sizeof(struct node)); //�½����
    q->data = a;                                                 //�½�����������Ϊa
    q->next = p->next;                                           //�½ڵ����һ�����ִ���Ǹ�ԭ�Ȳ���λ�õĽ��
    p->next = q;                                                 //ǰһ��λ�õĽ��ָ���½ڵ�
}

//ɾ�����
//ɾ����headΪͷ������������������Ϊb�Ľ��
void del(struct node *head, int b)
{
    //p��pre����ָ�����ָ�����ͣ�������ָ������ǽ��
    struct node *p = head->next; //p�ӵ�һ����㿪ʼö��
    struct node *pre = head;     //preʼ�ձ���p��ǰ���Ӵ����ָ��
    while (p != NULL)
    {
        if (p->data == b) //������ǡ��Ϊb��˵��Ҫɾ���˽��
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            //��������b����pre��p������һλ
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    int Array[5] = {5, 3, 6, 1, 2}, num;
    struct node *L = create(Array); //�½���������ͷָ��head
    L = L->next;                    //�ӵ�һ����㿪ʼ��������
    while (L != NULL)
    {
        printf("%d ", L->data); //���ÿ���ڵ��������
        L = L->next;
    }
    printf("��������Ҫ����������\n");
    scanf("%d", &num);
    printf("����Ҫ���ҵ�����%d����%d��\n", num, search(L, num));
    return 0;
}
