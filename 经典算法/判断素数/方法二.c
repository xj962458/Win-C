#include <stdio.h>
#include <math.h>
void main()
{
    int m;  // ��������� 
    int i;  // ѭ������
    int k;  // m ��ƽ���� 
    printf("����һ��������");
    scanf("%d",&m);
    // ��ƽ������ע��sqrt()�Ĳ���Ϊ double ���ͣ�����Ҫǿ��ת��m������ 
    k=(int)sqrt( (double)m );
    for(i=2;i<=k;i++)
        if(m%i==0)
            break;
    // ����������ѭ������ômΪ����
    // ע�����һ��ѭ������ִ��i++����ʱ i=k+1��������i>k 
    if(i>k)
        printf("%d��������\n",m);
    else
        printf("%d����������\n",m);
}