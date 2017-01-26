#include<stdio.h>
#include<stdlib.h>

struct graph{
	int data;
	struct graph * next;
}*head = NULL;
struct graph *list[1000];

int vertex;
int visited[1000],post[1000] = {-1},pre[1000] = {-1},count = 0,pred[1000];

void dfs();
void setList();
void addEdge(int ,int);
void printGraph();
void visit(int);
void printCycle(int,int);

int main()
{
	int i;
	int v1,v2;
	printf("Enter the no of vertiices\n");
	scanf("%d",&vertex);
	setList();
	printf("Enter the 2 vertices between which there is an edge and -1,-1 to terminate\n");
	scanf("%d %d",&v1,&v2);
	addEdge(v1,v2);
	while(v1!=-1 && v2!=-1)
	{
		scanf("%d %d",&v1,&v2);
		if(v1!=-1 && v2!=-1)
		{
			addEdge(v1,v2);
		}
	}
	printf("\nGraph is -:\n");
    printGraph(); 
	for(i = 0;i < vertex;i++)
	{
		visited[i] = 0;
		pred[i] = -1;
	}
    dfs();
    printf("\n\nNo Cycle Exists in Graph\n");
}

void setList()
{
	int i = 0;
	for(i = 0;i < vertex;i++)
	{
		struct graph *node = (struct graph*)malloc(sizeof(struct graph));
		node->data = i;
		node->next = NULL;
		list[i] = node;
	//	printf("%d ",list[i]->data);
	}
}

void addEdge(int a,int b)
{
		struct graph *temp = (struct graph*)malloc(sizeof(struct graph));
		struct graph *t = list[a];
		temp->data = b;
		if(list[a]->next == NULL)
		{
			list[a]->next = temp;
			temp->next = NULL;	
		}
		else
		{
			while(t->next != NULL)
			{
				t = t->next;
			}
			t->next = temp;
			temp->next = NULL;	
	}
	return;
}

void printGraph()
{
	int i;
		struct graph *temp = (struct graph*)malloc(sizeof(struct graph));
		for(i = 0;i < vertex;i++)
		{
			temp = list[i];
			while(temp != NULL)
			{
				printf("%d ->",temp->data);
				temp = temp->next;
			}
			printf("\n");
		}	
}


void dfs()
{
	int i;
	for(i = 0;i < vertex;i++)
	{
		visited[i] = 0;
		pred[i] = -1;
	}
	for(i = 0;i <vertex;i++)
	{
		if(visited[i] != 1)
		{
			visit(i);
		}
	}
}
void visit(int v)
{
	
	visited[v] = 1;
	pre[v] = count++;
	struct graph *temp;
	temp = list[v]->next;

	
	while(temp != NULL)
	{
		if(visited[temp->data] == 0)
		{
			pred[temp->data] = v;
			visit(temp->data);
		}
		else if(visited[temp->data] != 0 && (pre[temp->data] < pre[v]) && (post[temp->data] == -1))
		{
			printf("\n\n Vertices Forming Cycle are -: ");
			printCycle(v,temp->data);
		} 
	
		temp = temp->next;
	}
	post[v] = count++;
	return;
}

void printCycle(int v,int u)
{
	 do {
        printf("%d ",v);
        v = pred[v];
    } while (v != u);
    printf("%d \n\n",u);
    exit(0);
}
