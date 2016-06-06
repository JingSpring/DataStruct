#include<stdio.h>
#include<stdlib.h>
#define Max 20         //���Ҷ�ӽڵ���

struct huffNode
{
	char ch;                     //�ڵ��ַ�A-Z
	int weight;                 //�ڵ�Ȩֵ��
	int lChild;                //�ýڵ����ӽڵ��������е��±�
	int rChild;               //�ýڵ��Һ��ӽڵ��������е��±�
	int parent;              //�ýڵ�˫�׽ڵ��������е��±�
	char hCode[Max];        //�ýڵ��ַ��Ĺ���������
};
struct huffNode huffTree[2*Max-1];
typedef struct huffNode huffmanTree;

int n;         //���Ҷ�ӽڵ�ĸ���

void InitHuffTree();                        //��ʼ������huffTree
int createHuffmanTree();                   //������������ 
void huffmanTreeCode();                   //�����������㷨

int main()
{
	createHuffmanTree();
	huffmanTreeCode();
	return 0;
}

//��ʼ������huffTree
void InitHuffTree()
{
	int i;
	for(i=0;i<2*n-1;i++)
	{
		huffTree[i].weight=0;
		huffTree[i].lChild=-1;
        huffTree[i].rChild=-1;
		huffTree[i].parent=-1;
		huffTree[i].ch='A';
		//huffTree[i].hCode[i]=0;
	}
}
//������������
int createHuffmanTree()
{
	char ch='A';
	int i,j,w1,w2,i1,i2;             //i1��i2�д�������޸�����ҽ��Ȩֵ��С���������
	i=0;
	printf("������Ҷ�ӽڵ�ĸ���(���ܳ���20��)��");
	scanf("%d",&n);
	InitHuffTree();     //��ʼ��
	while(i<n)
	{
		printf("�������%d���ڵ��Ȩֵ��",i+1);
		scanf("%d",&huffTree[i].weight);
		i++;
	}
	//�ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�Ŷ�����
	for(i=0;i<n-1;i++)
	{
		w1=w2=10000;
		i1=i2=0;
		for(j=0;j<n+i;j++)
		{
			if(huffTree[j].weight<w1&&huffTree[j].parent==-1)
			{
				w2=w1;
				i2=i1;
				w1=huffTree[j].weight;
				i1=j;
			}
			else if(huffTree[j].weight<w2&&huffTree[j].parent==-1)
			{
				w2=huffTree[j].weight;
				i2=j;
			}
		}
		//�����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ
		huffTree[i1].parent=huffTree[i2].parent=n+i;
		huffTree[n+i].lChild=i1;
		huffTree[n+i].rChild=i2;
		huffTree[n+i].weight=huffTree[i1].weight+huffTree[i2].weight;
		//
		huffTree[n+i].ch=ch;
		printf("���ɽڵ�: %c",huffTree[n+i].ch);
		printf("\n");
		ch++;
	    //���ڲ���
	    printf ("i1.weight��i2.weight �ĵ�%d���ڵ�: %d, %d\n", i+1, huffTree[i1].weight, huffTree[i2].weight); 
        printf ("\n");
	}
}
//����������Ϊ0������������Ϊ1
void huffmanTreeCode()
{
	char hc[Max];
	int hcLen;
	int i,j,k,parent,p;
	for(i=0;i<n;i++)
	{
		printf("��%d���ڵ�Ĺ���������Ϊ��",i+1);
		hcLen=0;
		parent=huffTree[i].parent;         //�������ַ���˫�׽ڵ��±�
	    p=i;
		while(parent!=-1) //δ������ڵ�
		{
			if(huffTree[parent].lChild==p)  //������
				hc[hcLen]='0',hcLen++;
			else if(huffTree[parent].rChild==p)   //���Һ���
				hc[hcLen]='1',hcLen++;
			p=parent;
			parent=huffTree[parent].parent;     //��������ڵ����
		}
		for(j=0,k=hcLen-1;j<hcLen;j++,k--)      //������д����Ӧ�ַ�����
		{
			huffTree[i].hCode[j]=hc[k];
			printf("%c",huffTree[i].hCode[j]);
		}
		printf("\n");
		huffTree[i].hCode[j]='\0';    //�����ַ���������
	}
	return;
}