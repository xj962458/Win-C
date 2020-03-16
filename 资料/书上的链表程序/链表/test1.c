#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    char name[40];
    char no[18];
    int xb;
    int age;
    char tele[20];
    struct  student *next;
};


