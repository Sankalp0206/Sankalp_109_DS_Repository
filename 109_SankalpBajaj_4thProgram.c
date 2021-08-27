//Author- Sankalp Bajaj
//Date- 03-07-2021
//Purpose-To Evaluate Infix Expresssion using Stack

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX_operand 20
#define MAX_operator 20
int top_operand=-1;
int top_operator=-1;
int top_operator_precedence=0;
int operand_stack[20];
char operator_stack[10];
void push_operand(int);
void push_operator(char);
int pop_operand();
char pop_operator();
void operand_display();
void operator_display();
int evaluation();
int precedance(char);
int i;
int main()
{
	int number;
	char expr[20],digit;
	printf("Enter any expression");
	scanf("%[^\n]s",expr);
	printf("Expression  = %s\n",expr);
	for(i=0;expr[i]!='\0';i++)
	{
		digit=expr[i];
		if(isdigit(digit))
		{
			number=digit-'0';
			push_operand(number);
		}
		else
		{
			push_operator(digit);
		}

	}
	operand_display();
	operator_display();
	printf("\nexpression after evaluation = %d\n\n",evaluation());
}
void push_operand(int operand)
{
	if(top_operand==MAX_operand-1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top_operand=top_operand+1;
		operand_stack[top_operand]=operand;
	}
}
void push_operator(char digit)
{
	int operand_1, operand_2,result, precedance_op;
	char operator,operator1;
	if(top_operator==MAX_operator-1)
	{
		printf("Stack Overflow");
	}
	else if(top_operator==-1)
	{
		top_operator_precedence=precedance(digit);
		top_operator=top_operator+1;
		operator_stack[top_operator]=digit;
	}
	else		
	{
		precedance_op=precedance(digit);
		if(precedance_op>top_operator_precedence)
		{
			top_operator=top_operator+1;
			operator_stack[top_operator]=digit;
		}
		else
		{
			operator=pop_operator();
			operand_2=pop_operand();
			operand_1=pop_operand();
			if(operator=='+')
			{
				result=operand_1+operand_2;
			}
			else if(operator=='-')
			{
				result=operand_1-operand_2;
			}
			else if(operator=='*')
			{
				result=operand_1*operand_2;
			}
			else if(operator=='/')
			{
				result=operand_1/operand_2;
			}
			else
			{
				printf("Undefined Operator\n");
			}
			push_operand(result);
			top_operator=top_operator+1;
			operator_stack[top_operator]=digit;
		}	
	}	
}
int precedance(char digit)
{
		if(digit=='+' || digit=='-')
		{
			return 1;
		}
		else if(digit=='*' || digit=='/')
		{
			return 2;
		}
		else if(digit=='^')
		{
			return 3;
		}
	return -1;	
}
int pop_operand()
{
	int operand;
	if(top_operand==-1)
	{
		printf("No operand in stack\n");
		exit(0);
	}
	else
	{
		operand=operand_stack[top_operand];
		top_operand--;
	}
	return operand;
}
char pop_operator()
{
	char operator;
	if(top_operator==-1)
	{
		printf("No operator in stack\n");
		exit(0);
	}
	else
	{
		operator=operator_stack[top_operator];
		top_operator--;
	}
	return operator;

}
void operand_display()
{
	if(top_operand==-1)
	{
		printf("No operand in Stack\n");
	}
	else
	{
		printf("Operands in the stack are\n");
		for(i=top_operand;i>-1;i--)
		{
			printf("%d\t",operand_stack[i]);
		}
		printf("\n");
	}
}
void operator_display()
{
	if(top_operator==-1)
	{
		printf("No operator in Stack\n");
	}
	else
	{
		printf("Operator in the stack are\n");
		for(i=top_operator;i>-1;i--)
		{
			printf("%c\t",operator_stack[i]);
		}
		printf("\n");
	}
}
int evaluation()
{
	int operand_1, operand_2,result;
	char operator;
	if(top_operand==-1)
	{
		printf("no more operator in stack");
		exit(0);
	}
	else
	{
		for (i = top_operator; top_operator > -1; i++)
		{
			operator=pop_operator();
			operand_2=pop_operand();
			operand_1=pop_operand();
			if(operator=='+')
			{
				result=operand_1+operand_2;
			}
			else if(operator=='-')
			{
				result=operand_1-operand_2;
			}
			else if(operator=='*')
			{
				result=operand_1*operand_2;
			}
			else if(operator=='/')
			{
				result=operand_1/operand_2;
			}
			else
			{
				printf("Undefined Operator\n");
			}
			push_operand(result);
		}
	}
	return operand_stack[0];
}
