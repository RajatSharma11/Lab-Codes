/* To implement Binary Search Tree with insertion,deletion,search and traverse options */

#include<stdio.h>
#include<stdlib.h>

struct btnode{
	int value;
	struct btnode *l,*r;
}*root = NULL,*temp = NULL,*t1;

void deleting(struct btnode *);
void insert();
void delete(int n);
void inorder(struct btnode *t);
void Insertsearch(struct btnode *);
void searching(struct btnode *t,int);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void searchDelete(struct btnode *t,int data);
int smallest(struct btnode *t);
void display(struct btnode * ,int);
void deallocate(struct btnode * ptr);
int main()
{
	 int ch,n;

    while(1)
    {
    	printf("\n\nOPERATIONS ---");
   		printf("\n1 - Insert an element into tree\n");
    	printf("2 - Delete an element from the tree\n");
    	printf("3 - Search an element in the tree\n");
    	printf("4 - Inorder Traversal\n");
    	printf("5 - Preorder Traversal\n");
    	printf("6 - Postorder Traversal\n");
    	printf("7 - Dispaly\n");
    	printf("8 - Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
            insert();
            break;
        case 2:    
        	printf("Enter Element to be deleted -: ");
			scanf("%d",&n);
            delete(n);
            break;
        case 3:
			printf("Enter Element to search -: ");
			scanf("%d",&n);
        	searching(root,n);
        	break;
        case 4:    
            inorder(root);
            break;
        case 5:    
            preorder(root);
            break;
        case 6:    
            postorder(root);
            break;
        case 7:
        	display(root,1);
        	break;
        case 8:    
        	deallocate(root);
            exit(0);
        default :     
            printf("Wrong choice, Please enter correct choice  ");
            break;    
        }
    }
}

/* To search correct position where node has to be inserted */
void Insertsearch(struct btnode *ptr)
{
	if(ptr->value > temp->value && ptr->l != NULL)	
	Insertsearch(ptr->l);
	else if(ptr->value < temp->value && ptr->r != NULL)	
	Insertsearch(ptr->r);
	else if(ptr->value > temp->value && ptr->l == NULL)	
	ptr->l = temp;
	else if(ptr->value < temp->value && ptr->r == NULL)	
	ptr->r = temp;
}

/* To insert a node */
void insert()
{
	int n;
	printf("Elemnt to insert -: ");
	scanf("%d",&n);
	temp = (struct btnode*)malloc(sizeof(struct btnode));
	temp->value = n;
	temp->l = NULL;
	temp->r = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		Insertsearch(root);
	}
}

/* For searching an element in binary tree */
void searching(struct btnode * ptr,int n)
{
	if (root == NULL)
    {
        printf("No elements in a tree to Search \n");
        return;
    }
	if(ptr != NULL)
	{
		if(ptr->value == n)
		{
			printf("Found\n");
			return;
		}
		else if(ptr->value > n)
		{
			searching(ptr->l,n);
		}
		else if(ptr->value < n)
		{
			searching(ptr->r,n);
		}
	}
	else 
	{
		printf("Not Found\n");
	}
}

/* for inorder traversal */
void inorder(struct btnode * ptr)
{
	if (root == NULL)
    {
        printf("No elements in a tree to display \n");
        return;
    }
	if(ptr != NULL)
	{
		inorder(ptr->l);
		printf("%d ",ptr->value);
		inorder(ptr->r);
	}
		
}
/* for preorder traversal */
void preorder(struct btnode * ptr)
{
	if (root == NULL)
    {
        printf("No elements in a tree to display \n");
        return;
    }
	if(ptr != NULL)
	{
		printf("%d ",ptr->value);
		preorder(ptr->l);
		preorder(ptr->r);
	}
		
}
/* for postorder traversal */
void postorder(struct btnode * ptr)
{
	if (root == NULL)
    {
        printf("No elements in a tree to display \n");
        return;
    }
	if(ptr != NULL)
	{
		postorder(ptr->l);
		postorder(ptr->r);
		printf("%d ",ptr->value);
	}
		
}

/* To display whole Binary Tree */
void display(struct btnode * ptr,int level)
{
	int i;
	if (root == NULL)
    {
    	printf("No elements in a tree to display \n");
        return;
    }
	if(ptr != NULL)
	{
		display(ptr->r,level + 1);
		printf("\n");
		for(i = 0;i < level;i++)
		{
			printf("      ");
		}
		printf("%d",ptr->value);
		display(ptr->l,level+1);
	}	
}

/* To find the smallest element in the right sub tree */
int smallest(struct btnode *ptr)
{
	if(ptr->l!= NULL)
	{
		smallest(ptr->l);
	}	
	else
	{
		return ptr->value ;
	}
}

/* To delete a node from binary tree */
void deleting(struct btnode *t)
{
	int k;
	/* if node is a leaf */
	if((t->l == NULL) &&( t->r == NULL))
	{
		/* if root is the only element in tree */
		if(t == root)				
		{
			root = NULL;
			free(t);
		}
	    else if(t1->l == t)
		{
			t1->l = NULL;
		}
		else
		{
			t1->r = NULL;
		}
		t= NULL;
		free(t);
		return;
	}
	/* if node has only right child */
	else if(t->r != NULL && t->l == NULL)
	{
		while(t->r != NULL)
		{
			t1 = t;
			t = t->r;
			t1->value = t->value;
		}
		t1->r = NULL;
		t = NULL;
		free(t);
		return;
	}
	/* if node has only left child */
	else if(t->l != NULL && t->r == NULL)
	{
		while(t->l != NULL)
		{
			t1 = t;
			t = t->l;
			t1->value = t->value;
		}
		t1->l = NULL;
		t = NULL;
		free(t);
		return;
	}
	else
	{
  		k = smallest(t->r);
		delete(k);				//deleting a leaf
		t->value = k;
	}
}

/* To search which node has to be deleted from binary tree */
void searchDelete(struct btnode *t, int data)
{
    if ((data > t->value))
    {
        t1 = t;
        searchDelete(t->r, data);
    }
    else if ((data < t->value))
    {
        t1 = t;
        searchDelete(t->l, data);
    }
    else if ((data == t->value))
    {
		deleting(t);
    }
}

void delete(int n)
{	
	if(root != NULL)
	{
		t1 = root;				// t1 is used to keep track of previous node to the node which has to be deleted
		searchDelete(root,n);
	}
	else
	{
		printf("There is no element to delete\n");
	}
}
void deallocate(struct btnode * ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	deallocate(ptr->l);
	deallocate(ptr->r);
	free(ptr);
}
