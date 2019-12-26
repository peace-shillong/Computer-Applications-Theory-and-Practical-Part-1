//MENU TREE
#include<iostream.h>
#include<conio.h>
struct tree{
	int data;
	struct tree *left,*right;
};
struct tree *build(int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
void main(){
	int ch,n;
	tree *s;
	do{
	clrscr();
	cout<<"\t BINARY TREE PROGRAM\n MENU";
	cout<<"\n1. Create tree";
	cout<<"\n2. Inorder Traversal";
	cout<<"\n3. Preorder Traversal";
	cout<<"\n4. Postorder Traversal";
	cout<<"\n5. Exit";
	cout<<"\nEnter Choice\n";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"\nEnter no of nodes";
			cin>>n;
			s=build(n);
			break;
		case 2:
			inorder(s);
			break;
		case 3:
			preorder(s);
			break;
		case 4:
			postorder(s);
			break;
		case 5:
			//exit(0);
			break;
		default:
			cout<<"\nWrong Input.";
		}
		getch();
	}while(ch!=5);
	getch();
}
struct tree *build(int n){
	int x,nl,nr;
	tree *t;
	if(n==0)
		t=NULL;
	else
	{
		nl=n/2;
		nr=n-nl-1;
		t=new tree;
		cout<<"Enter Data";
		cin>>x;
		t->data=x;
		t->left=build(nl);
		t->right=build(nr);
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
void preorder(tree *t){
	if(t!=NULL){
		cout<<" "<<t->data;
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(tree *t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		cout<<" "<<t->data;
	}
}