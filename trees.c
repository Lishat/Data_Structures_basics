#include<stdio.h>

struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
};
struct Tree *root;

void insert(int input)
{
	struct Tree *temp;
	temp = new Tree;
	temp->data = input;
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
			if(input < current->data)
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

void search(int input)
{
	struct Tree *current;
	current = new Tree;
	current = root;
	int flag = 0;
	while(1)
	{
		if(current == NULL)
		{
			flag = 0;
			break;
		}
		else if(input < current->data)
		{
			current = current->left;
		}
		else if(input > current->data)
		{
			current = current->right;
		}
		else if(current->data == input)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("Element not found\n");
	}
	else if(flag == 1)
	{
		printf("%d found\n", current->data);
	}
}

void preorder(struct Tree *head)
{
	if(head != NULL)
	{
		printf("%d ", head->data);
		preorder(head->left);
		preorder(head->right);
	}
}

void inorder(struct Tree *head)
{
	if(head != NULL)
	{
		inorder(head->left);
		printf("%d ", head->data);
		inorder(head->right);
	}
}

void postorder(struct Tree *head)
{
	if(head != NULL)
	{
		postorder(head->left);
		postorder(head->right);
		printf("%d ", head->data);
	}
}

int height(struct Tree *head)
{
	if(head == NULL)
	{
		return 0;		
	}
	else
	{
		int leftHeight = height(head->left);
		int rightHeight = height(head->right);
		if(leftHeight > rightHeight)
		{
			return (leftHeight+1);
		}	
		else
		{
			return (rightHeight+1);
		}
	}
}

void printLevel(struct Tree *head, int level)
{
	if(head == NULL)
	{
	
	}
	else if(level == 1)
	{
		printf("%d ", head->data);
	}
	else if(level > 1)
	{
		printLevel(head->left, level - 1);
		printLevel(head->right, level - 1);
	}
}

void levelorder(struct Tree *head)
{
	int i;
	for(i = 1; i <= height(head); i++)
	{
		printLevel(head, i);
	}
}


int main()
{
	int t, i, ops, inp;
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 0; i <= t - 1; i++)
	{
		printf("Enter the operation you need to perform:\n1.Insert data\n2.Search data\n3.Pre-order traversal\n4.In-order traversal\n5.Post-order traversal\n6.Level-order traversal\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
					scanf("%d", &inp);
					insert(inp);
					break;
			
			case 2:
					scanf("%d", &inp);
					search(inp);
					break;
					
			case 3:
					preorder(root);
					printf("\n");
					break;
					
			case 4:
					inorder(root);
					printf("\n");
					break;
					
			case 5:
					postorder(root);
					printf("\n");
					break;
			case 6:
					levelorder(root);
					printf("\n");
					break;
			case 7:
					height(root);
					printf("\n");
					break;

		}
		printLevel(root, height(root));
	}
	return 0;
}
