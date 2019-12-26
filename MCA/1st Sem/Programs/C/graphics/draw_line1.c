#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define getmaxx() 500
#define getmaxy() 450
void main()
{
	int driver=DETECT,mode;
	int x=0,y=0;
	int x1,y1;
	x1=getmaxx()-50;
	y1=getmaxy();
	initgraph(&driver,&mode,"C:\\TC\\bgi");
	for(x=1;x<x1;x+=50)
	{
		line(x,y,x1,y);
		setcolor(GREEN);
		for(y=1;y<y1;y+=50)
		{
			line(x,y,x,y1);
		}
	}
	for(x=1;x<y1;x+=50)
	{

		line(x,y,x,y);

		for(y=1;y<x1;y+=50)
		{
			line(x,y,x1,y);
		}
	}
		getch();
	closegraph();
}