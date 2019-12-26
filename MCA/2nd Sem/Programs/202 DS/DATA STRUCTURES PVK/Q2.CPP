#include<iostream.h>
#include<conio.h>
//BST TREE
struct tree {
	int data;
	struct tree *left,*right;

};

tree *build(tree *,int);
int search(tree*,int);
int smallest(tree*);
int largest(tree*);
void inorder(tree*);

//Main
void main()
{
	int ch,n,x,res;
	tree *t;
	t=NULL;
	do{
		clrscr();
		cout<<"\n\t PROGRAM ON BINARY SEARCH TREE.\n";
		cout<<"\n \t\tMENU";
		cout<<"\n 1. Create Binary Search Tree.";
		cout<<"\n 2. Inorder Traversal of The Tree.";
		cout<<"\n 3. Search for the Presence of a value in the tree.";
		cout<<"\n 4. Display the Smallest value in the tree.";
		cout<<"\n 5. Display the Largest value in the tree.";
		cout<<"\n 6. Exit Program.";
		cout<<"\n\n    Enter Your Choice:  \n\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(t!=NULL){
					delete(t);
					t=NULL;
					cout<<"\n A New Tree will be created.";
				}
				cout<<"\n Enter the Number of Nodes: ";
				cin>>n;
				if(n>0){
					//for(int i=0;i<n;i++)
					while(n!=0)
					{
						cout<<"\n Enter data: ";
						cin>>x;
						t=build(t,x);
						n--;
					}
					cout<<"\n Tree Successfully Created.";
				}
				else
					cout<<"\n Invalid Number of Nodes.";
				break;
			 case 2:
				if(t!=NULL)
				{
					cout<<"\n Inorder Traversal of tree: \n";
					inorder(t);
				}
				else
					cout<<"\t Tree Not Yet Created! \n \tPlease Create the Tree First";
				break;
			 case 3:
				if(t!=NULL)
				{
					cout<<"\n Enter the Value you want to find : ";
					cin>>x;
					res=search(t,x);
					if(res)
						cout<<" Value : "<<x<<" is Present in the tree.";
					else
						cout<<" Value : "<<x<<" is Not present in the tree.";
				}
				else
					cout<<" \t Tree Not Yet Created! \n \tPlease Create the Tree First";
				break;
			 case 4:
				if(t!=NULL)
				{
					cout<<"\n The Smallest Value in the Tree is: ";
					cout<<smallest(t);
				}
				else
					cout<<"\t Tree Not Yet Created! \n \tPlease Create the Tree First";

				break;
			 case 5:
				if(t!=NULL)
				{
					cout<<"\n The Largest Value in the Tree is: ";
					cout<<largest(t);
				}
				else
					cout<<"\t Tree Not Yet Created! \n\t Please Create the Tree First";

				break;
			 case 6:
				cout<<"\n Program will Exit.";
				break;
			 default:
				cout<<"Your Entered a Wrong Choice.";
				break;
		}
			getch();


	}while(ch!=6);
}

tree *build(tree *t,int x)
{
	if(t==NULL)
	{
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
		else
			cout<<"\n\n Duplicate Value. Node Will Not be created.";

	}
	return t;
}
void inorder(tree *t){
	   if(t!=NULL){
		inorder(t->left);
		cout<<" "<<t->data;
		inorder(t->right);
	   }
}

int search(tree *t,int x)
{
	if(t!=NULL){
		if(x<t->data)
			return search(t->left,x);
		else if(x>t->data)
			return search(t->right,x);
		else if(x==t->data)
			return 1;
		else
			return 0;
	}
	return 0;
}
int smallest(tree *t)
{
	if(t->left!=NULL)
		return smallest(t->left);
	else
		return t->data;
}
int largest(tree *t)
{
	if(t->right!=NULL)
		return largest(t->right);
	else
		return t->data;
}