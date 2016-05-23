#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

char node[MaxSize];

void createTree();   //创建二叉树
void seqInOrder(int i);   //中序遍历二叉树
void seqPreOrder(int i);  //前序遍历二叉树
void seqPostOrder(int i); //后序遍历二叉树


int main()
{
	createTree();
	printf("中序遍历二叉树结果如下：");
	seqInOrder(1);
	printf("\n");
	printf("前序遍历二叉树结果如下：");
	seqPreOrder(1);
	printf("\n");
	printf("后序遍历二叉树结果如下：");
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
		printf("元素%d:%c\n",i,node[i]);
		i++;
		j++;
	}
	printf("完全二叉树的元素有%d个\n",node[0]);
}
//中序遍历二叉树
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
//前序遍历二叉树
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
//后序遍历二叉树
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
