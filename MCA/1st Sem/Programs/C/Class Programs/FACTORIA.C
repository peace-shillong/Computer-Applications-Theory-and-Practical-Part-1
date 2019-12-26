//Program to Find Factorial of a Number
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int no,fact=1,i;
	clrscr();
	printf("To find Factorial of a Number");
	printf("\nEnter any Number");
	scanf("%d",&no);
	for(i=1;i<=no;i++){
		fact*=i;
	}
	printf("The Factorial is %d",fact);
	getch();
}