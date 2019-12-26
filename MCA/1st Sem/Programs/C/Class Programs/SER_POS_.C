//Program to Print Series
//1 - 1/22 +1/32 -1/42 +1/52......
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int n,s=1,nxt,f=0,sum=0,avg,i=0;
	clrscr();
	printf("Enter the Limit");
	scanf("%d",&n);
	printf("Fibonacci Series:\n");
	printf("%d",f);
	while(i<n-1){
		printf("\t%d",s);
		sum+=s;
		nxt=f+s;
		f=s;
		s=nxt;
		i++;
	}
	avg=sum/n;
	printf("\nSum of the Series is %d \nAverage of the Series is %d",sum,avg);
	getch();
}