#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void bresenham(int,int,int,int);

void main()
{
	int x1,x2,y1,y2;
	int driver=DETECT,mode;
	clrscr();

	printf("\n");
	printf("Enter the Starting Point - X1 Axis : ");
	scanf("%d",&x1);
	printf("Enter the Starting Point - Y1 Axis : ");
	scanf("%d",&y1);
	printf("Enter the Ending   Point - X2 Axis : ");
	scanf("%d",&x2);
	printf("Enter the Ending   Point - Y2 Axis : ");
	scanf("%d",&y2);

	initgraph(&driver,&mode,"C:\\TC\\BGI");
	bresenham(x1,y1,x2,y2);

	getch();
	closegraph();
}

void bresenham(int x0,int y0,int x1,int y1)
{
	int x;
	double m,y,dx,dy,incE,incNE;

	dx=x1-x0;
	dy=y1-y0;

	x=x0;
	y=y0;
	m=2*dy-dx;

	incE=2*dy;
	incNE=2*(dy-dx);

	for(x=x0;x<x1;x++)
	{
		putpixel(x,y,BLUE);
		if(m<=0)
		{
			m=m+incE;
		}
		else
		{
			y++;
			m=m+incNE;
		}
	}

}
