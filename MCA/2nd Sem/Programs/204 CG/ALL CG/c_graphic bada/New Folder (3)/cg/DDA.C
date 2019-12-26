#include<graphics.h>
#include<conio.h>
#include<math.h>


void main()
{
	int x,y,x1,y1,k,x2,y2,m,i,t;
	float dx,dy,xi,yi;
	int driver=DETECT,mode;
	clrscr();

	printf("\nEnter the initial points:");
	scanf("%d %d",&x1,&y1);
	printf("\nEnter the terminal points:");
	scanf("%d %d",&x2,&y2);
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	dx=x2-x1;
	dy=y2-y1;

	if((abs(dx))>(abs(dy)))
		k=abs(dx);
	else
		k=abs(dy);

	xi=dx/k;
	yi=dy/k;

	x=x1;
	y=y1;

	for(i=1;i<t;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel(x,y,GREEN);
	}
	getch();
	closegraph();

 }









