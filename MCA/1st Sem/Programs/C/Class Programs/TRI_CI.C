#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void main()
{
	int gd=DETECT,gm,t[]={200,100,100,200,300,200,200,100};
	initgraph(&gd,&gm,"C:\\TC\\bgi");

	circle(200,200,100);
	drawpoly(4,t);



	getch();
}