#include<iostream>
#include<vector>
using namespace std;
#define N 7
int main()
{   
    bool c;
    vector<int> a(N,1);
    vector<int> b(N,2);
    c=a==b;
    a.assign(4,2);
    cout<<a.capacity()<<endl;
    cout<<a.front()<<endl;
    cout<<c<<endl;
}