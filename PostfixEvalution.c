/* To evaluate Postfix expression */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
 	double element;
 	struct node *next;
} *head;

void push(double c); 
double pop();

int main() 
{
	int i = 0,k;
	int no[100]; 									// to store more than one digit numbers
	char *exp = (char *)malloc(sizeof(char)*100);										
	char tmp;										// to store characters of string
	head = NULL;

	printf("Enter the postfix expression: ");
	scanf("%[^\n]s", exp);
	
	while( (tmp=exp[i++]) != '\0') 						// loop till end of string
	{ 
	
		if(tmp >= '0' && tmp <= '9')					//whether character is integer or not
		{
			int count = 1,j = 0;
			double num = 0.0;
			no[j] = tmp - '0';
			while(exp[i]>= '0' && exp[i]<= '9' )		// to store continuous digits of integer from string
			{
				j++;
				no[j] = exp[i] - '0';					//to extract integer from character
				i++;
				count++;
			}
			for(k = 0;k < count;k++)
			{
				num = num + no[count - k - 1] * pow(10,k);		// forming integer again
			}

			push(num);
			continue;
		}	
		else 
		{
			if (tmp == ' ')						// neglecting spaces
			{
				continue;
			}
			else
			{
				if(head != NULL && head ->next !=NULL)		//stack should have atleast two integers for operation
				{
					double no1 = pop();
					double no2 = pop();
				
			 		if(tmp == '+')					// Left Associative
					{
	 					push(no1 + no2);
					} 
					else if (tmp == '-')			// Left Associative
					{
						push(no2 - no1);
					}
					else if (tmp == '*')			// Left Associative
					{
						push(no1 * no2);
					}
					else if (tmp == '/')			// Left Associative
					{
						if(no1 != 0.0)				//division by zero
						{
							push(no2 / no1);
						}
						else
						{
							printf("Error division by 0\n");
							return 3;
						}
					}
					else if(tmp == '^')  // Right associative 
					{
						push(pow(no2,no1));
					}
					else 					// for operator other than defined
					{
						printf("Error -: undefined opeartor\n");
						return 5;
					}
				}
				else					// if stack has no or one operand to operate 
				{
					printf("Error -: More opeartor than operands\n");
					return 6;
				}
			}
		}
	}
	if(head->next== NULL)						// if only element left in stack after end of string
	{
		printf("Result of the evalution is %f\n", pop());
		return 2;
	}
	else									// if two or more operands left in stack without operators
	{
		printf("Error -: More number of operands\n");
	}
}

void push(double c)
{
	if(head == NULL) 
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->element = c;
		head->next = NULL;
	} 
	else
	{
		struct node *tNode;
		tNode = (struct node *)malloc(sizeof(struct node));
		tNode->element = c;
		tNode->next = head;
		head = tNode;
	}
}

double pop()				// returning head's element
{
	struct node *tNode;
	tNode = head;
	head = head->next;
	return tNode->element;
}
