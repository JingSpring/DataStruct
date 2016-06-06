#include<stdio.h>
#include<stdlib.h>
#define Max 20         //最大叶子节点树

struct huffNode
{
	char ch;                     //节点字符A-Z
	int weight;                 //节点权值域
	int lChild;                //该节点左孩子节点在数组中的下标
	int rChild;               //该节点右孩子节点在数组中的下标
	int parent;              //该节点双亲节点在数组中的下标
	char hCode[Max];        //该节点字符的哈夫曼编码
};
struct huffNode huffTree[2*Max-1];
typedef struct huffNode huffmanTree;

int n;         //存放叶子节点的个数

void InitHuffTree();                        //初始化数组huffTree
int createHuffmanTree();                   //创建哈夫曼树 
void huffmanTreeCode();                   //哈夫曼编码算法

int main()
{
	createHuffmanTree();
	huffmanTreeCode();
	return 0;
}

//初始化数组huffTree
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
//创建哈夫曼树
int createHuffmanTree()
{
	char ch='A';
	int i,j,w1,w2,i1,i2;             //i1、i2中存放两个无父结点且结点权值最小的两个结点
	i=0;
	printf("请输入叶子节点的个数(不能超过20个)：");
	scanf("%d",&n);
	InitHuffTree();     //初始化
	while(i<n)
	{
		printf("请输入第%d个节点的权值：",i+1);
		scanf("%d",&huffTree[i].weight);
		i++;
	}
	//找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树
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
		//设置找到的两个子结点 x1、x2 的父结点信息
		huffTree[i1].parent=huffTree[i2].parent=n+i;
		huffTree[n+i].lChild=i1;
		huffTree[n+i].rChild=i2;
		huffTree[n+i].weight=huffTree[i1].weight+huffTree[i2].weight;
		//
		huffTree[n+i].ch=ch;
		printf("生成节点: %c",huffTree[n+i].ch);
		printf("\n");
		ch++;
	    //用于测试
	    printf ("i1.weight和i2.weight 的第%d个节点: %d, %d\n", i+1, huffTree[i1].weight, huffTree[i2].weight); 
        printf ("\n");
	}
}
//左子树编码为0，右子树编码为1
void huffmanTreeCode()
{
	char hc[Max];
	int hcLen;
	int i,j,k,parent,p;
	for(i=0;i<n;i++)
	{
		printf("第%d个节点的哈夫曼编码为：",i+1);
		hcLen=0;
		parent=huffTree[i].parent;         //待编码字符的双亲节点下标
	    p=i;
		while(parent!=-1) //未到达根节点
		{
			if(huffTree[parent].lChild==p)  //是左孩子
				hc[hcLen]='0',hcLen++;
			else if(huffTree[parent].rChild==p)   //是右孩子
				hc[hcLen]='1',hcLen++;
			p=parent;
			parent=huffTree[parent].parent;     //继续向根节点查找
		}
		for(j=0,k=hcLen-1;j<hcLen;j++,k--)      //将编码写入相应字符数组
		{
			huffTree[i].hCode[j]=hc[k];
			printf("%c",huffTree[i].hCode[j]);
		}
		printf("\n");
		huffTree[i].hCode[j]='\0';    //加上字符串结束符
	}
	return;
}