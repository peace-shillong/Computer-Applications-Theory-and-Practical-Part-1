#include<iostream.h>
#include<conio.h>
struct node
{
	int exp,coeff;
	node *next;
};
node* create(int max);
void addPoly(node *p,node *q);
void main()
{
	node *poly[3];
	int ch,i=0,m;
	do{
	clrscr();
	cout<<" Polynomial Addition ";
	cout<<"\n 1. Create the Polynomials";
	cout<<"\n 2. Add the polynomial";
	cout<<"\n 3.Exit";
	cin>>ch;
	switch(ch){

		case 1:
			cout<<"Enter The Max Degree of the polymonial";
			cin>>m;
			poly[i]=create(m);
			i++;
			break;
		case 2:
			addPoly(poly[0],poly[1]);
			break;
		case 3:
			break;
		default:
			break;
	}
	}while(ch!=3);
	getch();
}

node* create(int m)
{
	node *q,*p,*r;
	p=new node;
	int coeff;
	cout<<"Enter Coefficient: ";
	cin>>coeff;
	if(coeff==0)
		p->coeff=1;
	else
		p->coeff=coeff;
	cout<<"Enter Power";
	cin>>p->exp;
	p->next=NULL;
	q=p;
	for(int i=0;i<m-1;i++){
		cout<<"Enter Coefficient";
		cin>>coeff;
		if(coeff!=0){
			r= new node;
			r->coeff=coeff;
			cout<<"Enter Power";
			cin>>r->exp;
			r->next=NULL;
			q->next=r;
			q=r;
		}
	}
	return p;

}

void addPoly(node *p,node *q){
	int newpower,newcoeff;
	node *p1,*q1,*r,*temp,*sum;
	p1=p;q1=q;

	while((p1!=NULL)&&(q1!=NULL)){
		if(p1->exp==q1->exp){
			newcoeff=p1->coeff+q1->coeff;
			newpower=p1->exp;
			p1=p1->next;
			q1=q1->next;
		}
		else if(p1->exp>q1->exp){
			newcoeff=q1->coeff;
			newpower=q1->exp;
			q1=q1->next;
		}
		else{
			newcoeff=p1->coeff;
			newpower=p1->exp;
			p1=p1->next;
		}

		if(newcoeff!=0){
			temp=new node;
			temp->exp=newpower;
			temp->coeff=newcoeff;
			if(r==NULL)
				sum=temp;
			else{
				r->next=temp;
				r=temp;
			}
			temp->next=NULL;
			temp=NULL;
		}

	}
	while(p1!=NULL){

		newcoeff=p1->coeff;
		newpower=p1->exp;
		temp=new node;
		temp->exp=newpower;
		temp->coeff=newcoeff;
		r->next=temp;
		temp->next=NULL;
		temp=NULL;
		p1=p1->next;
	}
	while(q1!=NULL){
		temp=new node;
		temp->coeff=q1->coeff;
		temp->exp=q1->exp;
		r->next=temp;
		temp->next=NULL;
		temp=NULL;
		q1=q1->next;
	}
	sum=temp;
	while(sum!=NULL){
		cout<<"Coeff : "<<sum->coeff;
		cout<<" Power : "<<sum->exp;
		cout<<"\n";
		sum=sum->next;
	}
}