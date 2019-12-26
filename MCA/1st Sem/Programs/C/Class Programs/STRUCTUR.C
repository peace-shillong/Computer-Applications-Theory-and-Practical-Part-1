#include<stdio.h>
#include<conio.h>

	struct customer
	{
		char name[20];
		char address[30];
		int age;
	};

void main()
{
	struct customer c1;
	clrscr();
	printf("Enter Name: ");
	gets(c1.name);
	printf("Enter Address: ");
	gets(c1.address);
	printf("Enter Age: ");
	scanf("%d",&c1.age);

	printf("Name: %s\nAddress: %s\nAge: %d",c1.name,c1.address,c1.age);
	getch();

}