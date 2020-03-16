#include <stdio.h>
#include <string.h>
struct student
{  
    int num;
    char name[20];
    int score;
};
void main()
{
    struct student stud[5];
    int i,n=0;
    for(i=0;i<5;i++)
    {
        printf("Input NO.%d num: ",i+1);
        scanf("%d",&stud[i].num);
        printf("Input NO.%d name: ",i+1);
        scanf("%s",stud[i].name);
        printf("Input NO.%d score: ",i+1);
        scanf("%d",&stud[i].score);
    }
    printf("num\tname\t\tscore\n");
    i=0;
    while(i<5)
    {
        if(stud[i].score<60)
        {
            printf("%d\t%-15s\t%d\n",stud[i].num,stud[i].name,stud[i].score);
            n++;
        }
        i++;
    }
    printf("n=%d\n",n);
}
