//Program to Find Average of three Numbers
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int a,b,c,average;
	clrscr();
	printf("To find Average of three Numbers");
	printf("\nEnter the three Numbers");
	scanf("%d %d %d",&a,&b,&c);
	average=(a+b+c)/3;
	printf("The Average is %d",average);
	getch();
}