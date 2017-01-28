//To implement Tower of Hanoi problem using Recursion

#include<stdio.h>

void tower_of_hanoi(int ,int ,int ,int);

int main()
{
	int no_of_disks;
	int A = 1,B = 2,C = 3;
	printf("Enter Number of Disks -: ");
	scanf("%d",&no_of_disks);
	
	tower_of_hanoi(no_of_disks,A,C,B);
}

void tower_of_hanoi(int n,int A,int C,int B)
{
	if(n == 1)													// Base Case
	{
		printf("Transfer disk %d from %d to %d\n",n,A,C);
		return;
	}
	
	tower_of_hanoi(n-1,A,B,C);									//Move n-1 disks from pole A to B using C
	printf("Transfer disk %d from %d to %d\n",n,A,C);			//Move remaining disk from pole A to C
	tower_of_hanoi(n-1,B,C,A);									//Move n-1 disks from pole B to C using A
}
