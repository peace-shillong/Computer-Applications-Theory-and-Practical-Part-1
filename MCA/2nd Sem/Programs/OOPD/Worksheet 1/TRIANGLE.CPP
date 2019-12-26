#include<iostream.h>
#include<conio.h>
//Program to Check Whether three numbers represent the sides of a triangle
int main(){
	clrscr();
	int a,b,c;
	cout<<"Enter First Side"<<endl;
	cin>>a;
	cout<<"Enter Second Side"<<endl;
	cin>>b;
	cout<<"Enter Third Side"<<endl;
	cin>>c;
	if(a+b>=c && a+c>=b && b+c>=a){
	  cout<<"Given Sides Represents a Triangle";
	}
	else{
		cout<<"There are not the sides of a Triangle";
	}
	getch();
	return 0;
}