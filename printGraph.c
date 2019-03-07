#include<stdio.h>

void print(int GRAPH[][5])
{
	int i, j;
	for(i = 0; i <= 4; i++)
	{
		for(j = 0; j <= 4; j++)
		{
			printf("%d ", GRAPH[i][j]);
		}
		printf("\n");
	}
}

void prints(int stack[], int top)
{
	int i, j;
	for(i = 0; i <= top - 1; i++)
	{
		printf("%d ", stack[i]+1);
	}
	printf("\n");
}

void permute(int GRAPH[][5], int stack[], int top, int mark, int visit[])
{
	int i, flag, j;
	for(i = 0; i <= 4; i++)
	{
		flag = 1;
		for(j = 0; j <= 4; j++)
		{
			visit[j] = 0;
		}
		for(j = 0; j <= top-1; j++)
		{
			visit[stack[j]] = 1;
		}
		if(GRAPH[mark][i] != 0 && visit[i] == 0)
		{
			stack[top] = i;
			visit[mark] = 1;
			permute(GRAPH, stack, top+1, stack[top], visit);
			flag = 0;
		}
	}
	if(flag == 1)
	{
		prints(stack, top);
	}
}

int main()
{
	int GRAPH[5][5] = {{0, 1, 1, 1, 1},{1, 0, 1, 1, 1},{1, 1, 0, 0, 1},{1, 1, 0, 0, 1},{1, 1, 1, 1, 0}};
	int stack[5], visit[5];
	int i, j, k;
	for(i = 0; i <= 4; i++)
	{
		visit[i] = 0;
	}
	for(i = 0; i <= 4; i++)
	{
		visit[i] = 1;
		stack[0] = i;
		for(j = 0; j <= 4; j++)
		{
			if(GRAPH[i][j] != 0)
			{
				stack[1] = j;
				visit[j] = 1;
				permute(GRAPH, stack, 2, j, visit);
			}
		}
		for(k = 0; k <= 4; k++)
		{
			visit[k] = 0;
		}
	}
	return 0;
}
