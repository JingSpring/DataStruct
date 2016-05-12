
/////-----�������ȳ�ʼ��һ��ѭ����������ʹ��תΪѭ��˫�����ٶ�ѭ��˫�����������ɾ���顢�Ĳ���-----\\\\\
                  /*���һ��ʼ���������Ǻ���Ϥ���������������ϣ����˽⣬����ʼд����*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//���Ӵ洢�ڵ㶨��
struct SLinkList
{
	struct SLinkList *prior;             //ָ����ֵΪ��
	int data;                           //������
	struct SLinkList *next;            //ָ����ָ���̽ڵ�
};

struct SLinkList *first=NULL;      //ͷָ�룬ָ��ͷ�ڵ㣬��ʼ��Ϊ��ָ��
int listLength;                   //������
                    
void initDataList(int a[],int n);             //��ʼ��ѭ��������
void displayList();                         //��ʾ����                
int locateList(int x);                    //��ֵ��������Ԫ��
int insertList(int i,int x);             //����Ԫ��
int deleteList(int i,int *x);           //ɾ��Ԫ��
void singleCircleToDoubleCircleLinkList();            //ѭ��������תΪѭ��˫����

int main()
{
	int rec,x,i;
	char ch;                    //����ѡ��
	int a[10] = {1,25,-2,54,96,-75,61,84,24,7};
	initDataList(a,10);         //��ʼ��ѭ��������
    singleCircleToDoubleCircleLinkList();    
    while(1)
	{
		printf("\t0:��������\n");
		printf("\t1:ѭ��������תΪѭ��˫����\n");
		printf("\t2:�������\n");
		printf("\t3:����Ԫ�ص�ѭ��˫����\n");
		printf("\t4:��ѭ��˫����ɾ��Ԫ��\n");
		printf("\t5:��������Ԫ��\n");
		printf("\t6:����\n");
		printf("������Ҫѡ��Ĳ�����");
		fflush(stdin);    //������뻺��
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
				printf("ѭ����������תΪѭ��˫��������\n");
			}
			system("pause");
			break;
		case '2':
			system("cls");
			if(first->prior!=NULL)
			{
				printf("ѭ��˫����Ԫ�����£�\n");
				displayList();
			}
			else
			{
				printf("ѭ��������Ԫ�����£�\n");
				displayList();
			}
			system("pause");
			break;
		case '3':
			printf("������Ҫ�����Ԫ�ؼ�λ��,�ö���(Ӣ��)������");
			scanf("%d,%d",&x,&i);
			printf("�������Ԫ��ǰԪ�����£�\n");
			displayList();
            rec=insertList(i,x);
			if(rec)
			{
				printf("\n�������Ԫ�غ�Ԫ�����£�\n");
				displayList();
				printf("\n");
			}
			else
			{
				printf("�������Ԫ��ʧ�ܣ�����\n");
			}
			break;
		case '4':
			printf("ɾ���ڵ�ǰ����Ԫ�����£�\n");
			displayList();
			printf("\n������Ҫɾ���ڵ��λ�ã�");
			scanf("%d",&i);
			rec=deleteList(i,&x);
			if(rec)
			{
				printf("����ɾ���ڵ��Ԫ�����£�\n");
				displayList();
				printf("\nɾ����Ԫ��Ϊ��%d\n",x);
			}
			else
			{
				printf("����ɾ��Ԫ��ʧ�ܣ�����\n");
			}
			break;
		case '5':
			printf("\n������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d",&x);
			i=locateList(x);
			if(i!=-1)
			{
				printf("Ҫ���ҵ�Ԫ��%d��λ���ǵ�%d��Ԫ��\n",x,i);
			}
			else
			{
				printf("Ҫ���ҵ�Ԫ��%d����������\n",x);
			}
			system("pause");
			break;
		case '6':
			system("cls");
			system("pause");
			break;
		default:
			printf("\t�����ڸò��������������룡����\t\n");
		}
	}
	return 0;
}
//��ʼ��ѭ��������
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
		p->next=first;      //β�ڵ�nextָ��ͷ�ڵ�
		listLength = n;
		printf("\nѭ���������ʼ���ɹ�������\n");
	}
	else
	{
		printf("\nѭ���������Ѵ��ڣ�����\n");
	}
}
                            
//��ʾ����
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
		printf("\n���Ա����ڣ�����\n");
	}
}
    
//������תΪ˫����       
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
		printf("\n�ɹ�ʹ������ת˫��������\n");
	}
	else
	{
		printf("\n���Ա����ڣ�����\n");
	}
}

//��ֵ��������Ԫ��
int locateList(int x)
{
	struct SLinkList *p=NULL;
	int count=0;
	if(!first)
	{
		printf("�������ڣ�����\n");
		return 0;
	}
	if(first->prior==NULL)
	{
		printf("��ǰ������ѭ��˫��������\n");
		return 0;
	}
	p=first->next;
	count++;
	while(p && p->next!=first)    //������������ĩβʱ����������в�����xʱ������ѭ��
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
//����Ԫ��(i:�������ݵ�λ�ã�x���������ݵ���ֵ��
int insertList(int i,int x)
{
	struct SLinkList *s=NULL,*p=NULL;
	int count = 0;
	if(!first)
	{
		printf("�������ڣ�����\n");
		return 0;
	}
	if(first->prior==NULL)
	{
		printf("��ǰ������ѭ��˫��������\n");
		return 0;
	}
	if(i<0 || i>listLength+1)
	{
		printf("Ԫ�ز����λ�÷Ƿ�������\n");
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
	p->prior->next=s;     //�޸�p��ǰ����㣬ʹ��ָ��sָ��Ľڵ�
	s->next=p;
	p->prior=s;
	listLength++;
	return 1;
}
//ɾ��Ԫ��
int deleteList(int i,int *x)
{
	struct SLinkList *p=NULL;
	int count = 0;
	if(!first)
	{
		printf("�������ڣ�����\n");
		return 0;
	}
	if(first->prior==NULL)
	{
		printf("��ǰ������ѭ��˫��������\n");
		return 0;
	}
	if(i<0 || i>listLength)
	{
		printf("Ҫɾ����Ԫ�ز����ڣ�����\n");
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
	p->prior->next=p->next;      //ʹp��ǰ������nextָ��pָ��Ľڵ�ָ���next����p����һ���ڵ㣩
	p->next->prior=p->prior;    //ʹp�ĺ�̽ڵ��priorָ��pָ��Ľڵ�ָ���prior����p����һ���ڵ㣩
	free(p);
	return 1;
}