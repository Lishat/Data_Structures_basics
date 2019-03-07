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
	temp->next = first;
	rear->next = temp;
	first = temp;
	
}

void insertlast(int p)
{
	struct Node *temp;	
	temp = new Node;
	temp->data = p;
	temp->next = first;
	rear->next = temp;
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
	head->next = temp;
	head = first;
	
}

void deletefirst()
{
	struct Node *temp;
	temp = new Node;
	temp = first;
	first = first->next;
	rear->next = first;
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
	delete(temp);
	head=first;
	
}

void create(int p)
{
	head->data = p;
	head->next = head;
	first = new Node;
	first = head;
	rear = new Node;
	rear = first;
}

void update(int p, int pos)
{
	head = first;
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

void reverse()
{
	struct Node *prev;
	prev = new Node;
	prev = rear;
	struct Node *current;
	current = new Node;
	current = head;
	rear = head;
	struct Node *nex;
	nex = new Node;
	nex = current->next;
	current->next = prev;
	prev = current;
	current = nex;
	while(current != first)
	{
		nex = current->next;
		current->next = prev;
		prev = current;
		current = nex;
	}
	head = prev;
	first = head;
}
	
int main()
{
	int p, t, i, op, pos;
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{ 	
		printf("-------------------------------------------------------\nEnter the operation on  Circular Singly Linked List:\n-------------------------------------------------------\n1.Insertion\n2.Deletion\n3.Updation\n4.Sorting\n5.Reverse print\n-------------------------------------------------------\n");
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
		}	
		else if(op == 3)
		{
			scanf("%d", &p);
			scanf("%d", &pos);
			update(p, pos);
		}
		else if(op == 4)
		{
			sort();
		}
		else if(op == 5)
		{
			reverse();
		}
		print();
	}
	return 0;	
}
