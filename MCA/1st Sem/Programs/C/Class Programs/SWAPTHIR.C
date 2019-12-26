//Program to Swap using third variable
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int a,b,c;
	clrscr();
	printf("Swapping using a third variable.");
	printf("\nEnter Two Numbers\n");
	scanf("%d %d",&a,&b);
	printf("Before Swapping. \n a and b is %d %d",a,b);
	c=a;
	a=b;
	b=c;
	printf("\nAfter Swapping. \n a and b is %d %d",a,b);
	getch();
}