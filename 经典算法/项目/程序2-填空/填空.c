#include<stdio.h>
void main()
{   
    union un
   {   
       int i;
       char c[2];
    };
    union un a;
    scanf("%c,%c",&a.c[0],&a.c[1]);
    printf("%x\n",a.i);
    printf("%x%x\n",a.c[1],a.c[0]);
}

