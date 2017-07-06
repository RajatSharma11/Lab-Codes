#include<stdio.h>

int toggle(int n,int l,int r)
{
  int num = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);    // this generates the binary number with r bits and bits only between l and are set
  n = n ^ num;
  return n;
}

int unsetBits(int n,int l,int r)
{
  int num = ((1 << (sizeof(int) * 8 - 1)) - 1);     // this generates the highest intger with all set bits.
  int temp = toggle(num,l,r);
  return n & temp;
}

int main()
{
  int n,l,r;
  printf("Enter the number whose bits in the given range has to be unset: ");
  scanf("%d",&n);
  printf("Enter the range (l,r) : ");
  scanf("%d %d",&l,&r);
  int ans = unsetBits(n,l,r);
  printf("%d\n",ans);
}
