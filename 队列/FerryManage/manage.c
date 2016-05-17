
//1代表客车，0代表货车

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

//车队列车的数量
int busLen;
int truckLen;
int ferryLen;

//队列
int bus[MaxSize];
int truck[MaxSize];
int ferry[MaxSize];
//数量
int busNum;
int truckNum;
int totalNum;

//队头和队尾指针
int bFront,bRear;
int tFront,tRear;
int fFront,fRear;

void InitQueue();                        //初始化队列
void pushBus(int n);                    //客车队列入列
int popBus();                          //客车队列出队
void pushTruck(int n);                //货车队列入队
int popTruck();                      //货车队列出队
void pushFerry(int n);              //渡船队列入队
void ferryManage(int a[]);         //渡口管理

int main()
{
	int a[10]={1,0,1,0,1,1,0,1,1,0};
	ferryManage(a);
	return 0;
}

//初始化队列
void InitQueue()
{
	bRear=tRear=fRear=MaxSize-1;
	bFront=tFront=fFront=MaxSize-1;
}
//客车入队
void pushBus(int n)
{
	if(busLen==MaxSize)
	{
		printf("队列已满！！！\n");
		return;
	}
	bRear=(bRear+1)%MaxSize;
	bus[bRear]=n;
	busLen++;
	return;
}
//客车出队
int popBus()
{
	int x;
	if(busLen==0)
	{
		printf("队列为空！！！\n");
		return -1;
	}
	bFront=((bRear+MaxSize)-busLen+1)%MaxSize;    //获取队头元素
	x=bus[bFront];
	busLen--;
	return x;
}
//货车入队
void pushTruck(int n)
{
	if(truckLen==MaxSize)
	{
		printf("队列已满！！！\n");
		return;
	}
	tRear=(tRear+1)%MaxSize;
	truck[tRear]=n;
	truckLen++;
	return;
}
//货车出队
int popTruck()
{
	int x;
	if(truckLen==0)
	{
		printf("队列为空！！！\n");
		return -1;
	}
	tFront=((tRear+MaxSize)-truckLen+1)%MaxSize;
	x=truck[tFront];
	truckLen--;
	return x;
}

//渡口入队
void pushFerry(int n)
{
	if(ferryLen==MaxSize)
	{
		printf("队列已满！！！\n");
		return;
	}
	fRear=(fRear+1)%MaxSize;
	ferry[fRear]=n;
	ferryLen++;
	return;
}
//渡口管理
void ferryManage(int a[])
{
	int i,rec,result;
	InitQueue();
	totalNum=0;busNum=0;truckNum=0,i=0;
	while(i<10)
	{
		if(a[i]==1)
		{
     		pushBus(a[i]);
	    	i++;
		}
		else if(a[i]==0)
		{
			pushTruck(a[i]);
			i++;
		}
		else
		{
			printf("有无法识别的车辆！！！\n");
			return;
		}
	}
	printf("客车队列里现有%d辆客车！\n",busLen);
	printf("货车队列里现有%d辆货车！\n",truckLen);
	while(totalNum<MaxSize)
	{
		if(busNum<4 && busLen!=0)     //3.1
		{
			rec=popBus();
			pushFerry(rec);
			totalNum++;
			busNum++;
		}
		else if(busNum<4 && busLen==0 && truckLen!=0)     //3.2
		{
			rec=popTruck();
			pushFerry(rec);
			totalNum++;
			truckNum++;
			busNum=0;
		}
		else if(busNum>=4 && truckLen!=0)     //3.3
		{
			rec=popTruck();
			pushFerry(rec);
			totalNum++;
			truckNum++;
			busNum=0;
		}
		else if(busNum>=4 && truckLen==0 && busLen!=0)    //3.4
		{
			rec=popBus();
			pushFerry(rec);
			rec=popTruck();
			pushFerry(rec);
			totalNum++;
			truckNum=0;
			busNum++;
		}
		else if(busLen==0 && truckLen==0)          //3.5
		{
			break;
		}
	}
	result = totalNum-truckNum;
	printf("客车队列里还有%d辆客车在等待！\n",busLen);
	printf("货车队列里还有%d辆货车在等待！\n",truckLen);
	printf("渡船装载汽车的情况为：%d辆客车，%d辆货车！\n",result,truckNum);
}
