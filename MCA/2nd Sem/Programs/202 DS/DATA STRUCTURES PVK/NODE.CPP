#include<iostream.h>
#include<conio.h>

struct node {
	int data;
	struct node *next;

}node;

void main(){
	struct node *p;
	clrscr();

	cout<<" CREATE NODE "<<endl;
	p=new node;
	cout<<"Enter Data";
	cin>>p->data;
	p->next=NULL;
	getch();
	cout<<"DATA "<<p->data;

}