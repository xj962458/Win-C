#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int temp, hh;
typedef struct
{
	char stu_name[40];
	int stu_id;
	char stu_clas[40];
	double stu_cj1;
	double stu_cj2;
	double stu_cj3;
	double stu_cj4;
	double stu_cj5;
	double avg_grade;
} student;
student all_stu[200], a[200];
int stu_number = 0;

int main()
{
	//system("color f0");
	void first();
	void secend();
	void third();
	void fourth();
	void fifth();
	void sixth();
	void seventh();
	void TC();
	void DQ();
	int option;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t=====================ѧ���ɼ�����ϵͳ==================\n");
		printf("\t\t* ���ߣ�***  �༶��**** ѧ�ţ�********      *\n");
		printf("\t\t*                                                     *\n");
		printf("\t\t*          1>. ����ѧ���ɼ�                           *\n");
		printf("\t\t*          2>. ��ʾѧ���ɼ�                           *\n");
		printf("\t\t*          3>. �鿴ѧ���ɼ�                           *\n");
		printf("\t\t*          4>. ɾ��ѧ���ɼ�                           *\n");
		printf("\t\t*          5>. �޸�ѧ���ɼ�                           *\n");
		printf("\t\t*          6>. ����ѧ����Ϣ                           *\n");
		printf("\t\t*          7>. ƽ���ɼ�����                           *\n");
		printf("\t\t*          8>. ��ȡ�ĵ���Ϣ                           *\n");
		printf("\t\t*          0>. �˳�����ϵͳ                           *\n");
		printf("\t\t*                                    ��ӭʹ�ñ�ϵͳ�� *\n");
		printf("\t\t=======================================================\n");
		printf("\t\t����ѡ����س�����ѡ��: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			first();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 2:
			third();
			getchar();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 3:
			secend();
			getchar();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 4:
			fourth();
			getchar();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 5:
			fifth();
			getchar();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 6:
			sixth();
			printf("\n\n\n�ѽ��������ѧ����Ϣ�浵���ף��Һ�Ŭ���ļ�ס���ϡ�");
			getchar();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 7:
			seventh();
			getchar();
			printf("\n\n\n===============================================================================");
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 8:
			DQ();
			printf("\n���꣬�밴������������˵�\n");
			getchar();
			system("cls");
			break;
		case 0:
			TC();
			printf("\n\n\n\n\n\n\n\n\t\t\t        ��л����ʹ��.\n\n\n\t     ��ϵͳ���ߣ���Ӣ��  �༶��Java(2) ѧ�ţ�621413530204  \n\n    \t        ���о���ϵͳ�ܺ��ã��ǵ�������ĬĬ�������ϣ�\n\n\t\t\tôô��~~�밴������˳���\n");
			getchar();
			exit(0);
			;
			break;
		}
	} while (option);

	return 0;
}

