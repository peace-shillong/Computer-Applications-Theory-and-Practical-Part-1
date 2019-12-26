#include<iostream.h>
#include<conio.h>
//Program to Find GCD of two Numbers
int main(){
	clrscr();
	long a,b,c,gcd;
	//int i,j,k;
	cout<<"Enter First Number :"<<endl;
	cin>>a;
	cout<<"Enter Second Number"<<endl;
	cin>>b;
	if(a>b)
		c=a;
	else
		c=b;
	for(int i=1;i<c;i++){
		if(a%i==0 && b%i==0)
		{
		       //	a=a/i;

		      //	b=b/i;
			gcd=i;
		}
	}
	cout<<gcd;
	getch();
	return 0;
}