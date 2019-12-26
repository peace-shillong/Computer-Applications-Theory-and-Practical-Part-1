//Program to Find if a number is An Armstrong Number
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int x,r,sum=0,ref;
	clrscr();
	printf("Enter any Number");
	scanf("%d",&x);
	ref=x;
	while(x>0){
		r=x%10;
		x=x/10;
		r=r*r*r;
		sum+=r;
	}
	if(sum==ref)
		printf("%d is an Armstrong Number",ref);
	else
		printf("%d is not an Armstrong Number",ref);

	getch();
}