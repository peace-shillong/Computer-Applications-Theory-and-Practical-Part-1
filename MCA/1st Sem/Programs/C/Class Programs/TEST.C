#include<stdio.h>
#include<conio.h>
void main(){
	int a;
	clrscr();
	if(3+2%5)
		printf("This Works\n");
	if(a=10)
		printf("This Works\n");
	if(-5)
		printf("This Works\n");
	a=!a;
	if(a)
		printf("This Does not  Works");
	printf("%d",a);

	getch();
}