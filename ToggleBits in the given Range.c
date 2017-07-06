#include<stdio.h>

int toggleBit(int n,int l,int r)
{
  int num;
  num = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);    // this will genarate a binary number with r bits and bits only between l and r set.
  
  n = n ^ num;
  return n;
  
}

int main()
{
  int n,l,r;
  printf("Enter the Integer whose bits in the given range to be toggled : ");
  scanf("%d",&n);
  printf("Enter the range (l , r) : ");
  scanf("%d %d",&l,&r);
  int ans = toggleBit(n,l,r);
  printf("%d\n",ans);
}
