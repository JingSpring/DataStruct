#include<stdio.h>
#include<stdlib.h>
#define N 100

struct biTreeNode
{
	char data;
	struct biTreeNode *leftChild,*rightChild;   //��������������
};
struct biTreeNode *root;             //���ڵ�
char node[N] = {"AB#D##C##"};

struct biTreeNode *TreeStack[N];
int top,bottom;

void InitTree();                                                             //��ʼ��������
struct biTreeNode *createBiTree(struct biTreeNode *T);                      //�Եݹ�ķ�������������
void preOrder(struct biTreeNode *T);                                       //ǰ��������ݹ飩
void midOrder(struct biTreeNode *T);                                      //����������ݹ飩
void behindOrder(struct biTreeNode *T);                                  //����������ݹ飩
void nPreOrder(struct biTreeNode *T);                                   //ǰ��������ǵݹ飩                 //
void InitTreeStack();                                                  //��ʼ��ջ
void PushTreeStack(struct biTreeNode *T);                             //��ջ
struct biTreeNode *PopTreeStack();                                   //��ջ
void freeTree(struct biTreeNode *T);                                //���ٶ�����

int main()
{
	char ch;
	InitTree();    //��ʼ��һ�ÿ���
	while(1)
	{
		printf("\t\t0:�˳�\n");
		printf("\t\t1:����һ�ö�����\n");
		printf("\t\t2:ǰ��������ݹ飩������\n");
		printf("\t\t3:����������ݹ飩������\n");
		printf("\t\t4:����������ݹ飩������\n");
		printf("\t\t5:ǰ��������ǵݹ飩������\n");
		printf("\t\t6:���ٶ�����\n");
		printf("\t\t7:����\n");
		printf("��ѡ�����������");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='0')   break;
		switch(ch)
		{
		case '1':
			if(root==NULL)
			{
				root=createBiTree(root);
				printf("�����������ɹ�������\n");
			}
			else
			{
				printf("�������Ѵ��ڣ�����\n");
			}
			break;
		case '2':
			if(root)
			{
				printf("������ǰ�����������£�");
				preOrder(root);
				printf("\n");
			}
			else
			{
				printf("������Ϊ�գ�����\n");
			}
			break;
		case '3':
			if(root)
			{
				printf("�������������������£�");
				midOrder(root);
				printf("\n");
			}
			else
			{
				printf("������Ϊ�գ�����\n");
			}
			break;
		case '4':
			if(root)
			{
				printf("�������������������£�");
				behindOrder(root);
				printf("\n");
			}
			else
			{
				printf("������Ϊ�գ�����\n");
			}
			break;
		case '5':
			if(root)
			{
				printf("������ǰ��������ǵݹ飩������£�");
				nPreOrder(root);
				printf("\n");
			}
			else
			{
				printf("������Ϊ�գ�����\n");
			}
			break;
		case '6':
            freeTree(root);
			printf("�ɹ����ٶ�����������\n");
			break;
		case '7':
			system("cls");
			break;
		default:
			printf("����������������룡����\n");
		}
	}
	return 0;
}
//��ʼ��������
void InitTree()
{
	root=NULL;
}
//�Եݹ�ķ�������������
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
		T->leftChild=createBiTree(T->leftChild);   //�Եݹ�ķ�������T�ڵ��������
		T->rightChild=createBiTree(T->rightChild); //�Եݹ�ķ�������T�ڵ��������
	}
	return T;
}
//ǰ��������ݹ飩
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
//����������ݹ飩
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
//����������ݹ飩
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

//��ʼ��ջ
void InitTreeStack()
{
	top=bottom=-1;
}
//��ջ
void PushTreeStack(struct biTreeNode *T)
{
	top++;
	TreeStack[top]=T;
}
//��ջ
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

//ǰ��������ǵݹ飩
void nPreOrder(struct biTreeNode *T)
{
	InitTreeStack();
	while(T!=NULL || top!=-1)
	{
		while(T!=NULL)
		{
			printf("%c",T->data);
			PushTreeStack(T);         //��ջ
			T=T->leftChild;
		}
		if(top!=bottom)
		{
			T=PopTreeStack();
			T=T->rightChild;
		}
	}
}

//���ٶ�����
void freeTree(struct biTreeNode *T)
{
	if(T!=NULL)
	{
		freeTree(T->leftChild);     //�ͷ�������
		freeTree(T->rightChild);   //�ͷ�������
		free(T);                  //�ͷŸ��ڵ�
	}
	root=NULL;
}
