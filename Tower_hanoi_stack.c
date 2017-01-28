//To implement Tower of Hanoi using Stacks

#include<stdio.h>
#include<stdlib.h>

struct Snapshot
{
	int A,B,C;
	int n;
	int stage;
};

void tower_hanoi(int n,int A,int C,int B)
{
	struct Snapshot Snapshotstack[1000],currentsnapshot,newsnapshot;
	int stacktop = -1;   // initial stack is empty
	
	/* Push initial Values */
	currentsnapshot.A = A;
	currentsnapshot.B = B;
	currentsnapshot.C = C;
	currentsnapshot.n = n;
	currentsnapshot.stage = 0;
	stacktop = 0;
	Snapshotstack[stacktop] = currentsnapshot;
	while(stacktop >= 0)
	{
		/* Pop current values to be used */
		currentsnapshot = Snapshotstack[stacktop];
		stacktop --;
		switch(currentsnapshot.stage)
		{
			case 0:
				if(currentsnapshot.n == 1)
				{
					printf("\nMove disk %d from %d to %d ",currentsnapshot.n,currentsnapshot.A,currentsnapshot.C);
					continue;
				}
				if(currentsnapshot.n > 1)
				{
					currentsnapshot.stage = 1;  /* 	Stage to continue,after returning from 1st recursion */
					stacktop++;
					/* Push details to be used after returning from 1st recursion */
					Snapshotstack[stacktop] = currentsnapshot;
					newsnapshot.n = currentsnapshot.n - 1;
					newsnapshot.A = currentsnapshot.A;
					newsnapshot.B = currentsnapshot.C;
					newsnapshot.C = currentsnapshot.B;
					newsnapshot.stage = 0;
					stacktop++;
					Snapshotstack[stacktop] = newsnapshot;
					continue;
				}
				break;
			case 1:
				printf("\nMove Disk %d from %d to %d ",currentsnapshot.n,currentsnapshot.A,currentsnapshot.C);
				
				currentsnapshot.stage = 2;    /* 	Stage to continue,after returning from 2nd recursion */
				stacktop++;
				/* Push details to be used after returning from  recursion */
				Snapshotstack[stacktop] = currentsnapshot;
				newsnapshot.A = currentsnapshot.B;
				newsnapshot.B = currentsnapshot.A;
				newsnapshot.C = currentsnapshot.C;
				newsnapshot.n = currentsnapshot.n - 1;
				newsnapshot.stage = 0;
				stacktop++;
				Snapshotstack[stacktop] = newsnapshot;
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
	int no_of_disks;
	int A = 1,B = 2,C = 3;
	printf("Enter Number of Disks -: ");
	scanf("%d",&no_of_disks);
	if(no_of_disks > 0)
	{
		tower_hanoi(no_of_disks,A,C,B);
	}
	else if(no_of_disks == 0)
	{
		printf("No disk to transfer\n");
	}
	else
	{
		printf("Enter Valid number of disks\n");
	}
}
