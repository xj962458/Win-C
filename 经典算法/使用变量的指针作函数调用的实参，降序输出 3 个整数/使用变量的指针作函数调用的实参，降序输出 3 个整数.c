void exchange(int *pointer1, int *pointer2)
{	
	int temp;
	temp=*pointer1, *pointer1=*pointer2, *pointer2=temp;
}
/*������main()*/ 
void main()
{	
	int num1,num2,num3;
	/*�Ӽ��������� 3 ������*/
	printf("Input the first number: "); 
	scanf("%d", &num1);
	printf("Input the second number: "); 
	scanf("%d", &num2); 
	printf("Input the third number: "); 
	scanf("%d",&num3); 
	printf("num1=%d,num2=%d, num3=%d\n", num1, num2, num3);
	/*��� 3 �������ĳ�ֵ*/
	/*����*/
	if( num1 < num2 )	/*num1<num2*/
	exchange(  &num1, &num2);	/*ָ����ʵ�ε��ú��� exchange()������num1 ��num2 ��ֵ*/ 
	if( num1 < num3 ) 
		exchange( &num1,&num3 );
	if(num2<num3 ) 
		exchange( &num2,&num3 );
	/*���������*/
	printf("������: %d, %d, %d\n",num1,num2,num3);
}
