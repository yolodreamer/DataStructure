#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

//定义一个二叉树结构体
typedef struct BinaryTree{

    char date;
    struct BinaryTree* lnode;
    struct BinaryTree* rnode;
}Btree,*BTree;


//构造一个队列来存储节点，在层序遍历时使用
queue<BTree> q;

//初始二叉树
BTree inittree(char x)
{
    Btree* w=(Btree*)malloc(sizeof(Btree));
    if(w==NULL)
    {
        cout<<"内存分配失败"<<endl;
        return NULL;
    }
    w->date=x;
    w->lnode=w->rnode=NULL;
    return w;
}

//寻找父亲节点
BTree find(Btree* root,char fx)
{
    
    if(root->date==fx)
    {
        return root;
    }
    if(root->lnode!=NULL)
    {
        Btree* ans=find(root->lnode,fx);
        if(ans!=NULL&&ans->date==fx)
        {
            return ans;
        }
    }
    if(root->rnode!=NULL)
    {
        Btree* ans=find(root->rnode,fx);
        if(ans!=NULL&&ans->date==fx)
        {
            return ans;
        }
    }
    return NULL;
}


//二叉树的插入

void insert(Btree* root,char x,char fx,int flag)
{
    Btree* fxx=find(root,fx);
    if(fxx==NULL)
    {
        cout<<"找不到父节点"<<endl;
        return;
    }
    Btree* c=(Btree*)malloc(sizeof(Btree));
    c->date=x;
    if(flag==1)
    {
        fxx->rnode=c;
        c->lnode=c->rnode=NULL;
    }
    else if(flag==0)
    {
        fxx->lnode=c;
        c->lnode=c->rnode=NULL;
    }
}


//层序遍历
void SequenceTraversa(Btree* root)
{
    if(root==NULL)
    {
        cout<<"空树"<<endl;
        return;
    }
    q.push(root);
    //非递归版
    while(!q.empty())
    {
        Btree* z=q.front();
        q.pop();
        if(z->lnode!=NULL)
        {
            q.push(z->lnode);
        }
        if(z->rnode!=NULL)
        {
            q.push(z->rnode);
        }
        cout<<z->date<<" ";
    }
}

//先序遍历
void preorderTraversal(Btree* root)
{
    if(root!=NULL)
    {
        cout<<root->date<<" ";
    }
    if(root->lnode!=NULL)
    {
        preorderTraversal(root->lnode);
    }
    if(root->rnode!=NULL)
    {
        preorderTraversal(root->rnode);
    }
}

//中序遍历
void inorderTraversal(Btree* root)
{
    if(root->lnode!=NULL)
    {
        inorderTraversal(root->lnode);
    }
    if(root!=NULL)
    {
        cout<<root->date<<" ";
    }
    if(root->rnode!=NULL)
    {
        inorderTraversal(root->rnode);
    }
}

//后序遍历
void postorderTraversal(Btree* root)
{
     
    if(root->lnode!=NULL)
    {
        postorderTraversal(root->lnode);
    }
    if(root->rnode!=NULL)
    {
        postorderTraversal(root->rnode);
    }
    if(root!=NULL)
    {
        cout<<root->date<<" ";
    }
}
int main()
{
    Btree* root;
    int n;
    cin>>n;
    char r;
    cin>>r;
    root=inittree(r);
    for(int i=2;i<=n;i++)
    {

        char x,fx;
        int flag;
        cin>>x>>fx>>flag;
        insert(root,x,fx,flag);
    }
    cout<<"层序遍历"<<endl;
    SequenceTraversa(root);
    cout<<endl;
    cout<<"先序遍历"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"中序遍历"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"后序遍历"<<endl;
    postorderTraversal(root);

}


/*
9
A
B A 0
E A 1
C B 1
D C 0
F E 1
G F 0
H G 0
K G 1
//层序遍历
A B E C F D G H K
//先序遍历
A B C D E F G H K
//中序遍历
B D C A E H G K F
//后序遍历
D C B H K G F E A

*/
