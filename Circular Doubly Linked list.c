#include<stdio.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *first = NULL;
struct Node *rear = NULL;

void displayforward()
{
	head = first;
	printf("%d ", head->data);
	head=head->next;
	while(head != first)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
	head = first;
}

void displaybackward()
{
	head = rear;
	printf("%d ", head->data);
	head = head->prev;
	while(head != rear)
	{
		printf("%d ", head->data);
		head = head->prev;
	}
	printf("\n");
	head = first;
}

void create(int p)
{
	head->prev = head;
	head->data = p;
	head->next = head;
	first = new Node;
	first = head;
	rear = new Node;
	rear = first;
}

int length()
{
	int len=1;
	head = first;
	head=head->next;
	while(head != first)
	{
		head=head->next;
		len++;
	}
	head = first;
	return len;
}


void insertfirst(int p)
{
	struct Node *temp;
	temp = new Node;
	temp->data = p;
	temp->prev = rear;
	rear->next = temp;
	first->prev = temp;
	temp->next = first;
	first = temp;
	
}

void insertlast(int p)
{
	
	struct Node *temp;	
	temp = new Node;
	temp->data = p;
	temp->prev = rear;
	temp->next = first;
	rear->next = temp;
	first->prev = temp;
	rear = temp;
}

void insert(int p, int q)
{
	int count=0;
	head = first;
	while(count != q - 1)
	{
		head = head->next;
		count++;
	}
	struct Node *temp;
	temp = new Node;
	temp->data=p;
	temp->next=head->next;
	temp->prev=head;
	temp->next->prev=temp;
	head->next = temp;
	head = first;
	
}

void deletefirst()
{
	struct Node *temp;
	temp = new Node;
	temp = first;
	first = first->next;
	first->prev = rear;
	rear->next=first;
	head = first;
	delete(temp); 	
}

void deletelast()
{
	int len=1, p;
	head=first;
	p = length();
	while(len <= p - 2)
	{
		head=head->next;
		len++;
	}
	struct Node *temp;
	temp = new Node;
	temp=head->next;
	head->next=first;
	first->prev=head;
	delete(temp);
	rear = head;
	head=first;
}

void deletepos(int pos)
{
	int len=0;
	head=first;
	while(len != pos - 1)
	{
		head=head->next;
		len++;
	}
	struct Node *temp;
	temp = new Node;
	temp = head->next;
	head->next=head->next->next;
	head->next->prev = head;
	delete(temp);
	head=first;
	
}

void update(int p, int pos)
{
	int len=0;
	while(len != pos)
	{
		head=head->next;
		len++;
	}
	head->data=p;
	head=first;
}

void sort()
{
	int j = length() - 1, k;
	int temp;
	while(j >= 1)
	{
		k = 1;
		head = first;
		while(k <= j)
		{
			if(head->data > head->next->data)
			{
				temp = head->data;
				head->data = head->next->data;
				head->next->data = temp;
			}
			head = head->next;
			k++;
		}
		j--;
	}
	head=first;
}


int main()
{
	int p, t, i, op, pos;
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{ 	
		printf("-------------------------------------------------------\nEnter the operation on  Circular Doubly Linked List:\n-------------------------------------------------------\n1.Insertion\n2.Deletion\n3.Updation\n4.Sorting\n5.Reverse print\n-------------------------------------------------------\n");
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d", &p);
			scanf("%d", &pos);
			if(i == 1 || head == NULL)
			{
				head = new Node;
				create(p);
			}
			else if(pos == 0)
			{
				insertfirst(p);
			}
			else if(pos == length())
			{
				insertlast(p);
			}
			else if(pos > 0 && pos <= length()-1)
			{
				insert(p, pos);
			}
			head = first;
			displayforward();
		}
		else if(op == 2)
		{
			scanf("%d", &pos);
			if(pos == 0)
			{
				deletefirst();
			}
			else if(pos == length() - 1)
			{
				deletelast();
			}
			else if(pos > 0 && pos < length())
			{
				deletepos(pos);
			}
			displayforward();	
		} 
		else if(op == 3)
		{
			scanf("%d", &p);
			scanf("%d", &pos);
			update(p, pos);
			displayforward();
		}
		else if(op == 4)
		{
			sort();
			displayforward();
		}
		else if(op == 5)
		{
			displaybackward();
		}
	}
	return 0;
}

