// Complexity O(n^2)

#include<stdio.h>

void swap(int *x ,int *y)
{
  int t;
  t = *x;
  *x = *y;
  *y = t;
}

void sort(int a[], int n)
{
  for(int i = 0;i < n-1;i++)
  {
    for(int j = i+1;j < n;j++)
    {
      if(a[i] > a[j])
      {
        swap(&a[i],&a[j]);
      }
    }
  }
}

void find_triplet(int a[], int n,int k)
{
  int l,r;
  sort(a,n);
  for(int i = 0;i < n - 2;i++)
  {
    l = i + 1;
    r = n - 1;
    while(l < r)
    {
     // printf("%d\n",a[i] + a[l] + a[r]);
      if(a[i] + a[l] + a[r] == k)
      {
        printf("%d %d %d\n",a[i],a[l],a[r]);
        l++;
        r--;
      }
      else if(a[i] + a[l] + a[r]  < k)
      {
        l++;
      }
      else
      {
        r--;
      }
    }
  }
}

int main()
{
  int n,a[100];
  int k;
  printf("Enter the size of array : ");
  scanf("%d",&n);
  printf("Enter the array -: \n");
  for(int i = 0; i < n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the value of sum : ");
  scanf("%d",&k);
  find_triplet(a,n,k);
}
