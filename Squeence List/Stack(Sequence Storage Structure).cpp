#include<cstdio>
#include<iostream>
#define MAX 10 //将max定义为常量10 

using namespace std;
int a[MAX];
int top;//栈顶指针 

//入栈函数 
void push(int x)
{
	if(top>=10)//判断栈是否满如果不满可以入栈 
	{
		printf("栈满");
	}
	else
	{
		top++;
		a[top]=x; 
	}
}

//出栈函数
void pop()
{
	if(top==-1)// 判断栈是否为空如果为空，则无法出栈 
	{
		printf("栈为空"); 
	}
		a[top]=0;
		top--;
	
 } 
 //打印函数 
void printff()
{
	for(int i=top;i>0;i--)
	{
		printf("%d ",a[i]);
	}
 } 
int main()
{
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);	
	printff();
	printf("\n");
	pop();
	printff();
	return 0;
} 
