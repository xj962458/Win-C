// շת����������Լ��
# include <stdio.h>

void main()
{
	int x, y, t, yu;
	scanf("%d %d", &x, &y);
	// շת�����Ҫ���1�������ڵ��ڵ�2����
	if(x<y)
	{
		t=x;
		x=y;
		y=t;
	}

	yu=x%y;
	while(yu)
	{
		x=y;
		y=yu;
		yu=x%y;
	}
	printf("%d\n", y);
}


