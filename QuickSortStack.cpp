#include<stdio.h>

struct snapshot
{
	int l;
	int u;
	int posn;
	int stage;
};

void swap(int *x,int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
int partition(int a[],int l,int u)
{
	int i = l - 1,pivot = a[u];
	for(int j = l;j < u;j++)
	{
		if(a[j] <= pivot)
		{
			i++;
			swap((a + i),(a + j));
		}
	}
	swap((a + i + 1),(a + u));
	return (i + 1);
}
void qsort(int a[],int l,int u)
{
	struct snapshot snapshotStack[100],currentsnapshot,newsnapshot;
	int stacktop = -1;
	currentsnapshot.l = 0;
	currentsnapshot.u = u;
	currentsnapshot.posn = u;
	currentsnapshot.stage = 0;
	stacktop++;
	snapshotStack[stacktop] = currentsnapshot;
	while(stacktop >= 0)
	{
		currentsnapshot = snapshotStack[stacktop];
		stacktop--;
		switch(currentsnapshot.stage)
		{
			case 0:
				if(currentsnapshot.l < currentsnapshot.u)
				{
					currentsnapshot.posn = partition(a,currentsnapshot.l,currentsnapshot.u);
					currentsnapshot.stage = 1;
					stacktop++;
					snapshotStack[stacktop] = currentsnapshot;
					newsnapshot.l = currentsnapshot.l;
					newsnapshot.u = currentsnapshot.posn - 1;
					newsnapshot.stage = 0;
					stacktop++;
					snapshotStack[stacktop] = newsnapshot;
					continue;
				}
				break;
				case 1:
					currentsnapshot.stage = 2;
					stacktop++;
					snapshotStack[stacktop] = currentsnapshot;
					newsnapshot.l =  currentsnapshot.posn + 1;
					newsnapshot.u = currentsnapshot.u;
					newsnapshot.stage = 0;
					stacktop++;
					snapshotStack[stacktop] = newsnapshot;
					continue;
					break;
				case 2:
					continue;
					break;
		}
	}
}
int main()
{
	int a[100];
	int n;
	printf("Enter Total numbers to be sorted -: ");
	scanf("%d",&n);
	printf("Enter Your Numbers \n");
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,0,n - 1);
	printf("\n");
	for(int i = 0;i < n;i++)
	{
		printf("%d ",a[i]);
	}
}
