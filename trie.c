#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct TRIE
{
	int value;
	struct TRIE *children[54];	
}TRIE;

void printStack(char *stack, int top)
{
	int i;
	for(i = 0 ; i <= top - 1; i++)
	{
		printf("%c", stack[i]);
	}
	printf("\n");
}

void insertchar(TRIE *head, char *name, int l, int strlength)
{
	int i;
	if(l > 1)
	{
		if(name[strlength - l]	>= 65 && name[strlength - l] <= 90)
		{
			if(head->children[name[strlength-l] - 39] == NULL)
			{
				TRIE *temp;
				temp = (TRIE *)(malloc(sizeof(TRIE)));
				temp->value = 1;
				head->children[name[strlength-l] - 39] = temp;
			}
			head = head->children[name[strlength-l] - 39];
			insertchar(head, name, l - 1, strlength);
		}
		else if(name[strlength - l] >= 97 && name[strlength - l] <= 122)
		{
			if(head->children[name[strlength-l] - 97] == NULL)
			{
				TRIE *temp;
				temp = (TRIE *)(malloc(sizeof(TRIE)));
				temp->value = 1;
				head->children[name[strlength-l] - 97] = temp;
			}
			head = head->children[name[strlength-l] - 97];
			insertchar(head, name, l - 1, strlength);
		}
		else if(name[strlength - l] == 46)
		{
			if(head->children[52] == NULL)
			{
				TRIE *temp;
				temp = (TRIE *)(malloc(sizeof(TRIE)));
				temp->value = 1;
				head->children[52] = temp;
			}
			head = head->children[52];
			insertchar(head, name, l - 1, strlength);
		}
	}
	else if(l == 1)
	{
		if(name[strlength - l]	>= 65 && name[strlength - l] <= 90)
		{
			if(head->children[name[strlength-l] - 39] == NULL)
			{
				TRIE *temp;
				temp = (TRIE *)(malloc(sizeof(TRIE)));
				temp->value = 1;
				head->children[name[strlength-l] - 39] = temp;
			}
			head = head->children[name[strlength-l] - 39];
			insertchar(head, name, l - 1, strlength);
		}
		else if(name[strlength - l] >= 97 && name[strlength - l] <= 122)
		{
			if(head->children[name[strlength-l] - 97] == NULL)
			{
				TRIE *temp;
				temp = (TRIE *)(malloc(sizeof(TRIE)));
				temp->value = 1;
				head->children[name[strlength-l] - 97] = temp;
			}
			head = head->children[name[strlength-l] - 97];
			insertchar(head, name, l - 1, strlength);
		}
		else if(name[strlength - l] == 46)
		{
			if(head->children[52] == NULL)
			{
				TRIE *temp;
				temp = (TRIE *)(malloc(sizeof(TRIE)));
				temp->value = 1;
				head->children[52] = temp;
			}
			head = head->children[52];
			insertchar(head, name, l - 1, strlength);
		}
		if(head->children[53] == NULL)
		{
			TRIE *tempi;
			tempi = (TRIE *)(malloc(sizeof(TRIE)));
			tempi->value = 1;
			head->children[53] = tempi;
		}
	}
}

TRIE *insertTrie(TRIE *root,char *name)
{
	int l = strlen(name), i;
	insertchar(root, name, l, l);
	return root;
}

void printAllPrefixes(TRIE *head, char *stack, int top, int k)
{
	int i, count = 0;
	for(i = 0; i <= 53; i++)
	{
		if(head->children[i] != NULL)
		{
			if(i <= 25 && i >= 0)
			{
				char c = i + 97;
				stack[top] = c;
				printAllPrefixes(head->children[i], stack, top+1, k);
			}
			else if(i == 52)
			{
				stack[top] = '.';
				printAllPrefixes(head->children[i], stack, top+1, k);
			}
			else if(i >= 26 && i <= 51)
			{
				char c = i + 39;
				stack[top] = c;
				printAllPrefixes(head->children[i], stack, top+1, k);
			}
			count++;
		}
		
	}
	if(count > 1 && top >= k)
	{
		printStack(stack, top);
	}
}

int main()
{
	int count = 0;
	TRIE *root;
	root = (TRIE *)(malloc(sizeof(TRIE)));
	root->value = 0;
	char name[100];
	char stack[100];
	FILE *fp = fopen("names-authors.txt", "r");
	while(fscanf(fp, "%s", name) >= 1)
	{
		if(rand()%2 == 1)
		{
			root = insertTrie(root, name);
			count++;
		}
		if(count == 200)
		{
			break;
		}
	}
	printAllPrefixes(root,stack, 0, 3);
	fclose(fp);
	return 0;
}
