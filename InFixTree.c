/** This program converts a infix equation to a tree **/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100

/* structure to keep track to forming trees and operands */
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *stack[MAX];					// structure array
int stacktop = -1;							// intially array is empty
struct tree *node = NULL;

/* structure to keep track tooperators */
struct oprt{
	char item;
};
struct oprt *stack1[MAX];					// structure array
int top = -1;								// intially array is empty
struct oprt *node1 = NULL;					

/* To keep count of operands ,operators,(,) */
int countOperators = 0 , countOperands = 0, count3 = 0, count4 = 0;		

void pushTree(struct tree *node)						//for pushing new operand or tree in stack
{
	stack[++stacktop] = node;

}

void pushOprt(struct oprt *node1)					//for pushing new operator in stack1
{
	stack1[++top] = node1;

}

struct tree* popTree()
{
	return(stack[stacktop--]);
}

char popOprt()
{

	return(stack1[top--]->item);
}

void operands(int b)							// making node od operands and tree
{
	node=(struct tree*)malloc(sizeof(struct tree)); 
	node->data = b;
	node->left = NULL;
	node->right = NULL;
	pushTree(node);
}

void operators(char b)						// making node od operators
{
	node1=(struct oprt*)malloc(sizeof(struct oprt)); 
	node1->item = b;
	pushOprt(node1);
}

int precedence(char token)				// for checking precedence order of operators
{
	if(token == '+' || token == '-')
	{
		return 1;
	}
	else if(token == '*' || token == '/')
	{
		return 2;
	}
	else if(token == '^')
	{
		return 3;
	}
}

int isStackEmpty()							// for checking whether operators stack is empty or not
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int convertTree(char in_fix[])
{
	int i = 0,j,count,no,num[MAX],k;
	while(in_fix[i] != '\0')
	{
		if(in_fix[i] >= '0' && in_fix[i] <= '9')
		{
				j = 0;
            	count = 1;
            	no = 0;
            	num [j] = in_fix[i] - '0';
            	i++;
            	while(in_fix[i] != '\0' && (in_fix[i] >= '0' && in_fix[i] <= '9'))
            	{
            		j++;
            		num[j] = in_fix[i] - '0';
            		i++;
            		count++;
				}
				for(k = 0;k < count;k++)
				{
					no = no + num[count - k - 1] * pow(10,k);		// forming integer again
				}
				countOperands++;
            	operands(no); 
            }
            else if (in_fix[i] == ' ')
            {
            	i++;
			}
			else if(in_fix[i] == '(')				// '(' simply push in stack 
			{
				operators(in_fix[i]);
				count3++;
				i++;
			}
            else if(in_fix[i] == '+' || in_fix[i] == '-'|| in_fix[i] == '*'|| in_fix[i] == '/'||in_fix[i] == '^')
            {
            	if(isStackEmpty() || stack1[top]->item == '(')
            	{
            		operators(in_fix[i]);
            		i++;
            		countOperators++;
				}
				else if(in_fix[i] == '^' && stack1[top]->item == '^' )					// ^ is right associative
				{
				/*if stack1's top is ^ then push next ^ in stack1 */
	
					operators(in_fix[i]);
					i++;
					countOperators++;
				} 
				else if(precedence(stack1[top]->item) >= precedence(in_fix[i]))
				{
					countOperators++;
					while(!isStackEmpty() && (precedence(stack1[top]->item) >= precedence(in_fix[i])) && stack1[top]->item != '(')
					{
						struct tree *tmp = (struct tree*)malloc(sizeof(struct tree));
						tmp->data = popOprt();
						tmp->right = popTree();
						tmp->left = popTree();
						pushTree(tmp);  
					}
					operators(in_fix[i]);
					i++;
				}
				else
				{
					operators(in_fix[i]);
					countOperators++;
					i++;
				}
			}
			else if(in_fix[i] == ')')
			{
				count4++;
				while(top!= -1 && stack1[top]->item != '(')  
				{
/* making operands node then pop-up  operator adding it to node's data and pop-up two nodes from stack and adding into operands node and finally push node into stack  */
					struct tree *tmp = (struct tree*)malloc(sizeof(struct tree));
					tmp->data = popOprt();
					tmp->right = popTree();
					tmp->left = popTree();
					pushTree(tmp);  
				}	
				if(top != -1)			
				{
					popOprt();
				}
				else
				{
					printf("Error\n");
					exit(12);
				}
				i++;
			}
			else
			{
				printf("Error\n");
				exit(20);
			}
		}
		while(!isStackEmpty())	// if stack1 is not empty at last then pop everything out and push newly formed tree in stack
		{
			struct tree *tmp;
			tmp = (struct tree*)malloc(sizeof(struct tree));
			tmp->data = popOprt();
			tmp->right = popTree();
			tmp->left = popTree();
			pushTree(tmp);
		}  
}

void display(struct tree *ptr,int space)			// to print Tree structure
{
	int i ;
	if(ptr != NULL)
	{
	display(ptr->right,space+1);				//Recursive call
	printf("\n");
	for(i = 0;i <space;i++)
	{
		printf("   ");
	}
	if((ptr->left != NULL && ptr->right !=NULL) && (ptr->data == '+' || ptr->data == '-'|| ptr->data == '*'|| ptr->data == '/'||ptr->data == '^'))
    printf("%c", ptr->data);
    else
    printf("%d", ptr->data);
	display(ptr->left,space+1);					//Recursive call
}
}

int main()
{
	char infix[MAX];
	printf("Enter Infix Expression -: ");
	scanf("%[^\n]s",infix);
	convertTree(infix);
	if((countOperators + 1 == countOperands)&&(count3 == count4))
	{
		display(stack[stacktop],1);
	}
	else
	{
		printf("Error\n");
		exit(11);
	}
	free(stack[stacktop]);
}
