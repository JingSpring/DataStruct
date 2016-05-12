#include<stdio.h>
#include<string.h>
#define MaxSize 100


struct OptrStack
{
	char StackData[MaxSize];
	int top;
};
typedef struct OptrStack pStack;


void InitStack(pStack *s);                                //��ʼ��ջ    
int StackEmpty(pStack s);                                //�ж�ջ�Ƿ�Ϊ��
int GetTop(pStack s,char *e);                           //ȡ��ջ��Ԫ��
int PushStack(pStack *s,char e);                       //��ջ
int PopStack(pStack *s,char *e);                      //��ջ
int StackLength(pStack s);                           //ջ�ĳ���
void ClearStack(pStack *s);                         //���ջ
void InfixExpressionToSuffixExpression(char InfixExpression[],char SuffixExpression[]); //��׺���ʽת��Ϊ��׺���ʽ


int main()
{
	char InfixExpression[MaxSize],SuffixExpression[MaxSize];
	printf("������һ���������ʽ��\n");
	gets(InfixExpression);
	printf("��׺���ʽΪ��%s\n",InfixExpression);
    InfixExpressionToSuffixExpression(InfixExpression,SuffixExpression);
	printf("��׺���ʽΪ��%s\n",SuffixExpression);
    //calculateSuffixExpression(SuffixExpression);
	return 0;
}


//��ʼ��ջ
void InitStack(pStack *s)
{
	s->top = 0;
}


//�ж�ջ�Ƿ�Ϊ��,1Ϊ��
int StackEmpty(pStack s)
{
	if(s.top==0)
		return 1;
	else
		return 0;
}
//ȡ��ջ��Ԫ��,1��ʾ�ɹ�
int GetTop(pStack s,char *e)
{
	if(s.top<=0)
	{
		printf("ջΪ�գ�����\n");
		return 0;
	}
	else
	{
		*e=s.StackData[s.top-1];
		return 1;
	}
}
//��ջ
int PushStack(pStack *s,char e)
{
	if(s->top>=MaxSize)
	{
		printf("ջ����������\n");
		return 0;
	}
	else
	{
		s->StackData[s->top]=e;
		s->top++;
		return 1;
	}
}
//��ջ
int PopStack(pStack *s,char *e)
{
	if(s->top==0)
	{
		printf("ջΪ�գ��޷�����ջ����������\n");
		return 0;
	}
	else
	{
		s->top--;
		*e = s->StackData[s->top];
		return 1;
	}
}
//ջ�ĳ���
int StackLength(pStack s)
{
	return s.top;
}
//���ջ
void ClearStack(pStack *s)
{
	s->top=0;
}

//��׺���ʽת��Ϊ��׺���ʽ
void InfixExpressionToSuffixExpression(char InfixExpression[],char SuffixExpression[])
{
	pStack s;
	char ch;
	char e;
	int i=0,j=0;
	InitStack(&s);
	ch=InfixExpression[i];
	i++;
	while(ch!='\0')
	{
		switch(ch)
		{
		case '(':
			PushStack(&s,ch);
			break;
		case ')':
			while(GetTop(s,&e)&&e!='(')
			{
				PopStack(&s,&e);
                SuffixExpression[j]=e;
				j++;
				SuffixExpression[j]=' ';
				j++;
			}
			PopStack(&s,&e);
			break;
		case '+':
		case '-':
			while(!StackEmpty(s)&&GetTop(s,&e)&&e!='(')
			{
				PopStack(&s,&e);
				SuffixExpression[j]=e;
				j++;
				SuffixExpression[j]=' ';
				j++;
			}
			PushStack(&s,ch);
			break;
		case '*':
		case '/':
			while(!StackEmpty(s)&&GetTop(s,&e)&&e=='/'||e=='*')
			{
				PopStack(&s,&e);
				SuffixExpression[j]=e;
				j++; 
				SuffixExpression[j]=' ';
				j++;
			}
			PushStack(&s,ch);
			break;
		case ' ':
			break;
		default:
			while(ch>='0' && ch<='9')
			{
				SuffixExpression[j]=ch;
				j++;
				ch=InfixExpression[i];
				i++;
			}
			i--;
			SuffixExpression[j]=' ';
			j++;
		}
		ch=InfixExpression[i];
		i++;
	}
	while(!StackEmpty(s))
	{
		PopStack(&s,&e);
		SuffixExpression[j]=e;
		j++;
		SuffixExpression[j]=' ';
		j++;
	}
	SuffixExpression[j]='\0';
}

