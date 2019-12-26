//Program to Find biggest and smallest
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int a,b,c;
	clrscr();
	printf("Program to Find The Biggest and Smallest\n Enter any three Numbers: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b && a>c)
		printf("%d is the Biggest",a);
	else if(b>c)
		printf("%d is the Biggest",b);
	else
		printf("%d is the Biggest",c);
	getch();
}
