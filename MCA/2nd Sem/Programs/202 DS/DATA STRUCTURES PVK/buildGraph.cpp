#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
#define MEMBER 1
#define NOMEMBER 0
#define MAXNODES 10

int weight[MAX][MAX];


int shortestpath(int weight[MAX][MAX], int s, int t);
void push(int);
int pop();

int stack[100];
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
void dfs(graph *g,int start);

int q[MAX];
int front=-1,end=0,top=-1;
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
	cout<<"\n Short path: ";
	cout<<shortestpath(weight,0,n-1);
	getch();
}
void buildGraph(graph *g)
{
	int i,j,x;
	int n=g->noOfVertices;
	adjList *start,*end,*node;
	cout<<endl<<endl<<"****Building the graph****"<<endl;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			weight[i][j]=0;
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

				       //	inend(start,j);
				}
				cout<<"\n Wnter Weight: ";
				cin>>weight[i][j];
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
	//step 2
	for(i=0;i<n;i++)
		visited[i]=0;
	//step 3
	visited[start]=1;
	//step 4
	addQ(start);
	adjList *current;
	//step 5
	while(!empty)
	{
		//step 5 a.
		v=deleteQ();
		//step 5 b.
		cout<<v<<" ";
		//step 5 c.
		current=g->adjVertex[v];
		//step 5 d.
		while(current != NULL)
		{
			//step 5 d. 1.
			if(visited[current->vertex]==0)
			{
				visited[current->vertex]=1;
				addQ(current->vertex);
			}
			//step 5 d. 2.
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
void dfs(graph *g,int start)
{
	full=0;empty=1;
	int v,i,n;
	//int stack[MAX];
	adjList *current;
	int visited[MAX];
	n=g->noOfVertices;
	//step 2
	for(i=0;i<n;i++)
		visited[i]=0;
	//step 3
	visited[start]=1;
	//step 4
	push(start);
      //	adjList *current;
	//step 5
	while(!empty)
	{
		//step 5 a.
		v=pop();
		//step 5 b.
		cout<<v<<" ";
		getch();
		//step 5 c.
		current=g->adjVertex[v];
		//step 5 d.
		while(current != NULL)
		{
			//step  5 d. 1 and 2.
			if(visited[current->vertex]==0)
			{
				visited[current->vertex]=1;
				push(current->vertex);
			}
			current=current->next;
		}
	}

}
void push(int s)
{
	 if(full)
	{
		cout<<"Stack is full cannot push";
		getch();
		exit(0);
	      //	return 0;
	}
	top++;
	empty=0;
	stack[top]=s;

}
int pop()
{

	int x;
	if(empty)
	{
		cout<<"Stack is empty";
		getch();
		exit(0);
		//return 0;
	}
	else{
		top--;
		x=stack[top];
		if(top==-1)
		empty=1;
		return x;
	}
	return -1;
}


int shortestpath(int weight[][MAX], int s, int t)
{
	int distance[MAXNODES], perm[MAXNODES],precede[MAXNODES];
	int current, i, k, dc;
	int smalldist, newdist;
	/* initialization of the distance and perm arrays*/
	for(i=0;i<3; i++)
	{
		perm[i]=NOMEMBER;
		distance[i]=MAX;
	}
	perm[s]=MEMBER;
	distance[s]=0;
	current=s;

	while(current !=t)
	{
		smalldist=MAX;
		dc=distance[current];
		for(i=0;i<3;i++)
			if(perm[i]==NOMEMBER)
			{
				newdist=dc+weight[current][i];
			       //	cout<<newdist;
				if(newdist<distance[i])
				{ /*distance from s to i through current is smaller than distance[i]*/
					distance[i]=newdist;
					precede[i]=current;
				}
				if(distance[i]<smalldist)
				{
					smalldist=distance[i];
					k=i;
				}
			}
			current=k;
			perm[current]=MEMBER;
	}
	return(distance[t]);
}