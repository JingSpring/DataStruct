
/////-----本程序先初始化一个循环单链表，再使其转为循环双链表，再对循环双链表进行增、删、查、改操作-----\\\\\
                  /*编程一开始对链表还不是很熟悉，但经过查阅资料，逐渐了解，并开始写程序*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//链接存储节点定义
struct SLinkList
{
	struct SLinkList *prior;             //指针域，值为空
	int data;                           //数据域
	struct SLinkList *next;            //指针域，指向后继节点
};

struct SLinkList *first=NULL;      //头指针，指向头节点，初始化为空指针
int listLength;                   //链表长度
                    
void initDataList(int a[],int n);             //初始化循环单链表
void displayList();                         //显示链表                
int locateList(int x);                    //按值查找链表元素
int insertList(int i,int x);             //插入元素
int deleteList(int i,int *x);           //删除元素
void singleCircleToDoubleCircleLinkList();            //循环单链表转为循环双链表

int main()
{
	int rec,x,i;
	char ch;                    //操作选择
	int a[10] = {1,25,-2,54,96,-75,61,84,24,7};
	initDataList(a,10);         //初始化循环单链表
    singleCircleToDoubleCircleLinkList();    
    while(1)
	{
		printf("\t0:结束操作\n");
		printf("\t1:循环单链表转为循环双链表\n");
		printf("\t2:输出链表\n");
		printf("\t3:插入元素到循环双链表\n");
		printf("\t4:从循环双链表删除元素\n");
		printf("\t5:查找链表元素\n");
		printf("\t6:清屏\n");
		printf("请输入要选择的操作：");
		fflush(stdin);    //清空输入缓存
		scanf("%c",&ch);
		if(ch =='0')
			break;
		switch(ch)
		{
		case '1':
			if(first->prior==NULL)
			{
				singleCircleToDoubleCircleLinkList();
			}
			else
			{
				printf("循环单链表已转为循环双链表！！！\n");
			}
			system("pause");
			break;
		case '2':
			system("cls");
			if(first->prior!=NULL)
			{
				printf("循环双链表元素如下：\n");
				displayList();
			}
			else
			{
				printf("循环单链表元素如下：\n");
				displayList();
			}
			system("pause");
			break;
		case '3':
			printf("请输入要插入的元素及位置,用逗号(英文)隔开：");
			scanf("%d,%d",&x,&i);
			printf("链表插入元素前元素如下：\n");
			displayList();
            rec=insertList(i,x);
			if(rec)
			{
				printf("\n链表插入元素后元素如下：\n");
				displayList();
				printf("\n");
			}
			else
			{
				printf("链表插入元素失败！！！\n");
			}
			break;
		case '4':
			printf("删除节点前链表元素如下：\n");
			displayList();
			printf("\n请输入要删除节点的位置：");
			scanf("%d",&i);
			rec=deleteList(i,&x);
			if(rec)
			{
				printf("链表删除节点后元素如下：\n");
				displayList();
				printf("\n删除的元素为：%d\n",x);
			}
			else
			{
				printf("链表删除元素失败！！！\n");
			}
			break;
		case '5':
			printf("\n请输入要查找的元素：");
			scanf("%d",&x);
			i=locateList(x);
			if(i!=-1)
			{
				printf("要查找的元素%d的位置是第%d个元素\n",x,i);
			}
			else
			{
				printf("要查找的元素%d不在链表中\n",x);
			}
			system("pause");
			break;
		case '6':
			system("cls");
			system("pause");
			break;
		default:
			printf("\t不存在该操作，请重新输入！！！\t\n");
		}
	}
	return 0;
}
//初始化循环单链表
void initDataList(int a[],int n)
{
	int i;
	struct SLinkList *p,*s;
	if(!first)
	{
		first=(struct SLinkList *) malloc(sizeof(struct SLinkList));
		first->prior=NULL;
		first->data=0;
		first->next=NULL;
		p=first;
		for(i=0;i<=n;i++)
		{
			s=(struct SLinkList *) malloc(sizeof(struct SLinkList));
			s->prior=NULL;
			s->data=a[i];
			p->next=s;
			p=p->next;
		}
		p->next=first;      //尾节点next指向头节点
		listLength = n;
		printf("\n循环单链表初始化成功！！！\n");
	}
	else
	{
		printf("\n循环单链表已存在！！！\n");
	}
}
                            
//显示链表
void displayList()
{
	struct SLinkList *p;
	if(first && first->next)
	{
		p=first->next;
		while(p && p->next!=first)
		{
			printf("%d\t",p->data);
			p=p->next;
		}
	}
	else
	{
		printf("\n线性表不存在！！！\n");
	}
}
    
//单链表转为双链表       
void singleCircleToDoubleCircleLinkList()
{
	struct SLinkList *p,*q;
	if(first && first->next)
	{
		p=first;
		q=first->next;
        while(q!=first)
		{
			q->prior=p;
			p=p->next;
			q=q->next;
		}
		q->prior=p;
		printf("\n成功使单链表转双链表！！！\n");
	}
	else
	{
		printf("\n线性表不存在！！！\n");
	}
}

//按值查找链表元素
int locateList(int x)
{
	struct SLinkList *p=NULL;
	int count=0;
	if(!first)
	{
		printf("链表不存在！！！\n");
		return 0;
	}
	if(first->prior==NULL)
	{
		printf("当前链表不是循环双链表！！！\n");
		return 0;
	}
	p=first->next;
	count++;
	while(p && p->next!=first)    //当遍历到链表末尾时，如果链表中不存在x时，结束循环
	{
		if(p->data==x)
			break;
		p=p->next;
		count++;
	}
	if(count<=listLength)
		return count;
	else
		return -1;
}
//插入元素(i:插入数据的位置，x：插入数据的数值）
int insertList(int i,int x)
{
	struct SLinkList *s=NULL,*p=NULL;
	int count = 0;
	if(!first)
	{
		printf("链表不存在！！！\n");
		return 0;
	}
	if(first->prior==NULL)
	{
		printf("当前链表不是循环双链表！！！\n");
		return 0;
	}
	if(i<0 || i>listLength+1)
	{
		printf("元素插入的位置非法！！！\n");
		return 0;
	}
	p=first->next;
	while(p->next)
	{
		count++;
		if(count==i)
			break;
		p=p->next;
	}
	s=(struct SlinkList *) malloc(sizeof(struct SLinkList));
	s->data=x;
	s->prior=p->prior;
	p->prior->next=s;     //修改p的前驱结点，使其指向s指向的节点
	s->next=p;
	p->prior=s;
	listLength++;
	return 1;
}
//删除元素
int deleteList(int i,int *x)
{
	struct SLinkList *p=NULL;
	int count = 0;
	if(!first)
	{
		printf("链表不存在！！！\n");
		return 0;
	}
	if(first->prior==NULL)
	{
		printf("当前链表不是循环双链表！！！\n");
		return 0;
	}
	if(i<0 || i>listLength)
	{
		printf("要删除的元素不存在！！！\n");
		return 0;
	}
	p=first->next;
	while(p->next)
	{
		count++;
		if(count==i)
			break;
		p=p->next;
	}
	*x=p->data;                 
	p->prior->next=p->next;      //使p的前驱结点的next指向p指向的节点指向的next（即p的下一个节点）
	p->next->prior=p->prior;    //使p的后继节点的prior指向p指向的节点指向的prior（即p的上一个节点）
	free(p);
	return 1;
}