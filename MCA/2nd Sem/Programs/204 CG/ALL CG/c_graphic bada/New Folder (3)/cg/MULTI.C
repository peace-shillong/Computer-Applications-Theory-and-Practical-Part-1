#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void draw_line(int,int,int,int);
void main()
{
	int x,y,x1,y1,x2,y2,i;
	int gd=DETECT,gm;
	clrscr();

	x1=10;
	y1=10;
	x2=50;
	y2=50;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(i=1;i<1000;i++)
	{
		draw_line(x1,y1,x2,y2);
		x1=x1+100;
		x2=x2+100;
		if(x2>getmaxx())
		{
			x1=10;
			x2=50;
			y1=y1+10;
			y2=y2+10;
		}
		if(y2>getmaxy())
		{
			y1=0;
			y2=0;
			x1=x1+10;
			x2=x2+10;
		}
	}
	getch();
	closegraph();
}

void draw_line(int x1,int y1,int x2,int y2)
{
	int x,y,m1;
	float m;
	m=(y2-y1)/(x2-x1);

	for(x=x1;x<=x2;x=x+m)
	{
		y=m*(x-x1)+y1;
		putpixel(x,y,BLUE);
	}
}





