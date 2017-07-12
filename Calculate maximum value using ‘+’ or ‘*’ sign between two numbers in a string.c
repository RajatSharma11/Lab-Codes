// Given a string of numbers, the task is to find the maximum value from the string, you can add a ‘+’ or ‘*’ sign between any two numbers.
// Approach: we can get the maximum value on multiplying all values but the point is to handle the case of 0 and 1 i.e. On multiplying with
//           0 and 1 we get the lower value as compared to on adding with 0 and 1.
//           So, use ‘*’ sign between any two numbers(except numbers containing 0 and 1) and use ‘+’ if any of the number is 0 and 1.

#include<stdio.h>
#include<string.h>

int calculate(char s[])
{
  int count = s[0] - 48;
  for(int i = 1;i < strlen(s);i++)
  {
    if(s[i] == 48 || s[i] == 49 || s[i - 1] == 48 || s[i - 1] == 49)
    {
      count += s[i] - 48;
    }
    else
    {
      count *= s[i] - 48;
    }
  }
  return count;
}

int main()
{
  char s[100];
  printf("Enter the String whose value is to be calculated : ");
  scanf("%s",s);
  int ans = calculate(s);
  printf("Maximum possible value of string %s is %d\n",s,ans);
  return 0;
}
