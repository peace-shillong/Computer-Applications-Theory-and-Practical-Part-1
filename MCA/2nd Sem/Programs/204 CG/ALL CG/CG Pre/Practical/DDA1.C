#include<stdio.h>
#include<graphics.h>

void main()
{
	int x1,y1,x2,y2,gd=DETECT,gm,dx,x,y,m;

	clrscr();

	printf("Enter the coordinates of (x1,y1) : ");
	scanf("\%d %d",&x1,&y1);
	printf("Enter the coordinates of (x2,y2) : ");
	scanf("\%d %d",&x2,&y2);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	m=(y2-y1)/(x2-x1);
	x=x1;
	y=y1;
	while(x<=x2 && y<=y2 && abs(m)>=1 )
	{
		putpixel(x,y,4);
		y=y+1;
		dx=(1/m)+x;
		x=dx;
	}
	getch();
	closegraph();
}
