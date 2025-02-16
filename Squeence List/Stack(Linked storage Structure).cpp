#include<cstdio>
#include<iostream>

using namespace std;

//定义链式结构体
typedef struct stack
{
    int val;
    stack* next;
}stack,*Stack;

//初始化一个带头结点单链表
stack* initstack()
{
    Stack t=(stack*)malloc(sizeof(stack));//t是该链表的头结点
    t->next=NULL;
}

//利用头插法插入节点
void push(stack* head,int n)
{
    stack* c=(stack*)malloc(sizeof(stack));
    c->val=n;
    c->next=head->next;
    head->next=c;
}

//删除头结点即出栈
void pop(stack* head)
{
    if(head->next==NULL)
    {
        printf("栈为空");
    }
    stack* w;
    w=head->next;
    head->next=w->next;
    w->next=NULL;
    free(w);
}
//查看栈顶元素
void top(stack* head)
{
     if(head->next==NULL)
    {
        printf("栈为空");
    }

        printf("%d\n",head->next->val);
        
    
}

int main()
{
    Stack t;
    t=initstack();
    push(t,1);
    push(t,2);
    push(t,3);
    push(t,4);
    push(t,5);
    push(t,6);
    top(t);
    pop(t);
    top(t);

    return 0;
}