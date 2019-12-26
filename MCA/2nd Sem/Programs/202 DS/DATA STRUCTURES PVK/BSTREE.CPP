#include<iostream.h>
#include<conio.h>
#include<process.h>
#define MAX 200
//BST
struct tree{

	int data;
	struct tree *left,*right;
};
void display(tree *t);
void preorder(tree *t);
void inorder(tree *t);
void postorder(tree *);
tree *build(tree *t,int x);
void push(tree *);
int isFull();
tree *pop();
int isEmpty();
void pushValue(int);
int popValue();
int stackNotEmpty();

tree *findsmallest(tree *);
int findlargest(tree *);
int search(tree *t,int x);

tree * delNode(tree *,int x);
int top=-1,vTop=-1;
tree *stack[MAX];
void main(){

	struct tree *t;

	t=NULL;
	int ch,n;

	do
	{
	clrscr();

	cout<<"Binary Search Tree \tMENU\n";
	cout<<"1.Create Tree\n2.Traverse Preorder\n3.Traverse Inorder\n4.Traverse Postorder \n5.Search Node. \n6. Delete Node \n7.Exit\n";
	cout<<"Enter Choice: ";
	cin>>ch;
	switch(ch){

		case 1:
			cout<<"Enter Data. Enter 0 to stop";
			cin>>n;
			if(n!=0){
				t=build(t,n);
			       }
			else
				cout<<"List Not Created";
			break;
		case 2:
			cout<<"Preorder\n";
			preorder(t);
			cout<<" Lar "<<findlargest(t);
			getch();
			break;
		case 3:
			cout<<"INORDER \n";
			inorder(t);
			//display(t);
			break;
		case 4:
			cout<<"POST ORDER\n";
			postorder(t);
			break;
		case 5:
			cout<<"Enter Element You want to Find: ";
			int x;
			cin>>x;
			int res=search(t,x);
			if(res)
				cout<<"Element Found";
			else
				cout<<"Element not Found";
			getch();
			break;
		case 6:
			cout<<"Enter Node You want to delete.";
			cin>>x;
			t=delNode(t,x);
			break;
		case 7:
			break;
		default:
			cout<<"Wrong Input";
		}
	}while(ch!=6);


	getch();
}

tree *build(tree *t,int x){

	  if(t==NULL){
				t=new tree;
				t->data=x;
				t->left=NULL;
				t->right=NULL;
	  }
	  else
	  {

		if(x<t->data)
			t->left=build(t->left,x);
		else if(x>t->data)
			t->right=build(t->right,x);
		else{
			cout<<"Duplicate.";
			getch();
		}
	  }
	  return t;


}

void display(tree *t){

	tree *p;
	p=t;
	cout<<"\n";
	while(p!=NULL){
		cout<<p->data;
		p=p->left;

	}
	getch();
}
void preorder(tree *t){

	while(1){

		while(t!=NULL){
			push(t);
			cout<<t->data;
			t=t->left;
		}
		if(top==-1)
			break;
		else{
			t=pop();
			t=t->right;
		}
	}
}

void inorder(tree *t){


	while(1){

		while(t!=NULL){
			push(t);
			t=t->left;
		}
		if(top==-1)
			break;
	      //	if(isEmpty())
	      //	break;
		       //	return;
		else
		{
			t=pop();
			cout<<t->data;
			t=t->right;
		}
	}
	//cout<<" INORDER";
    //	getch();
}
int value_stack[MAX];
void postorder(tree *t){

	int value;
	while(1){

		while(t!=NULL){
				push(t);
				pushValue(1);
				if(t->right!=NULL){
					push(t->right);
					pushValue(2);
				}

				t=t->left;


		}
		while(stackNotEmpty()){
			t=pop();
			value=popValue();
			if(value==1)
				cout<<t->data;
			else if(t->left==NULL && t->right==NULL)
				cout<<t->data;
			else
				break;
		//	cout<<" top "<<top<<" vtop "<<vTop<<endl;
		}

	       //	if(t->left!=NULL)
		 //	cout<<t->left->data;
	       //	if(t->right!=NULL)
		  //	cout<<t->right->data;
		if(top==-1){
			if(t->data!=NULL)
			cout<<t->data;
			break;
		}

	}
       //	cout<<" POST ORDER";
	getch();

}
void push(tree *t){

	if(isFull()){
		cout<<"Stack is Full";
		getch();
	       //	exit(1);
		exit(1);
	}
	top++;
       //	cout<<"top "<<top<<endl;
	stack[top]=t;
       //	getch();

	return;
}

tree *pop(){

	if(isEmpty()){
		cout<<"Stack is Empty";
		getch();
		return 0;
       //		exit(1);
	}
	else{
	tree *x=stack[top];
	top--;
	return x;
	}
	//FIX
       //	return 0;

}

int isFull(){
      if(top==MAX-1)
	return 1;
      else
	return 0;
}

int isEmpty(){

	if(top==-1)
		return 1;
	else
		return 0;
}

int stackNotEmpty(){

	if(top>-1)
		return 1;
	else
		return 0;
}

void pushValue(int v){

       /*	if(isFull()){
		cout<<"FULL";
		getch();
		return;
	}*/
	vTop++;
	value_stack[vTop]=v;

}
int popValue(){

	if(isEmpty()){
	     //	cout<<"Empty";
	      //	getch();
	      return -1;
	}
	else{
		int x=value_stack[vTop];
		vTop--;
		return x;
	}
       //	return 0;
}

tree *findsmallest(tree *t){

	if(t==NULL)
		return 0;
	if(t->left==NULL)
		return t;
	else
		return findsmallest(t->left);


}
int findlargest(tree *t){

	if(t==NULL)
		return 0;
	if(t->right==NULL)
		return t->data;
	else
		return findlargest(t->right);
      // else
      //	return t->data;


}

int search(tree *t,int x){
	if(t==NULL)
		return 0;
	else if(x<t->data)
		return search(t->left,x);
	else if(x>t->data)
		return search(t->right,x);
	else
		return 1;

}
tree* delNode(tree* t,int x)
{
	tree *temp;
	if(t==NULL)
		return NULL;
	else if(x<t->data)
		t->left=delNode(t->left,x);
	else if(x>t->data)
		t->right=delNode(t->right,x);
	else
	{
		if(t->left!=NULL && t->right!=NULL)
		{
			/*
				Condition (3)
				Node t has left & right subtree
				We perform replacement of value for such a case
				Then delete the node used for replacement
			*/
			temp=findsmallest(t->right);
			t->data=temp->data;
			t->right=delNode(t->right,temp->data);
		}
		else
		{
			/*
				Condition (1) & (2)
				t is either terminal node or t has left or right child
				free the memory space occupied by t
				Then assign to t the address to be returned to the parent
				Two possibilities:
					t=NULL, if terminal node Or t=address of left/right child
				Here, we perform address replace not value
			*/
			temp=t;
			if(t->left==NULL)
				t=t->right;
			else if(t->right==NULL)
				t=t->left;
			delete(temp);

		}
	}
	return t;
}
