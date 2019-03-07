#include<stdio.h>
#include<math.h>
struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
};
struct Tree *root;
int count = 0;
int inserted = 0;
int rem()
{
	int flag = 1, i;
	for(i = 0; count > pow(2, i); i++)
	{
		if(count == pow(2, i+1) -1)
		{
			flag = 0;
			break;
		}
	}
	if(count == 1)
	{
		flag = 0;
	}
	return flag;
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
void insertLevel(struct Tree *head, int level, struct Tree *temp)
{
	if(head == NULL)
	{
		
	}
	else if(level == 2)
	{
		if(head->left == NULL && inserted == 0)
		{
			head->left = temp;
			inserted = 1;
		}
		else if(head->right == NULL && inserted == 0)
		{
			head->right = temp;
			inserted = 1;
		}
	}
	else if(level > 1)
	{
		insertLevel(head->left, level - 1, temp);
		insertLevel(head->right, level - 1, temp);
	}
}
void insert(int input)
{
	struct Tree *temp;
	temp = new Tree;
	temp->data = input;
	temp->left = NULL;
	temp->right = NULL;
	struct Tree *head;
	head = new Tree;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		if(rem() != 0)
		{
			head = root;
			inserted = 0;
			insertLevel(head, height(head), temp);
		}
		else
		{
			head = root;
			while(head->left != NULL)
			{
				head=head->left;
			}
			head->left = temp;
		}
	}	
	count++;
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
int main()
{
	int t, i, ops, inp;
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 0; i <= t - 1; i++)
	{
		printf("Enter the operation you need to perform:\n1.Insert data\n2.Level-order traversal\n3.Pre-order traversal\n4.In-order traversal\n5.Post-order traversal\n6.Height\n");
		scanf("%d", &ops);
		switch(ops)
		{
			case 1:
					scanf("%d", &inp);
					insert(inp);
					break;
			
			case 2:
					levelorder(root);
					printf("\n");
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
					printf("%d\n", height(root));
					break;

		}
	}
	return 0;
}
