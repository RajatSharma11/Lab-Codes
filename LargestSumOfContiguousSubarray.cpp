#include<stdio.h>
int main()
{
	int array[100000];
	int n ,max_so_far = 0,max_end_here = 0;
	printf("Enter Total number of Elemnts -: ");
	scanf("%d",&n);
	printf("Enter Your Elemnts \n");
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&array[i]);
		max_end_here = max_end_here + array[i];
		if(max_end_here < 0)
		{
			max_end_here = 0;
		}
		else if(max_so_far < max_end_here)
		{
			max_so_far = max_end_here;
		}
	}
	printf("Largest Sum of Contiguous Subarray is %d\n",max_so_far);
	
}
