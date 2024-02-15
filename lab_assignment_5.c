//Alexander Disharoon
//CS1 Lab Assignment 4

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int length = 1;

	while(head->next != NULL) 
	{
		head = head->next;
		length++;
	}

	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	char* str = (char*)malloc((length(head) + 1) * sizeof(char));
	int index = 0;
	while(head != NULL) 
	{
		str[index] = head->letter;
		head = head->next;
		index++;
	}

	str[index] = '\0';

	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* head = *pHead;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;

	if(head == NULL) 
	{
		*pHead = newNode;
		return;
	}

	while(head->next != NULL) 
	{
		head = head->next;
	}

	
	head->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while(*pHead != NULL) 
	{
		node* head = *pHead;
		node* nextNode = head->next;
		free(*pHead);
		*pHead = nextNode;
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}