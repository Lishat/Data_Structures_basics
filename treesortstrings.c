#include<stdio.h>
#include<string.h>

struct Tree
{
	char data[25];
	struct Tree* left;
	struct Tree* right;
};
struct Tree *root;
void insert(char input[])
{
	struct Tree *temp;
	temp = new Tree;
	strcpy(temp->data, input);
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct Tree *current;
		current = new Tree;
		struct Tree *parent;
		parent = new Tree;
		current = root;
		while(1)
		{
			parent = current;
			if(strcmp(input, current->data) < 0)
			{
				current = current->left;
				if(current == NULL)
				{
					parent->left = temp;
					break;
				}
			}
			else
			{
				current = current->right;
				if(current == NULL)
				{
					parent->right = temp;
					break;
				}
			}
		}
	}
}

void inorder(struct Tree *head)
{
	if(head != NULL)
	{
		inorder(head->left);
		printf("%s ", head->data);
		inorder(head->right);
	}
}

int main()
{
	int t, i, ops;
	char inp[20];
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 0; i <= t - 1; i++)
	{
		printf("Enter the operation you need to perform:\n1.Insert data\n2.In-order traversal\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
					scanf("%s", inp);
					insert(inp);
					break;
					
			case 2:
					inorder(root);
					printf("\n");
					break;
		}
	}
	return 0;
}
