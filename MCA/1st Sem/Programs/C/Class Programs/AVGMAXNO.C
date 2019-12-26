//Program to Find Average of Max n number
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int no,max,count,sum=0,div,average;
	clrscr();
	printf("To find Average of Max n Numbers");
	printf("\nEnter the Max N or Max limit");
	scanf("%d",&max);
	div=max;
	for(count=1;count<=max;count++){
		printf("Enter a number");
		scanf("%d",&no);
		if(no>0)
			sum+=no;
		else
			div--;
	}
	average=sum/div;
	printf("The Average is %d",average);
	getch();
}