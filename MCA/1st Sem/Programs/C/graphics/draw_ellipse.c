#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define stangle 0
#define endangle 360
void main(){
	int de,md;
	int radius ;
	int xE =300 , yE=250;
	int xE1 =300 , yE1=250;
	int xRad = 150 , yRad =30 ;
	int xRad1= 30 , yRad1 =150;
	clrscr();
	de=DETECT;
	initgraph(&de,&md,"c:\\Tc\\bgi");
	setcolor(BLUE);
  ellipse(xE,yE,stangle,endangle,xRad,yRad);
 ellipse(xE1,yE1,stangle,endangle,xRad1,yRad1);
 
	getch();
	closegraph();
}