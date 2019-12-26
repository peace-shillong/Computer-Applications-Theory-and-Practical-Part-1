#include<iostream.h>
#include<conio.h>
//To Find a given number is a palindrome or not
void main(){
	long no,rev=0,t,r;
	clrscr();
	cout<<"Enter a Number: ";
	cin>>no;
	t=no;
	while(t>0){
		r=t%10;
		t=t/10;
		rev=rev*10+r;
	}
//	cout<<no<<" "<<rev;
	if(no==rev){
		cout<<"The Number "<<no<<" is a Palindrome";
	}
	else
		cout<<"The Number "<<no<<" is not a Palindrome";
	getch();

}