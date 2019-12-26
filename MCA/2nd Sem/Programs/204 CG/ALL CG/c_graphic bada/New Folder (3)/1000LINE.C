#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void draw(int,int,int,int);
void main()
{
	int gd=DETECT,gm,i;
	int maxx,maxy;
	int x1,y1,x2,y2;
	x1=10;y1=10;x2=40;y2=40;
	clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	maxx=getmaxx();
	maxy=getmaxy();
	for(i=1;i<=1000;i++)
	{
	    draw(x1,y1,x2,y2);
	    x1=x1+5;
	    x2=x2+5;
	    if(x2>maxx||y2>maxy)
	    {
		x1=20;
		x2=50;
		y1=y1+20;y2=y2+20;
	    }

	}
	getch();
	closegraph();
}
void draw(int x1,int y1,int x2,int y2)
{

	int x,y,j,m;
	m=(y2-y1)/(x2-x1);
	for(j=x1;j<=x2;j=j+m)
	{
		x=j;
		y=m*(x-x2)+y1;
		putpixel(x,y,WHITE);
	}
}
