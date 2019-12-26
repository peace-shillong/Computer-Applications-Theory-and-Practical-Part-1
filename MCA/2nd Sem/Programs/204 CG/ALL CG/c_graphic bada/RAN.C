#include<stdio.h>
#include<conio.h>
void main()
{
	int i ;
	clrscr();
	for(i=0;i<20;i++)
	{
		printf("%d",rand()%10);
		printf("\n\n");
	}
getch();
}