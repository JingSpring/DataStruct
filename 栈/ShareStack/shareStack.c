#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

int dsStack[MaxSize];                     //��������ջ
int lsTop,rsTop;                         //��������ջջ��

void InitStack();             //��ʼ������ջ
void push(int s,int x);      //��ջ��s=1������ջ��s=2������ջ��x Ϊ��ջԪ��
int pop(int s,int *x);      //��ջ�� s=1������ջ,s=2������ջ��x���س�ջԪ�أ��ɹ���������1�����򷵻�


int main()
{
	int i,x;
	int a[]={10,20,30,40,50,60,70};
	int b[]={70,60,50,40,30,20,10};
	InitStack();
	printf("������a��Ԫ�ؽ����ջ....\n");
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)      //������a��Ԫ�ؽ����ջ
	{
		 push(1,a[i]);
	}
	printf("������b��Ԫ�ؽ��Ҷ�ջ....\n");
	for(i=0;i<sizeof(b)/sizeof(b[0]);i++)      //������b��Ԫ�ؽ��Ҷ�ջ
	{
		 push(2,b[i]);
	}
	system("pause");
	printf("���ջ�ĳ�ջԪ�������ǣ�");
	while(lsTop!=-1)
	{
		pop(1,&x);
		printf("%5d",x);
	}
	printf("\n");
	printf("�Ҷ�ջ�ĳ�ջԪ�������ǣ�");
	while(rsTop!=MaxSize-1)
	{
		pop(2,&x);
		printf("%5d",x);
	}
    printf("\n");
	return 0;
}

//��ʼ������ջ
void InitStack()
{
	lsTop=-1;
	rsTop=MaxSize-1;
}

//��ջ��s=1������ջ��s=2������ջ��x Ϊ��ջԪ��
void push(int s,int x)
{
	if(rsTop==lsTop+1)//ջ��
	{
		printf("ջ������\n");
		return;
	}
	if(s==1)//����ջ
	{
		lsTop++;
		dsStack[lsTop]=x;
		printf("Ԫ��---%d---�ѽ���ջ...\n",x);
	}
	else if(s==2)//����ջ
	{
		rsTop--;
		dsStack[rsTop]=x;
		printf("Ԫ��---%d---�ѽ���ջ...\n",x);
	}
	else
		printf("��ջ�����ڣ�\n");
	return;
}


//��ջ�� s=1������ջ,s=2������ջ��x���س�ջԪ�أ��ɹ���������1�����򷵻�
int pop(int s,int *x)
{
	if(s==1)//����ջ
	{
		if(lsTop==-1)
		{
			printf("ջ�ѿգ�\n");
			return 0;
		}
		*x=dsStack[lsTop];
		lsTop--;
	}
	else if(s==2)//����ջ
	{
		if(rsTop==MaxSize)
		{
			printf("ջ�ѿգ�\n");
			return 0;
		}
		*x=dsStack[rsTop];
		rsTop++;
	}
	else
	{
		printf("��ջ�����ڣ� \n");
		return 0;
	}
	return 1;
}

/*��ȡջ��Ԫ��,s=1����ȡ��ջջ��Ԫ��,s=2������ջջ��Ԫ��
int GetTop(int s,int *x)
{
	if(s==1)
	{
		if(lsTop==-1)
		{
			printf("ջΪ�գ�����\n");
			return 0;
		}
		*x=dsStack[lsTop];
	}
	else if(s==2)
	{
		if(rsTop==MaxSize)
		{
			printf("ջΪ�գ�\n");
			return 0;
		}
		*x=dsStack[rsTop];
	}
	else
	{
		printf("��ջ�����ڣ� \n");
		return 0;
	}
	return 1;
}

//��ʾջԪ��
void displayStack(int s)
{
	int i;
	if(s==1)
	{
		for(i=1;i<=lsTop;i++)
		{
			printf("��ջ��Ԫ����:%d\t",dsStack[i]);
		}
		printf("\n");
	}
	else if(s==2)
	{
		for(i=1;i<=rsTop;i++)
		{
			printf("��ջ��Ԫ����:%d\t",dsStack[i]);
		}
		printf("\n");
	}
	else
	{
		printf("��ջ�����ڣ� \n");
	}
}*/