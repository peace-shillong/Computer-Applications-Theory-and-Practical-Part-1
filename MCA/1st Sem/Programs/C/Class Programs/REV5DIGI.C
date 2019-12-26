//Program to Find the reverse of a number
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int x,r;
	double rev=0;
	clrscr();
	printf("Enter a 5-digit Number");
	scanf("%d",&x);
	while(x>0){
		r=x%10;
		x=x/10;
		rev=(rev*10)+r;
	}
	printf("Reverse is %.0f",rev);

	getch();
}