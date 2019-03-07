#include<stdio.h>
#include<math.h>
struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
};
struct Tree *root;
int count = 0, scount = 0;
int inserted = 0;
int flag = 0;
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

void set(struct Tree *current)
{
	if(current->left != NULL && current->data < current->left->data)
	{
		int temp;
		temp = current->data;
		current->data = current->left->data;
		current->left->data = temp;
		set(root);
	}
	else if(current->right != NULL && current->data < current->right->data)
	{
		int temp;
		temp = current->data;
		current->data = current->right->data;
		current->right->data = temp;
		set(root);
	}
	else if(current->left != NULL && current->right != NULL)
	{
		set(current->left);
		set(current->right);
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
	set(root);	
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

void deleteLast(struct Tree *head, int level)
{
	if(head == NULL)
	{
	
	}
	else if(level == 1)
	{
		scount++;
		if(scount == count/2)
		{
			if(head->right != NULL && flag == 1)
			{
				root->data = head->right->data;
				head->right = NULL;
				flag = 0;
				count--;
			}
			else if(head->left != NULL && flag == 1)
			{
				root->data = head->left->data;
				head->left = NULL;
				flag = 0;
				count--;
			}	
		}
	}
	else if(level > 1)
	{
		deleteLast(head->left, level - 1);
		deleteLast(head->right, level - 1);
	}
}

void deletenode(struct Tree *head)
{
	int i;
	scount = 0;
	flag = 1;
	for(i = 1; i<= height(head);i++)
	{
		deleteLast(head, i);
	}
}

void heapsort(struct Tree *head)
{
	int i;
	int r = count;
	for(i = 1; i <= r; i++)
	{
		set(root);
		printf("%d ", root->data);
		deletenode(root);
		scount = 0;
	}
	printf("\n");
}
int main()
{
	int t, i, ops, inp;
	printf("Enter the number of testcases:\n");
	scanf("%d", &t);
	for(i = 0; i <= t - 1; i++)
	{
		printf("Enter the operation you need to perform:\n1.Insert data\n2.Level-order traversal\n3.Pre-order traversal\n4.In-order traversal\n5.Post-order traversal\n6.Height\n7.Heap sort\n");
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
			case 7:
					heapsort(root);
					break;
		}
	}
	return 0;
}
