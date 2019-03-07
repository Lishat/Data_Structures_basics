#include<stdio.h>
#include<string.h>
#include<ctype.h>

int stack[25];
int top = -1;

void push(int item)
{
	stack[++top] = item;
}

int pop()
{
	return stack[top--];
}

int evaluate(char postfix[])
{
	char ch;
	int i = 0, a, b;
	while((ch = postfix[i++]) != '\0')
	{
		if(isdigit(ch))
		{
			push(ch - '0');
		}
		else
		{
			b = pop();
			a = pop();
			switch(ch)
			{
				case '+':
					push(a+b);
					break;
				case '-':
					push(a-b);
					break;
				case '*':
					push(a*b);
					break;
				case '/':
					push(a/b);
					break;
			}
		}
	}
	return stack[top];
}

int main()
{
	char postfix[25];
	scanf("%s", postfix);
	printf("%d\n", evaluate(postfix));
	return 0;
}
