#include<stdio.h>
#include<stdlib.h>
#define N 100

struct biTreeNode
{
	char data;
	struct biTreeNode *leftChild,*rightChild;   //左子树，右子树
};
struct biTreeNode *root;             //根节点
char node[N] = {"AB#D##C##"};

struct biTreeNode *TreeStack[N];
int top,bottom;

void InitTree();                                                             //初始化二叉树
struct biTreeNode *createBiTree(struct biTreeNode *T);                      //以递归的方法创建二叉树
void preOrder(struct biTreeNode *T);                                       //前序遍历（递归）
void midOrder(struct biTreeNode *T);                                      //中序遍历（递归）
void behindOrder(struct biTreeNode *T);                                  //后序遍历（递归）
void nPreOrder(struct biTreeNode *T);                                   //前序遍历（非递归）                 //
void InitTreeStack();                                                  //初始化栈
void PushTreeStack(struct biTreeNode *T);                             //入栈
struct biTreeNode *PopTreeStack();                                   //出栈
void freeTree(struct biTreeNode *T);                                //销毁二叉树

int main()
{
	char ch;
	InitTree();    //初始化一棵空树
	while(1)
	{
		printf("\t\t0:退出\n");
		printf("\t\t1:创建一棵二叉树\n");
		printf("\t\t2:前序遍历（递归）二叉树\n");
		printf("\t\t3:中序遍历（递归）二叉树\n");
		printf("\t\t4:后序遍历（递归）二叉树\n");
		printf("\t\t5:前序遍历（非递归）二叉树\n");
		printf("\t\t6:销毁二叉树\n");
		printf("\t\t7:清屏\n");
		printf("请选择所需操作：");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='0')   break;
		switch(ch)
		{
		case '1':
			if(root==NULL)
			{
				root=createBiTree(root);
				printf("二叉树创建成功！！！\n");
			}
			else
			{
				printf("二叉树已存在！！！\n");
			}
			break;
		case '2':
			if(root)
			{
				printf("二叉树前序遍历结果如下：");
				preOrder(root);
				printf("\n");
			}
			else
			{
				printf("二叉树为空！！！\n");
			}
			break;
		case '3':
			if(root)
			{
				printf("二叉树中序遍历结果如下：");
				midOrder(root);
				printf("\n");
			}
			else
			{
				printf("二叉树为空！！！\n");
			}
			break;
		case '4':
			if(root)
			{
				printf("二叉树后序遍历结果如下：");
				behindOrder(root);
				printf("\n");
			}
			else
			{
				printf("二叉树为空！！！\n");
			}
			break;
		case '5':
			if(root)
			{
				printf("二叉树前序遍历（非递归）结果如下：");
				nPreOrder(root);
				printf("\n");
			}
			else
			{
				printf("二叉树为空！！！\n");
			}
			break;
		case '6':
            freeTree(root);
			printf("成功销毁二叉树！！！\n");
			break;
		case '7':
			system("cls");
			break;
		default:
			printf("输入错误，请重新输入！！！\n");
		}
	}
	return 0;
}
//初始化二叉树
void InitTree()
{
	root=NULL;
}
//以递归的方法创建二叉树
struct biTreeNode *createBiTree(struct biTreeNode *T)
{
	char ch;
	static int i=0;
	ch=node[i];
	i++;
	if(ch=='#')
	{
		T=NULL;
	}
	else
	{
		T=(struct biTreeNode *) malloc(sizeof(struct biTreeNode));
		if(!T)   exit(0);
		T->data=ch;
		T->leftChild=createBiTree(T->leftChild);   //以递归的方法创建T节点的左子树
		T->rightChild=createBiTree(T->rightChild); //以递归的方法创建T节点的右子树
	}
	return T;
}
//前序遍历（递归）
void preOrder(struct biTreeNode *T)
{
	if(T==NULL)
		return;
	else
	{
		printf("%c",T->data);
		preOrder(T->leftChild);
		preOrder(T->rightChild);
	}
}
//中序遍历（递归）
void midOrder(struct biTreeNode *T)
{
	if(T==NULL)
		return;
	else
	{
		midOrder(T->leftChild);
		printf("%c",T->data);
		midOrder(T->rightChild);
	}
}
//后序遍历（递归）
void behindOrder(struct biTreeNode *T)
{
	if(T==NULL)
		return;
	else
	{
		behindOrder(T->leftChild);     
		behindOrder(T->rightChild);
		printf("%c",T->data);
	}
}

//初始化栈
void InitTreeStack()
{
	top=bottom=-1;
}
//入栈
void PushTreeStack(struct biTreeNode *T)
{
	top++;
	TreeStack[top]=T;
}
//出栈
struct biTreeNode *PopTreeStack()
{
	struct biTreeNode *p;
	if(top!=bottom)
	{
		p=TreeStack[top];
		top--;
		return(p);
	}
	else
	{
		return NULL;
	}
}

//前序遍历（非递归）
void nPreOrder(struct biTreeNode *T)
{
	InitTreeStack();
	while(T!=NULL || top!=-1)
	{
		while(T!=NULL)
		{
			printf("%c",T->data);
			PushTreeStack(T);         //入栈
			T=T->leftChild;
		}
		if(top!=bottom)
		{
			T=PopTreeStack();
			T=T->rightChild;
		}
	}
}

//销毁二叉树
void freeTree(struct biTreeNode *T)
{
	if(T!=NULL)
	{
		freeTree(T->leftChild);     //释放左子树
		freeTree(T->rightChild);   //释放右子树
		free(T);                  //释放根节点
	}
	root=NULL;
}
