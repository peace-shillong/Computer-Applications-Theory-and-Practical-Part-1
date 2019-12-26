#include<iostream.h>
#include<conio.h>
//To Find a given number is Odd or Even
void main(){
	int no;
	clrscr();
	cout<<"Enter a Number: ";
	cin>>no;
	if(no%2==0){
		cout<<"The Number "<<no<<" is Even";
	}
	else
		cout<<"The Number "<<no<<" is Odd";
	getch();

}