#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawcircle(float xc,float yc,float r);
void main()
{
	int gd = DETECT , gm ;
	float r , i , xc , yc , xmin , xmax ;
	float x,y , y1 , rad , xres , yres ;
	clrscr();
	initgraph(&gd,&gm,"c:\tc\bgi");
	printf("\nEnter the value for Xc and Yc:");
	scanf("%f%f",&xc,&yc);
	printf("\nEnter the radius:");
	scanf("%f",&r);
	drawcircle(xc, yc, r);
	getch();
	closegraph();

}
void drawcircle(float xc,float yc,float r)
{
	float minx,maxx,y=0;
	int i;
	minx=xc-r;
	maxx=xc+r;
	for(i=minx;i<maxx;i++)
	{
	     y=sqrt((r*r)-((i-xc)*(i-xc)))+yc;
	     putpixel(i,y,WHITE);
	     y=-sqrt((r*r)-((i-xc)*(i-xc)))+yc;
	     putpixel(i,y,WHITE);
	}
}