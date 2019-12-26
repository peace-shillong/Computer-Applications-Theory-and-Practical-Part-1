#include<iostream.h>
#include<conio.h>
void swap(int *, int *);
void main(){

	int a,b;
	a=10,b=5;int *p,*q;
	p=&a;q=&b;
	clrscr();
	cout<<a<<" "<<b<<endl;
	swap(p,q);
	cout<<a<<" "<<b;
	getch();
}

void swap(int *x,int *y){

	int t;
	t=*x;
	x=y;
	*y=t;
}