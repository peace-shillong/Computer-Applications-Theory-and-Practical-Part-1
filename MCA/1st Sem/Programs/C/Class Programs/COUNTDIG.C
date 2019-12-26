//Program to count the number of digits
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int no,x,count=0;
	clrscr();
	printf("Enter any Number");
	scanf("%d",&no);
	x=no;
	while(x>0){
		x=x/10;
		count++;
	}
	printf("%d has %d digits.",no,count);

	getch();
}