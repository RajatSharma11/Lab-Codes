// Merge Sort Complexity O( log(n) )
// Algo Paradigm -: Divide and Conqure

#include<stdio.h>

void merge(int a[],int l,int m,int r)
{
  int n1 = m - l + 1 ;
  int n2 = r - m;
  int L[n1],R[n2];            // creating Temporary Array
  for(int i = 0;i < n1;i++)
  {
    L[i] = a[l+i];
  }
  for(int i = 0;i < n2;i++)
  {
    R[i] = a[m + i + 1];
  }
  
  int i = 0;
  int j = 0;
  int k = l;
  
  while(i < n1 && j < n2)
  {
    if(L[i] > R[j])
    {
      a[k++] = R[j];
      j++;
    }
    else
    {
      a[k++] = L[i];
      i++;
    }
  }
  while(i < n1)       // if array R is finished and array L is left
  {
    a[k++] = L[i];
    i++;
  }
  while(j < n2)     // if array L s finished and array R is left
  {
    a[k++] = R[j];
    j++;
  }
}

void mergeSort(int a[],int l,int r)
{
  if(l < r)                   // Condition to stop recursion
  {
    int m = l + (r - l) / 2;
    mergeSort(a,l,m);
    mergeSort(a,m + 1,r);
    merge(a,l,m,r);
  }
}

int main()
{
  int n,a[100];
  printf("Enter the size of array to be sorted : ");
  scanf("%d",&n);
  printf("Enter the array :\n");
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&a[i]);
  }
  mergeSort(a,0,n-1);
  printf("Sorted array is : \n");
  for(int i = 0;i < n;i++)
  {
    printf("%d  ",a[i]);
  }
}
