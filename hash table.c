#include<stdio.h>
#define size 20

struct Hash
{
	int data;
	int key;
};

struct Hash *hashArray[size]; 

int hashCode(int key)
{
	return key%size;
}

void insert(int key, int data)
{
	struct Hash *item;
	item = new Hash;
	item->data = data;
	item->key = key;
	int hashIndex = hashCode(key);
	while(hashArray[hashIndex] != NULL)	// for linear probing
	{
		++hashIndex;
		hashIndex %= size;
	}
	hashArray[hashIndex] = item;
}

void delet(int key)
{
	struct Hash *item;
	item = new Hash;
	int hashIndex = hashCode(key);
	while(hashArray[hashIndex] != NULL)
	{
		if (hashArray[hashIndex]->key == key)
		{
			hashArray[hashIndex] = NULL;
			break;
		}
		++hashIndex;
		hashIndex %= size;
	}
}

void search(int key)
{
	struct Hash *item;
	item = new Hash;
	int hashIndex = hashCode(key);
	while(hashArray[hashIndex] != NULL)
	{
		if (hashArray[hashIndex]->key == key)
		{
			item = hashArray[hashIndex];
			break;
		}
		++hashIndex;
		hashIndex %= size;
	}
	if(item != NULL)
	{	
		printf("(%d, %d)\n", item->key, item->data);
	}
	else
	{
		printf("Key not found\n");
	}
}

void display()
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		if(hashArray[i] != NULL)
		{
			printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->data);
		}
		else
		{
			printf(" ~~ ");
		}
	}
	printf("\n");
}

int main()
{
	int i, t, ops, key, value;
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{
		printf("Select the operation to be performed:\n1.Insert\n2.Delete\n3.Search\n4.Display\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
				scanf("%d %d", &key, &value);
				insert(key, value);
				break;
			case 2:
				scanf("%d", &key);
				delet(key);
				break;
			case 3:
				scanf("%d", &key);
				search(key);
				break;
			case 4:
				display();
				break;
		}
	}
	return 0;
}
