#include<iostream.h>
#include<conio.h>
#include<dos.h>
//Program to generate Fibonacci series given nth term
int main(){
	clrscr();
	long n,f,s,nxt;
	int j,k;
	f=0;s=1;
	cout<<"Enter nth term :"<<endl;
	cin>>n;

	cout<<"Fibonacci series is:"<<endl<<f;
	for(int i=1;i<n;i++){
		cout<<" "<<s;
		nxt=f+s;
		f=s;
		s=nxt;
	}
	//
	/*
	for(j=1000;j>=1;j-=1)
	{
		cout<<"\a\a";
		delay(90);
		cout<<" \a";
	}*/
	getch();
	return 0;
}