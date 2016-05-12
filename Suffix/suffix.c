#include<stdio.h>
#include<string.h>
#define MaxSize 100


struct OptrStack
{
	char StackData[MaxSize];
	int top;
};
typedef struct OptrStack pStack;


void InitStack(pStack *s);                                //初始化栈    
int StackEmpty(pStack s);                                //判断栈是否为空
int GetTop(pStack s,char *e);                           //取出栈顶元素
int PushStack(pStack *s,char e);                       //入栈
int PopStack(pStack *s,char *e);                      //出栈
int StackLength(pStack s);                           //栈的长度
void ClearStack(pStack *s);                         //清空栈
void InfixExpressionToSuffixExpression(char InfixExpression[],char SuffixExpression[]); //中缀表达式转换为后缀表达式


int main()
{
	char InfixExpression[MaxSize],SuffixExpression[MaxSize];
	printf("请输入一个算术表达式：\n");
	gets(InfixExpression);
	printf("中缀表达式为：%s\n",InfixExpression);
    InfixExpressionToSuffixExpression(InfixExpression,SuffixExpression);
	printf("后缀表达式为：%s\n",SuffixExpression);
    //calculateSuffixExpression(SuffixExpression);
	return 0;
}


//初始化栈
void InitStack(pStack *s)
{
	s->top = 0;
}


//判断栈是否为空,1为空
int StackEmpty(pStack s)
{
	if(s.top==0)
		return 1;
	else
		return 0;
}
//取出栈顶元素,1表示成功
int GetTop(pStack s,char *e)
{
	if(s.top<=0)
	{
		printf("栈为空！！！\n");
		return 0;
	}
	else
	{
		*e=s.StackData[s.top-1];
		return 1;
	}
}
//入栈
int PushStack(pStack *s,char e)
{
	if(s->top>=MaxSize)
	{
		printf("栈已满！！！\n");
		return 0;
	}
	else
	{
		s->StackData[s->top]=e;
		s->top++;
		return 1;
	}
}
//出栈
int PopStack(pStack *s,char *e)
{
	if(s->top==0)
	{
		printf("栈为空，无法做出栈操作！！！\n");
		return 0;
	}
	else
	{
		s->top--;
		*e = s->StackData[s->top];
		return 1;
	}
}
//栈的长度
int StackLength(pStack s)
{
	return s.top;
}
//清空栈
void ClearStack(pStack *s)
{
	s->top=0;
}

//中缀表达式转换为后缀表达式
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

