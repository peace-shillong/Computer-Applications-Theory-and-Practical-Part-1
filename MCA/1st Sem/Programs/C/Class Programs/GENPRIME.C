//Program to Print Prime nos
//2 3
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int n,num,div,p=1;
	clrscr();
	printf("\n Enter the limit:");
	scanf("%d",&num);
	printf("Prime numbers till %d are :\n",num);
	for(n=2;n<=num;n++){
	  for(div=2;div<n;div++){
		  if(n%div==0){
			  p=0;
			  break;
		  }
		  p=1;
	  }
	  if(p){
		  printf("\t %d",n);
	  }
       }
       getch();
}