void exchange(int *pointer1, int *pointer2)
{	
	int temp;
	temp=*pointer1, *pointer1=*pointer2, *pointer2=temp;
}
/*主函数main()*/ 
void main()
{	
	int num1,num2,num3;
	/*从键盘上输入 3 个整数*/
	printf("Input the first number: "); 
	scanf("%d", &num1);
	printf("Input the second number: "); 
	scanf("%d", &num2); 
	printf("Input the third number: "); 
	scanf("%d",&num3); 
	printf("num1=%d,num2=%d, num3=%d\n", num1, num2, num3);
	/*输出 3 个变量的初值*/
	/*排序*/
	if( num1 < num2 )	/*num1<num2*/
	exchange(  &num1, &num2);	/*指针作实参调用函数 exchange()，互换num1 和num2 的值*/ 
	if( num1 < num3 ) 
		exchange( &num1,&num3 );
	if(num2<num3 ) 
		exchange( &num2,&num3 );
	/*输出排序结果*/
	printf("排序结果: %d, %d, %d\n",num1,num2,num3);
}
