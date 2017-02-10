/** This program implements Binary Search using Stack **/
#include<stdio.h>
struct snapshot
{
	int l,u;
};

void binearysearch(int a[],int l,int u,int n)
{
	snapshot snapshotStack[100],currentsnapshot,newsnapshot;
	int stacktop = -1;
	currentsnapshot.l = l;
	currentsnapshot.u = u;
	stacktop++;
	snapshotStack[stacktop] = currentsnapshot;
	while(stacktop >= 0)
	{
		currentsnapshot = snapshotStack[stacktop];
		stacktop--;
				int mid = (currentsnapshot.l + currentsnapshot.u)/2;
				if(a[mid] == n)
				{
					printf("Elemnt %d is found at %d ",n,mid + 1);
					break;
				}
				else if(a[mid] > n)
				{
					newsnapshot.l = currentsnapshot.l;
					newsnapshot.u = mid -1;
					stacktop++;
					snapshotStack[stacktop] = newsnapshot;
				}	
				else
				{
					newsnapshot.u = currentsnapshot.u;
					newsnapshot.l = mid + 1;
					stacktop++;
					snapshotStack[stacktop] = newsnapshot;
				}
		}
	}
int main()
{
	int size ,n;
	int a[100];
	printf("Enter size of the sorted Array -: ");
	scanf("%d",&size);
	printf("Enter Sorted Array -: \n");
	for(int i = 0;i < size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element -: ");
	scanf("%d",&n);
	binearysearch(a,0,size - 1,n);
}
