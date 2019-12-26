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
//DECLARATIONS STACK
int stack[MAX];
int top=-1;
int full=0,empty=1;     //to keep track if stack is empty or full

//FUNCTION DECLARATION FOR STACKS
void push(int x);
int pop();

//FUNCTION DECLARATIONS FOR GRAPH
void buildGraph(graph *g);
void dfs(graph *g,int start);


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
	cout<<endl<<"The depth first search traversal of graph: ";
	dfs(g,0);
	getch();
}
void buildGraph(graph *g)
{
	int i,j,x;
	int n=g->noOfVertices;
	adjList *start,*end,*node;
	cout<<endl<<endl<<"Building the graph:-"<<endl;
	for(i=0;i<n;i++) //i->current vertex, j->adjacent vertex
	{
		start=NULL; //for every vertex i, there is a possibility of new adjacency list

		for(j=0;j<n;j++)
		{
			cout<<"Enter 1 if edge present from vertex "<<i<<" to "<<j <<"?";
			cin>>x;
			if(x==1)
			{
				node=new adjList;
				node->vertex=j;
				node->next=start;
				start=node;
			}
		}
		g->adjVertex[i]=start;
	}
}

//DEPTH FIRST SEARCH
void dfs(graph *g,int start)
{
	int visited[MAX];
	int v,i,n;
	n=g->noOfVertices;
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[start]=1;
	push(start);
	adjList *current;
	while(!empty)
	{
		v=pop();
		cout<<v<<" ";
		current=g->adjVertex[v];
		while(current != NULL)
		{
			if(visited[current->vertex]==0)
			{
				visited[current->vertex]=1;
				push(current->vertex);
			}
			current=current->next;
		}
	}
}
void push(int x)
{
	if(full)
	{
		cout<<"Stack is full";
		getch();
		exit(0);
	}
	top++;
	stack[top]=x;
	empty=0;
	if(top==MAX-1)
		full=1;
}
int pop()
{
	int x;
	if(empty)
	{
		cout<<"Queue is empty";
		getch();
		exit(0);
	}
	x=stack[top];
	top--;
	full=0;
	if(top==-1)
		empty=1;
	return x;
}


