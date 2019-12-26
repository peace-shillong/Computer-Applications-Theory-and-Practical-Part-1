#include<iostream.h>
#include<conio.h>
struct node {
	int data;
	struct node *next;

};
void display(node *start){
	node *p;
	p=start;
	while(p->data!=0){
		cout<<p->data<<" ";
		p=p->next;
	}
}
void main(){
	int n;
	struct node *p,*q,*start;
	clrscr();

	cout<<" CREATE NODE "<<endl;

	cout<<"Enter Data";
	cin>>n;
	if(n==0){
		cout<<"Exit";//exit(0);
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
		}while(q->data!=0);
	}
//	cout<<"DATA "<<p->data;
	display(start);
	getch();

}