# include <stdio.h>

void main()
{
	// δ֪λ���Ĳ��������
	int x, gw, k=0;
	scanf("%d", &x);
	while(x)
	{
		gw = x%10;
		k = k*10 + gw;	// �������
		x = x/10;
	}
	printf("%d \n", k);
}