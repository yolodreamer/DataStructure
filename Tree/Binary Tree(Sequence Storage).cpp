#include<cstdio>
#include<iostream>

using namespace std;
char a[100];
int flag;//flag=0表示为左节点，flag=1表示右节点
int n;

int find(char x)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    cin>>n;//节点数目
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        char x,fx;
        cin>>x>>fx>>flag;
        int fxi=find(fx);//查找父亲节点的下标
        if(fxi!=-1)
        {
            if(flag==0)
            {
                a[fxi*2]=x;
            }
            else
            {
                a[2*fxi+1]=x;
            }
        }
    }
    char b;
    getchar();
	scanf("%c",&b);
	int xi=find(b);
	printf("孩子节点：%c %c\n",a[2*xi],a[2*xi+1]);
    return 0;
}