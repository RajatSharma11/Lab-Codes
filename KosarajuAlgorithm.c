/** Storngly Connected Components (Kosaraju Algorithm) **/


/*********
			Input format:

			First line : n (number of vertices of the graph)

			Next line : neighbours of v1 separated by a space and ended by -1
	
			Next line : neighbours of v2 separated by a space and ended by -1

			and so on..  
									*******/

#include<stdio.h>
#include<stdlib.h>

struct graph{
	int vertex;
	struct graph *next;
}*list_before[50],*list_after[50];

int post[50]={-1},count = 0,component[50],count_comp = 0;

struct stack{
	int vertex;
	struct stack * next;
}*head = NULL;

void push(int v)
{
	struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
	temp->vertex = v;
	if(head == NULL)
	{
		temp->next = NULL;
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}	
}
int pop()
{
	struct stack *temp;
	temp = head;
	head = temp->next;
	int v = temp->vertex;
	free(temp);
	return v;
}

void addEdge(int v1,int v2,int flag)
{
	struct graph *temp;
	temp = (struct graph *)malloc(sizeof(struct graph));
	if(temp != NULL)
	{
		temp->vertex = v2;
		if((list_before[v1] == NULL && flag == 0) || (list_after[v1] == NULL && flag == 1))
		{
			temp->next =  NULL;
			if(flag == 0)
				list_before[v1] = temp;
			else if(flag == 1)
				list_after[v1] = temp;
		}
		else
		{
			if(flag == 0)
			{
				temp->next = list_before[v1];
				list_before[v1] = temp;
			}
			else if(flag == 1)
			{
				temp->next = list_after[v1];
				list_after[v1] = temp;
			}
		}
	}	
}

void dfs_before(int u,int visited_before[])
{
	visited_before[u] = 1;
	struct graph *temp;
	temp = list_before[u];
	while(temp != NULL)
	{
		if(visited_before[temp->vertex] == 0)
		{
			dfs_before(temp->vertex,visited_before);
		}
		
		temp = temp->next;
	}
	post[u] = count++;					// calculating finish time of vertex
	push(u);							// adding vertex to stack based on finish time
	return;
}

void dfs_after(int u,int visited_after[])
{
	visited_after[u] = 1;
	component[u] = count_comp;
	struct graph *temp;
	temp = list_after[u];
	while(temp != NULL)
	{
		if(visited_after[temp->vertex] == 0)
		{
			dfs_after(temp->vertex,visited_after);
		}
		
		temp = temp->next;
	}
}

void visit(int vertices,int flag)
{
	int visited_before[50],i,visited_after[50];
	if(flag == 1)								// for original graph
	{
		for(i = 0;i < vertices;i++)
		{
			visited_before[i] = 0;
		}
		for(i = 0;i < vertices;i++)
		{
			if(visited_before[i] != 1)
			{
				dfs_before(i,visited_before);
			}
		}
	}
	else if(flag == 2)					// for transposed graph
	{
		for(i = 0;i < vertices;i++)
		{
			visited_after[i] = 0;
		}
		for(i = 0;i < vertices;i++)
		{
			int v = pop();				// poping vertex out of stack for dfs
			if(visited_after[v] != 1)
			{
				count_comp++;
				dfs_after(v,visited_after);
			}
		}
	}
	
	
}

int main()
{
	int n,v1 = 0,v2,vertices,i;
	printf("Enter Total number of vertices : ");
	scanf("%d",&vertices);
	for(i = 0;i < vertices;i++)
	{
		scanf("%d",&v2);
		while(v2 != -1)
		{
			addEdge(v1,v2 - 1,0); 		// for orginial graph 
			addEdge(v2 - 1, v1,1);		// for transposed graph
			scanf("%d",&v2);
		}
		v1++;
	}
	visit(vertices,1);
	visit(vertices,2);
	printf("\n Total Component : %d\n",count_comp);
	printf("\n\nVertex    |     Component No");
	for(i = 0;i < vertices;i++)
	{
		printf("\n%d     -------     %d",i + 1,component[i]);
	}
	return 11;
}

