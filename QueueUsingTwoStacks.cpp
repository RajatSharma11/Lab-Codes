// Implementing Queue using two user defined Stacks

/** Basic Algo 

			enQueue(x)
  				1) Push x to stack1.

			deQueue(q)
  			1) If both stacks are empty then error.
  			2) If stack2 is empty
      			 While stack1 is not empty, push everything from stack1 to stack2.
  			3) Pop the element from stack2 and return it.
**/

#include<stdio.h>
#include<stdlib.h>

struct stack1
{
	int data;
	struct stack1 *next;
}* head1 = NULL;

struct stack2
{
	int data;
	struct stack2 *next;
} *head2 = NULL;

void push1(int x)
{
	struct stack1 *temp = (struct stack1*)malloc(sizeof(struct stack1));
	temp->data = x;
	temp->next = NULL;
	if(head1 == NULL)
	{
		head1 = temp;
	}
	else
	{
		temp->next = head1;
		head1 = temp;
	}
}

void push2(int x)
{
	struct stack2 *temp = (struct stack2*)malloc(sizeof(struct stack2));
	temp->data = x;
	temp->next = NULL;
	if(head2 == NULL)
	{
		head2 = temp;
	}
	else
	{
		temp->next = head2;
		head2 = temp;
	}
}

int pop1()
{
	struct stack1 *temp;
	temp = head1;
	head1 = head1->next;
	int t = temp->data;
	temp->next = NULL;
	free(temp);
	return t;
}

int pop2()
{
	struct stack2 *temp;
	temp = head2;
	head2 = head2->next;
	int t = temp->data;
	temp->next = NULL;
	free(temp);
	return t;
}

void enQueue(int x)
{
	push1(x);
}

void deQueue()
{
	if(head2 == NULL && head1 == NULL)
	{
		printf("Nothing to Dequeue\n");
	}
	else if(head2 == NULL)
	{
		while(head1 != NULL)
		{
			push2(pop1());
		}
	}
	if(head2 != NULL)
	{
		printf("%d\n",pop2());
	}
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
