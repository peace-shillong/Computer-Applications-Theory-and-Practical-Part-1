#include<iostream.h>
#include<conio.h>
//LINKED LIST MT

struct node{
	int data;
	node *next;
};
node* create(int n);
void print(node *p);
node* insert(node* p,int i);
node* del(node* p,int i);
node* rev(node *p);
node* concat(node *p, node *q);
void main(){
	node *p,*q,*r;
	clrscr();
	cout<<"\nCreate : enter size";
	int n;
	cin>>n;
	p=create(n);
	cout<<endl;
	print(p);
	cout<<"\nINSERT AT POSITION: ";
	cin>>n;
	p=insert(p,n);
	print(p);
	cout<<"\nDELETE AT POSITION: ";
	cin>>n;
	p=del(p,n);
	print(p);
	cout<<"\nREVERSE LIST: \n";
       //	q=rev(p);
       //	print(q);
      //	getch();
	cout<<"\n CONCAT LIST: \n";
	r=concat(p,p);
	//getche();
	print(r);


		getch();
}
node* create(int n){
	node *q,*p,*r;
	p=new node;
	cin>>p->data;
	p->next=NULL;
	q=p;
	for(int i=0;i<n-1;i++){
		r= new node;
		cin>>r->data;
		r->next=NULL;
		q->next=r;
		q=r;
	}
	return p;
}

void print(node *p){
	node *q;
	q=p;

	while(q->data!=NULL){
		cout<<q->data<<"->";
		q=q->next;
	}
	cout<<"NULL";
}

node* insert(node*p,int i){
	node *q,*r;
	if(i==0){
		r=new node;
		cin>>r->data;
		r->next=p;
		p=r;
		return p;
	}
	q=p;
	for(int j=1;j<i && q!=NULL;j++){
		q=q->next;
	}
	r=new node;
	cin>>r->data;
	r->next=q->next;
	q->next=r;
	return p;
}
node* del(node *p,int i){
	node *q,*prev;
	q=p;
	if(i==0){
		p=q->next;
		delete q;
		return p;
	}
	for(int j=0;j<i && q!=NULL;j++){
		prev=q;
		q=q->next;
	}
	if(q==NULL)
		return p;
	prev->next=q->next;
	q->next=NULL;
	delete q;
	return p;
}

node* rev(node *p){

	node *r,*q,*s;
	q=p;
	r=NULL;
	s=q->next;
	while(q->next!=NULL){
		q->next=r;
		r=q;
		q=s;
		s=q->next;
	}
	q->next=r;
	return q;
}

node * concat(node *p,node *q){
	node *r,*t;
	if(p==NULL)
		p=q;
	else{
		r=p;
		t=p;
		while(t!=NULL){
			t=t->next;
		 //	if(t!=NULL)
		//	r=r->next;
		}
		t->data=q->data;
		t->next=q->next;
		r=t;
	}
	return t;
}