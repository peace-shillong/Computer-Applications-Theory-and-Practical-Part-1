//Program to Find Product of Four Numbers
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int no,i=1,prod=1;
	clrscr();
	printf("To find Product of 4 Numbers\n");
	while(i<=4){
		printf("Enter a number ");
		scanf("%d",&no);
		if(no!=0){
			prod*=no;
			i++;
		}

	}
	printf("The Product is %d",prod);
	getch();
}