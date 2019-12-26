//Program to Find Net Salary
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	float da,hra,pf,ns,bs;
	clrscr();
	printf("Calculate the Net Salary\n");
	printf("Enter The Basic Salary ");
	scanf("%f",&bs);
	da=bs*0.45;
	hra=bs*0.3;
	pf=bs*0.08;
	ns=bs+hra+da-pf;
	printf("The Net Salary is %.3f",ns);

	getch();
}