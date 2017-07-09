// Naive Apporach 
// Complexity-: Theta(log(n))
// Apporach : Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count.

#include<stdio.h>

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)                // run loop till n not equal to 0
  {
    count += n & 1;
    n >>= 1;              // right shift n by 1 bit each time
  }
  return count;
}

int main()
{
  int n;
  printf("Enter Number in which number of set bits are to be found : ");
  scanf("%d",&n);
  printf("\nTotal number of set bits in %d are : ",n);
  printf("%d\n",countSetBits(n));
}

___________________________________________________________________________________________________________________________________

// Brian Kernighan’s Algorithm  
// Complexity: O(log(n)
// Approach : Subtraction of 1 from a number toggles all the bits (from right to left) till the rightmost set bit(including the righmost
//            set bit). So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the righmost set bit. If we do
//            n & (n-1) in a loop and count the no of times loop executes we get the set bit count.

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
int main()
{
  int n;
  printf("Enter Number in which number of set bits are to be found : ");
  scanf("%d",&n);
  printf("\nTotal number of set bits in %d are : ",n);
  printf("%d\n",countSetBits(n));
}
