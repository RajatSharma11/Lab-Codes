//To reverse a Linked list using Recursion

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*var,*trav;

void insert_at_begning(int value)
{
     var = (struct node *)malloc(sizeof (struct node));
     var->data = value;
     if(head == NULL)
     {
         head = var;
         head->next = NULL;
     }
     else
     {
         var->next = head;
         head = var;
     }
}

void insert_at_end(int value)
{
      struct node *temp; 
      temp = head;
      var = (struct node *)malloc(sizeof (struct node));
      var->data = value;
      if(head == NULL)
      {
          head = var;
          head->next = NULL;
      }
      else
      {
          while(temp->next != NULL)
          {     
               temp = temp->next;
          }
          var->next = NULL;
          temp->next = var;
      }
}

void insert_at_middle(int value, int loc)
{
     struct node *var2,*temp;
     var = (struct node *)malloc(sizeof (struct node));
     var->data = value;
     temp = head;

     if(head == NULL)
     {
          head = var;
          head->next = NULL;
     }
     else
     {
          while(temp->data != loc)
          {
                temp = temp->next;
          }
          var2 = temp->next;
          temp->next = var;
          var->next = var2;
     }
}

void display()
{
     trav = head;
     if(trav == NULL)
     {
          printf("\nList is Empty");
     }
     else
     {
          printf("\nElements in the List: ");
          while(trav!=NULL)
          {
               printf(" %d -> ",trav->data);
               trav = trav->next;
          }
      printf("\n");
      }
}

void reverse(struct node ** head)
{
	struct node* first,*rest;
	/* if list is Empty */
	if(*head == NULL)
	{
		printf("No Element to Reverse\n");
		return;
	}
	first = *head;
	rest = first->next;
	/* if list has only one node */
	if(rest == NULL)
	{
		return;
	}
	/* reverse list and fix first element first */
	reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	/* fix the head pointer */
	*head = rest;
}

int main()
{
     int i = 0;
     head = NULL;
     
     while(1)
     {
     	printf("\n\ninsertion at begning of linked list - 1");
    	printf("\ninsertion at the end of linked list - 2");
     	printf("\ninsertion at the middle where you want - 3");
     	printf("\nReverse - 4");
     	printf("\nexit - 5\n");
        printf("\nenter the choice of operation to perform on linked list");
        scanf("%d",&i);
        switch(i)
        {
           case 1:
            {
            	int value;
                printf("\nenter the value to be inserted");
                scanf("%d",&value);
                insert_at_begning(value);
                display();                
                break; 
            }
            case 2:
            {  
                int value;
                printf("\nenter value to be inserted");
                scanf("%d",&value);
                insert_at_end(value);
                display();
                break;
            }
            case 3:
            {
                int value,loc;
                printf("\nafter which data you want to insert the data");
                scanf("%d",&loc);
                printf("\nenter the value to be inserted");
                scanf("%d",&value);
                insert_at_middle(value,loc);
                display();
                break;
            }
            case 4:
            {
				reverse(&head);
                display();
                break;
            }
            default:
                printf("Select Valid Option\n");
            }
        }
    }
