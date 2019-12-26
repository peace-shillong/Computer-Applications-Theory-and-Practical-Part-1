#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 200

struct tree
{
	int data;
	struct tree* left;
	struct tree*right;
};
tree* stack[MAX];
int top=-1;

tree* build(tree *t,int n);
void inorder(tree *t);
void inorderNonRecur(tree *t);
int isFull();
int isEmpty();
tree* pop();
void push(tree* addressOfNode);

void main()
{
	int n,i;
	tree *root;
	clrscr();
	cout<<"Program to perform in-order traversal of a Binary Tree"<<endl;
	cout<<"______________________________________________________"<<endl;
	cout<<endl<<"Enter the number of nodes: ";
	cin>>n;
	root=build(root,n);
	cout<<endl<<"Recursive Inorder Traversal:-"<<endl;
	inorder(root);
	cout<<endl<<"Non-recursive Inorder:-"<<endl;
	inorderNonRecur(root);
	getch();
}
tree* build(tree *t,int n)
{
	int nl,nr,x;
	if(n==0)
		return NULL;
	else
	{
		nl=n/2;
		nr=n-nl-1;
		t=new(tree);
		cout<<"Enter node value: ";
		cin>>x;
		t->data=x;
		t->left=build(t->left,nl);
		t->right=build(t->right,nr);
	}
	return t;
}
void inorder(tree *t)
{
	if(t==NULL)
		return;
	else
	{
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	return;
}
void inorderNonRecur(tree *t)
{
	while(1)
	{
		while(t!=NULL)
		{
			push(t);
			t=t->left;
		}
		if(isEmpty())
			return;
		t=pop();
		cout<<t->data<<" ";
		t=t->right;
	}
}
int isFull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(tree *addressOfNode)
{
	if(isFull())
	{
		cout<<endl<<"Stack Overflow!!";
		getch();
		exit(1);
	}
	top++;
	stack[top]=addressOfNode;
}
tree* pop()
{
	tree *x;
	if(isEmpty())
	{
		cout<<endl<<"Stack Underflow!!";
		getch();
		exit(1);
	}
	x=stack[top];
	top--;
	return x;
}
