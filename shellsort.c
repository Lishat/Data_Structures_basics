#include<stdio.h>

void scan(int A[], int n)
{
	int i;
	for(i = 0; i <= n - 1; i++)
	{
		scanf("%d", &A[i]);
	}
}

void print(int A[], int n)
{
	int i;
	for(i = 0; i <= n - 1; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void shellsort(int A[], int n)
{
	int inter = 1, i, j, k, value;
	while(inter <= n/3 - 1)
	{
		inter = inter*3 + 1;
	}
	while(inter > 0)
	{
		for(i = inter; i < n; i++)
		{
			value = A[i];
			for(j = i; j >= inter && A[j - inter] >= value; j -= inter)
			{
				A[j] = A[j - inter];
			}
			A[j] = value;
		}
		inter = (inter-1)/3;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	scan(A, n);
	shellsort(A, n);
	print(A, n);
	return 0;
}
