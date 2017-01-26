// Implement Breadth First Search

#include<stdio.h>
#include<stdlib.h>
#define UNDEFINED -1000


/*    Structure for Making Graph Adjacency List  */
struct graph{
	int vertex;
	struct graph *next;
}*list[50];

/*    Structure For Queue to Store Currently Visiting Vertex During BFS   */
struct queue{
	int data;
	struct queue *next;
}*front = NULL,*rear = NULL;

/*  Function For Enqueuing Element in the Queue at the back  */
void enqueue(int vertex){
	struct queue *temp ;
	temp = (struct queue*)malloc(sizeof(struct queue));
	if(temp != NULL){
		temp->data = vertex;
		if(front == NULL){
			temp->next = NULL;
			front = temp;
			rear = temp;
		}
		else{
			temp->next = NULL;
			rear->next = temp;
			rear = temp;
		}
	}
	else{
		printf("Memory is not allocated\n");
		exit(0);
	}
}

/*  Function for Dequeuing Element from the Queue from Front  */
int dequeue(){
	int vertex;
	struct queue *temp;
	temp = front;
	front = temp->next;
	temp->next = NULL;
	vertex = temp->data;
	free(temp);
	return vertex;
}

/* For Setting Up initial Graph */
/* Setting Parent node for Each Adjancency  List  */
void setList(int vertices){
	int i;
	for(i = 0;i < vertices;i++){
		struct graph *temp;
		temp = (struct graph *)malloc(sizeof(struct graph));
		if(temp != NULL){
		temp->vertex = i;
		temp->next = NULL;
		list[i] = temp;
		}
		else{
			printf("Memory is not allocated\n");
			exit(0);
		}
	}
	
}

/* For Adding an Edge From Vertex v1 to v2 in Graph */
void addEdge(int v1 , int v2){
	
	struct graph *temp;
	temp = (struct graph *)malloc(sizeof(struct graph));
	struct graph *t;
	t = list[v1];
	
	if(temp != NULL){				// If list has only starting vertex node
		temp->vertex = v2;
		if(list[v1]->next == NULL)
		{
			list[v1]->next = temp;
			temp->next = NULL;	
		}
		else						// If list has node of other than starting vertex node 
		{
			while(t->next != NULL)
			{
				t = t->next;
			}
			t->next = temp;
			temp->next = NULL;	
		}
	}
	else{
		printf("Memory is not allocated\n");
		exit(0);
	}
}

/* For Printing all The Adjancency Lists  */
void printGraph(int vertices){
	
	struct graph *temp;
	int i;
	
	for(i = 0;i < vertices;i++){
		temp = list[i];
		while(temp != NULL){
			printf("%d -> ",temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

/* BFS Function  */
void Bfs(int s,int distance[]){
	int u,i;
	struct graph *temp,*t;
	distance[s] = 0;
	enqueue(s);
	while(front != NULL && rear != NULL){		// If Queue is not Empty
		u = dequeue();
		printf("%d ",u);							// Printing the order of visited Vertex
		temp = list[u];
		t = list[u];
		while(temp->next != NULL){				// For all edge starting from u
			temp = temp->next;
			if(distance[temp->vertex] == UNDEFINED){        // Checking If vertex is already visited or not
				enqueue(temp->vertex);						// Putting Vertex in the queue for future traversal
				distance[temp->vertex] = distance[t->vertex] + 1;	// Incrementing distance of vertex by 1 from previous Vertex
			}
		}
	}
}

int main(){
	
	int vertices;
	int v1 , v2;
	int distance[50];
	int startVertex;
	int i;
	
	printf("Enter total number of vertices -: ");
	scanf("%d",&vertices);
	
	setList(vertices);				// Setting Parent node for Each Adjancency List and adding int the List
	
	printf("Enter the Edges connecting different Vertices (Vertex Numering Start from 0 & to stop enter (-1 -1)) -:\n");
	scanf("%d %d",&v1,&v2);
	if(v1 != -1 && v2 != -1){
		addEdge(v1 , v2);					// adding edge from vertex v1 to v2
		addEdge(v2 , v1);					// adding edge from vertex v2 to v1
	} 
	while(v1 != -1 && v2 != -1){
		scanf("%d %d",&v1,&v2);
		if(v1 != -1 && v2 != -1){
			addEdge(v1 , v2);				// adding edge from vertex v1 to v2
			addEdge(v2 , v1);				// adding edge from vertex v2 to v1
  		}
	} 
	printGraph(vertices);
	
	for(i = 0;i < vertices;i++){
		distance[i] = UNDEFINED;
	}
	
	/*  startVertex is the Source Vertex  for BFS  */
	printf("Enter Starting Vertex for BFS -: ");
	scanf("%d",&startVertex);
	
	Bfs(startVertex,distance);
	
	for(i = 0;i < vertices;i++){
		printf("\n\n%d   %d",i,distance[i]);
	}
	return 0;
}
