#include <stdlib.h>
#include <stdio.h>
# include <string.h>
//孩子兄弟表示法---二叉链表
typedef struct Node{
	char data;
	struct Node* first;//指向第一个孩子
	struct Node* bro;//指向右边第一个亲兄弟 
 }TNode,*TreeList; 

TreeList initTree(char root)
{
	TNode* s=(TNode*)malloc(sizeof(TNode));
	s->data=root;
	s->first=s->bro=NULL;
	return s;
}

//大问题是：在以r为根节点的树中，找到fx所在的结点 
//1.和根结点对比，r->data==fx,reture r; 否则执行2
//2.问题转化为去以r->first为根的子树中找fx find(r->fisrt,fx) 
//3.或者 以r->bro为根的子树中找fx    find(r->beo,fx)
//递归出口： r==NULL 

TNode* find(TreeList r,char fx)
{
	
	if(r==NULL||r->data==fx)
	{
		return r;
	}
	if(r->first!=NULL)
	{
		TNode* ans=find(r->first,fx);
		if(ans!=NULL&&ans->data==fx)
		{
			return ans;
		}
		
	}
	if(r->bro!=NULL)
	{
		TNode* ans=find(r->bro,fx);
		if(ans!=NULL&&ans->data==fx)
		{
			return ans;
		}	
	}
	return NULL;//若fx不存在树中，NULL 
	
}

//往以r为根节点的树中，插入数据x，x的父亲数据是fx 
void insert(TreeList r,char x,char fx)
{
	TNode* f=find(r,fx);
	if(f==NULL)
	{
		printf("该父亲结点不存在，插入失败\n"); 
		return ;
	 } 
	 TNode* s=(TNode*)malloc(sizeof(TNode));
	 s->data=x;
	 //s->first=NULL;
	 if(f->first==NULL)
	 {//x是长子
	    f->first=s; 
	    s->first=NULL;
	    s->bro=NULL;
	 }
	 else
	 {//x不是长子 
	 	TNode* fir=f->first;
	 	s->bro=fir->bro;
	 	fir->bro=s;
	 	s->first=NULL;
	 }
}
int main()
{
	int n;//结点个数 
	char root;
	TreeList r=NULL;
	scanf("%d",&n);
	getchar(); 
	scanf("%c",&root);
	r=initTree(root);
	char x,fx;
	for(int i=2;i<=n;i++)
	{
		getchar(); 
		scanf("%c %c",&x,&fx);
		insert(r,x,fx);
	}
	getchar(); 
    scanf("%c",&x);
    TNode* p=find(r,x);
    
    TNode* fir=p->first;
    if(fir!=NULL)
    {
    	p=fir;
    	while(p!=NULL)
    	{
    		printf("%c ",p->data );
    		p=p->bro;
		}
	}
	 
}
/*
10
A
B A
C A
D A
E B
F B
G B
H D
I D
J E
D
*/
/*
H I
*/