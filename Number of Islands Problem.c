#include<stdio.h>

int n,m;

/**  DFS Code **/
void DFS(int a[][n],int visited[][n],int i,int j)
{
	visited[i][j] = 1;
	int row,col;
	for(row = i - 1;row <= i + 1 && row < m; row++)
	{
		for(col = j - 1;col <= j + 1 && col < n; col++)
		{
			if(row >= 0 && col >= 0 && a[row][col] && !visited[row][col])
			{
				DFS(a,visited,row,col);
			}
		}
	}
}

int countIslands(int a[][n],int visited[][n])
{
	int i,j;
	int count = 0;
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			if(a[i][j] && !visited[i][j])
			{
				DFS(a,visited,i,j);
				count++;
			}
		}
	}
	return count;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
  	scanf("%d %d",&m,&n);
  	int visited[m][n];
  	int a[m][n];
  	int ans,i,j;
  	for(i = 0;i < m;i++)
  	{
  		for(j = 0;j < n;j++)
  		{
  			visited[i][j] = 0;
  			scanf("%d",&a[i][j]);
  		}
  	}
  	ans  = countIslands(a,visited);
  	printf("%d\n",ans);
  }
}
