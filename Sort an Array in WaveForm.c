// Given an unsorted array of integers, sort the array into a wave like array. An array ‘arr[0..n-1]’ is sorted in wave form 
// if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
// Complexity : O(n)
// The idea is based on the fact that if we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than 
// their adjacent odd elements, we don’t need to worry about odd positioned element. Following are simple steps.
// 1) Traverse all even positioned elements of input array, and do following.
// a) If current element is smaller than previous odd element, swap previous and current.
// b) If current element is smaller than next odd element, swap next and current.

#include<stdio.h>

void swap(int *x, int*y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sortInWaveForm(int a[], int n)
{
  for(int i = 0;i < n;i += 2)
  {
    if(i > 0 && a[i - 1] > a[i])
    {
      swap((a + i - 1),(a + i));
    }
    if(i < n - 1 && a[i] < a[ i + 1])
    {
      swap((a + i),(a + i + 1));
    }
  }
}

int main()
{
  int n, a[100];
  printf("Enter total number of elements : ");
  scanf("%d",&n);
  printf("Enter the array : ");
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&a[i]);
  }
  sortInWaveForm(a,n);
   for(int i = 0;i < n;i++)
  {
    printf("%d ",a[i]);
  }
  return 0;
}

________________________________________________________________________________________________________________________________
Alternate Approach:
1) First Sort the given array
2) Swap all adjacent elements
Complexity : O(nlog(n))
