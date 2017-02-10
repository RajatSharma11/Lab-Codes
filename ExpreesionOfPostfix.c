/** This program converts a Postfix Expression into Tree **/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
# define MAX 100

struct tree
{
	int data;
 	struct tree *right;
 	struct tree *left;
};
 struct tree *stack[MAX];			// structure array
 int top = -1;						// initally array is empty
 struct tree *node;
 
void push(struct tree* node) 			// pushing node in stack
{ 
    stack[++top]=node; 
}

struct tree * pop() 				// poping node out of stack
{ 
    return(stack[top--]); 
}
 
 /* Checking operator and operands */ 

int check(char ch) 
{ 
if(ch=='+'||ch=='-'||ch=='/'||ch=='*'|| ch =='^') 
return 2; 
else if(ch >= '0' && ch <= '9')
return 1; 
else if(ch == ' ')
return 4;
else
return 5;
}

/* Pushing operands in stack */
 void operand(int b) 					
{ 		
    node=(struct tree*)malloc(sizeof(struct tree)); 
    node->data=b; 
    node->left=NULL; 
    node->right=NULL; 
    push(node); 
}

/* making operator node than pop-up two nodes from stack and adding into operator node and finally push node into stack  */

void operators(int a) 
{ 
    node=(struct tree*)malloc(sizeof(struct tree)); 
    node->data=a;
	if(stack[top] != NULL && stack[top-1] != NULL)
	{ 
    	node->right=pop(); 
    	node->left=pop(); 
    	push(node); 
    }
    else
    {
    	printf("Error\n");
    	exit(0) ;
	}
    
}

/* displaying the tree */
void display(struct tree *ptr,int space)
{
 int i;
 if ( ptr!=NULL )
 {
  	display(ptr->right, space+1);		//Recursive Call
  	printf("\n");
    for (i = 0; i < space; i++)
    printf("    "); 
    if((ptr->left != NULL && ptr->right !=NULL) && (ptr->data == '+' || ptr->data == '-'|| ptr->data == '*'|| ptr->data == '/'||ptr->data == '^'))
    {
    	printf("%c", ptr->data);
    }
    else
    printf("%d", ptr->data);
    display(ptr->left, space+1);		//Recursive Call
 }
} 

int main()
{
	char postfix[100];
	printf("Enter A postfix Expression -: ");
	scanf("%[^\n]s",postfix);
	int k=strlen(postfix); 
    int i = 0,p,num[100],j,count,no;
	int countOperands = 0,countOperators = 0; 
    while(postfix[i] != '\0')
        { 
            p=check(postfix[i]); 			//checking whether postfix[i] is operator,operands or anything else
            if(p == 1) 
            {	
            	j = 0;
            	count = 1;
            	no = 0;
            	num [j] = postfix[i] - '0';
            	i++;
            	while(check(postfix[i]) == 1)
            	{
            		j++;
            		num[j] = postfix[i] - '0';
            		i++;
            		count++;
				}
				for(k = 0;k < count;k++)
				{
					no = no + num[count - k - 1] * pow(10,k);		// forming integer again
				}
            	operand(no); 
            	countOperands++;
            	i++;
            }
            else if(p == 2) 
            {
            	
            operators(postfix[i]);
			i++;
			countOperators++;
        	}
        	else if(p == 4)
        	{
        		i++;
			}
            else if(p == 5)
            {
            	printf("Error in input\n");
            	return 8;
			}
        } 
        if(countOperands == countOperators+1)
        {
        	display(node,1);
        	free(node);
        }
        else
        {
        	printf("Error\n");
		}
}