void first()
{
thefirst:
	system("cls");
	printf("********************************����ѧ����Ϣ*********************************");
	printf("\n\n");
	int cw, cx, temp, hh;
	char op;
	printf("\n>>>>>>>>����������: ");
	scanf("%s", all_stu[stu_number].stu_name);
	printf("\n>>>>>>>>������ѧ��: ");
	scanf("%d", &temp);
	all_stu[stu_number].stu_id = temp;
	getchar();
	for (cx = 0; cx < stu_number; cx++)
	{
		if (all_stu[stu_number].stu_id == all_stu[cx].stu_id)
		{
			printf("ѧ����������������������밴(Y)�˳��밴(N)");
			cw = getchar();
			if (cw == 'y' || cw == 'Y')
				goto thefirst;
			else
				goto thefirstend;
		}
	}
	printf("\n>>>>>>>>������༶�� ");
	scanf("%s", all_stu[stu_number].stu_clas);
	printf("\n>>>>>>>>�������һ�ųɼ�(С�ڵ���100)�� ");
	scanf("%lf", &all_stu[stu_number].stu_cj1);
	if (all_stu[stu_number].stu_cj1 > 100)
	{
		printf("����������������ȷ�ĳɼ���Ϣ���밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefirst;
	}
	printf("\n>>>>>>>>������ڶ��ųɼ�(С�ڵ���100)�� ");
	scanf("%lf", &all_stu[stu_number].stu_cj2);
	if (all_stu[stu_number].stu_cj2 > 100)
	{
		printf("����������������ȷ�ĳɼ���Ϣ���밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefirst;
	}
	printf("\n>>>>>>>>����������ųɼ�(С�ڵ���100)�� ");
	scanf("%lf", &all_stu[stu_number].stu_cj3);
	if (all_stu[stu_number].stu_cj3 > 100)
	{
		printf("������������������ȷ�ĳɼ���Ϣ����(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefirst;
	}
	printf("\n>>>>>>>>����������ųɼ�(С�ڵ���100)�� ");
	scanf("%lf", &all_stu[stu_number].stu_cj4);
	if (all_stu[stu_number].stu_cj4 > 100)
	{
		printf("����������������ȷ�ĳɼ���Ϣ���밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefirst;
	}
	printf("\n>>>>>>>>����������ųɼ�(С�ڵ���100)�� ");
	scanf("%lf", &all_stu[stu_number].stu_cj5);
	if (all_stu[stu_number].stu_cj5 > 100)
	{
		printf("����������������ȷ�ĳɼ���Ϣ���밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefirst;
	}
	hh = (all_stu[stu_number].stu_cj1 + all_stu[stu_number].stu_cj2 + all_stu[stu_number].stu_cj3 + all_stu[stu_number].stu_cj4 + all_stu[stu_number].stu_cj5) / 5;
	all_stu[stu_number].avg_grade = hh;
	printf("\n>>>>>>>>>>ƽ��ֵΪ__: ");
	printf("%.2lf", all_stu[stu_number].avg_grade);

	stu_number++;
thefirstone:
	printf("\n�Ƿ�������룬�����밴(Y),���밴(N): ");
	getchar();
	scanf("%c", &op);
	if (op == 'y' || op == 'Y')
		goto thefirst;
	if (op == 'n' || op == 'N')
		goto thefirstend;
	else
		goto thefirstone;
	getchar();
thefirstend:;
	getchar();
}

void secend()
{
thesecend:
	system("cls");
	printf("\n\n**************************��ʾѧ���ɼ�*************************");
	int num, cw, cx, ai, i = 0;
	char op;
	printf("\n>>>>>>>>������Ҫ����ѧ����ѧ��: ");
	scanf("%d", &num);
	for (ai = 0; ai < stu_number; ai++)
	{
		if (num = all_stu[ai].stu_id)
		{
			i = 1;
			break;
		}
	}
	if (i == 0)
	{
		printf("δ���ҵ���ѧ�ţ�������˰� = =..�Ƿ�Ҫ��������ѽ����~~����Ҫ�밴(Y)���粻��Ҫ�밴(N)���������˵�: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thesecend;
		if (cw == 'n' || cw == 'N')
			goto thesecendend;
	}
	else
	{

		printf("\n***************************************************************************");
		printf("\n*����___: ");
		printf("%s", all_stu[ai].stu_name);
		printf("\n*ѧ��___: ");
		printf("%d", all_stu[ai].stu_id);
		printf("\n*�༶___: ");
		printf("%s", all_stu[ai].stu_clas);
		printf("\n*�ɼ�һ_: ");
		printf("%.2lf", all_stu[ai].stu_cj1);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj2);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj3);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj4);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj5);
		printf("\n*ƽ���ɼ�___: ");
		printf("%.2lf", all_stu[ai].avg_grade);
		printf("\n***************************************************************************");
	}
thesecendone:
	getchar();
	printf("\n\n��~Ҫ��Ѱ�óɼ���Ϣ����ʾ���Ƿ�������ģ�\n��Ҫ�밲(Y),�粻��Ҫ�밲(N)��������������__: ");
	scanf("%c", &op);
	if (op == 'y' || op == 'Y')
		goto thesecend;
	if (op == 'n' || op == 'N')
		goto thesecendend;
	else
		goto thesecendone;
thesecendend:;
}

void third()
{
thethird:
	system("cls");
	printf("\n\n**************************��ʾѧ����Ϣ*********************************");
	int n = 0;
	printf("\n\n>>����");
	printf("\tѧ��");
	printf("\t�༶");
	printf("\t�ɼ�һ");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\tƽ��ֵ");
	//for (n=0;n<stu_number;n++);
	do
	{
		printf("\n>>%s", all_stu[n].stu_name);
		printf("\t%d", all_stu[n].stu_id);
		printf("\t%s", all_stu[n].stu_clas);
		printf("\t%.2lf", all_stu[n].stu_cj1);
		printf("\t%.2lf", all_stu[n].stu_cj2);
		printf("\t%.2lf", all_stu[n].stu_cj3);
		printf("\t%.2lf", all_stu[n].stu_cj4);
		printf("\t%.2lf", all_stu[n].stu_cj5);
		printf("\t%.2lf", all_stu[n].avg_grade);
		n++;
	} while (n < stu_number);
}

void fourth()
{
thefourth:
	system("cls");
	printf("\n\n\n\n**************************ɾ��ѧ���ɼ�************************************");
	printf("\n\n");
	int num, cw, cx, ai, i = 0;
	char op;
	printf("\n>>>>>>>>������Ҫ����ѧ����ѧ��: ");
	scanf("%d", &num);
	for (ai = 0; ai < stu_number; ai++)
	{
		if (num = all_stu[ai].stu_id)
		{
			i = 1;
			break;
		}
	}
	if (i == 0)
	{
		printf("δ���ҵ�Ҫɾ����ѧ����Ϣ���Ƿ�Ҫ�������룬��~~����Ҫ�밴(Y)���粻��Ҫ�밴(N)���������˵�: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefourth;
		if (cw == 'n' || cw == 'N')
			goto thefourthend;
	}
	else
	{
		stu_number--;
		for (; ai < stu_number; ai++)
		{
			all_stu[ai] = all_stu[ai + 1];
		}
	}
	printf("\n\n��ѧ�ŵ�ѧ���ɼ���Ϣ��ɾ����ллʹ�ñ��ι��ܣ��ǵø���Ŷ.����һ��ƽ����");
	getchar();
thefourthone:
	getchar();
	printf("\n��~Ҫɾ���ĳɼ���Ϣ��ɾ�����Ƿ������\n��Ҫ�밲(Y),�粻��Ҫ�밲(N)��������������__: ");
	scanf("%c", &op);
	if (op == 'y' || op == 'Y')
		goto thefourth;
	if (op == 'n' || op == 'N')
		goto thefourthend;
	else
		goto thefourthone;
thefourthend:;
}

void fifth()
{
thefifth:
	system("cls");
	printf("**************************�޸�ѧ���ɼ�*************************");
	printf("\n\n");
	int num, cw, cx, ai, i = 0, cy, team;
	char op;
	printf("\n>>>>>>>>������Ҫ����ѧ����ѧ��: ");
	scanf("%d", &num);
	for (ai = 0; ai < stu_number; ai++)
	{
		if (num = all_stu[ai].stu_id)
		{
			i = 1;
			break;
		}
	}
	if (i == 0)
	{
		printf("δ���ҵ�Ҫ�޸ĵ�ѧ����Ϣ���Ƿ�Ҫ�������룬����Ҫ�밴(Y)���粻��Ҫ�밴(N)���������˵�: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefifth;
		if (cw == 'n' || cw == 'N')
			goto thefifthend;
	}
	else
	{

		printf("***************************************************************************");
		printf("\n*����___: ");
		printf("%s", all_stu[ai].stu_name);
		printf("\n*ѧ��___: ");
		printf("%d", all_stu[ai].stu_id);
		printf("\n*�༶___: ");
		printf("%s", all_stu[ai].stu_clas);
		printf("\n*�ɼ�һ_: ");
		printf("%.2lf", all_stu[ai].stu_cj1);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj2);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj3);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj4);
		printf("\n*�ɼ���_: ");
		printf("%.2lf", all_stu[ai].stu_cj5);
		printf("\n***************************************************************************");
	}
	getchar();
	printf("\n\n�Ƿ�ȷ���޸Ĵ�ѧ���ɼ���Ϣ��(ע���޸ĺ󽫲��ɻ�ԭ)�����޸��밲(Y)���粻���޸�ѧ����Ϣ�밲(N)����__: ");
thefifthone:
	cw = getchar();
	if (cw == 'y' || cw == 'Y')
		goto thefifthtwo;
	if (cw == 'n' || cw == 'N')
		goto thefifthend;
	else
		goto thefifthone;
thefifthtwo:
	system("cls");
	printf("\n>>>>>>>>����������: ");
	scanf("%s", all_stu[ai].stu_name);
	printf("\n>>>>>>>>������ѧ��: ");
	scanf("%d", &temp);
	all_stu[ai].stu_id = temp;
	getchar();
	for (cy = 0; cy < ai; cy++)
	{
		if (all_stu[ai].stu_id == all_stu[cy].stu_id)
		{
			printf("ѧ����������������������밴(Y)�˳��밴(N)");
			cw = getchar();
			if (cw == 'y' || cw == 'Y')
				goto thefifthtwo;
			else
				goto thefifthend;
		}
	}
	printf("\n>>>>>>>>������༶�� ");
	scanf("%s", all_stu[ai].stu_clas);
	printf("\n>>>>>>>>�������һ�ųɼ�(С��100)�� ");
	scanf("%lf", &all_stu[ai].stu_cj1);
	if (all_stu[ai].stu_cj1 > 100)
	{
		printf("���������밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefifthtwo;
	}
	printf("\n>>>>>>>>������ڶ��ųɼ�(С��100)�� ");
	scanf("%lf", &all_stu[ai].stu_cj2);
	if (all_stu[ai].stu_cj2 > 100)
	{
		printf("���������밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefifthtwo;
	}
	printf("\n>>>>>>>>����������ųɼ�(С��100)�� ");
	scanf("%lf", &all_stu[ai].stu_cj3);
	if (all_stu[ai].stu_cj3 > 100)
	{
		printf("���������밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefifthtwo;
	}
	printf("\n>>>>>>>>����������ųɼ�(С��100)�� ");
	scanf("%lf", &all_stu[ai].stu_cj4);
	if (all_stu[ai].stu_cj4 > 100)
	{
		printf("���������밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefifthtwo;
	}
	printf("\n>>>>>>>>����������ųɼ�(С��100)�� ");
	scanf("%lf", &all_stu[ai].stu_cj5);
	if (all_stu[ai].stu_cj5 > 100)
	{
		printf("���������밴(Y)��������: ");
		getchar();
		cw = getchar();
		if (cw == 'y' || cw == 'Y')
			goto thefifthtwo;
	}
	hh = (all_stu[ai].stu_cj1 + all_stu[ai].stu_cj2 + all_stu[ai].stu_cj3 + all_stu[ai].stu_cj4 + all_stu[ai].stu_cj5) / 5;
	all_stu[ai].avg_grade = hh;
	printf("\n>>>>>>>>>>ƽ��ֵΪ__: ");
	printf("%.2lf", all_stu[ai].avg_grade);
	getchar();
	printf("\n\n");
	printf("\n OK ��ѧ���ɼ���Ϣ���޸���ɣ���л����ʹ�á�");
thefifthfanhui:
	getchar();
	printf("\n��~Ҫ�޸ĵĳɼ���Ϣ���޸ģ��Ƿ������\n��Ҫ�밲(Y),�粻��Ҫ�밲(N)��������������__: ");
	scanf("%c", &op);
	if (op == 'y' || op == 'Y')
		goto thefifth;
	if (op == 'n' || op == 'N')
		goto thefifthend;
	else
		goto thefifthfanhui;
thefifthend:;
}

void sixth()
{
thesixth:
	system("cls");
	printf("\n\n\n\t**************************�������������*************************");
	int i = 0;
	FILE *fp;
	if ((fp = fopen("stu_dat.txt", "wb")) == NULL)
	{
		printf("�޷��򿪵Ĳ���!");
		return;
	}

	//for(i=0;i<stu_number;i++)
	do
	{
		printf("\n\n���β�����Ϊ���������������ѧ���ɼ���Ϣ�浵��\n\n�밴��������д浵���һ�Ŭ����ס�ģ���");
		getchar();
		fprintf(fp, "%s", all_stu[i].stu_name);
		fprintf(fp, "%d", all_stu[i].stu_id);
		fprintf(fp, "%s", all_stu[i].stu_clas);
		fprintf(fp, "%lf", all_stu[i].stu_cj1);
		fprintf(fp, "%lf", all_stu[i].stu_cj2);
		fprintf(fp, "%lf", all_stu[i].stu_cj3);
		fprintf(fp, "%lf", all_stu[i].stu_cj4);
		fprintf(fp, "%lf", all_stu[i].stu_cj5);
		fprintf(fp, "%lf", all_stu[i].avg_grade);
		i++;
	} while (i < stu_number);
	fclose(fp);
	fflush(stdin);
	getchar();
}

void seventh()
{
theseventh:
	system("cls");
	printf("\n\n**************************�鿴ѧ��ƽ���ɼ�����*********************************");
	int i;
	int t = 1;
	int j;
	printf("%d", stu_number);
	for (i = stu_number - 1; i > 0; i--)
		for (j = 0; j < i; j++)
		{
			if (all_stu[j].avg_grade > all_stu[j + 1].avg_grade)
			{
				a[t] = all_stu[j];
				all_stu[j] = all_stu[j + 1];
				all_stu[j + 1] = a[t];
			}
		}
	printf("\n\n>>����");
	printf("\tѧ��");
	printf("\t�༶");
	printf("\t�ɼ�һ");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\tƽ��ֵ");
	for (i = 0; i < stu_number; i++)
	//do
	{
		printf("\n>>%s", all_stu[i].stu_name);
		printf("%d", all_stu[i].stu_id);
		printf("%s", all_stu[i].stu_clas);
		printf("%.2lf", all_stu[i].stu_cj1);
		printf("%.2lf", all_stu[i].stu_cj2);
		printf("%.2lf", all_stu[i].stu_cj3);
		printf("%.2lf", all_stu[i].stu_cj4);
		printf("%.2lf", all_stu[i].stu_cj5);
		printf("%.2lf", all_stu[i].avg_grade);
		//i++;
	} //while(i<stu_number);

	// printf(">>%s \t %d \t %s\t  %.2f\t  %.2f\t  %.2f\t %.2f\t  %.2f\t  %.2f \n",a[i].stu_name,a[i].stu_id,a[i].stu_clas,a[i].stu_cj1,a[i].stu_cj2,a[i].stu_cj3,a[i].stu_cj4,a[i].stu_cj5,a[i].avg_grade);

theseventhend:;
}

void TC()
{
	system("cls");
	getchar();
}

void DQ()
{
	system("cls");
	printf("\n\n**************************��ȡ�ĵ���Ϣ*********************************");
	getchar();
	student a[200], p;
	int n, i = 0;
	FILE *fp;
	if ((fp = fopen("stu_dat.txt", "rb")) == NULL)
	{
		printf("���ļ�ʧ�ܣ���鿴�ļ����Ƿ���ȷ��\n");
		getchar();
		goto theDQend;
	}
	for (n = 0; !feof(fp); n++)
	//do
	{
		fscanf(fp, "%s", a[n].stu_name);
		fscanf(fp, "%d", a[n].stu_id);
		fscanf(fp, "%s", a[n].stu_clas);
		fscanf(fp, "%f", a[n].stu_cj1);
		fscanf(fp, "%f", a[n].stu_cj2);
		fscanf(fp, "%f", a[n].stu_cj3);
		fscanf(fp, "%f", a[n].stu_cj4);
		fscanf(fp, "%f", a[n].stu_cj5);
		fscanf(fp, "%f", a[n].avg_grade);
		//n++;
	} //while(!feof(fp));
	fclose(fp);
	printf("\tѧ��");
	printf("\t�༶");
	printf("\t�ɼ�һ");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\t�ɼ���");
	printf("\tƽ��ֵ");
	for (i = 0; i < n; i++)
	//do
	{
		printf("\n%s", a[i].stu_name);
		printf("%d", a[i].stu_id);
		printf("%s", a[i].stu_clas);
		printf("%10.2f", a[i].stu_cj1);
		printf("%10.2f", a[i].stu_cj2);
		printf("%10.2f", a[i].stu_cj3);
		printf("%10.2f", a[i].stu_cj4);
		printf("%10.2f", a[i].stu_cj5);
		printf("%.2f", a[i].avg_grade);
		//i++;
	} //while(i<n);
theDQend:;
}
