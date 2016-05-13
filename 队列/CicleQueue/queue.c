
//循环队列的出队与入队操作

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50  

int sequ[MaxSize];
int front,rear;                //队头和队尾指针
int Len;

void InitQueue();           //初始化
void enterQueue(int x);    //入队
int exitQueue();          //出队
void display();

int main() 
{
	char ch;
	int i,x;
	int a[10] = {12,87,31,4,1,3,21,14,6,10};
	InitQueue();  //初始化队列
	printf("数组元素依次入队:");
	for(i=0;i<10;i++)
	{
		enterQueue(a[i]);
		printf("%5d",sequ[i]);
	}
	while(1)
	{
		printf("\n\t0:结束\n");
		printf("\t1:元素入队\n");
		printf("\t2:元素出队\n");
		printf("\t3:显示队列元素\n");
		printf("\t请选择要做的操作:");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='0')  break;
		switch(ch)
		{
		case '1':
			printf("请输入要入队的元素：");
			scanf("%d",&x);
			enterQueue(x);
			system("pause");
			break;
		case '2':
			x=exitQueue();
			printf("出队的元素为：%d\n",x);
			system("pause");
			break;
		case '3':
			printf("队列中的数组元素有:");
			display();
			//printf("%d\n",Len);
			break;
		default:
			printf("输入错误，请重新输入！！！\n");
		}
	}
	return 0;
}

//初始化
void InitQueue()
{
	front=rear=MaxSize-1;
}
 //入队
void enterQueue(int x)
{
	if(Len==MaxSize)
	{
		printf("队列已满！！！\n");
		return;
	}
	rear=(rear+1)%MaxSize;
	sequ[rear]=x;
	Len++;
	return;
}
//出队
int exitQueue()
{
	int i,x;
	if(Len==0)
	{
		printf("队列已空！！！\n");
		return -1;
	}
	front=((rear+MaxSize)-Len+1)%MaxSize;
	x=sequ[front];
	Len--;
	return x;
}

//显示队列元素
void display()
{
	int i;
	if(Len==0)
	{
		printf("队列已空！！！\n");
	}
	else
	{
		i=(front+1)%MaxSize;     //使i获得队列的头元素位置
		printf("%d\n",i);
		while(1)
		{
			printf("%5d",sequ[i]);
			if(i==rear) break;
			i=(i+1)%MaxSize;
		}
		printf("\n");
	}
}
