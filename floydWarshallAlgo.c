/** Floyd Warshall's Algorithms for all pair shortest path **/

// Input Format 
/*************
	First line : n (number of vertices of the graph)
	
	Second line : d1 (Number of neighbours of v1 whose vertex numbers are bigger than v1).
	
	Next d1 lines : vertex number of a higher numbered neighbour of v1 and the edge-weight of the corresponding edge (separated by a space). Assume the neighbors are given increasing order of vertex numbers. 

	Next line : d2 ((Number of neighbours of v2 whose vertex numbers are bigger than v2).

	Next d2 lines : vertex number of a higher numbered neighbour of v2 and the edge-weight of the corresponding edge (separated by a space). Assume the neighbors are given increasing order of vertex numbers.

	and so on..
	              **************/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF INT_MAX

int vertices;				// total number of vertices in a graph

void printsolution(int *dist)
{
	int i,j;
	printf ("Following matrix shows the shortest distances between every pair of vertices \n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if ((*(dist + i * vertices + j)) == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", (*(dist + i * vertices + j)));
        }
        printf("\n");
    }	
	
}

void floydwarshall(int *graph)
{
	int dist[vertices][vertices],i,j,k;
	int parent[vertices][vertices];			// Array for storing predecessor
	
	for(i = 0;i < vertices;i++)
	{
		for(j = 0;j < vertices;j++)
		{
			dist[i][j] = *(graph + i * vertices + j);
 			if(i == j)
				parent[i][j] = INF;
			if(*(graph + i * vertices + j) != INF)
				parent[i][j] = i;
			else
				parent[i][j] = INF;
		}
	}

	for(k = 0;k < vertices;k++)
	{
		for(i = 0;i < vertices;i++)
		{
			for(j = 0;j < vertices;j++)
			{
			if ( dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					parent[i][j]=parent[k][j];
				}
			}
		}
	}
	printsolution(*dist);							// for printing updated Matrix
	for(i = 0;i< vertices;i++)
		for(j = 0;j< vertices;j++)
		{
			printf("(%d,%d) -:  dist : ",i + 1 ,j + 1);
			if (dist[i][j] == INF)
                printf("%s ", "INF");
            else
                printf ("%d ", (dist[i][j]));
			if(parent[i][j]!=INF)
			{
				printf("pred : %d ",parent[i][j] + 1);
			}
			else
				printf("pred : No path");
			printf("\n");
		}
}

int main()
{
	int i ,j, noOfQuery,v1 = 0 , v2, weight;

	
	printf("Enter the no of vertices\n");
	scanf("%d", &vertices);
	int graph[vertices][vertices];
    for(i = 0;i < vertices;i++)
    {
    	for(j = 0;j < vertices;j++)
    	{
    		if(i == j)					// for diagonal Elements of Matrix
    		{
    			graph[i][i] = 0;
			}
			else
    			graph[i][j] = INF;
		}
	}

	for(i = 0;i < vertices;i++)
	{
		scanf("%d",&noOfQuery);
		for(j = 0;j < noOfQuery;j++)
		{
			scanf("%d %d",&v2,&weight);	
			graph[v1][v2 - 1] = weight; 
			graph[v2 - 1][v1] = weight;
		}
		v1++;
	}
	
	// printing entered Matrix 
	for(i = 0;i < vertices;i++)
    {
    	for(j = 0;j < vertices;j++)
    	{
    		 if (graph[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", graph[i][j]);
		}
		printf("\n");
	}
		
    floydwarshall(*graph);
    printf("\n\n");
	
    return 0;
}
