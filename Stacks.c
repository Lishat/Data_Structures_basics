#include<stdio.h>

	int Max_size;
	int *stack;
	int top = -1;

bool isEmpty()
{
	if(top == -1)
	return 1;
	else if(top != -1)
	return 0;
}

bool isFull()
{
	if(top == Max_size - 1)
	return 1;
	else if(top != Max_size - 1)
	return 0;
}

void peek()
{
	if(isEmpty())
	{
		printf("Stack is Empty\n");	
	}
	else
	{
		printf("%d\n", stack[top]);
	}
}

void push(int data)
{
	if(isFull())
	{
		printf("Stack is full, not possible to push\n");
	}
	else if(!isFull())
	{
		top += 1;
		stack[top] = data;
		printf("%d pushed in stack\n", data);
	}
}

void pop()
{
	if(isEmpty())
	{
		printf("Stack is empty, not possible to pop\n");
	}
	else if(!isEmpty())
	{
		printf("%d popped out in stack\n", stack[top]);
		top -= 1;
	}
}

int main()
{
	int trials, i, ops, data;
	scanf("%d", &Max_size);
	stack = new int[Max_size];
	scanf("%d", &trials);
	for(i = 1; i <= trials; i++)
	{
		printf("--------------------\nSelect Operation\n--------------------\n1.Push\n2.Pop\n3.Peek\n");
		scanf("%d", &ops);
		if(ops == 1)
		{
			printf("Enter data to pop\n");
			scanf("%d", &data);
			push(data);
		}
		else if(ops == 2)
		{
			pop();
		}
		else if(ops == 3)
		{
			peek();
		}
	}
	return 0;
}
