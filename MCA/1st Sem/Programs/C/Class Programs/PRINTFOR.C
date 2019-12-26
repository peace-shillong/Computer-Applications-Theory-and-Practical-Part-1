//Program For Formatted Print
//Author K. Dkhar
//Year 2015
#include<stdio.h>
#include<conio.h>
void main(){
	int i=12345; float x=345.678;
	float f_var = 10.12576893;
	int wid_prec;
	int a,b;
	clrscr();
	//First
	printf("%3d %5d %8d \n",i,i,i);
	printf("%3f %10f %13f \n",x,x,x);
	//Second
	printf("Output 1: %f\n",f_var);
	printf("Output 2: %20f\n",f_var);
	printf("Output 3: %-20f\n",f_var);
	printf("Output 4: %+f\n Enter Wid_prec\n",f_var);
	scanf("%i",&wid_prec);
	printf("Output 5: %*f \n",wid_prec,f_var);
	printf("Output 6: %.5f \n Enter Value\n",f_var);
	//Third
	scanf("%2d %2d",&a,&b);
	printf("a=%d b=%d",a,b);
	getch();
}
