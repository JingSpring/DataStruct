
//////顺序表///////////


//////---总结---\\\\\
一开始把正负函数写进去时，每次先插入一个数再正负排序时，会出现显示错误，后经调试与检查，发现是数组不同的原因


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MaxSize 100

int List[MaxSize];
int listLen;                                                        //数据长度
int initFlag;                                                      //线性表初始化标志变量

void Print();                                                    //展示线性表数据
void quickSwapList(int a[]);                                    //正负排序
void initList(int a[],int n);                                  //初始化线性表
int deleteList(int i,int *x);                                 //删除数据
int insertList(int i,int x);                                 //插入数据
int get(int i,int *x);                                      //按位置查找，成功返回1，否则返回0
int locate(int x);                                         //按值查找，查找成功，用i返回位置，否则返回-1
void freeList();                                          //销毁线性表

int main() 
{
	int i,x,rec;                                       //位置，数据，函数返回结果
	char ch;                                          //存放选择结果
	int a[10] = {-1,-8,98,-7,-96,-45,12,96,94,87};
	initList(a,10);
    while(1)
	{
		printf("\n\t\t0：结束\n");
		printf("\t\t1：展示线性表元素\n");
		printf("\t\t2：按正负排序元素\n");
		printf("\t\t3：初始化线性表\n");
		printf("\t\t4：删除数据\n");
		printf("\t\t5：插入数据\n");
		printf("\t\t6：按位置查找元素\n");
		printf("\t\t7：按值查找元素\n");
		printf("\t\t8：销毁线性表\n");
		printf("\t\t9：清屏\n");
		printf("\n请选择所需要的操作：");
		fflush(stdin);            //清空输入缓存
		scanf("%c",&ch);
		if(ch == '0')   break;
		switch(ch)
		{
		case '1':
			system("cls");
			Print();
			system("pause");
			break;
		case '2':
            printf("\n排序前的线性表有如下元素：\n");
			Print();
			quickSwapList(a);
			system("pause");
			break;
		case '3':
			if(!initFlag)
			{
				initList(a,10);
			}
			else
			{
				printf("\n线性表已初始化！！！\n");
			}
            system("pause");
			break;
		case '4':
			printf("\n线性表目前有如下元素：\n");
			Print();
            printf("\n请输入要删除数据的位置：");
			scanf("%d",&i);
			rec = deleteList(i,&x);
			if(rec)
			{
				printf("\n删除后的线性表有如下元素：\n");
				Print();
				printf("\n删除的数据是：%d",x);
			}
			else
			{
				printf("\n删除数据失败！！！\n");
			}
			break;
		case '5':
			printf("\n请输入要插入的数据：");
			scanf("%d",&x);
            printf("\n请输入要插入数据的位置：");
			scanf("%d",&i);
            printf("\n插入数据前的线性表有如下元素：\n");
			Print();
			rec = insertList(i,x);
            if(rec)
			{
				printf("\n插入后的线性表有如下元素：\n");
				Print();
			}
			else
			{
				printf("\n插入数据失败！！！\n");
			}
			break;
		case '6':
			printf("\n请输入要查找的位置：");
			scanf("%d",&i);
			rec = get(i,&x);
			if(rec)
			{
				printf("\n线性表第%d个元素是：%d\n",i,x);
			}
			system("pause");
			break;
		case '7':
			printf("\n请输入要查找的数据：");
			scanf("%d",&x);
			i = locate(x);
			if(i!=-1)
			{
				printf("\n要查找的数据%d是线性表的第%d个元素。\n",x,i);
			}
			else
			{
				printf("\n要查找的数据%d不在线性表中\n",x);
			}
			system("pause");
			break;
		case '8':
			freeList();
            system("pause");
			break;
		case '9':
			system("cls");
			system("pause");
			break;
        default:
			printf("\n输入错误，请重新输入！！！\n");
		}
	}
	return 0;

}

//////////////////////////////----函数部分---\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
---------------------------------------------------------------------------
//初始化线性表
void initList(int a[],int n)
{
	int i;
	for(i = 0;i<n;i++)
	{
		List[i] = a[i];
	}
	listLen = n;
	printf("\n初始化成功...\n");
	printf("数据长度为：%d\n",listLen);
	initFlag = 1;
}
//正负排序
void quickSwapList(int a[])
{
	int k,i = 0,j = listLen-1;
	if(!initFlag)
	{
		printf("线性表不存在！！！\n");
		return 0;
	}
	while(i<j)
	{
		while(List[i] < 0 && i<j) i++;
		while(List[j] >= 0 && i<j) j--;
		if(i<j)
		{
			int t = List[i];List[i]=List[j];List[j]=t;
		}
		i++;
		j--;
	}
   	printf("排序后的数据如下：\n");
	Print();
}
//展示线性表数据
void Print() 
{
	int i;
	if(initFlag)
	{
		for(i = 0;i<listLen;i++)
		{
			printf("%d\t",List[i]);
		}
		printf("\n");
	}
	else
	{
		printf("线性表不存在！！！\n");
	}
	
}
//删除数据
int deleteList(int i,int *x)
{
	int j;
	if(!initFlag)
	{
		printf("\n线性表不存在！！！\n");
		return 0;
	}
	if(listLen==0)
	{
		printf("\n线性表为空，无法做删除操作！！！\n");
		return 0;
	}
	if(i<0 || i>=listLen)
	{
		printf("\n删除数据的位置非法！！！\n");
		return 0;
	}
	*x = List[i-1];
	for(j=i;j<listLen;j++)
	{
		List[j-1] = List[j];
	}
	listLen--;
	return 1;
}
//插入数据
int insertList(int i,int x)
{
	int j;
    if(!initFlag)
	{
		printf("\n线性表不存在！！！\n");
		return 0;
	}
	if(listLen>=MaxSize)
	{
		printf("\n线性表已满，无法插入数据！！！\n");
		return 0;
	}
	if(i<0 || i>listLen+1)
	{
		printf("\n插入数据的位置非法！！！\n");
		return 0;
	}
	for(j=listLen;j>=i;j--)
	{
		List[j] = List[j-1];
	}
	List[i-1] = x;
	listLen++;
	return 1;
}
//按位置查找，成功返回1，否则返回0
int get(int i,int *x)
{
	if(!initFlag)
	{
		printf("\n线性表不存在！！！\n");
		return 0;
	}
	if(i<0 || i>=listLen)
	{
		printf("\n查找的位置不合法！！！\n");
		return 0;
	}
	*x = List[i-1];
	return 1;
}
//按值查找，查找成功，用i返回位置，否则返回-1
int locate(int x)
{
	int i;
    if(!initFlag)
	{
		printf("\n线性表不存在！！！\n");
		return 0;
	}
	for(i=0;i<listLen;i++)
		if(List[i] = x)
			return i+1;
	return -1;
}
//销毁线性表
void freeList()
{
	char ch;
	if(initFlag)
	{
		printf("\n确定要销毁线性表吗（Y/N）:");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y')
		{
			listLen = 0;
			initFlag = 0;
			printf("\n线性表已销毁！！！\n");
		}
	}
	else
	{
		printf("\n线性表不存在！！！\n");
	}
}

