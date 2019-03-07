#include<stdio.h>
int Array[10] = {4, 1, 0, 2, 3, 5, 6, 7, 8, 9};
void display()
{
	int i;
	for(i = 0; i <= 9; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");
}

void swap(int i1, int i2)
{
	int temp = Array[i1];
	Array[i1] = Array[i2];
	Array[i2] = temp;
}

int Partition(int left, int right, int pivot)
{
	int leftpointer = left - 1;
	int rightpointer = right;
	for(;;)
	{
		for(;Array[++leftpointer] < pivot;)
		{

		}
		for(;rightpointer > 0 && Array[--rightpointer] > pivot;)
		{

		}
		if(leftpointer >= rightpointer)
		{
			break;
		}
		else
		{
			swap(leftpointer, rightpointer);
		}
	}
	swap(leftpointer, right);
	return leftpointer;
}

void quickSort(int left, int right)
{
	if(right > left)
	{
		int pivot = Array[right];
		int Partitionpoint = Partition(left, right, pivot);
		quickSort(left, Partitionpoint - 1);
		quickSort(Partitionpoint + 1, right);
	}
}

int main()
{
	quickSort(0, 9);
	display();
	return 0;
}
