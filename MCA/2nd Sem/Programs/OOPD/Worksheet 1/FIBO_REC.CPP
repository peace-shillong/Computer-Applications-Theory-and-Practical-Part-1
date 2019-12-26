#include<iostream.h>
#include<conio.h>
int fibo(int n);
//Program to generate Fibonacci series given nth term using recursion
int main(){
	clrscr();
	long n;
	int j;

	cout<<"Enter nth term :"<<endl;
	cin>>n;

	cout<<"Fibonacci series is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<fibo(i);

	}
	getch();
	return 0;
}

int fibo(int n){

	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fibo(n-1)+fibo(n-2);
}