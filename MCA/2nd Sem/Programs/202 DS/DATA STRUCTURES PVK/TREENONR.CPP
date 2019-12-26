#include<iostream.h>
#include<conio.h>
struct tree {
	int data;
	struct tree *left,*right;

};
int top=-1;
void push(tree *);
struct tree *s[100];
void main(){
	struct tree *t,*p;
	clrscr();

	cout<<" CREATE NODE "<<endl;
	p=new(tree);
	cout<<"Enter Data";
	cin>>p->data;
	p->left=p->right=NULL;
	getch();
	cout<<"DATA "<<p->data;

}
void non_rec_inorder(tree *t){
	while(1){
		while(t!=NULL){
			push(t);
			t=t->left;
		}
		if(top==-1){
			break;
		}
	}
}
void push(tree *t){
	s[top]=t;
}

