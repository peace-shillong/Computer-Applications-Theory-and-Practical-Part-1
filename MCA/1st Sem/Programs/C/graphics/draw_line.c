#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#define IGNORED 0
void main(){
	int de,md;
	int xC=300,yC=200;
	int x0=300,y0=100;
	int x1=400,y1=200;
	int x2=400,y2=200;
	int x3=200,y3=200;
	int x4=200,y4=200;
	int x5=300,y5=100;
	int radius=100;
	clrscr();
	de=DETECT;
	initgraph(&de,&md,"c:\\Tc\\bgi");
	setcolor(BLUE);
	circle(xC,yC,radius);
	setcolor(YELLOW);
	setlinestyle(SOLID_LINE,IGNORED,THICK_WIDTH);
	line(x0,y0,x1,y1);
	line(x2,y2,x3,y3);
	line(x4,y4,x5,y5);
	getch();
	closegraph();
}