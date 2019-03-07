#include<stdio.h>
#define size 6
int queue[size];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(int data)
{
	if (rear == size - 1)
	{
		rear = -1;
	}
	queue[++rear] = data;
	count++;
}

int dequeue()
{
	front++;
	if (front == size)
	{
		front = 0;
	}
	count--;
	return queue[front];
}

int peek()
{
	return queue[front];
}

int main()
{
	int t, ops, i, data;
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 1; i <= t;i++)
	{
		printf("Select the operation to be performed:\n1.Enqueue\n2.Dequeue\n3.Peek\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
					if(count == size)
					{
						printf("Queue is full\n");
						break;
					}
					else
					{
						scanf("%d", &data);
						enqueue(data);
						break;
					}
			case 2:
					if(count == 0)
					{
						printf("Queue is empty\n");
						break;
					}
					else
					{
						dequeue();
						break;
					}
			
			case 3:
					if(count == 0)
					{
						printf("Queue is empty\n");
						break;
					}
					else
					{
						printf("%d\n", peek());
						break;
					}
		}
	}
	return 0;
}
