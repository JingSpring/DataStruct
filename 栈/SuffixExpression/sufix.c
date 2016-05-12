#include<stdio.h>
#include<string.h>
#define MaxSize 100

int opndStack[MaxSize];          //运算对象
int opndTop;                    //运算栈栈顶

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
void InitOpnd();                                  //初始化运算对象栈
int PushOpnd(int n);                             //运算对象入栈
int PopOpnd(int *f);                            //运算对象出栈
void calculateSuffixExpression(char a[]);      //后缀表达式求值
int changeCharToInt(int n,char c);            //字符转为数字
void calculate(char optr);                   //后缀表达式运算
void getInfixExpression(char str[]);        //获取中缀表达式


int main()
{
	//int i;
	char ch,InfixExpression[MaxSize],SuffixExpression[MaxSize];
	while(1)
	{
			//printf("请输入一个算术表达式：");
        	getInfixExpression(InfixExpression);
			printf("中缀表达式为：%s\n",InfixExpression);
			InfixExpressionToSuffixExpression(InfixExpression,SuffixExpression);
			printf("后缀表达式为：%s\n",SuffixExpression);
			printf("后缀表达式计算结果为：");
			calculateSuffixExpression(SuffixExpression);
			fflush(stdin);
			printf("继续转换并计算下一个表达式？(Y|N)：");
			ch=getchar();
			if(ch=='Y'||ch=='y')
			{
				continue;
			}
			else
			{
				break;
			}
	}
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

//初始化运算对象栈
void InitOpnd()
{
	opndTop=-1;
	return;
}
//运算对象入栈
int PushOpnd(int n)
{
	if(opndTop==MaxSize-1)
	{
		printf("栈已满！！！\n");
		return 0;
	}
	opndTop++;
	opndStack[opndTop]=n;
	return 1;
}
//运算对象出栈
int PopOpnd(int *e)
{
	if(opndTop==-1)
	{
		printf("栈为空！！！\n");
		return 0;
	}
	*e=opndStack[opndTop];
	opndTop--;
	return 1;
}
//字符转为数字
int changeCharToInt(int n,char c) 
{
	int v;
	v=c-48;
	n=10*n+v;
	return n;
}

//后缀表达式运算
void calculate(char optr)
{
	int rect,a,b,result;
	rect=PopOpnd(&a);
	rect=PopOpnd(&b);
	switch(optr)
	{
	case '+':
		result = a+b;
		break;
	case '-':
		result = b-a;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		result = b/a;
		break;
	}
	PushOpnd(result);
	return;
}

//后缀表达式求值
void calculateSuffixExpression(char a[])
{
	int i,j, rect,value;
	char ch;
	InitOpnd();
    i=0;
	while((ch=a[i])!='\0')
	{
		if(ch>='0'&&ch<='9')
		{
			j=i+1;
			value=ch-48;
			while(a[j]>='0'&&a[j]<='9')
			{
				value=changeCharToInt(value,a[j]);
				j++;
				i++;
			}
			PushOpnd(value);
			i++;
		}
		else if(ch==32)
		{
			i++;
		}
		else
		{
			calculate(ch);
			i++;
		}
	}
	rect=PopOpnd(&value);
	printf("%d\n",value);
	return;
}

void getInfixExpression(char str[])
{
	int Length;
	int len;
	while(1)//循环直到输入了正确的中缀表达式
	{	
		printf("请输入表达式(中缀),以#结束：");
		fflush(stdin);
		gets(str);
		len=strlen(str);
		if(str[0]=='#')
		{
			printf("表达式不要以#开头，请重新输入！\n");
			continue;
		}
		if(str[len-1]!='#')
		{
			printf("表达式必须以#结束，请重新输入！\n");
			continue;
		}
		break;
	}
	return;	
}