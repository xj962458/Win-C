#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int count=1;
    queue<int> q;
    for(int i=1;i<=8;i++)
        q.push(i);
    while (!q.empty())
    {
        int a;
        a=q.front();
        q.pop();
        if (count % 2 != 0) 
            q.push(a);
        else
            printf("%d ", a); 
        count++;
    }
    return 0;
}
