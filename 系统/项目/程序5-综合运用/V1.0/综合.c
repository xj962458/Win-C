#include<stdio.h>
#define N 5

//�����һ��Ĵ��еĽṹ������
struct student1
{  
    int num;
    char name[20];
    int score;
};

//������������еĽṹ������
struct student2 
{
	int num;
	char name[30];
	int score[3];
};

//�Զ������������õ�����������
typedef struct student2 stu;

//���к�����ԭ���������ڴ˴�
void correct();		//��1��--�Ĵ�
void fill();		//��2��--���
void verification();	//��3��--��֤	
void program_1();		//��4��--���
void program_2();		//��5��--������txt�ļ�
void input(stu* p);		//����
void print(stu* p);		//���
void xprint(stu* p ,FILE *fp);	//������ı��ļ�
double aver(stu* p);			//����ƽ����
int excellect(stu* p);			//�ж���߷�,�����±�


void main()	//������
{
	int item;
	while(1)
	{
		int item;
		system("cls");
		printf("���ڲ˵�:\n");
		printf("��1��--�Ĵ�\n");
		printf("��2��--���\n");
		printf("��3��--��֤\n");
		printf("��4��--���\n");
		printf("��5��--�������ı��ļ�\n");
	
	
		printf("��������Ӧ�����֣�������Ӧ�ĳ���\n");
		scanf("%d",&item);
	  	switch(item)
		{
			case 1:
				correct();
				getchar();getchar();
				break; 
			case 2:
				fill();
				getchar();getchar();
				break;
			case 3:
				verification();
				getchar();getchar();
				break;
			case 4:
				program_1();
				getchar();getchar();
				break;
			case 5:
				program_2();
				getchar();getchar();
				break; 
			case 0:
				exit(0);
				printf("�������\n");
				getchar();getchar();
				break;
			default :
				printf("\n\n����������,����������!!\n");
				getchar();getchar();
				break;
			
		}
	}
}
void correct()	//��1��--�Ĵ�
{
	struct student1 stud[5];
	int i,n=0;
	for(i=0;i<5;i++)
	{
      printf("Input NO.%d num: ",i+1);
      scanf("%d",&stud[i].num);
      printf("Input NO.%d name: ",i+1);
      scanf("%s",stud[i].name);
      printf("Input NO.%d score: ",i+1);
      scanf("%d",&stud[i].score);
	}
    printf("num\tname\t\tscore\n");
    i=0;
    while(i<5)
    {
        if(stud[i].score<60)
        {
            printf("%d\t%-15s\t%d\n",stud[i].num,stud[i].name,stud[i].score);
            n++;
        }
        i++;
    }
    printf("n=%d\n",n);
}

void fill()		//��2��--���
{ 
    union un
   {   
       int i;
       char c[2];
    };
    union un a;
	printf("�����������ַ�\n");
    scanf("%c,%c",&a.c[0],&a.c[1]);
    printf("%x\n",a.i);
    printf("%x%x\n",a.c[1],a.c[0]);
}

void verification()		//��3��--��֤
{
	
	    int a,b;
	    a=2,b=3;
	    printf("%d\n",a^b>>2);
		a=a>>2;
	    b=b<<3;
	    printf("%d,%d \n",a,b);
}

void program_1()	//��4��--���
{
	int i,n;
	stu a[N];
	stu* p = a;
	input(p);
	printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	for (i = 0; i < N; i++) 
	{
		print(p + i);
		printf("%.1f\n", aver(p + i));
	}
	printf("��߷ֵ�ѧ����������\nѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	n = excellect(p);
	print(p + n);
	printf("%.1f\n", aver(p + n));
}

void program_2()	//��5��--������txt�ļ�
{
	FILE *fp;
	int i,n;
	stu a[N];
	stu* p = a;
	fp=fopen("xjt.txt","w");
	input(p);
	fprintf(fp,"ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	for (i = 0; i < N; i++) {
		xprint(p + i,fp);
		fprintf(fp,"%.1f\n", aver(p + i));
	}
	fprintf(fp,"��߷ֵ�ѧ����������\nѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ��\n");
	n =excellect(p);
	xprint(p + n,fp);
	fprintf(fp,"%.1f\n", aver(p + n));
	fclose(fp);
}

void input(stu* p)	//����
{
	int i,j;
	for (i = 0; i < N; ++i) {
		printf("�������%d��ѧ������Ϣ\n", i + 1);
		printf("������num\n");
		scanf("%d", &(p + i)->num);
		printf("����������\n");
		scanf("%s", &(p + i)->name);
		for (j = 0; j < 3; ++j) {
			printf("������score%d\n", j + 1);
			scanf("%d", &(p + i)->score[j]);
		}
	}
}

void print(stu* p)	//���
{
	int j;
	printf("%d\t", p->num);
	printf("%s\t", p->name);
	for (j = 0; j < 3; ++j) {
		printf("%d\t", p->score[j]);
	}
}


void xprint(stu* p ,FILE *fp)	//������ı��ļ�
{
	int j;
	fprintf(fp,"%d\t", p->num);
	fprintf(fp,"%s\t", p->name);
	for (j = 0; j < 3; ++j) {
		fprintf(fp,"%d\t", p->score[j]);
	}
}


double aver(stu* p)		//����ƽ����
{
	int i;
	double sum = 0;
	for (i = 0; i < 3; ++i)
	{
		sum += p->score[i];
	}
	return sum / 3;
}


int excellect(stu* p)	//�ж���߷�,�����±�
{
	int i,j;
	double sum = 0;
	double max = 0;
	int record = 0;
	for (i = 0; i < N; ++i) {
		sum = 0;
		for (j = 0; j < 3; ++j) {
			sum += (p + i)->score[j];
		}
		if (max < sum) {
			max = sum;
			record = i;
		}
	}
	return record;
}








