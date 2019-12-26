//Program to Add two Numbers
//Author K. Dkhar
//2015
#include<stdio.h>
#include<conio.h>

void main(){
      int n,n2,sum;
      clrscr();
      printf("Enter first Number");
      scanf("%d",&n);
      printf("Enter Second Number");
      scanf("%d",&n2);
      sum = n+n2;
      printf("Addition of %d and %d is %d",n,n2,sum);
      getch();
}