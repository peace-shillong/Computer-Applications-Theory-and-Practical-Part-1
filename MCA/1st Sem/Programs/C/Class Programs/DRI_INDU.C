//Program to Check if driver is insured or not
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	char m,s;
	int age;
	clrscr();
	printf("\nEnter your marital status (Y/N)\n");
	scanf("%c",&m);
	if((m=='Y')||(m=='y')){
		printf("You are insured");
	}
	else if((m=='N')||(m=='n')){

	printf("\nEnter your Gender (M/F)");
	scanf("%s",&s);
	printf("\nEnter Your Age ");
	scanf("%d",&age);
		if((s=='M')||(s=='m')){
			if(age>30)
				printf("You are insured");
			else
				printf("You are Not insured!");
		}else{
			if(age>25)
				printf("You are insured");
			else
				printf("You are Not insured!");

		}
	}else
		printf("Sorry You are not Insured.");

	getch();
}
