// Approach: Using BitWise Operations (XOR)
// Complexity : O(n)

#include<stdio.h>

void findNumbers(int a[],int n,int *x, int *y)
{
  *x = 0;
  *y = 0;
  int xor_result = a[0];
  for(int i = 1;i < n;i++)
  {
    xor_result ^= a[i];
  }
  int set_bit_no = xor_result & ~(xor_result - 1);
  for(int i = 0;i < n;i++)
  {
    if(a[i] & set_bit_no)
    {
      *x = *x ^ a[i];
    }
    else
    {
      *y = *y ^ a[i];
    }
  }
  
}

int main()
{
  int n,a[100];
  int *x = (int *)malloc(sizeof(int));
  int *y = (int *)malloc(sizeof(int));
  printf("Enter the size of array : ");
  scanf("%d",&n);
  printf("Enter the Array : \n");
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&a[i]);
  }
  findNumbers(a,n,x,y);
  printf("Two Non-Repeating Numbers in Array are %d and %d\n",*x,*y);
  return 0;
}

_________________________________________________________________________________________________________________________________

Alternate Approach :
Use Sorting
