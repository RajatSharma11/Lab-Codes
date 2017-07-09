// A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.
// Complexity : O(nlog(n)

#include<stdio.h>

int countSetBits(int n)
{
  int count = 0;
  while(n)
  {
    n = n & (n - 1);
    count += 1;
  }
  return count;
}

int isBleak(int n)
{
  for(int i = 1;i < n;i++)
  {
    if(i + countSetBits(i) == n)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int n;
  printf("Enter number to be checked : ");
  scanf("%d",&n);
  if(isBleak(n))
  {
    printf("Yes, %d is a Bleak\n",n);
  }
  else
  {
   printf("No, %d is not a Bleak\n",n); 
  }
  return 0;
}
