//Program to Find Value of a Number raised to another number
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int no,pow,i,prod=1;
	clrscr();
	printf("To find a Number raised to another Number.");
	printf("\nEnter any Number\n");
	scanf("%d",&no);
	printf("Enter the Number where %d is to be raised to:\n",no);
	scanf("%d",&pow);
	for(i=1;i<=pow;i++){
		prod*=no;
	}
	printf("%d raised to power of %d  is %d",no,pow,prod);
	getch();
}