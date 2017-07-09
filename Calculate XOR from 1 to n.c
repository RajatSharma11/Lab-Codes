// Approach : 1- Find the remainder of n by moduling it with 4.
//            2- If rem = 0, then xor will be same as n.
//            3- If rem = 1, then xor will be 1.
//            4- If rem = 2, then xor will be n+1.
//            5- If rem = 3 ,then xor will be 0.

#include<stdio.h>

int computeXor(int n)
{
  if(n % 4 == 0)
  {
    return n;
  }
  else if(n % 4 == 1)
  {
    return 1;
  }
  else if(n % 4 == 2)
  {
    return n + 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int n;
  printf("Enter the number upto which xor is to be computed : ");
  scanf("%d",&n);
  printf("%d\n",computeXor(n));
  return 0;
}
