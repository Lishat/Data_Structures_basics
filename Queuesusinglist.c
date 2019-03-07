#include<stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *first = NULL;
struct Node *rear = NULL;

void print()
{
	head = first;
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
	head = first;
}

void enqueue(int p)
{
	
	struct Node *temp;	
	temp = new Node;
	temp->data = p;
	temp->next = NULL;
	rear->next = temp;
	rear = temp;
}


void dequeue()
{
	struct Node *temp;
	temp = new Node;
	temp = first;
	first = first->next;
	head = first;
	delete(temp); 	
}

void create(int p)
{
	head->data = p;
	head->next = NULL;
	first = new Node;
	first = head;
	rear = new Node;
	rear = first;
}
	
int main()
{
	int p, t, i, op, pos;
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{ 	

		printf("-----------------------------------\nEnter the operation on Queues:\n-----------------------------------\n1.Enqueue\n2.Dequeue\n3.Peek\n-----------------------------------\n");
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d", &p);
			if(i == 1 || head == NULL)
			{
				head = new Node;
				create(p);
			}
			else
			{
				enqueue(p);
			}
			head = first;
		}
		else if(op == 2)
		{
			dequeue();
		}	
		else if(op == 3)
		{
			printf("%d\n", first->data);
		}
		print();
	}
	return 0;	
}
