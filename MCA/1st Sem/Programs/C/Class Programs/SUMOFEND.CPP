//Program to Find sum of first and last digit of a number
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int x,l,r,sum,n;
	sum=0;
	l=4;
	clrscr();
	printf("Enter a 4-digit Number");
	scanf("%d",&x);
	n=x;
	r=x%10;
	sum=sum+r;
	while(x!=0){
		r=x%10;
		x=x/10;
		//if(l==1 || l==4)
		//sum=sum+r;
		//l--;
	}
	sum=sum+r;
	printf("Sum of First and last digit of %d is %d",n,sum);

	getch();
}