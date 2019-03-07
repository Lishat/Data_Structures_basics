#include<stdio.h>
#include<malloc.h>

void addEdge(int a, int b, int **GRAPH)
{
	GRAPH[a][b] = GRAPH[b][a] = 1;
}

int adjacent(int **GRAPH, int index, int *visit, int n)
{
	int i;
	for(i = 0; i <= n - 1; i++)
	{
		if(GRAPH[index][i] == 1 && visit[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

void print(int *stack, int top)
{
	int i;
	for(i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]+1);
	}
	printf("\n");
}
void AllPaths(int **GRAPH, int n, int mark)
{
	int i, j;
	int stack[n], visit[n], top = -1, flag = 0;
	for(i = 0; i <= n - 1; i++)
	{
		visit[i] = 0;
	}
	for(i = 0; i <= n - 1;i++)
	{
		visit[i] = 1;
		stack[++top] = i;
		while(top != -1)
		{
			int temp = adjacent(GRAPH, stack[top], visit, n);
			if(temp == -1)
			{
				top--;
			}
			else
			{
				visit[temp] = 1;
				stack[++top] = temp;
			}
			if(mark == top && flag == 0)
			{
				print(stack, top);
				flag = 1;
			}
			else if(top < flag)
			{
				flag = 0;
			}	
		}
		for(j = 0; j <= n - 1; j++)
		{
			visit[j] = 0;
		}
	}
	
}

void printAdjacencyMatrix(int **GRAPH, int n)
{
	int i, j;
	for(i = 0; i <= n - 1; i++)
	{
		for(j = 0; j <= n - 1; j++)
		{
			printf("%d ", GRAPH[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n, i, j, t, ops, a, b, k;
	scanf("%d", &n);
	int **GRAPH = (int **)malloc(n*(sizeof(int *)));
	for(i = 0; i <= n - 1; i++)
	{
		GRAPH[i] = (int *)malloc(n*(sizeof(int)));	
	}
	for(i = 0; i <= n - 1; i++)
	{
		for(j = 0; j <= n - 1; j++)
		{
			GRAPH[i][j] = 0;
		}
	}
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{
		printf("Enter the operation to be performed:\n1.Insert an Edge\n2.All Possible Paths of length k\n3.Print adjacency matrix\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
				scanf("%d %d", &a, &b);
				addEdge(a - 1, b - 1, GRAPH);
				break;

			case 2:
				scanf("%d", &k);
				AllPaths(GRAPH, n, k);
				break;
			case 3:
				printAdjacencyMatrix(GRAPH, n);
				break;
		}
	}
	return 0;
}
