#include<iostream.h>
#include<conio.h>

void zeroSmaller(int &,int &);

void main()
{
	int x,y;
	clrscr();
	cout<<endl<<"Program to set smaller number to 0"<<endl;
	cout<<"Enter First Number ";
	cin>>x;
	cout<<"Enter Second Number";
	cin>>y;
	cout<<endl<<"Numbers : "<<x<<" "<<y<<endl;
	zeroSmaller(x,y);
	cout<<"Numbers : "<<x<<" "<<y<<endl;
	getch();
}

void zeroSmaller(int &a,int &b){
	int &x=a;
	int &y=b;
	if(x<y)
		x=0;
	else
		y=0;
	cout<<" Smaller number has been set to 0 "<<endl;
}