//The main idea of the solution is, while traversing from top to bottom, the first node n we encounter with value between n1 and n2, i.e., n1 < n < n2 or same as one of the n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2). So just recursively traverse the BST in, if node’s value is greater than both n1 and n2 then our LCA lies in left side of the node, if it’s is smaller than both n1 and n2, then LCA lies on right side. Otherwise root is LCA (assuming that both n1 and n2 are present in BST)

// Complexity O(h), h is height of the tree

#include<stdio.h>
#include<stdlib.h>

struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
}*root = NULL;

void searchInsert(struct tree *r,struct tree *ptr)
{
  if(r->data > ptr->data && r->left != NULL)
  {
    searchInsert(r->left,ptr);
  }
  else if(r->data < ptr->data && r->right != NULL)
  {
    searchInsert(r->right,ptr);
  }
  else if(r->data > ptr->data && r->left == NULL)
  {
    r->left = ptr;
  }
  else if(r->data < ptr->data && r->right == NULL)
  {
    r->right = ptr;
  }
}

void addNode(int u)
{
  struct tree *temp;
  temp =(struct tree*)malloc(sizeof(struct tree));
  temp->data = u;
  temp->left = NULL;
  temp->right = NULL;
  if(root == NULL)
  {
    root = temp;
  }
  else
  {
    searchInsert(root,temp);
  }
}
/* Recursive Function

struct tree* LCA(struct tree *r, int n1,int n2)
{
  if(r == NULL)
  {
    return NULL;
  }
  if(r->data > n1 && r->data > n2)
  {
    return LCA(r->left,n1,n2);
  }
  if(r->data < n1 && r->data < n2)
  {
    return LCA(r->right,n1,n2);
  }
  return r;
}
*/

/** Iterative Function **/
struct tree* LCA(struct tree *r, int n1,int n2)
{
  while(r != NULL)
  {
     if(r->data > n1 && r->data > n2)
     {
       r = r->left;
     }
     else if(r->data < n1 && r->data < n2)
     {
       r = r->right;
     }
    else
    {
      break;
    }
  }
  return r;
}

int main()
{
  int n,n1,n2;
  printf("Enter the nodes of tree : ");
  scanf("%d",&n);
  while(n != -1)
  {
    addNode(n);
    scanf("%d",&n);
  }
  printf("Enter two numbers whose LCA is to be found: ");
  scanf("%d %d",&n1,&n2);
  struct tree *temp = LCA(root,n1,n2);
  printf("The LCA of %d and %d is %d\n",n1,n2,temp->data);
}
