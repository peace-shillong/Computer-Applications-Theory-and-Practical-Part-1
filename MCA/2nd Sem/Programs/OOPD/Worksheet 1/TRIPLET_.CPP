#include<iostream.h>
#include<conio.h>
//Program to Print all Pythogorian Triplets from 1-9999
int main(){
	clrscr();
	long a,b,c;
	//int i,j,k;
	cout<<"The Pythogorian Triplets :"<<endl;
	//a*a+b*b=c*c
	for(a=1;a<=9999;a++){
	   for(b=1;b<=9999;b++){
		for(c=1;c<=9999;c++){
		if(a*a+b*b==c*c ){
			cout<<a<<" "<<b<<" and "<<c<<endl;//"Sides of Right angled Triangle";
		}
		/*else if(a*a+c*c==b*b ){
			cout<<a<<" "<<c<<" ="<<b<<endl;//"Sides of Right angled Triangle";
		}
		else if(c*c+b*b==a*a ){
			cout<<b<<" "<<c<<" ="<<a<<endl;//"Sides of Right angled Triangle";
		}*/
		else{
		 //	cout<<"There are not the sides of a Triangle";
		}
		}
	    }
	}
	getch();
	return 0;
}