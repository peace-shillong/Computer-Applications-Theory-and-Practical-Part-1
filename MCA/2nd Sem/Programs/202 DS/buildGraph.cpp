#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 200

struct adjList
{
	int vertex;
	adjList *next;
};
struct graph
{
	int noOfVertices;
	adjList *adjVertex[MAX];
};

void buildGraph(graph *g);
void bfs(graph *g,int start);

int q[MAX];
int front=-1,end=0;
			//points to the queue for adding and deleting
			//adding to the end
			//deleting from the front
int full=0,empty=1;     //to keep track if queue is empty or full

void addQ(int x);
int deleteQ();

void main()
{
	graph *g;
	int i,n;
	clrscr();
	cout<<"Program to build an unweigted graph and perform breadth first search"<<endl;
	cout<<"Enter the number of nodes[MAX-"<<MAX<<"]: ";
	cin>>n;
	g=new graph();
	g->noOfVertices=n;
	cout<<"The vertices are: ";
	for(i=0;i<n;i++)
		cout<<i<<", ";
	buildGraph(g);
	cout<<endl<<"Result:"<<endl;
	cout<<"The breadth first search traversal of graph: ";
	bfs(g,0);
	getch();
}
void buildGraph(graph *g)
{
	int i,j,x;
	int n=g->noOfVertices;
	adjList *start,*end,*node;
	cout<<endl<<endl<<"****Building the graph****"<<endl;
	for(i=0;i<n;i++) //i->current vertex, j->adjacent vertex
	{
		start=NULL; //for every vertex i, there is a possibility of new adjacency list

		for(j=0;j<n;j++)
		{
			cout<<"Enter 1 if edge present from vertex "<<i<<" to "<<j <<"?";
			cin>>x;
			if(x==1)
			{
				if(start==NULL)
				{
					start=new adjList;
					start->vertex=j;
					start->next=NULL;
					end=start;
				}
				else
				{

					node=new adjList;
					node->vertex=j;
					node->next=NULL;
					end->next=node;
					end=node;
				}
			}
		}
		g->adjVertex[i]=start;
	}
}
void bfs(graph *g,int start)
{
	int visited[MAX];
	int v,i,n;
	n=g->noOfVertices;
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[start]=1;
	addQ(start);
	adjList *current;
	while(!empty)
	{
		v=deleteQ();
		cout<<v<<" ";
		current=g->adjVertex[v];
		while(current != NULL)
		{
			if(visited[current->vertex]==0)
			{
				visited[current->vertex]=1;
				addQ(current->vertex);
			}
			current=current->next;
		}
	}
}
void addQ(int x)
{
	if(full)
	{
		cout<<"Queue is full";
		getch();
		exit(0);
	}
	if(front==-1)
		front++;
	q[end]=x;
	end++;
	empty=0;
	if(end==MAX-1)
		full=1;
}
int deleteQ()
{
	int x;
	if(empty)
	{
		cout<<"Queue is empty";
		getch();
		exit(0);
	}
	x=q[front];
	front++;
	full=0;
	if(front==end)
		empty=1;
	return x;
}