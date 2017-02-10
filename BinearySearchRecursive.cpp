/* This Program implements Binary Search Algorithm Recursively*/
/** Worst Case Complexity O(log n) **/

#include<stdio.h>
void binearysearch(int a[],int l,int u,int n)
{
	if(l <= u)
	{
	int mid = (l + u)/2;
	if(a[mid] == n)
	{
		printf("Elemnt %d is found at %d ",n,mid + 1);
		return;
	}
	else if(a[mid] < n)
	{
		binearysearch(a,mid+1,u,n);
	}
	else
	{
		binearysearch(a,l,mid-1,n);
	}
	}	
	else
	{
		printf("Not Found");
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
