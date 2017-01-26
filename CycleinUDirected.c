// Checking Cycle in Undirected Graph and printing vertices in cycle

#include<stdio.h>
#include<stdlib.h>

struct gnode{							// structure for adjancency list
	int data ;
	struct gnode * next ;
};

struct adnode{							// structure to store head pointer of list
	struct gnode * top ;
};

struct graph{					// structure for graph
	int v;
	struct adnode * array ;
};

int cycle = 0,p = 0,q = 0,pred[1000];

struct graph * createGraph(int v)			// create graph
{
	struct graph * g = (struct graph *)malloc(sizeof(struct graph));
	if(g != NULL)
	{
		g->v=v;
		g->array=(struct adnode *)malloc(v*sizeof(struct adnode));
		int i;
		for(i=0;i<v;i++)
		{
			 g->array[i].top=NULL;
		}
	}
	else 
	{
		printf("Error in memory allocation \n");
		exit(0);
	}
	return g;
}

struct gnode * add(int data)				
{
	struct gnode * temp = (struct gnode *)malloc(sizeof(struct gnode));
	if(temp != NULL)
	{
		temp->data=data;
		temp->next=NULL;
	}
	else 
	{
		printf("Error in memory allocation \n");
		exit(0);
	}
	return temp;
}

void addEdge(struct graph * g , int src, int dest)				// to add  edege from src to dest
{
	struct gnode * temp = add(dest);
	temp->next=g->array[src].top;
	g->array[src].top=temp;
}

void dfs1(struct graph * g , int visit[] , int x) 				// function checking Cycles and performing dfs
{
	visit[x]=1 ;
	printf("%d ",x);
	struct gnode * temp = g->array[x].top;

	while(temp!=NULL)
	{
		if(visit[temp->data]==0)
		{
			pred[temp->data] = x;
			dfs1( g,visit,temp->data);							// recursive Call
		}
		else if(visit[temp->data] != 0 && temp->data != pred[x])	// checking for cycle 
		{
			cycle = 1;
			p = temp->data;			// storing start and end vertices of cycle
			q = x;
		}
		temp=temp->next;
	}
}

void dfs(struct graph *g)
{
	int i;
	int visit[g->v];

	for(i=0;i< g->v;i++)		// initailising visit array,pred array 
	{
		visit[i]=0;
		pred[i] = -1;
	}
	
	printf(" dfs traversal of a graph is \n \n ");

	for(i=0;i<g->v;i++)								// calling dfs for each non - visited vertex
	{
		if(visit[i] == 0)
		{
			dfs1(g , visit , i);
		}
	}
}

void printCycle(int v,int u)						// function for printing Cycle in graph
{
	 do {
        printf(" %d ",v);
        v = pred[v];								// tracing back by using predcessor
    } while (v != u);
    printf("%d \n\n",u);
}

int main()
{
	int vertex ,v1,v2,i;
	printf("Enter the no of vertices\n");
	scanf("%d",&vertex);
	struct graph* g = createGraph(vertex);
	if(g != NULL)
	{
		printf("Enter the 2 vertices between which there is an edge and -1,-1 to terminate\n");
		scanf("%d %d",&v1,&v2);
		addEdge(g,v1,v2);												// adding edge from vertex v1 to v2
		addEdge(g,v2,v1);												// adding edge from vertex v2 to v1
		while(v1!=-1 && v2!=-1)
		{
			scanf("%d %d",&v1,&v2);
			if(v1!=-1 && v2!=-1)
			{
				addEdge(g,v1,v2);										// adding edge from vertex v1 to v2
				addEdge(g,v2,v1);										// adding edge from vertex v2 to v1
			}
		}
		dfs(g);
			if(cycle == 1)											// if cycle is present then print vertices of cycle
		{
			printf("\nVertices in Cycle are - :\n\n");
			printCycle(p,q);
		}	
		else
		{
			printf("\nNo Cycle Exists in Graph \n");
		}
			printf("\n i     pred[i]\n");								// printing predcessor for each vertex
		for(i = 0;i < vertex;i++)
		{
			printf("\n %d    %d\n",i,pred[i]);
		}
	}
	else
	{
		printf("Error in memory allocation \n");
		exit(0);
	}
return 0;
}
