/**********
	Input format:

	First line : n (number of vertices of the graph)

	Second line : d1 (Number of neighbours of v1 whose vertex numbers are bigger than v1).

	Next d1 lines : vertex number of a higher numbered neighbour of v1 and the edge-weight of the corresponding edge (separated by a space).

	Next line : d2 ((Number of neighbours of v2 whose vertex numbers are bigger than v2).

	Next d2 lines : vertex number of a higher numbered neighbour of v2 and the edge-weight of the corresponding edge (separated by a space).

	and so on.. 

	Line m+n+2 : vertex number of the source vertex from which the shortest paths are to be computed 0(m is the number of edges).
			**********/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX

struct graph{
	int vertex;
	int weight;
	struct graph * next;
}*list[50];

struct vertexInfo{
	int distance;
	int index;
	int vertex;
	int visited;
	int pred;
} vertexInfo[50];

void addEdge(int v1,int v2,int weight)
{
	struct graph * temp;
	temp = (struct graph *)malloc(sizeof(struct graph));
	if(temp != NULL)
	{
		temp->vertex = v2;
		temp->weight = weight;
		if(list[v1] == NULL)
		{
			temp->next = NULL;
			list[v1] = temp;
		}
		else
		{
		
			temp->next = list[v1];
			list[v1] = temp;
		}
	}
}

int n;

void swap(int *x,int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;	
}
void printGraph(int vertices)							// Function to print Graph 
{
	int i;
	struct graph *temp = (struct graph*)malloc(sizeof(struct graph));
	for(i = 0;i < vertices;i++)
	{
		temp = list[i];
		printf("%d -> ",i + 1);
		while(temp != NULL)
		{
			printf(" %d ->",temp->vertex + 1);
			temp = temp->next;
		}
		printf("\n");
	}	
}
void minheapify(int H[],int index)
{
	int s;
	int lChild = 2 * index + 1;
	int rChild = 2 * index + 2;
	if(index >= n / 2)
		return;
	if(rChild < n && H[rChild] < H[lChild])
	{
		s = rChild;
	}
	else
	{
		s = lChild;
	}
	if(H[index] > H[s])
	{
		swap(&H[index],&H[s]);
		swap(&vertexInfo[s].vertex,&vertexInfo[index].vertex);
		vertexInfo[vertexInfo[s].vertex].index = s;
		vertexInfo[vertexInfo[index].vertex].index = index;
		minheapify(H,s);
	}
}


void BuildHeap(int H[],int n)
{
	int i;
	for(i = (n / 2) - 1 ;i >= 0;i--)
	{
		minheapify(H,i);
	}
}
void decreaseKey(int H[],int index,int newKey)
{
	H[index] = newKey;
	int parent = (index - 1) / 2;
	while(H[parent] > H[index] && parent >= 0)
	{
		swap(&H[index],&H[parent]);
		swap(&vertexInfo[index].vertex,&vertexInfo[parent].vertex );	
		vertexInfo[vertexInfo[index].vertex].index = index;
		vertexInfo[vertexInfo[parent].vertex].index = parent;
		index = parent;
		parent = (parent - 1) / 2;
	}
}

int extractMin(int H[])
{
	int minIndex = vertexInfo[0].vertex;
	vertexInfo[minIndex].distance = H[0];		
	swap(&H[0],&H[n - 1]);
	vertexInfo[0].vertex = vertexInfo[n-1].vertex;
	vertexInfo[vertexInfo[0].vertex].index = 0;
	vertexInfo[n - 1].vertex = -1;
	H[n - 1] = -1; 
	n--;
	minheapify(H,0);
	return minIndex;
}

void djkstra(int dist[])
{
	struct graph *temp;
	while(n > 0)
	{
		int u = extractMin(dist);
		vertexInfo[u].visited = 1;
		temp = list[u];
		while(temp != NULL)
		{
			if(vertexInfo[temp->vertex].visited != 1)
			{
				if(vertexInfo[temp->vertex].distance > vertexInfo[u].distance + temp->weight)
				{
					vertexInfo[temp->vertex].distance = vertexInfo[u].distance + temp->weight;
					vertexInfo[temp->vertex].pred = u;
					decreaseKey(dist,vertexInfo[temp->vertex].index,vertexInfo[temp->vertex].distance);
				}
			}
			temp = temp->next;
		}
	}
}

int main()
{
	int v1 = 0,v2,weight,i,j,vertices;
	int dist[50];
	int noOfQuery;
	int sourceVertex;
	
	printf("Enter the no of vertices\n");
	scanf("%d",&n);
	vertices = n;
	for(i = 0;i < n;i++)
	{
		scanf("%d",&noOfQuery);
		for(j = 0;j < noOfQuery;j++)
		{
			scanf("%d %d",&v2,&weight);	
			addEdge(v1,v2 - 1,weight);
			addEdge(v2 - 1,v1,weight);
		}
		v1++;
	}
	scanf("%d",&sourceVertex);
	for( i = 0;i < n;i++)
	{
		dist[i] = INFINITY;
		vertexInfo[i].vertex = i;
		vertexInfo[i].index = i;
		vertexInfo[i].distance = INFINITY;
		vertexInfo[i].pred = -1;
		vertexInfo[i].visited = -1;
	}
	sourceVertex-=1;
	dist[sourceVertex] = 0;
	BuildHeap(dist,n);
	vertexInfo[sourceVertex].distance = 0;
	vertexInfo[sourceVertex].index= 0;
	vertexInfo[0].index = sourceVertex;
	printGraph(vertices);
	djkstra(dist);
	printf("Vertices            Distance from Source\n");
	for(i = 0;i < vertices;i++)
	{
		printf("\n%d\t\t\t%d\n",i + 1,vertexInfo[i].distance);
	}

	printf("Vertices            Predcessor\n");
	for(i = 0;i < vertices;i++)
	{
		printf("\n%d\t\t\t%d\n",i + 1,vertexInfo[i].pred + 1);
	}
	return 0;
}
