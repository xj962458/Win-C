# include <stdio.h>

// ����1!+2!+3!+...+10!  �����������۳˺��ۼӵ���Ŀ������һ��forѭ�����������۳��ۼ������ʵ�֡�
void main()
{
	int sum=0, product = 1, i;	// i: !ǰ�������
	for(i=1; i<=10; i++)
	{
		product = product * i;
		sum = sum + product ;
	}
	printf("%d \n", sum);
}