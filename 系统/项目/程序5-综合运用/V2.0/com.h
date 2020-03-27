#include<stdio.h>
#define N 5

//定义第一题改错中的结构体类型
struct student1
{  
    int num;
    char name[20];
    int score;
};

//定义第四五题中的结构体类型
struct student2 
{
	int num;
	char name[30];
	int score[3];
};

//自定义四五题中用到的数据类型
typedef struct student2 stu;

//所有函数的原型声明放在此处
void correct();		//第1题--改错
void fill();		//第2题--填空
void verification();	//第3题--验证	
void program_1();		//第4题--编程
void program_2();		//第5题--编程输出txt文件
void input(stu* p);		//输入
void print(stu* p);		//输出
void xprint(stu* p ,FILE *fp);	//输出至文本文件
double aver(stu* p);			//计算平均分
int excellect(stu* p);			//判断最高分,返回下标
void menu();                    //输出菜单

