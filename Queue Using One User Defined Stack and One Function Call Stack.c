/** Implement Queue using One Useer defined stack and One Function Call Stack  **/

/*** 
Basic Algo 
				enQueue(x)
				1) Push x to stack.

				deQueue:
				1) If stack is empty then error.
				2) If stack has only one element then return it.
				3) Recursively pop everything from the stack, store the popped item 
				   in a variable res,  push the res back to stack and return res
***/

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
} *head = NULL;

void push(int x)
{
	struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
	temp->data = x;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

int pop()
{
	struct stack *temp;
	temp = head;
	head = head->next;
	int t = temp->data;
	temp->next = NULL;
	free(temp);
	return t;
}

void enQueue(int x)
{
	push(x);
}

int deQueue()
{
  int res;
	if(head == NULL)
	{
	  printf("Nothing to DeQeueue\n");
	}
	else if(head->next == NULL)
	{
	  printf("%d \n",head->data);
	  return pop();
	}
	else
	{
	  res = pop();
	  deQueue();
	}
	push(res);
}

int main()
{
	int n,a;
	printf("Enter Number of Elements to enQueue in Queue\n");
	scanf("%d",&n);
	printf("\nEnter Elements -: \n");
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a);
		enQueue(a);
	}
	printf("\nElements in the Queue are :\n");
	for(int i = 0;i < n;i++)
	{
		deQueue();
	}
}
