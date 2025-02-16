#include<cstdio>
#include<iostream>


using namespace std;

#define maxx 10

//定义一个循环结构体
typedef struct queue
{
    int* data;
    int left;
    int right;
    int sum;
}Queue,*deque;

//对整个循环队列进行初始化
deque init()
{
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->data=(int*)malloc(sizeof(int)*maxx);
    q->left=q->right=0;
    q->sum=0;
    return q;
}

//左端插入
void left_push(Queue* q,int x)
{
    if(q->sum==maxx)
    {
        cout<<"队列满"<<endl;
        return;
    }
    q->left=(q->left-1+maxx)%maxx;
    q->data[q->left]=x;
    q->sum++;
}

//左端删除
void left_pop(Queue* q)
{
    if(q->sum==0)
    {
        cout<<"队空，无法删除"<<endl;
        return;
    }
    cout<<q->data[q->left]<<endl;
    q->left=(q->left+1)%maxx;
    
    q->sum--;
}

//右端插入
void right_push(Queue* q,int x)
{
    if(q->sum==maxx)
    {
        cout<<"队列满"<<endl;
        return;
    }
    q->data[q->right]=x;
    q->right=(q->right+1)%maxx;
    q->sum++;
}

//右端删除
void right_pop(Queue* q)
{
    if(q->sum==0)
    {
        cout<<"队空，无法删除"<<endl;
        return;
    }
    int c;
    q->right=(q->right-1+maxx)%maxx;
    c=q->data[q->right];
    cout<<c<<endl;
    q->sum--;
}

int main()
{
    deque q;
    q=init();
    right_push(q,1);
    right_push(q,2);
    right_push(q,3);
    right_push(q,4);
    right_push(q,5);
//     left_push(q,9);
//     left_push(q,8);
//     left_push(q,7);
//     left_push(q,6);
//     left_push(q,5);
    left_pop(q);
    left_pop(q);
    left_pop(q);
    left_pop(q);
    left_pop(q);
//    right_pop(q);
//    right_pop(q);
//    right_pop(q);
//    right_pop(q);
//    right_pop(q);
//    right_pop(q);
//    
    return 0;
}



