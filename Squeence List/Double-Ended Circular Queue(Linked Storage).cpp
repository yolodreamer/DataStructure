#include<stdio.h>
#include<iostream>


using namespace std;

typedef struct  Node
{
    int data;
    struct  Node* next;
    struct  Node* pre;
}node;
//左右指针标记左右插入和删除
node*l;
node*r;

//初始化双链表节点，对左右指针进行初始化
void init()
{
    node* q=(node*)malloc(sizeof(node));
    q->next=q->pre=NULL;
    l->next;
    l=r=q;
}

//左端插入
void left_push(int x)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    l->next=n;
    n->pre=l;
    l=n;

}

//右端插入
void right_push(int x)
{
   node* n=(node*)malloc(sizeof(node));
   r->data=x;
   r->pre=n;
   n->next=r;
   r=n;
   r->pre=NULL;
}

//左端删除
void left_pop()
{
    if(l==r)
    {
        cout<<"该队列为空"<<endl;
        return;
    }
    node* p;
    p=l;
    l=l->pre;
    p->pre=NULL;
    cout<<p->data<<endl;
    free(p);
    p=NULL;
}

//右端删除
void right_pop()
{
     if(l==r)
    {
        cout<<"该队列为空"<<endl;
        return;
    }
    node* p=r;
    r=r->next;  
    cout<<r->data<<endl;
    p->pre=NULL;
    free(p);
    p=NULL;
}
//遍历整个队列，打印输出
void prt()
{
    node* q=l;
    while(q!=r)
    {
        cout<<q->data<<" ";
        q=q->pre;
    }
}

int main()
{
    init();
    left_push(1);
    left_push(2);
    right_push(3);
    right_push(4);
    right_push(5);
    prt();
    left_pop();
    right_pop();
    right_pop();
    right_pop();
    prt();
    return 0;
}