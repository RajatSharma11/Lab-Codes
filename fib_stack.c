#include<stdio.h>
struct Snapshot
{
	int n;
	int stage;	
	int temp;
	int temp2;
};
int fib(int n)
{
	struct Snapshot snapshotStack[1000],currentsnapshot,newsnapshot;
	int stacktop = -1; //stack is initially empty
	int retVal = 0;
	/* Push initial Values */
	currentsnapshot.n = n;
	currentsnapshot.stage = 0;
	currentsnapshot.temp = 0;
	currentsnapshot.temp2 = 0;
	stacktop++;
	snapshotStack[stacktop] = currentsnapshot;
	while(stacktop >= 0)
	{
		/* Pop current values to be used */
		currentsnapshot = snapshotStack[stacktop];
		stacktop--;
		switch(currentsnapshot.stage)
		{
			case 0:
				if (currentsnapshot.n == 0)
				{
					currentsnapshot.temp2 = currentsnapshot.temp;
					snapshotStack[stacktop].temp2 = currentsnapshot.temp2;
					continue;
				}
				else if(currentsnapshot.n == 1)
				{
					currentsnapshot.temp =currentsnapshot.temp + 1;
					currentsnapshot.temp2 = currentsnapshot.temp;
					if(stacktop >= 0)
					{
						snapshotStack[stacktop].temp2 = currentsnapshot.temp2;
					}
					else
					{
						retVal = currentsnapshot.temp2;
					}
					continue;
				}
				else
				{
					currentsnapshot.stage = 1;		/* Stage to continue,after returning from 1st recursion */
					newsnapshot.temp = currentsnapshot.temp2;
					stacktop++;
					/* Push details to be used after returning from recursion */
					snapshotStack[stacktop] = currentsnapshot;
					newsnapshot.n = currentsnapshot.n - 1;
					newsnapshot.stage = 0;
					newsnapshot.temp2 = 0;
					stacktop++;
					snapshotStack[stacktop] = newsnapshot;
					continue;
				}
				break;
			case 1:
				
				currentsnapshot.stage = 2;		/* 	Stage to continue,after returning from 2nd recursion  */
				newsnapshot.temp = currentsnapshot.temp2;
				stacktop++;
				snapshotStack[stacktop] = currentsnapshot;
				newsnapshot.n = currentsnapshot.n - 2;
				newsnapshot.stage = 0;
				newsnapshot.temp2 = 0;
				stacktop++;
				snapshotStack[stacktop] = newsnapshot;
				continue;
				break;
			case 2:
					retVal = retVal + currentsnapshot.temp2;
					continue;
					break;
		}
	}
	return retVal;
}

int main()
{
	int n;
	printf("Enter which term of fibonacci series to be found -: ");
	scanf("%d",&n);
	if(n > 0)
	{
    	int f = fib(n - 1);
    	printf("%d",f);
    }
    else
    {
    	printf("Enter Valid Term Number \n");
	}
}

