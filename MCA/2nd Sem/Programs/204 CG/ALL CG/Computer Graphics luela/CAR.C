#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#define ROUND(a) ((int) (a+0.5))
void circle();
void dda(int x1,int y1,int x2,int y2,int c)        //DDA Line Algorithm
{
	int dx,dy,k,steps;
	float ddx,ddy,x=x1,y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	ddx=dx/(float)steps;
	ddy=dy/(float)steps;
	putpixel(ROUND(x),ROUND(y),c);
	for(k=0;k<=steps;k++)
	{
	      putpixel(ROUND(x),ROUND(y),c);
		x+=ddx;
		y+=ddy;
	       putpixel(ROUND(x),ROUND(y),c);
	}
}
void main()
 {
 int gd=DETECT,md,x,y,r;
 initgraph(&gd,&md,"c:\\tc\\bgi");


       dda(70,60,100,50,RED);
       dda(100,50,120,30,RED);
       dda(120,30,170,30,RED);
       dda(170,30,190,50,RED);
       dda(190,50,230,60,RED);
       dda(230,60,230,80,RED);
       dda(70,60,70,80,RED);
       dda(70,80,230,80,RED);
	getch();
	closegraph();
 }

