#include<stdio.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main(){
	int gd=DETECT,gm,i,j,x;
	int x1,x2,y1,y2;
	clrscr();
	printf("\n Enter the value of x1:");
	scanf("%d",&x1);
	printf("\n Enter the value of y1:");
	scanf("%d",&y1);
	printf("\n Enter the value of x2:");
	scanf("%d",&x2);
	printf("\n Enter the value of y2:");
	scanf("%d",&y2);
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	for(i=x1;i<=x2;i++)
	{
		j=(((i-x1)*(y2-y1))/(x2-x1))+y1;
		putpixel(i,j,GREEN);
	}
	getch();
	closegraph();
}