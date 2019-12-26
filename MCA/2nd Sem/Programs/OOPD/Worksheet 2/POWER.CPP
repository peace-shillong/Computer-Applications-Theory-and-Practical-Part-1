#include<iostream.h>
#include<conio.h>

double power(double m,int n=2);

void main()
{
	int n;
	double m;
	clrscr();
	cout<<endl<<"Program to find a number raised to another number"<<endl;
	cout<<"Enter the value of m ";
	cin>>m;
	cout<<"Enter the value of n "<<endl<<"Enter a negative number to SKIP ";
	cin>>n;
	if(n>=0)
		cout<<endl<<power(m,n);
	else
		cout<<endl<<power(m);
	cout<<"\n";
	getch();
}

double power(double m,int n){
	double mn,pow=1;
	int nn;
	mn=m;
	nn=n;
	for(int i=0;i<nn;i++){
	      pow=pow*mn;
	}
	return pow;
}