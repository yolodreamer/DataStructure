#include<cstdio>
#include<iostream>

using namespace std;

//定义最大值为10
#define MAX 10

//定义循环队列结构体
typedef struct queue
{  
    int* data;//指针模拟数组
    int front;
    int rear;
}queue,*Queue;

//初始化循环队列
Queue initqueue()
{
   queue* q=(queue*)malloc(sizeof(queue));
   q->data=(int*)malloc(sizeof(int)*MAX);
   q->front=q->rear=0;
   return q;
}

//入队
void push(Queue q,int n)
{
    if(q->front==(q->rear+1)%MAX)
    {
        cout<<"队列已满"<<endl;
        return;
    } 
   q->data[q->rear]=n;
   q->rear=(q->rear+1)%MAX;
}


//出队
void pop(Queue q)
{
    if(q->front==q->rear)
    {
        cout<<"队列为空"<<endl;
        return;
    }
    q->front=(q->front+1)%MAX;;
    
}

//查看队头元素
void front(Queue q)
{
    if(q->front==q->rear)
    {
        cout<<"队列为空"<<endl;
        return;
    }
   cout<<q->data[q->front]<<endl;
}

//查看队尾元素
void back(Queue q)
{
    if(q->front==q->rear)
    {
        cout<<"队列为空"<<endl;
        return;
    }
  cout<<q->data[q->rear-1]<<endl;//rear指向的是下一个元素的位置,数据是在rear-1的位置
}


int main()
{

    Queue q;
    q=initqueue();
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    push(q,5);
    back(q);
    pop(q);
    front(q);
    back(q);
    cout<<endl;
    return 0;
}