
//ѭ�����еĳ�������Ӳ���

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50  

int sequ[MaxSize];
int front,rear;                //��ͷ�Ͷ�βָ��
int Len;

void InitQueue();           //��ʼ��
void enterQueue(int x);    //���
int exitQueue();          //����
void display();

int main() 
{
	char ch;
	int i,x;
	int a[10] = {12,87,31,4,1,3,21,14,6,10};
	InitQueue();  //��ʼ������
	printf("����Ԫ���������:");
	for(i=0;i<10;i++)
	{
		enterQueue(a[i]);
		printf("%5d",sequ[i]);
	}
	while(1)
	{
		printf("\n\t0:����\n");
		printf("\t1:Ԫ�����\n");
		printf("\t2:Ԫ�س���\n");
		printf("\t3:��ʾ����Ԫ��\n");
		printf("\t��ѡ��Ҫ���Ĳ���:");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='0')  break;
		switch(ch)
		{
		case '1':
			printf("������Ҫ��ӵ�Ԫ�أ�");
			scanf("%d",&x);
			enterQueue(x);
			system("pause");
			break;
		case '2':
			x=exitQueue();
			printf("���ӵ�Ԫ��Ϊ��%d\n",x);
			system("pause");
			break;
		case '3':
			printf("�����е�����Ԫ����:");
			display();
			//printf("%d\n",Len);
			break;
		default:
			printf("����������������룡����\n");
		}
	}
	return 0;
}

//��ʼ��
void InitQueue()
{
	front=rear=MaxSize-1;
}
 //���
void enterQueue(int x)
{
	if(Len==MaxSize)
	{
		printf("��������������\n");
		return;
	}
	rear=(rear+1)%MaxSize;
	sequ[rear]=x;
	Len++;
	return;
}
//����
int exitQueue()
{
	int i,x;
	if(Len==0)
	{
		printf("�����ѿգ�����\n");
		return -1;
	}
	front=((rear+MaxSize)-Len+1)%MaxSize;
	x=sequ[front];
	Len--;
	return x;
}

//��ʾ����Ԫ��
void display()
{
	int i;
	if(Len==0)
	{
		printf("�����ѿգ�����\n");
	}
	else
	{
		i=(front+1)%MaxSize;     //ʹi��ö��е�ͷԪ��λ��
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
