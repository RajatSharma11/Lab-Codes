/** Program To find kth Smallest Element in an Unsorted Array **/

#include<stdio.h>
#include<math.h>

void swap(int *x,int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

/** It searches for x in arr[l..r], and partitions the array  around x. **/
int partition(int a[],int l,int r,int medOfMed)
{
	/** Search for x in arr[l..r] and move it to end **/
    int i,j;
    for (i = l; i < r; i++)
        if (a[i] == medOfMed)
           break;
    swap(&a[i], &a[r]);
 
    i = l;
    for (j = l; j <= r - 1; j++)
    {
        if (a[j] <= medOfMed)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[r]);
    return i;
	
}

/** Sorting using Insertion Sort **/
int sort(int a[],int l,int r)
{
	int i,j;
	
	for(i = l ;i <= r;i++)
	{
		for(j = l; j < i;j++)
		{
			if(a[j] > a[i])
			{
				swap(&a[i],&a[j]);
			}
		}
	}
		
	return a[l+(r-l)/2];
}

int kthSmallest(int a[],int l,int r,int item)
{
	if(item > 0 && item <= (r - l + 1))
	{
		int total_items = r - l + 1;			// Number of elements in a[l..r]
		int j = l;
		
		int n = (total_items + 4) / 5;		// There will be floor((n+4)/5) groups;
		
		// Divide arr[] in groups of size 5, calculate median of every group and store it in median[] array.
        
		int median[n];		
		int i;
		for(i = 0; i < total_items / 5;i++)
		{
			median[i] = sort(a,j,j+4);
			j+=5;
		}
		if (i * 5 < total_items) //For last group with less than 5 elements
        {
            median[i] = sort(a,j,total_items - j); 
            i++;
        }    

		// Find median of all medians using recursive call.If median[] has only one element, then no need of recursive call
        int medOfMed = (i == 1) ? median[i-1] : kthSmallest(median, 0, i-1, i/2);
                               
                                 
        // Partition the array around medOfMed  and get position of pivot element in sorted array
        
        int pos = partition(a,l,r,medOfMed);
  
		
        // If position is same as k
        if(pos - l == item - 1) 
        {
        	return a[pos];
		}
		// If position is more, recur for left
		else if(pos - l > item - 1)
		{
			return (kthSmallest(a,l,pos - 1,item));
		}
		 // Else recur for right subarray
		else
		{
			return (kthSmallest(a,pos + 1,r,item - pos + l -1));
		}
	}
	else
	{
		printf("Please Enter Valid Value\n");
		exit(0);
	}
	return 0;
}



int main()
{
	int arr[50];
    int n,k,i;
    printf("Enter total number of Entries : ");
    scanf("%d",&n);
    printf("Enter the unsorted Integers for finding Kth largest number\n");
    for(i = 0;i < n;i++)
	{
    	scanf("%d",&arr[i]);
	}
	
	//printf("Enter Entry which you want to find :");
    //scanf("%d",&k);
    
   	k = ceil(n / 2.0);				// For median
    printf("\nMedian is %d \n",  kthSmallest(arr, 0, n-1, k));
    return 0;
}
