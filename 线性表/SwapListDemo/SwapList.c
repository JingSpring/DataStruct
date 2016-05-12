
//////˳���///////////


//////---�ܽ�---\\\\\
һ��ʼ����������д��ȥʱ��ÿ���Ȳ���һ��������������ʱ���������ʾ���󣬺󾭵������飬���������鲻ͬ��ԭ��


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MaxSize 100

int List[MaxSize];
int listLen;                                                        //���ݳ���
int initFlag;                                                      //���Ա��ʼ����־����

void Print();                                                    //չʾ���Ա�����
void quickSwapList(int a[]);                                    //��������
void initList(int a[],int n);                                  //��ʼ�����Ա�
int deleteList(int i,int *x);                                 //ɾ������
int insertList(int i,int x);                                 //��������
int get(int i,int *x);                                      //��λ�ò��ң��ɹ�����1�����򷵻�0
int locate(int x);                                         //��ֵ���ң����ҳɹ�����i����λ�ã����򷵻�-1
void freeList();                                          //�������Ա�

int main() 
{
	int i,x,rec;                                       //λ�ã����ݣ��������ؽ��
	char ch;                                          //���ѡ����
	int a[10] = {-1,-8,98,-7,-96,-45,12,96,94,87};
	initList(a,10);
    while(1)
	{
		printf("\n\t\t0������\n");
		printf("\t\t1��չʾ���Ա�Ԫ��\n");
		printf("\t\t2������������Ԫ��\n");
		printf("\t\t3����ʼ�����Ա�\n");
		printf("\t\t4��ɾ������\n");
		printf("\t\t5����������\n");
		printf("\t\t6����λ�ò���Ԫ��\n");
		printf("\t\t7����ֵ����Ԫ��\n");
		printf("\t\t8���������Ա�\n");
		printf("\t\t9������\n");
		printf("\n��ѡ������Ҫ�Ĳ�����");
		fflush(stdin);            //������뻺��
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
            printf("\n����ǰ�����Ա�������Ԫ�أ�\n");
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
				printf("\n���Ա��ѳ�ʼ��������\n");
			}
            system("pause");
			break;
		case '4':
			printf("\n���Ա�Ŀǰ������Ԫ�أ�\n");
			Print();
            printf("\n������Ҫɾ�����ݵ�λ�ã�");
			scanf("%d",&i);
			rec = deleteList(i,&x);
			if(rec)
			{
				printf("\nɾ��������Ա�������Ԫ�أ�\n");
				Print();
				printf("\nɾ���������ǣ�%d",x);
			}
			else
			{
				printf("\nɾ������ʧ�ܣ�����\n");
			}
			break;
		case '5':
			printf("\n������Ҫ��������ݣ�");
			scanf("%d",&x);
            printf("\n������Ҫ�������ݵ�λ�ã�");
			scanf("%d",&i);
            printf("\n��������ǰ�����Ա�������Ԫ�أ�\n");
			Print();
			rec = insertList(i,x);
            if(rec)
			{
				printf("\n���������Ա�������Ԫ�أ�\n");
				Print();
			}
			else
			{
				printf("\n��������ʧ�ܣ�����\n");
			}
			break;
		case '6':
			printf("\n������Ҫ���ҵ�λ�ã�");
			scanf("%d",&i);
			rec = get(i,&x);
			if(rec)
			{
				printf("\n���Ա��%d��Ԫ���ǣ�%d\n",i,x);
			}
			system("pause");
			break;
		case '7':
			printf("\n������Ҫ���ҵ����ݣ�");
			scanf("%d",&x);
			i = locate(x);
			if(i!=-1)
			{
				printf("\nҪ���ҵ�����%d�����Ա�ĵ�%d��Ԫ�ء�\n",x,i);
			}
			else
			{
				printf("\nҪ���ҵ�����%d�������Ա���\n",x);
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
			printf("\n����������������룡����\n");
		}
	}
	return 0;

}

//////////////////////////////----��������---\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
---------------------------------------------------------------------------
//��ʼ�����Ա�
void initList(int a[],int n)
{
	int i;
	for(i = 0;i<n;i++)
	{
		List[i] = a[i];
	}
	listLen = n;
	printf("\n��ʼ���ɹ�...\n");
	printf("���ݳ���Ϊ��%d\n",listLen);
	initFlag = 1;
}
//��������
void quickSwapList(int a[])
{
	int k,i = 0,j = listLen-1;
	if(!initFlag)
	{
		printf("���Ա����ڣ�����\n");
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
   	printf("�������������£�\n");
	Print();
}
//չʾ���Ա�����
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
		printf("���Ա����ڣ�����\n");
	}
	
}
//ɾ������
int deleteList(int i,int *x)
{
	int j;
	if(!initFlag)
	{
		printf("\n���Ա����ڣ�����\n");
		return 0;
	}
	if(listLen==0)
	{
		printf("\n���Ա�Ϊ�գ��޷���ɾ������������\n");
		return 0;
	}
	if(i<0 || i>=listLen)
	{
		printf("\nɾ�����ݵ�λ�÷Ƿ�������\n");
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
//��������
int insertList(int i,int x)
{
	int j;
    if(!initFlag)
	{
		printf("\n���Ա����ڣ�����\n");
		return 0;
	}
	if(listLen>=MaxSize)
	{
		printf("\n���Ա��������޷��������ݣ�����\n");
		return 0;
	}
	if(i<0 || i>listLen+1)
	{
		printf("\n�������ݵ�λ�÷Ƿ�������\n");
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
//��λ�ò��ң��ɹ�����1�����򷵻�0
int get(int i,int *x)
{
	if(!initFlag)
	{
		printf("\n���Ա����ڣ�����\n");
		return 0;
	}
	if(i<0 || i>=listLen)
	{
		printf("\n���ҵ�λ�ò��Ϸ�������\n");
		return 0;
	}
	*x = List[i-1];
	return 1;
}
//��ֵ���ң����ҳɹ�����i����λ�ã����򷵻�-1
int locate(int x)
{
	int i;
    if(!initFlag)
	{
		printf("\n���Ա����ڣ�����\n");
		return 0;
	}
	for(i=0;i<listLen;i++)
		if(List[i] = x)
			return i+1;
	return -1;
}
//�������Ա�
void freeList()
{
	char ch;
	if(initFlag)
	{
		printf("\nȷ��Ҫ�������Ա���Y/N��:");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y')
		{
			listLen = 0;
			initFlag = 0;
			printf("\n���Ա������٣�����\n");
		}
	}
	else
	{
		printf("\n���Ա����ڣ�����\n");
	}
}

