#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
	int data;
	struct node *next;

}node;
node *insertbeg(node *start);
void display(node *start);
void insertend(node *start);
node *insertmiddle(node *start);
node *deleteFirst(node *start);
void deleteLast(node *start);
node *deleteMiddle(node *start);
node *create();
void main()
{
	int n,i;
	char ch;
	//clrscr();
	node *p,*q,*start;
	start=NULL;
	do
	{       clrscr();
		cout<<"A Program on Linked List Operations.";
		cout<<"\n\tMENU"<<endl;
		cout<<"1. Create linked list."<<endl;
		cout<<"2. Display linked list"<<endl<<endl;
		cout<<"3. Insert node at beginning of linked list"<<endl;
		cout<<"4. Insert node at the end of linked list"<<endl;
		cout<<"5. Insert node in the middle of the linked list"<<endl<<endl;
		cout<<"6. Delete node from beginning of linked list"<<endl;
		cout<<"7. Delete node from the end of linked list"<<endl;
		cout<<"8. Delete node from the middle of the linked list"<<endl<<endl;
		cout<<"9. Exit"<<endl;
		cout<<"Enter Your Choice.";
		cin>>n;
		switch(n)
		{
			case 1:
			{

				start=create();
				break;
			}
			case 2:
			{
				if(start==NULL)
					cout<<"Linked list not created"<<endl;
				else
					cout<<endl;
					display(start);
				break;
			}
			case 3:
			{
				start=insertbeg(start);
				break;
			}
			case 4:
			{
				insertend(start);
				break;
			}
			case 5:
			{
				start=insertmiddle(start);
				break;
			}
			case 6:
			{
				start=deleteFirst(start);
				break;
			}
			case 7:
			{
				deleteLast(start);
				break;
			}
			case 8:
			{
				start=deleteMiddle(start);
				break;
			}
			case 9:
			{
				exit(1);
			}
			default:
			      //	ch='y';
				cout<<"Invalid input. Program will end";
				break;
		}
		cout<<"\nPress Y to continue..."<<endl;
		cin>>ch;

	}while(ch=='y' || ch=='Y'||n>0||n<9);

	getch();
}
node* insertbeg(node* start)
{
	node *p;
	p=new node;
	cout<<"Enter the data to insert "<<endl;
	cin>>p->data;
	p->next=start;
	start=p;
	cout<<endl<<"Node :"<<p->data<<" inserted.";
	return start;
}
void insertend(node* start){
	node *p,*q;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	q=new node;
	cout<<"Enter the data to insert "<<endl;
	cin>>q->data;
	q->next=NULL;
	p->next=q;
	//return start;
	cout<<endl<<"Node :"<<p->data<<" inserted.";
}

node* insertmiddle(node* start){
	node *p,*q;
	int i,j,flag=0;

	p=start;
	cout<<"Enter The Position to insert into";
	cin>>i;
	j=1;
	if(i==1)
	{
		p=insertbeg(p);
		return p;
	     //cout<<"Insert beg";
	}
	while(j<(i-1))
	{
		if(p->next!=NULL){
			p=p->next;
		}
		else
			flag=1;
		j++;

	}
	if(flag==1)
		cout<<"Range exceeded. Inserting to the last node";
	q=new node;
	cout<<"Enter the data: "<<endl;
	cin>>q->data;
	q->next=p->next;
	p->next=q;
	cout<<endl<<"Node :"<<q->data<<" inserted.";
	return start;

}

node* create()
{
	int n,i;
	node *p,*q,*start;
	p=new node;
	cout<<"Enter the number of data you want to add"<<endl;
	cin>>n;
	cout<<"Enter data"<<endl;
	cin>>p->data;
	start=p;
	p->next=NULL;
	for(i=1;i<n;i++)
	{
		q=new node;
		cout<<"Enter data"<<endl;
		cin>>q->data;
		p->next=q;
		q->next=NULL;
		p=q;

	}
	return(start);
}
void display(node *start)
{
	node *p,*q;
	p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL";
}

node *deleteFirst(node *start){
	node *temp;
	temp=start;
	start=start->next;
	cout<<endl<<"Node :"<<temp->data<<" deleted.";
	delete(temp);
	return start;
}

void deleteLast(node *start){
	node *temp,*q;
	temp=start;
	while(temp->next!=NULL){
		q=temp;
		temp=temp->next;
	}
	cout<<endl<<"Node :"<<temp->data<<" deleted.";
	delete(temp);
	q->next=NULL;
       //	return start;
}

node *deleteMiddle(node *start){
	node *temp,*prev,*q;
	int data,i,flag=1;
	temp=start;
	cout<<"Enter Data to Delete";
	cin>>data;

	while(temp->data!=data){
	      if(temp->next!=NULL){
	      prev=temp;
	      temp=temp->next;
	      }
	      else{
		cout<<"Node does not exist";
		flag=0;
		break;
	      }
	}
	if(flag!=0)
	if(temp==start)
		return deleteFirst(temp);
	else if(temp->next==NULL)
	       deleteLast(temp);
	else{
		prev->next=temp->next;
		cout<<endl<<"Node :"<<temp->data<<" deleted.";
		delete(temp);
	}
	//start=start->next;
	//delete(temp);
	//Different Logic Not Working
	       /*	q=temp;

		while(start->next!=NULL){

			if(prev->data==data){
				prev->next=q->next;
				cout<<endl<<"Node :"<<temp->data<<" deleted.";
				delete(temp);

			}
			else
			{
				//prev=temp;
				node *temp=q->next;
				prev=temp;

			}

		}*/

	return start;
}