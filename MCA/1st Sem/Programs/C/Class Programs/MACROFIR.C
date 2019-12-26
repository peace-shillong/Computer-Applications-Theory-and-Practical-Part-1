#define GREATEST(x,y,z) if(x>y && x>z)\
				printf("%d is the Biggest",x);\
			else if(y>z)                           \
				printf("%d is the Biggest",y);  \
			else                                     \
				printf("%d is the Biggest",z);

#include<stdio.h>
#include<conio.h>
void main(){
	int a,b,c,grt;
	clrscr();
	printf("Program to Find The Biggest and Smallest\n Enter any three Numbers: ");
	scanf("%d %d %d",&a,&b,&c);
	GREATEST(a,b,c);
	getch();


}