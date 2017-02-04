/** Code to implement Heap maethods and Heap Sort **/

#include<stdio.h>
#include<math.h>

void swap(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

void minHeapify(int H[], int n, int index)
{
	int lindex, rindex, s;
	lindex = 2 * index + 1;
	rindex = 2 * index + 2;
	if(index >= (n / 2))					// if index is more than equals to n/2 then nothing to do
	{
		return;
	}
	if(rindex < n && H[rindex] < H[lindex])			// finding which child right or left is smaller
	{
		s = rindex;
	}
	else
	{
		s = lindex;
	}
	if(H[index] > H[s])					// swapping the parent with smaller child and calling minheapify to maintain heap property
	{
		swap(&H[s], &H[index]);
		minHeapify(H,n,s);
	}
}

void BuildHeap(int H[],int n)
{
	int i;
	for(i = (n / 2) - 1 ;i >= 0;i--)
	{
		minHeapify(H,n,i);
	}
}


void displayElements(int H[], int n)
{
	int i;
	if(n == 0)
	{
		printf("No elements to display\n\n");
	}
	else
	{
		for(i = 0;i < n;i++)
		{
			printf("%d  ",H[i]);
		}
	}
}

void deleteHeap(int H[], int index,int n)
{
	if(n == 0)
	{
		printf("No Element to delete\n\n");
	}
	if(n == 1)							// if only one element delete it
	{
		H[0] = -1;
	}
	else								// if more than one element is present delete top most and minHeapify to maintain heap property
	{
		swap(&H[index],&H[n - 1]);
		H[n - 1] = -1;
		minHeapify(H,n - 1,index);
	}
}

int findMin(int H[])
{
	return H[0];
}

int extractMin(int H[],int n)
{
	int min ;
	if(n == 0)
	{
		printf("Nothing to Extract\n\n");
		return 10;
	}
	min = H[0];
	deleteHeap(H,0,n);
	return min;
}


void HeapSort(int H[],int n)
{
	int i;
	for(i = 0;i < n ;i++)
	printf("%d ",extractMin(H,n - i));
}

void insert(int H[], int size,int num)
{
    int parent;
    while (size > 0)
    {
        parent = (size - 1)/2;
        if (num >= H[parent])				// if new number is greater than parent than simply insert
        {
            H[size] = num;
            return;
        }						// otherwise swap it with parent
        H[size] = H[parent];
        size = parent;
    }
    H[0] = num; 					//assign number to the root node 
}

void decreaseKey(int H[],int index,int newKey,int n)
{
	int parent;
	if(H[index] < newKey)				// if new key is greater than previous key than change key and call minHeapify at that index
	{
		printf("Sorry you are not Decreasing Key rather You are increasing it\n\n");
	}
	else				// if new key is less than previous key than change key and call minHeapify at the parent of that index
	{
		parent = (index - 1) / 2;
		H[index] = newKey;
		while(H[index] < H[parent])
		{
			swap(&H[index],&H[parent]);
			index = parent;
			parent = (parent - 1) / 2;
		}
	}
}

int main()
{
	int choice,a[50],n,i,j = 0,k = 0;
	int value;
	int min,extractedMin,newKey,index;
	do{
		printf("\nEnter Your Choice \n");
		printf("Press 1) for BuildHeap\n");
		printf("Press 2) for Find Min\n");
		printf("Press 3) for Extract Minimum\n");
		printf("Press 4) for Decrease Key\n");
		printf("Press 5) for Insert\n");
		printf("Press 6) for Display Elements\n");
		printf("Press 7) for HeapSort\n");
		printf("Press 8) for Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Array Size to Build Heap\n");
				scanf("%d",&n);
				printf("Enter your Array \n");
				for(i = j;i < n + j;i++)
				{
					scanf("%d",&a[i]);
				}
				BuildHeap(a,n + j);
				j = j + n;
				break;
			case 2:
				min = findMin(a);
				printf("Min is %d ",min);
				break;
			case 3:
				extractedMin = extractMin(a,j);
				if(extractedMin != 10)			// if heap ios already empty
				{
					j--;
					printf("Min is Extraxted from heap & min is %d\n\n",extractedMin);
				} 
				break;
			case 4:
				printf("Enter index whose key is to be decreased : ");
				scanf("%d",&index);
				printf("Enter new Key Value : ");
				scanf("%d",&newKey);
				decreaseKey(a,index - 1,newKey,j);
				break;
			case 5:
				printf("Enter a value to insert in Heap : ");
				scanf("%d",&value);
				if(j < 50)
				insert(a,j++,value);
				else
				printf("Cannot insert Number limit reached\n");
				break;
			case 6:
				displayElements(a,j);
				break;
			case 7:
				HeapSort(a,j);
				j = 0;
				break;
			case 8:
				return(0);
			default:
				printf("Please Enter valid Choice\n");
		}
	}while(1);
	return 11;
}



