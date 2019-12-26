#include<iostream.h>
#include<conio.h>
#define MAX 100

struct adjList{
	int data;
	struct adjList *next;
};
struct graph{
	int noOfVertices;
	adjList* adjVertex[MAX];
};
void bfs(graph g,adjList* s);
void insertEnd(adjList* s,int j);
void dfs(graph g,adjList* s);
void main(){
	graph g;
	adjList* start;
	int n,e;
	clrscr();
	cout<<"Enter The Number of Nodes: ";
	cin>>n;
	g.noOfVertices=n;
	for(int i=0;i<n;i++){
		start=NULL;
		for(int j=0;j<n;j++){
			cout<<"Is there an edge from "<<i+1<<"to "<<j+1<<"\nEnter 1 If Yes \n Enter 0 If No:\n ";
			cin>>e;
			if(e){
				while(start!=NULL)
						start=start->next;
				if(start==NULL){
					start->data=j;
					start->next=NULL;
				}
				//else
				//	insestEnd(start,j);
			}
		g.adjVertex[i]=start;
		}
	}
	//Display()
       //	cout<<endl<<"GRAPH";
      //	cout<<g.adjVertex[0]->data;
      //	cout<<endl<<g.adjVertex[1]->data;
	dfs(g,start);
	getch();
}

//void bfs(graph g,adjList* s){

//}

//void insertEnd(start,j){}

void dfs(graph g,adjList *s){

}