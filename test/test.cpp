#include<iostream>
#include<string>
#include<random>
using namespace std;
typedef int ElemType;
const int MaxSize=10;

class Queue{
    public:
        Queue();
        void EnQueue(ElemType e);
        void DnQueue(ElemType &e);
        bool QueueEmpty();
    private : 
        int data[MaxSize];
        int front,rear;
};

Queue::Queue(){
    front=rear=-1;
}

void Queue::EnQueue(ElemType e){
    if(front==MaxSize-1)
        return;
    front++;
    data[front]=e;
}

void Queue::DnQueue(ElemType &e){
    if(rear==MaxSize-1)
        return;
    rear++;
    data[rear]=e;
}

bool Queue::QueueEmpty()
{
    return (front==rear);
}
int main()
{
    Queue q;
    int e,i=0;
    for(i=0;i<100;i++)
        q.EnQueue(i);
    while(i!=0){
        q.DnQueue(e);
        cout<<e;
        i--;
    }
    return 0;
}
