#include<iostream.h>
#include<conio.h>

inline void circleArea(double r);

void main()
{
	double r;
	clrscr();
	cout<<endl<<"Program to find area of circle"<<endl;
	cout<<"Enter the value of the radius ";
	cin>>r;
	circleArea(r);
	getch();
}

void circleArea(double m){
	double area=1;
	const PI=3.14;
	area=PI*m*m;
	cout<<"Area of Circle is "<<area;
}