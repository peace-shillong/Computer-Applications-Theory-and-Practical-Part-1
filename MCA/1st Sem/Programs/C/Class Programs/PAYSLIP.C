//Program to Find Net Salary, Gross Salary and Display pay slip
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	float da,hra,pf,ns,gs,bs,bonus;
	int des_code,emp_no=1;
	clrscr();
	printf("To Display pay slip\n");
	printf("Enter The Basic Salary\n ");
	scanf("%f",&bs);
	printf("Enter The Designation Code\n");
	scanf("%d",&des_code);
	da=bs*0.5;
	hra=bs*0.4;
	pf=bs*0.1;
	if(des_code==101)
		bonus=2000;
	else
		bonus=1550;
	ns=bs+hra+da+bonus-pf;
	gs=ns+pf;
	printf("The Pay Slip is Given Below\n\n");
	printf("Emp no\tBasic Pay\tDA\tHRA\tPF\t Bonus\t G.S\t Net Salary\n\n");
	printf("%d\t%.0f\t\t%.0f \t%.0f\t %.0f\t %.0f\t %.0f \t %.0f",emp_no,bs,da,hra,pf,bonus,gs,ns);

	getch();
}