#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\bgi");

	ellipse(100,100,0,360,50,10);
	ellipse(100,100,0,360,10,50);


	getch();
}