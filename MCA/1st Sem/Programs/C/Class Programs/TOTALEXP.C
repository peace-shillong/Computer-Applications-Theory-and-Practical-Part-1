//Program to Find Total Expenses
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	float price,total_exp,discount,total_dis=0;
	int quantity;
	total_exp=0;
	clrscr();
	printf("To Find Total Expenses\n\n");
	printf("Enter the No of items or Quantity ");
	scanf("%d",&quantity);
	while(quantity>0){
		printf("\nEnter The Price the item %d: ",quantity);
		scanf("%f",&price);
		if(price>1000){
			discount=price*0.1;
			total_dis+=discount;
			}
		else{
			discount=0;
			total_dis+=discount;
			}
		total_exp+=price-discount;
		quantity--;
	}
	printf("Discount : %.2f \nThe Total Expeneses is %.2f",total_dis,total_exp);
	getch();
}
