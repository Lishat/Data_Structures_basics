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
int precedence(char symbol) {
	switch(symbol) {
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
		case '(':
		case ')':
		case '#':
			return 1;
			break;
	}
}
//check whether the symbol is operator?
int isOperator(char symbol) {
	switch(symbol) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':
			return 1;
			break;
		default:
			return 0;
	}
}
//converts infix expression to postfix
void convert(char infix[],char postfix[])
{
	int i,symbol,j = 0;
	stack[++top] = '#';
	for(i = 0;i<strlen(infix);i++)
	{
		symbol = infix[i];
		if(isOperator(symbol) == 0) 
		{
			postfix[j] = symbol;
			j++;
		}
		else if(symbol == '(') 
		{
				push(symbol);
		}
		else if(symbol == ')') 
		{
			while(stack[top] != '(')
			{
				postfix[j] = pop();
				j++;
			}
			pop();//pop out (.
		} 
		else if(precedence(symbol)>precedence(stack[top]))
		{
			push(symbol);
		}
		else 
		{
			while(precedence(symbol)<=precedence(stack[top]))
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
	postfix[j]='\0';//null terminate string.
}
int main() {
	char infix[25] = "1*(2+3)",postfix[25];
	convert(infix,postfix);
	printf("Infix expression is: %s\n" , infix);
	printf("Postfix expression is: %s\n" , postfix);
	return 0;
}
