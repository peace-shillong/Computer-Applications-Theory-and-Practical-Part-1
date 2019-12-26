//Program to Find if number is +ve or -ve
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int a;
	clrscr();
	printf("Program to Find If Number entered is Positive or Negative\n Enter any Numbers: ");
	scanf("%d",&a);
	if(a==0)
		printf("%d is Zero and is Neither Positive or Negative Number");
	else if(a<0)
		printf("%d is a Negative Number",a);
	else
		printf("%d is a Positive Number",a);
	getch();
}
