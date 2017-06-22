#include<stdio.h>
#include<stdlib.h>

int graph[50][50];

void findNumberOfTraingles(int n)
{
  int count = 0;
  for(int i = 0;i < n;i++)
  {
    for(int j = 0;j < n;j++)
    {
      for(int k = 0;k < n;k++)
      {
        if(i != j && j != k && k != i && graph[i][j] && graph[j][k] && graph[k][i])
        {
          count++;
        }
      }
    }
  }
  printf("%d",count / 6); // Each triangle is counted 6 times 

int main()
{
  int m,n;
  int u,v;

  scanf("%d %d",&m,&n);
  for(int i = 0;i < m;i++)
  {
    scanf("%d %d",&u,&v);
    graph[u-1][v-1] = 1;
  }
  findNumberOfTraingles(n);
}
