//Program to Check if employee gets Bonus
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int year,yoj,bonus;
	clrscr();
	printf("\nEnter Current year \n");
	scanf("%d",&year);
	printf("\nEnter your Year of Joining ");
	scanf("%d",&yoj);
	if((year-yoj)>3){
			bonus=2500;
			printf("You Received a bonus of:%d",bonus);
		}
	else
		printf("You Received no bonus.");
	getch();
}
