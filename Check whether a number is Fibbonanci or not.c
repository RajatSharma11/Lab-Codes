// To check whether a numbner is Fibbonacci number or not
// If a number is Fibbonanci then one or both of (5 * n ^ 2 + 4 , 5 * n ^ 2 - 4) is perfect square

#include<stdio.h>
#include<math.h>

int isPerfectSquare(int n)
{
  int s = sqrt(n);
  return s * s == n; 
}

void checkFibbonaci(int n)
{
  if(isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4))
  {
    printf("Yes\n");
    return;
  }
  printf("No\n")
}

int main()
{
  int n;
  printf("Enter The number for checking : ");
  scanf("%d",&n);
  checkFibbonaci(n);
  return 0;
}
