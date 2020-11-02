#include<iostream>
#include<string>
using namespace std;

class Stack{
    public:
        void InitStack();
        void CreateStack(int a[],int n);
        void Push(int a);
        void Pop();
        int GetTop();
        void PrintStack();
        bool EmptyStack();
        int LengthStack();
    private:
        int data[10];
        int top;
};

void Stack::InitStack(){
    top=-1;
}

void Stack::CreateStack(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        data[top+1]=a[i];
        top++;
    }
}

void Stack::Push(int a){
    data[top+1]=a;
    top++;
}

void Stack::Pop(){
    top--;
}

int Stack::GetTop(){
    return data[top];
}

bool Stack::EmptyStack(){
    return (top==-1);
}

int Stack::LengthStack(){
    return top+1;
}

void Stack::PrintStack(){
    int x=top;
    while(top!=-1)
    {
        cout<<data[top]<<" ";
        top--;
    }
    top=x;
    cout<<endl;
}
int main()
{
    Stack *s=new Stack;
    int a[]={23,54,65,77,65,45,70,9};
    // s->InitStack();
    // cout<<(s->EmptyStack()?"空":"非空")<<endl;
    // cout<<"栈的长度:"<<s->LengthStack()<<endl;
    s->InitStack();
    s->CreateStack(a,8);
    s->PrintStack();
    cout<<s->GetTop()<<endl;
    cout<<s->GetTop()<<endl;
    cout<<"栈的长度为:"<<s->LengthStack()<<endl;
    s->Push(100);
    s->PrintStack();
    cout<<"栈的长度为:"<<s->LengthStack()<<endl;
    return 0;
}
