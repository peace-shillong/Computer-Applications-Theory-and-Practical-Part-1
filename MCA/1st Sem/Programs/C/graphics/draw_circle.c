#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main(){
	int driver , mode ;
	int xC=300,yC=200 ;
	int radius1=100;
	int xD=300,yD=200;
	int radius2=50;
	clrscr();
	driver=DETECT;
	initgraph(&driver,&mode,"c:\\Tc\\bgi");
	setcolor(RED);
	setcolor(GREEN);
	circle(xC,yC,radius1);
	setcolor(BLUE);
	circle(xD,yD,radius2);
	getch();
	closegraph();
}