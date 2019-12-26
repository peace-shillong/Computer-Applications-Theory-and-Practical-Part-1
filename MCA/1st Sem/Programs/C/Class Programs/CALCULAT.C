//Calculator
//Author K.Dkhar
//ywar 2015
#include<stdio.h>
void plus(int,int);
void minus(int,int);
void div(int,int);
void mul(int,int);
void main()
{
	int n,m,c;
	clrscr();
	printf("\nBASIC CALCULATOR MENU\n");
	printf("\nEnter two Numbers");
	scanf("%d %d",&n,&m);
	printf("\n1.Add two numbers");
	printf("\n2. Subtract two numbers");
	printf("\n3. Divide two numbers ");
	printf("\n4. Muntiply two numbers");
	printf("\n5. Exit");
	printf("\nEnter Your Choice.");
	scanf("%d",&c);
	switch(c){
		case 1:
			plus(n,m);
			break;
		case 2:
			minus(n,m);
			break;
		case 3:
			div(n,m);
			break;
		case 4:
			mul(n,m);
			break;
		case 5:
		      printf("Exiting");
		      getch();
		      exit(0);
		default:
			break;
	}
       //	getch();
}
void plus(int a,int b){
	printf("\n Adding Two Numbers %d and %d",a,b);
	printf("\nThe Sum is %d",a+b);
	getch();
}
void minus(int a,int b){

	printf("\n Subtracting Two Numbers %d and %d",a,b);
	printf("\nThe Difference is %d",a-b);
	getch();
}
void div(int a,int b){
	printf("\n Dividing Two Numbers %d and %d",a,b);
	if(a>b)
		printf("\nThe quotient is %d",a/b);
	else if(b>a)
		printf("\nThe quotient is %d",b/a);
	getch();
}
void mul(int a,int b){
	printf("\n Multiplying Two Numbers %d and %d",a,b);
	printf("\nThe Product is %d",a*b);
	getch();
}