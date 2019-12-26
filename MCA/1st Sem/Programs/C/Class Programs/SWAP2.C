//Program to Swap without using third variable
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int a,b;
	clrscr();
	printf("Enter two Numbers\n");
	scanf("%d %d",&a,&b);
	printf("Before Swapping. \n a and b is %d %d",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("\nAfter Swapping. \n a and b is %d %d",a,b);

	getch();
}