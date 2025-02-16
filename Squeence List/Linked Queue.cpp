#include<cstdio>
#include<iostream>
 
using namespace std;

//定义链队列结构体
typedef struct node
{
    int data;
    struct node* next;
}Node,*pnode;
//定义头尾指针
typedef struct Linkedqueue
{
    struct node* rear;
    struct node* front;
}linkqueue;


//初始化
void init(linkqueue *q)
{

    q->rear=q->front=(node*)malloc(sizeof(node));
    if(q->front==NULL)
    {
        cout<<"申请失败"<<endl;

    }
    else
    {
        q->front->next=NULL;
    }
}
//利用尾差法将新增节点插入
void push(linkqueue* q,int n)
{
    Node* c=(Node*)malloc(sizeof(Node));
    c->data=n;
    c->next=NULL;
    q->rear->next=c;
    q->rear=c;
}
//利用头删将节点删除
void pop(linkqueue* q)
{
    if(q->front->next==NULL)
    {
        cout<<"为空"<<endl;
        return;
    }
    Node* w;
    w=q->front->next;
    int x;
    x=w->data;
    cout<<x<<endl;
    q->front->next=w->next;
    if(q->rear==w)//但链表中只剩一个节点时，删除节点后rear指向空需要指向头结点
    {
        q->rear=q->front;
    }
    free(w);
    w=NULL;
    
}


int main()
{
    linkqueue* q=(linkqueue*)malloc(sizeof(linkqueue));
    init(q);
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    push(q,5);
    push(q,6);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    return 0;
}