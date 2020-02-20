#include<stdio.h>   /*I/O函数*/
#include<stdlib.h>  /*其它说明*/
#include<string.h>  /*字符串函数*/
#define LEN 15      /* 学号和姓名最大字符数,实际请更改*/
#define N 200       /* 最大学生人数,实际请更改*/
struct record
{
    char code[LEN+1]; /* 学号*/
    char name[LEN+1]; /* 姓名*/
    int age;          /* 年龄*/
    char sex;         /* 性别*/
    float score[3];   /* 3门课程成绩*/
}stu[N];        
int k=1,n=0, m=0;/*定义全局变量， n代表当前记录的学生总人数，m为新增加的学生人数*/    
/* 函数声明*/
void help();         /* 帮助界面*/
void readfile();    /* 读入数据*/
void seek();        /* 查找信息*/
void modify();       /* 修改数据*/
void insert();       /* 插入数据*/
void del();          /* 删除数据*/
void display();       /* 显示信息*/
void save();          /* 保存信息*/
void menu();        /* 菜单*/
int main()          /* 主函数*/
{ 
    while(k)
    {
        menu();
    }
    system("pause");
    return 0;
} 
void help()      /* 帮助信息*/
{ 
    printf("\n0.欢迎使用系统帮助！\n");
    printf("\n1.初次进入系统后,请先选择增加学生信息;\n");
    printf("\n2.按照菜单提示键入数字代号;\n");
    printf("\n3.增加学生信息后,切记保存;\n");
    printf("\n4.谢谢您的使用！\n");
    system("pause");         /* 发出一个DOS命令，屏幕上输出"请按任意键继续"*/
} 
void readfile()
{
    char filename[LEN+1];             /* 文件名*/
    FILE *fp;                             /* 文件指针*/
    int i=0;
    printf("请输入以存有学生信息的文件名：\n");    
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)         /* 以只读的方式打开指定文件*/
    {
        printf("打开文件%s错误",filename);
        printf("你需要先选择菜单4增加学生信息\n");
        system("pause");
        return;
    }
     /* 循环读入学生信息*/
    while(fscanf(fp,"%s%s%d%c%f%f%f",stu[i].code,stu[i].name,&stu[i].age,&stu[i].sex,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2])==7)
    {
        i++;
    }
    n=i;
    if(0==i)
        printf("文件为空，你需要先选择菜单4增加学生信息\n");
    else
        printf("读入成功\n");
    fclose(fp);
    system("pause");
}


