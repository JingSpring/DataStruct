
//1����ͳ���0�������

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

//�����г�������
int busLen;
int truckLen;
int ferryLen;

//����
int bus[MaxSize];
int truck[MaxSize];
int ferry[MaxSize];
//����
int busNum;
int truckNum;
int totalNum;

//��ͷ�Ͷ�βָ��
int bFront,bRear;
int tFront,tRear;
int fFront,fRear;

void InitQueue();                        //��ʼ������
void pushBus(int n);                    //�ͳ���������
int popBus();                          //�ͳ����г���
void pushTruck(int n);                //�����������
int popTruck();                      //�������г���
void pushFerry(int n);              //�ɴ��������
void ferryManage(int a[]);         //�ɿڹ���

int main()
{
	int a[10]={1,0,1,0,1,1,0,1,1,0};
	ferryManage(a);
	return 0;
}

//��ʼ������
void InitQueue()
{
	bRear=tRear=fRear=MaxSize-1;
	bFront=tFront=fFront=MaxSize-1;
}
//�ͳ����
void pushBus(int n)
{
	if(busLen==MaxSize)
	{
		printf("��������������\n");
		return;
	}
	bRear=(bRear+1)%MaxSize;
	bus[bRear]=n;
	busLen++;
	return;
}
//�ͳ�����
int popBus()
{
	int x;
	if(busLen==0)
	{
		printf("����Ϊ�գ�����\n");
		return -1;
	}
	bFront=((bRear+MaxSize)-busLen+1)%MaxSize;    //��ȡ��ͷԪ��
	x=bus[bFront];
	busLen--;
	return x;
}
//�������
void pushTruck(int n)
{
	if(truckLen==MaxSize)
	{
		printf("��������������\n");
		return;
	}
	tRear=(tRear+1)%MaxSize;
	truck[tRear]=n;
	truckLen++;
	return;
}
//��������
int popTruck()
{
	int x;
	if(truckLen==0)
	{
		printf("����Ϊ�գ�����\n");
		return -1;
	}
	tFront=((tRear+MaxSize)-truckLen+1)%MaxSize;
	x=truck[tFront];
	truckLen--;
	return x;
}

//�ɿ����
void pushFerry(int n)
{
	if(ferryLen==MaxSize)
	{
		printf("��������������\n");
		return;
	}
	fRear=(fRear+1)%MaxSize;
	ferry[fRear]=n;
	ferryLen++;
	return;
}
//�ɿڹ���
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
			printf("���޷�ʶ��ĳ���������\n");
			return;
		}
	}
	printf("�ͳ�����������%d���ͳ���\n",busLen);
	printf("��������������%d��������\n",truckLen);
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
	printf("�ͳ������ﻹ��%d���ͳ��ڵȴ���\n",busLen);
	printf("���������ﻹ��%d�������ڵȴ���\n",truckLen);
	printf("�ɴ�װ�����������Ϊ��%d���ͳ���%d��������\n",result,truckNum);
}
