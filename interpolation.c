#include<stdio.h>

void scan(int A[], int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}
}

void interpolation(int A[], int low, int high, int mid, int k)
{
	if(A[mid] == k)
	{
		printf("A[%d] = %d\n", mid, k);
	}
	else if(low == mid)
	{
		printf("Element not found\n");
	}
	else if(A[mid] > k)
	{
		high = mid;
		mid = low + ((high - low)/(A[high] - A[low]))*(k - A[low]);
		interpolation(A, low, high, mid, k);
	}
	else if(A[mid] < k)
	{
		low = mid;
		mid = low + ((high - low)/(A[high] - A[low]))*(k - A[low]);
		interpolation(A, low, high, mid, k);
	}
}

int main()
{
	int A[1000000], n, k, low, high, mid;
	scanf("%d", &k);
	scanf("%d", &n);
	scan(A, n);
	low = 1;
	high = n;
	mid = low + ((double)(high - low)/(A[high] - A[low]))*(k - A[low]);
	interpolation(A, low, high, mid, k);
	return 0;
}
