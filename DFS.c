#include<stdio.h>
#include<stdbool.h>

#define Max 5

struct Vertex
{
	char label;
	bool visited;
};

int stack[Max];
int top = -1;

int adj[Max][Max];
struct Vertex list[Max];
int count = 0;

void push(int item)
{
	stack[++top] = item;
}

int pop()
{
	return stack[top--];
}

int peek()
{
	return stack[top];
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

void dfs()
{
	int i;
	list[0].visited = true;
	printf("%c ", list[0].label);
	push(0);
	while(top != -1)
	{
		int temp = adjacent(peek());
		if(temp == -1)
		{
			pop();
		}
		else
		{
			list[temp].visited = true;
			printf("%c ", list[temp].label);
			push(temp);
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
		printf("Enter the operation to be performed:\n1.Insert a vertice\n2.Insert an Edge\n3.Depth First Search\n");
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
				dfs();
				break;
		}
	}
	return 0;
}

