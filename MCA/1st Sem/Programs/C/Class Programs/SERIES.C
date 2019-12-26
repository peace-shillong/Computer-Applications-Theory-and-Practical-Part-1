//Program to Print Series
// 1 -1/22 1/32 -1/42 1/52
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int n,i;
	clrscr();
	printf("Enter the Limit");
	scanf("%d",&n);
	printf("\nThe Series\n1");
	for(i=2;i<=n;i++){

		if(i%2==0)
			printf("\t-1/%d",(11*i)-(i-2));
		else
			printf("\t+1/%d",(11*i)-(i-2));
	}
	getch();
}