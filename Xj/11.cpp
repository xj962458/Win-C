#include<iostream>
#include<string>
using namespace std;

int main()
{
    int a[4][4]={{1,2,4,5},{4,5,67,6},{9,4,56,4},{23,4,4,5}};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
