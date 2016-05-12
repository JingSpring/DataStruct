#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

int dsStack[MaxSize];                     //定义左右栈
int lsTop,rsTop;                         //定义左右栈栈顶

void InitStack();             //初始化共享栈
void push(int s,int x);      //入栈，s=1，入左栈，s=2，入右栈，x 为入栈元素
int pop(int s,int *x);      //出栈， s=1，出左栈,s=2，出右栈，x返回出栈元素，成功函数返回1，否则返回


int main()
{
	int i,x;
	int a[]={10,20,30,40,50,60,70};
	int b[]={70,60,50,40,30,20,10};
	InitStack();
	printf("将数组a中元素进左端栈....\n");
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)      //将数组a中元素进左端栈
	{
		 push(1,a[i]);
	}
	printf("将数组b中元素进右端栈....\n");
	for(i=0;i<sizeof(b)/sizeof(b[0]);i++)      //将数组b中元素进右端栈
	{
		 push(2,b[i]);
	}
	system("pause");
	printf("左端栈的出栈元素依次是：");
	while(lsTop!=-1)
	{
		pop(1,&x);
		printf("%5d",x);
	}
	printf("\n");
	printf("右端栈的出栈元素依次是：");
	while(rsTop!=MaxSize-1)
	{
		pop(2,&x);
		printf("%5d",x);
	}
    printf("\n");
	return 0;
}

//初始化共享栈
void InitStack()
{
	lsTop=-1;
	rsTop=MaxSize-1;
}

//入栈，s=1，入左栈，s=2，入右栈，x 为入栈元素
void push(int s,int x)
{
	if(rsTop==lsTop+1)//栈满
	{
		printf("栈已满！\n");
		return;
	}
	if(s==1)//入左栈
	{
		lsTop++;
		dsStack[lsTop]=x;
		printf("元素---%d---已进左栈...\n",x);
	}
	else if(s==2)//入右栈
	{
		rsTop--;
		dsStack[rsTop]=x;
		printf("元素---%d---已进右栈...\n",x);
	}
	else
		printf("该栈不存在！\n");
	return;
}


//出栈， s=1，出左栈,s=2，出右栈，x返回出栈元素，成功函数返回1，否则返回
int pop(int s,int *x)
{
	if(s==1)//出左栈
	{
		if(lsTop==-1)
		{
			printf("栈已空！\n");
			return 0;
		}
		*x=dsStack[lsTop];
		lsTop--;
	}
	else if(s==2)//出右栈
	{
		if(rsTop==MaxSize)
		{
			printf("栈已空！\n");
			return 0;
		}
		*x=dsStack[rsTop];
		rsTop++;
	}
	else
	{
		printf("该栈不存在！ \n");
		return 0;
	}
	return 1;
}

/*获取栈顶元素,s=1，获取左栈栈顶元素,s=2，出右栈栈顶元素
int GetTop(int s,int *x)
{
	if(s==1)
	{
		if(lsTop==-1)
		{
			printf("栈为空！！！\n");
			return 0;
		}
		*x=dsStack[lsTop];
	}
	else if(s==2)
	{
		if(rsTop==MaxSize)
		{
			printf("栈为空！\n");
			return 0;
		}
		*x=dsStack[rsTop];
	}
	else
	{
		printf("该栈不存在！ \n");
		return 0;
	}
	return 1;
}

//显示栈元素
void displayStack(int s)
{
	int i;
	if(s==1)
	{
		for(i=1;i<=lsTop;i++)
		{
			printf("左栈的元素有:%d\t",dsStack[i]);
		}
		printf("\n");
	}
	else if(s==2)
	{
		for(i=1;i<=rsTop;i++)
		{
			printf("右栈的元素有:%d\t",dsStack[i]);
		}
		printf("\n");
	}
	else
	{
		printf("该栈不存在！ \n");
	}
}*/