/** This Program Impelments Binary Search Algorithm **/
/** Worst Case Complexity O(log n) **/

#include<stdio.h>
int main()
{
	int size;
	printf("Enter the Size of Sorted Array -:  ");
	scanf("%d", &size);
	int array[size];
	int item;
	int p = 0 , r = size-1,q;
	
	printf("Enter the array -:\n");
	for(int i = 0;i < size;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Enter the item to find -: ");
	scanf("%d",&item);
	
	while(r >= p)
	{
		q = (p + r) / 2;
		if(array[q] == item)
		{
			printf("Item found at position %d",q+1);
			return 11;
		}
		else
		{
			if(array[q] > item)
			{
				r = q - 1;
			}
			else
			{
				p = q + 1;
			}
		}
	}
	printf("Sorry! Item not Found");
}
