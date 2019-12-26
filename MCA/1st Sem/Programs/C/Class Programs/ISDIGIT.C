//to check if user input is a digit or not
#include<stdio.h>
#include<conio.h>
#define ISDIGIT(x)  x>=48 && x<=57

void main(){
	char c;
	printf("enter A Digit");
	scanf("%c",&c);
	if(ISDIGIT(c))
		printf("is a digit");
	else
		printf("This is illegal");
		getch();
}