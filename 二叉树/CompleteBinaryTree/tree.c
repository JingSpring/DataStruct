#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

char node[MaxSize];

void createTree();   //����������
void seqInOrder(int i);   //�������������
void seqPreOrder(int i);  //ǰ�����������
void seqPostOrder(int i); //�������������


int main()
{
	createTree();
	printf("�������������������£�");
	seqInOrder(1);
	printf("\n");
	printf("ǰ�����������������£�");
	seqPreOrder(1);
	printf("\n");
	printf("�������������������£�");
	seqPostOrder(1);
	printf("\n");
	return 0;
}

void createTree()
{
	int count,i=1,j=0;
	char a[]={"ABCDEFGHIJ"};
	count=strlen(a);
	node[0]=count;
	while(i<=count)
	{
		node[i]=a[j];
		printf("Ԫ��%d:%c\n",i,node[i]);
		i++;
		j++;
	}
	printf("��ȫ��������Ԫ����%d��\n",node[0]);
}
//�������������
void seqInOrder(int i)
{
	if(i==0)
		return;
	else
	{
		if(2*i<=node[0])
			seqInOrder(2*i);    //
		else
			seqInOrder(0);
		printf("%2c",node[i]);
		if(2*i+1<=node[0])
			seqInOrder(2*i+1);
		else
			seqInOrder(0);
	}
}
//ǰ�����������
void seqPreOrder(int i)
{
	if(i==0)
		return;
	else
	{
		printf("%2c",node[i]);
		if(2*i<=node[0])
			seqPreOrder(2*i);
		else
			seqPreOrder(0);
		if(2*i+1<=node[0])
			seqPreOrder(2*i+1);
		else
			seqPreOrder(0);
	}
}
//�������������
void seqPostOrder(int i)
{
	if(i==0)
		return;
	else
	{
		if(2*i<=node[0])
			seqPostOrder(2*i);
		else
			seqPostOrder(0);
		if(2*i+1<=node[0])
			seqPostOrder(2*i+1);
		else
			seqPostOrder(0);
		printf("%2c",node[i]);
	}
}
