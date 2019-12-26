#include<iostream.h>
#include<conio.h>
//Program to check Right Triangle
int main(){
	clrscr();
	long a,b,c;
	int i;
	cout<<"Enter The sides of a Triangle\nEnter the length of the base"<<endl;
	cin>>a;
	cout<<"Enter length of the perpendicular"<<endl;
	cin>>b;
	cout<<"Enter length of the hypoteneus"<<endl;
	cin>>c;
	//a*a+b*b=c*c
	if(a*a+b*b==c*c){
		cout<<"Sides of Right angled Triangle";
	}
	else{
		cout<<"There are not the sides of a right angled Triangle";
	}
	getch();
	return 0;
}