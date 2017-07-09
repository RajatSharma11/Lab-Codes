// Approach : 1. Calculate XOR of A and B.   a_xor_b = A ^ B
//            2. Count the set bits in the above calculated XOR result. countSetBits(a_xor_b)

// Note : XOR of two number will have set bits only at those places where A differs from B.

#include<stdio.h>

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    n = n & (n - 1);
    count += 1;
  }
  return count;
}

int flippedBits(int a, int b)
{
  int a_xor_b = a ^ b;
  int ans = countSetBits(a_xor_b);
  return ans;
}
int main()
{
  int a,b;
  printf("Enter two numbers A and B : ");
  scanf("%d %d",&a,&b);
  printf("Number of bits to be flipped to convert %d to %d are : ",a,b);
  printf("%d\n",flippedBits(a,b));
  return 0;
}
