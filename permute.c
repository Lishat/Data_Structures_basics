#include<stdio.h>
int m;
void print(char *stack, int n)
{
	int i;
	for(i = n - 1; i >= 0; i--)
	{
		printf("%c", stack[i]);
	} 
	printf("\n");
}

void permute(char *stack, int n)
{
	int i;
	if(n == -1)
	{
		print(stack, m);
	}
	else
	{
		for(i = 'a'; i <= 'z'; i++)
		{
			stack[n] = i;
			permute(stack, n - 1); 
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	m = n;
	char stack[n];
	permute(stack, n - 1);
	return 0;
}
