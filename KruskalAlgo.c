/** Kruskal Algorithm **/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct graph{			// Structure of node in heap
	int u;
	int v;
	int weight;
	int flag;			// flag is for marking edges which are added in set T
}list[50];

struct subset			// structure for Union find And compression
{
    int parent;
    int rank;
}subset[50];

int n;					// total number of edges in graph

void swap(struct graph *x,struct graph *y)
{
	struct graph t;
	t = *x;
	*x = *y;
	*y = t;
}

void minHeapify(struct graph H[],int index)
{
	int lindex, rindex, s;
	lindex = 2 * index + 1;
	rindex = 2 * index + 2;
	if(index >= (n / 2))					// if index is more than equals to n/2 then nothing to do
	{
		return ;
	}
	if(rindex < n && H[rindex].weight < H[lindex].weight)		// finding which child weight , right or left is smaller
	{
		s = rindex;
	}
	else
	{
		s = lindex;
	}
	if(H[index].weight > H[s].weight)					// swapping the parent with smaller child and calling minheapify to maintain heap property
	{
		swap(&H[s], &H[index]);
		minHeapify(H,s);
	}
}

void BuildHeap(struct graph H[])
{
	int i;
	for(i = (n / 2) - 1 ;i >= 0;i--)
	{
		minHeapify(H,i);
	}
}

struct graph extractMin(struct graph H[])
{
	struct graph min = H[0];
	swap(&H[0],&H[n - 1]); 
	n--;									// reducing no of Edges by 1
	minHeapify(H,0);
	return min;
}
 
 void MakeSet()
 {
 	int i;
 	for(i = 0;i < n;i++)
 	{
 		subset[i].parent = i;
		subset[i].rank = 0;
	}
 }
 
int find(int u)						// Using path Compression for find
 {
 	if(u != subset[u].parent)
 	{
 		subset[u].parent = find(subset[u].parent );
 		
	}
	return subset[u].parent ;	
 }
 
 void Union(int u, int v)
 {
 	int rep1,rep2;
 	rep1 = find(u);
 	rep2 = find(v);
 	if(rep1 == rep2)
 	{
 		return;
	}
	// Attach smaller rank tree under root of high rank tree
	if (subset[rep1].rank < subset[rep2].rank)
        subset[rep1].parent = rep2;
    else if (subset[rep1].rank > subset[rep2].rank)
        subset[rep2].parent = rep1;
 
    // If ranks are same, then make one as root and increment its rank by one
    else
    {
        subset[rep2].parent = rep1;
        subset[rep1].rank++;
    }
 }
 

int main()
{
	int vertices,v1 = 0,v2,weight,i,j,k = 0;
	int dist[50];
	int noOfQuery;
	int sourceVertex;
	int noOfEdges = 0;
	struct graph temp;
	int count = 0;
	
	printf("Enter the no of vertices\n");
	scanf("%d",&vertices);
	for(i = 0;i < vertices;i++)
	{
		scanf("%d",&noOfQuery);
		for(j = 0;j < noOfQuery;j++)
		{
			scanf("%d %d",&v2,&weight);	
			list[k].u = v1;
			list[k].v = v2 - 1;
			list[k].weight = weight;
			list[k].flag = 0;
			noOfEdges++;
			k++;
		}
		v1++;
	}
	n = noOfEdges;
	BuildHeap(list);
	MakeSet();
	
	for(i = 0;i < noOfEdges;i++)
	{
		temp = extractMin(list);
		if(find(temp.u) != find(temp.v))
		{
			list[noOfEdges - i - 1].flag = 1;
			count++;
			Union(temp.u,temp.v);
		}
	}
	if(count == vertices - 1)			// condition for connected graph
	{
		printf("\nu\t\tv\t\tweight\n");
		for(i = 0;i < noOfEdges;i++)
		{
			if(list[i].flag == 1)
			{
				printf("%d\t\t%d\t\t   %d\n",list[i].u+1,list[i].v+1,list[i].weight);
			}
		}
	}
	else
	{
		printf("\nGraph is not Connected\n");
	}
	return 0;
}
