#include<stdio.h>
#include<string.h>

char stack[25];
int top = -1;

void push(char item)
{
	stack[++top] = item;
}

char pop()
{
	return stack[top--];
}

int precedence(char symbol)
{
	switch(symbol)
	{
		case '(':
		case ')':
		case '#':
			return 1;
			break;
		case '+':
		case '-':
			return 2;
			break;
		case '*':
		case '/':
			return 3;
			break;
		case '^':
			return 4;
			break;
	}
}

int isoperator(char symbol)
{
	switch(symbol)
	{
		case '(':
		case ')':
		case '#':
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}
void convert(char infix[25], char postfix[25])
{
	int i, j = 0, symbol;
	stack[++top] = '#';
	for(i = 0; i <= strlen(infix) - 1; i++)
	{
		symbol = infix[i];
		if (isoperator(symbol)==0) 			/*If it is a number, first all numbers are filled in postfix array*/
		{
			postfix[j] = symbol;
			j++;
		}
		else if(symbol == '(')
		{
			push(symbol);
		}
		else if(symbol == ')')				/*saves the symbols from ( to )*/
		{
			while(stack[top] != '(')
			{				
				postfix[j] = pop();
				j++;
			}
			pop();
		}
		else if(precedence(symbol) > precedence(stack[top])) /*if precedence is greater, then order is remained same and higher precedence is pushed at last*/
		{
			push(symbol);
		}
		else							/*if precedence is lower, then order is reversed and copied to postfix array and the symbol is pushed to the stack when it is of highest precedence*/
		{
			while(precedence(symbol) <= precedence(stack[top]))
			{
				postfix[j] = pop();
				j++;
			}
			push(symbol);
		}
	}
	while(stack[top] != '#')
	{
		postfix[j] = pop();
		j++;
	}	
	postfix[j] = '\0';
}


int main()
{
	char infix[25], postfix[25];
	scanf("%s", infix);			// 4*5+6/3 in infix = 45*63/+ in postfix
	convert(infix, postfix);
	printf("%s", postfix);
	return 0;
}
