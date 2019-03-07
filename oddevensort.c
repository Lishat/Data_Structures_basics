#include<stdio.h>

void swap(int A[], int j)
{
	int temp;
	temp = A[j];
	A[j] = A[j+1];
	A[j+1] = temp; 
}

int main()
{
	int i, n, count = 0, j;
	scanf("%d", &n);
	int A[n];
	for(i = 0; i <= n - 1; i++)
	{
		scanf("%d", &A[i]);
	}
	for(i = 1; i <= n ; i++)
	{
		if(count%2 == 0)
		{
			for(j = 0; j <= n - 2; j += 2)
			{
				if(A[j] > A[j+1])
				{
					swap(A, j);
				}
			}
		}
		else if(count%2 != 0)
		{
			for(j = 1; j <= n - 2; j += 2)
			{
				if(A[j] > A[j+1])
				{
					swap(A, j);
				}
			}
		}
		count++;
	}
	for(i = 0; i <= n - 1; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
