#include<stdio.h>

int gcd(int a, int b)
{
  if(a == 0)
  {
    return b;
  }
  return gcd(b%a,a);
}

int main()
{
  int n;
  int count;
  scanf("%d",&n);
  for(int i = 1;i < n;i++)
  {
    if(gcd(i,n) == 1)
    {
      count++;
    }
  }
  printf("%d",count);
}
