#include<stdio.h>
#define Max 5

int adj[Max][Max];
int queue[Max];
int front = 0;
int rear = -1;
int count = 0;
struct Vertex
{
	char label;
	bool visited;
};
struct Vertex list[Max];
int itemcount = 0;

void enqueue(int data)
{
	if (rear == Max - 1)
	{
		rear = -1;
	}
	queue[++rear] = data;
	itemcount++;
}

int dequeue()
{
	front++;
	if (front == Max)
	{
		front = 0;
	}
	itemcount--;
	return queue[front];
}

int peek()
{
	return queue[front];
}

void addVertex(char Label)
{
	struct Vertex temp;
	temp.label = Label;
	temp.visited = false;
	list[count++] = temp;
}

void addEdge(int a, int b)
{
	adj[a][b] = adj[b][a] = 1;
}

int adjacent(int index)
{
	int i;
	for(i = 0; i < Max; i++)
	{
		if(adj[index][i] == 1 && list[i].visited == false)
		{
			return i;
		}
	}
	return -1;
}

void bfs()
{
	int i;
	list[0].visited = true;
	printf("%c ", list[0].label);
	enqueue(0);
	while(itemcount != 0)
	{
		int temp = adjacent(peek());
		if(temp == -1)
		{
			dequeue();
		}
		else
		{
			list[temp].visited = true;
			printf("%c ", list[temp].label);
			enqueue(temp);
		}
	}
	for(i = 0; i <= count - 1; i++)
	{
		list[i].visited = false;
	}
	printf("\n");
}

int main()
{	
	int i, j, t, ops, a, b;
	char label;
	for(i = 0; i <= Max - 1; i++)
	{
		for(j = 0; j <= Max - 1; j++)
		{
			adj[i][j] = 0;
		}	
	}
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{
		printf("Enter the operation to be performed:\n1.Insert a vertice\n2.Insert an Edge\n3.Breadth First Search\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
				scanf(" %c", &label);
				addVertex(label);
				break;

			case 2:
				scanf("%d %d", &a, &b);
				addEdge(a, b);
				break;

			case 3:
				bfs();
				break;
		}
	}
	return 0;
}

