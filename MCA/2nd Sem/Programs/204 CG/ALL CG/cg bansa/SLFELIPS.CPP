#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
void main()
{
	int driver=DETECT,mode;
	int x1,x2,y1,y2,r1,r2;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	line(10,200,100,200);
	getch();
	closegraph();
}