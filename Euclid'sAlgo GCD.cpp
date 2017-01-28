#include<stdio.h>

int gcd(int a,int b)
{
	if(b == 0)
	{
		return a;
	}
	gcd(b,a % b);
}
int main()
{
	int a,b;
	printf("Enter Two Numbers - :");
	scanf("%d %d",&a,&b);
	if( a < b)
	{
		int t = a;
		a = b;
		b = t;
	}
	int g = gcd(a,b);
	printf("%d",g);
}
