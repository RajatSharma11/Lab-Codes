// Approach: Using BitWise Operations (XOR)
// Complexity : O(n)
// Let x and y be the non-repeating elements we are looking for and arr[] be the input array. First calculate the XOR of all the array 
// elements.
// xor = arr[0]^arr[1]^arr[2].....arr[n-1]
// All the bits that are set in xor will be set in one non-repeating element (x or y) and not in other. So if we take any set bit of 
// xor and divide the elements of the array in two sets – one set of elements with same bit set and other set with same bit not set. 
// By doing so, we will get x in one set and y in another set. Now if we do XOR of all the elements in first set, we will get first 
// non-repeating element, and by doing same in other set we will get the second non-repeating element.

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
First sort all the elements. In the sorted array, by comparing adjacent elements we can easily get the non-repeating elements. 
Time complexity of this method is O(nLogn)
