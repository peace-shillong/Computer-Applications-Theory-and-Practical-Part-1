#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void dda(int,int,int,int);

void main()
{
	int x1,x2,y1,y2;
	int driver=DETECT,mode;
	clrscr();

	printf("\n");
	printf("Enter the Starting Point X1 Axis : ");
	scanf("%d",&x1);
	printf("Enter the Starting Point Y1 Axis : ");
	scanf("%d",&y1);
	printf("Enter the Starting Point X2 Axis : ");
	scanf("%d",&x2);
	printf("Enter the Starting Point Y2 Axis : ");
	scanf("%d",&y2);

	initgraph(&driver,&mode,"C:\\TC\\BGI");

	dda(x1,y1,x2,y2);

	getch();
	closegraph();
}

void dda(int x0,int y0,int x1,int y1)
{
	int x;
	double m,y,dx,dy;

	dy=y1-y0;
	dx=x1-x0;

	m=dy/dx;

	x=x0;
	y=y0;

	if(dy<dx)
	{
		for(x=x0;x<x1;x++)
		{

			putpixel(x,(int)(y+0.5),GREEN);
			y=m+y;
		}
	}
	else
	{
		for(y=y0;y<y1;y++)
		{
			putpixel(y,(int)(x+0.5),BLUE);
			x=(1/m)+x;

		 }
	}
}