void seek() /*查找*/
{
    int i,item,flag;
    char s1[21]; /* 以姓名和学号最长长度+1为准*/
    printf("------------------\n");
    printf("-----1.按学号查询-----\n");
    printf("-----2.按姓名查询-----\n");
    printf("-----3.退出本菜单-----\n");
    printf("------------------\n");
    while(1)
    {
        printf("请选择子菜单编号:");
        scanf("%d",&item);
        flag=0;
        switch(item)
        {
        case 1:
            printf("请输入要查询的学生的学号:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(stu[i].code,s1)==0)
                {
                    flag=1;
                    printf("学生学号    学生姓名  年龄   性别  C语言成绩  高等数学  大学英语成绩\n");             
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6c %9.1f %10.1f %10.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
                }
                if(0==flag)
                    printf("该学号不存在！\n"); break;
        case 2:
            printf("请输入要查询的学生的姓名:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(stu[i].name,s1)==0)
                {
                    flag=1;
                    printf("学生学号    学生姓名  年龄   性别  C语言成绩  高等数学  大学英语成绩\n");             
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6c %9.1f %10.1f %10.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
                }
                    if(0==flag)
                        printf("该姓名不存在！\n"); break;
        case 3:return;
        default:printf("请在1-3之间选择\n");
        }
    }
} 


void modify() /*修改信息*/
{
    int i,item,num;                    /* item代表子菜单的编号，num是保存要修改信息的学生的序号*/
    char sex1,s1[LEN+1],s2[LEN+1]; /* 以姓名和学号最长长度+1为准*/
    float score1;
    printf("请输入要要修改的学生的学号:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(stu[i].code,s1)==0) /*比较字符串是否相等*/
            num=i;
        printf("------------------\n");
        printf("1.修改姓名\n");
        printf("2.修改年龄\n");
        printf("3.修改性别\n");
        printf("4.修改C语言成绩\n");
        printf("5.修改高等数学成绩\n");
        printf("6.修改大学英语成绩\n");
        printf("7.退出本菜单\n");
        printf("------------------\n");
        while(1)
        {
            printf("请选择子菜单编号:");
            scanf("%d",&item);
            switch(item)
            {
            case 1:
                printf("请输入新的姓名:\n");
                scanf("%s",s2);
                strcpy(stu[num].name,s2); break;
            case 2:
                printf("请输入新的年龄:\n");
                scanf("%d",stu[num].age);break;
            case 3:
                printf("请输入新的性别:\n");
                scanf("%c",&sex1);
                stu[num].sex=sex1; break;
            case 4:
                printf("请输入新的C语言成绩:\n");
                scanf("%f",&score1);
                stu[num].score[0]=score1; break;
            case 5:
                printf("请输入新的高等数学成绩:\n");
                scanf("%f",&score1);
                stu[num].score[1]=score1; break;
            case 6:
                printf("请输入新的大学英语成绩:\n");
                scanf("%f",&score1);
                stu[num].score[2]=score1; break;
            case 7: return;
            default:printf("请在1-7之间选择\n");
            }
        }
} 


void sort()/*按学号排序*/
{
    int i,j,k,*p,*q,s;
    char temp[LEN+1],ctemp;
    float ftemp;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
            if(strcmp(stu[j-1].code,stu[j].code)>0)       /*通过比较排序*/
            {
                strcpy(temp,stu[j-1].code);
                strcpy(stu[j-1].code,stu[j].code);
                strcpy(stu[j].code,temp);
                strcpy(temp,stu[j-1].name);
                strcpy(stu[j-1].name,stu[j].name);
                strcpy(stu[j].name,temp);
                ctemp=stu[j-1].sex;
            stu[j-1].sex=stu[j].sex;
                stu[j].sex=ctemp;
                p=&stu[j-1].age;
                q=&stu[j].age;
                s=*q;
                *q=*p;
                *p=s;
                for(k=0;k<3;k++)
                {
                    ftemp=stu[j-1].score[k];
                    stu[j-1].score[k]=stu[j].score[k];
                    stu[j].score[k]=ftemp;
                }
            }
    }
} 

void insert() /*插入函数*/
{
    int j=n,i,flag;

    printf("请输入待增加的学生数:\n");
    scanf("%d",&m);
    if(m>0)
    {
       do
    {
        flag=1;
        while(flag)
        {
            flag=0;
            printf("请输入第%d位学生的学号:\n",j+1);
            scanf("%s",stu[j].code);
            for(i=0;i<j;i++)                     /*与之前的学号比较，如果重复，则重新输入*/
                if(strcmp(stu[j].code,stu[i].code)==0)
                {
                    printf("已有该学号，请重新录入\n");
                    flag=1;
                    break;                       /*如有重复，退出内层循环*/
                }
        }
        printf("请输入第%d 个学生的学号:\n",j+1);
        scanf("%s",stu[j].code);
        printf("请输入第%d 个学生的姓名:\n",j+1);
        scanf("%s",stu[j].name);
        printf("请输入第%d 个学生的年龄:\n",j+1);
        scanf("%d",&stu[j].age);
        printf("请输入第%d 个学生的性别:\n",j+1);
        scanf(" %c",&stu[j].sex);
        printf("请输入第%d 个学生的C语言成绩\n",j+1);
        scanf("%f",&stu[j].score[0]);
        printf("请输入第%d 个学生的高等数学成绩:\n",j+1);
        scanf("%f",&stu[j].score[1]);
        printf("请输入第%d 个学生的大学英语成绩:\n",j+1);
        scanf("%f",&stu[j].score[2]);
        if(0==flag)
        {
            j++;
        }
    }
    while(j<n+m);
    }
    n+=m;
    printf("信息增加完毕！\n\n");
    sort();
    system("pause");
} 

void del()
{
    int i,j,flag=0;         /* flag为0表示查找失败，为1表示查找成功*/
    char s1[LEN+1];
    printf("请输入要删除学生的学号:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(stu[i].code,s1)==0)  /*找到要删除的学生记录*/
        {
            flag=1;                   /*查找成功*/
            for(j=i;j<n-1;j++)
            stu[j]=stu[j+1];

        }
        if(flag==0)                /*查找失败*/
            printf("该学号不存在！\n");
        if(flag==1)
        {
            printf("删除成功,显示结果请选择菜单\n");
            n--;
        }
    system("pause");
} 


void display()
{
    int i;
    printf("共有%d位学生的信息:\n",n);
    if(0!=n)
    {
        printf("学生学号  学生姓名 年龄  性别  C语言成绩  高等数学  大学英语成绩\n");             
        printf("--------------------------------------------------------------------\n");
        for(i=0;i<n;i++)
        { 
            printf("%7s %7s %6d %6c %9.1f %10.1f %10.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
        }
    }
    system("pause");
} 

void save()
{
    int i;
    FILE *fp;
    char filename[LEN+1];
    printf("请输入要保存该信息的文件名:\n");      /*输入要保存的文件的名字*/
    scanf("%s",filename);
    fp=fopen(filename,"w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s%s%d%c%.1f%.1f%.1f\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    printf("保存成功\n");
    fclose(fp);
    system("pause");
}


void menu()/* 界面*/
{
    int num;
    printf(" \n\n                    \n\n");
    printf("  ******************************************************\n\n");
    printf("  *                学生信息管理系统                    *\n \n");
    printf("  ******************************************************\n\n"); 
    printf("*********************系统功能菜单*************************       \n");
    printf("     ----------------------   ----------------------   \n");
    printf("     *********************************************     \n");
    printf("     * 0.系统帮助及说明  * *  1.刷新学生信息   *     \n");
    printf("     *********************************************     \n"); 
    printf("     * 2.查询学生信息    * *  3.修改学生信息   *     \n");
    printf("     *********************************************     \n");
    printf("     * 4.增加学生信息    * *  5.按学号删除信息 *     \n");
    printf("     *********************************************     \n");
    printf("     * 6.显示当前信息    * *  7.保存当前学生信息*     \n");
    printf("     ********************** **********************     \n");
    printf("     * 8.退出系统        *                            \n");
    printf("     **********************                            \n");
    printf("     ----------------------   ----------------------                           \n");
    printf("请选择菜单编号:");
    scanf("%d",&num);
    switch(num)
    { 
    case 0:help();break;
    case 1:readfile();break;
    case 2:seek();break;
    case 3:modify();break;
    case 4:insert();break;
    case 5:del();break;
    case 6:display();break;
    case 7:save();break;
    case 8:k=0;break;
    default:printf("请在0-8之间选择\n");
    }
}