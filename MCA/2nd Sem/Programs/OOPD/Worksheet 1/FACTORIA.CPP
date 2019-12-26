#include<iostream.h>
#include<conio.h>
//Program to Print Factorial of a number
int main(){
	clrscr();
	int no,fact=1;
	int i;
	cout<<"Enter a number:"<<endl;
	cin>>no;

	//a*a+b*b=c*c
	for(i=1;i<=no;i++)
		fact*=i;
	cout<<"Factorial of "<<no<<" is "<<fact;

	getch();
	return 0;
}