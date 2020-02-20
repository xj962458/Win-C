#include<stdio.h>
void main()
{
    int a=9,b=10;
    int sum(int a,int b);
    int (*p)(int a,int b);
    p=sum;
    printf("%d,%d\n",a,b);
    printf("%d\n",sum(a,b));
    printf("%d\n",p(a,b));
}
int sum(int a,int b)
{
    return a+b;
}

//函数指针是指向函数的指针变量，其本质是一个指针变量，用指针可以调用函数
//返回值类型标识符 (*指针变量名)(形参);
/*1、声明函数
  2、声明函数指针
  3、把函数首地址付给函数指针变量
  注意，函数指针是建立在已经定义声明好的函数上的，所以函数指针没有函数体，只有函数指针声明*/