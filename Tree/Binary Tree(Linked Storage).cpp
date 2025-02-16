#include<cstdio>
#include<iostream>

using namespace std;

int n;

//二叉树结构体
typedef struct BinaryTree{
    char data;
    struct BinaryTree* lnode;
    struct BinaryTree* rnode;
}Btree,*BTree;


//将根节点数据传进去初始化二叉树
BTree inittree(char r)
{
    Btree* w=(Btree*)malloc(sizeof(Btree));
    w->data=r;
    w->lnode=w->rnode=NULL;
    return w;
}

//寻找节点函数
BTree find(Btree* root,char fx)
{
    if(root->data==fx)
    {
        return root;
    }
    if(root->lnode!=NULL)
    {
        Btree* ans=find(root->lnode,fx);//保存递归调用返回的结果，经过第一个if会返回一个结果需要保存，这结果不会直接返回到下面
        if(ans!=NULL&&ans->data==fx)
        {
            return ans;
        }

    }
    if(root->rnode!=NULL)
    {
        Btree* ans=find(root->rnode,fx);
        if(ans!=NULL&&ans->data==fx)
        {
            return ans;
        }
    }
    return NULL;
}

//二叉树的插入
void insert(Btree* root,char x,char fx,int flag)
{
    Btree* f=find(root,fx);//寻找父亲节点
    if(f==NULL)
    {
        cout<<"不存在该父节点"<<endl;
        return;
    }
    Btree* c=(Btree*)malloc(sizeof(Btree));
    c->data=x;
    if(flag==1)
    {
        f->rnode=c;
        c->lnode=c->rnode=NULL;
    }
    else
    {
        f->lnode=c;
        c->lnode=c->rnode=NULL;
    }

}

int main()
{
    cin>>n;
    char r;
    cin>>r;
    Btree* root=NULL;
    root=inittree(r);

    for(int i=2;i<=n;i++)
    {
        char x,fx;
        int flag;
        cin>>x>>fx>>flag;
        insert(root,x,fx,flag);
    }
    char b;
    getchar();
	scanf("%c",&b);
	Btree* p=find(root,b); 
	if(p!=NULL)
	{
		if(p->lnode!=NULL)
		{
			printf("左%c\n",p->lnode->data );
		}
		if(p->rnode !=NULL)
		{
			printf("右%c\n",p->rnode ->data );
		}
	}
    return 0;
}
/*
7
A
B A 0
C B 0
D B 1
E D 0
F D 1
G E 1
D
E
F
     A
   B
 C   D
   E   F
     G
*/