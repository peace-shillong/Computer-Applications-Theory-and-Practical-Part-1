#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define IGNORED 0

void main()
{
	int driver=DETECT,mode;
	int x,y,x1,y1,x2,y2;

	initgraph(&driver,&mode,"C:\\TC\\BGI");

	x1=y1=0;
	x2=y2=1000;
	for(x=x2;x++;x<=x2)
	{
		y=((x-x1)/(x1-x2))*(y1-y2)+y1;
		putpixel(x,y,RED);
	}

	getch();
	closegraph();
}