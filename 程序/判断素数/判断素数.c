# include <stdio.h>

// isPrime1: ���n����������ֵ1�����򷵻�ֵ0
int isPrime1(int n)
{
	int chushu;
	for(chushu=2; chushu<=n-1; chushu++)
	{
		if(n%chushu == 0)
		{
			return 0;
		}
	}
	return 1;
}

// �޷���ֵ�����n�������������n�������������������n�Ǻ�����
void isPrime2(int n)
{
	int chushu;
	for(chushu=2; chushu<=n-1; chushu++)
	{
		if(n%chushu==0)
		{
			// ���n�ܱ�chushu������nһ���Ǻ�����û��Ҫ����ѭ����ȥ
			break;
		}
	}
	if(chushu==n)	// ֻ��n������ʱ��forѭ���Ż�����������������break��ǰ����������������for��chushu���õ���n
	{
		printf("%d ������\n", n);
	}
	else
	{
		printf("%d �Ǻ���\n", n);
	}
}

void main()
{
	int x;
	scanf("%d", &x);
	// ����isPrime1
	if(isPrime1(x))
	{
		printf("����\n");
	}
	else
	{
		printf("����\n");
	}

	// ����isPrime2
	isPrime2(x);
}