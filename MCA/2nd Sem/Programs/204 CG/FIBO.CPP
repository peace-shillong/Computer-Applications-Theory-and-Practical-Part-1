#include<iostream.h>
#include<conio.h>
#include<math.h>
int fibo(int);
void main()
{
	int n,f;
	clrscr();
	cout<<"Enter the nth fibonacci number:";
	cin>>n;
	f=fibo(n);
	cout<<"The "<<n<<"th fibonacci number is "<<abs(f);
	getch();
}
int fibo(int n)
{
	while(n>0)

		return fibo(n-1)+fibo(n-2);


}