#include<iostream.h>
#include<conio.h>

struct tree{
	int data;
	struct tree *left,*right;
};

tree *build(int n){
	int nl,nr;
	struct tree *t;
	if(n==0)
		t=NULL;
	else{
		nl=n/2;
		nr=n-nl-1;
		t=new tree;
		cout<<"Enter Data ";
		cin>>t->data;
		t->left=build(nl);
		t->right=build(nr);
	}
	return t;

}
void main(){

	struct tree *t;
	int n;
	clrscr();
	cout<<"Enter Number of Nodes ";
	cin>>n;
	t=build(n);

	preorder(t);
	getch();
}