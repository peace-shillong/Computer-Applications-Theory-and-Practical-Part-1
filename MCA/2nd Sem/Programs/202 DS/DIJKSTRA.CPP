#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
#define INFINITY 9999
#define MEMBER 1
#define NONMEMBER 0

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
//DECLARATIONS STACK
int stack[MAX];
int top=-1;
int full=0,empty=1;     //to keep track if stack is empty or full

//FUNCTION DECLARATION FOR STACKS
void push(int x);
int pop();

//FUNCTION DECLARATIONS FOR GRAPH
void buildGraph(graph *g);

//weight matrix
int w[MAX][MAX];
void print(graph *g);

//Dijkstra's algorithm
void shortest_path(graph *g,int s,int t);

void main()
{
	graph *g;
	int i,n,s,t;
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
	cout<<endl;
	print(g);
	cout<<endl;
	cout<<"For shortest path: "<<endl;
	cout<<"For start vertex: "<<endl;
	cin>>s;
	cout<<"For target vertex: "<<endl;
	cin>>t;
	shortest_path(g,s,t);
	getch();
}
void buildGraph(graph *g)
{
	int i,j,x;
	int n=g->noOfVertices;
	adjList *start,*node;
	cout<<endl<<endl<<"Building the graph:-"<<endl;
	for(i=0;i<n;i++) //INITIALIZING WEIGHT ARRAY
	{
		for(j=0;j<n;j++)
		{
			w[i][j]=INFINITY;
		}
	}
	for(i=0;i<n;i++) //i->current vertex, j->adjacent vertex
	{
		start=NULL; //for every vertex i, there is a possibility of new adjacency list
		for(j=0;j<n;j++)
		{
			cout<<"Enter 1 if edge present from vertex "<<i<<" to "<<j <<"?";
			cin>>x;
			if(x==1)
			{
				cout<<"Enter its weight: ";
				cin>>w[i][j];
				node=new adjList;
				node->vertex=j;
				node->next=start;
				start=node;
			}
		}
		g->adjVertex[i]=start;
	}
}

//DIJSTRA'S ALGORITHM
void shortest_path(graph *g,int s,int t)
{
	int i,current,k,smallestDist,newdist,dc;
	int shortest_dist;
	int distance[MAX],previous[MAX],permanent[MAX];
	int n=g->noOfVertices;

	for(i=0;i<n;i++)	 	//Initializations
	{
		permanent[i]=NONMEMBER;
		distance[i]=INFINITY;
	}
	permanent[s]=MEMBER;
	distance[s]=0;
	current=s; //start node
	while(current != t)
	{
		smallestDist=INFINITY; 	 //smallest distance from current to its adjacent nodes
		dc=distance[current]; //current distance to this node
		for(i=0;i<n;i++) //i represents vertices in graph
		{
			if(permanent[i]==NONMEMBER)
			{
				newdist=dc+w[current][i];
				if(newdist<distance[i])
				{
					distance[i]=newdist;
					previous[i]=current;
				}
				if(distance[i]<smallestDist)
				{
					smallestDist=distance[i];
					k=i;
				}
			}
		}
		current=k;
		permanent[current]=MEMBER;
	}
	shortest_dist=distance[t]; //shortest distance can be returned
	cout<<"Shortest Distance: "<<shortest_dist;
}

void print(graph *g)
{
	int n=g->noOfVertices;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<w[i][j]<<" ";
		}
		cout<<endl;
	}
}