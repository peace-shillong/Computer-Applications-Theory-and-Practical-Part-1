#include<iostream.h>
#include<conio.h>
//linked list of  n-integers and display
struct node {
	int data;
	struct node *next;
};

void display(node *start){
	node *p;
	p=start;
	while(p!=NULL){
		if(p->data!=0)
		cout<<p->data<<" ";
		p=p->next;
	}
}
void main(){
	int n,lim,i=1;
	struct node *p,*q,*start;
	clrscr();

	cout<<" CREATE NODE "<<endl;
	cout<<"Enter the limit";
	cin>>lim;
	cout<<"Enter Data";
	cin>>n;
	if(n==0){
		cout<<"Data must be an integer. Exit";//exit(0);
	}
	else{
		p= new node;
		p->data=n;
		p->next=NULL;
		start=p;
		do{
			q=new node;
			cout<<"Enter Data";
			cin>>q->data;
			q->next=NULL;
			p->next=NULL;
			p->next=q;
			p=q;
			i++;
		}while(i<lim);
	}
//	cout<<"DATA "<<p->data;
	display(start);
	getch();

}