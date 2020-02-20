#include<stdio.h>
void main()
{
    int a=10,b=9,c;
    int *sum(int a,int b);
    printf("%d,%d\n",a,b);
    c=sum(a,b);
    printf("%d\n",c);

}

int *sum(int a,int b)
{
    int *p;
    int c;
    c=a+b;
    p=&c;
    return p;
}

/*指针函数是返回值是指针的函数，其本质是函数
返回类型标识符 *函数名称(形式参数)
{
    函数体
}

*/