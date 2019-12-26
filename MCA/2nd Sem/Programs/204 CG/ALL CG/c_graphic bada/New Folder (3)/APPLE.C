#include<conio.h>
#include<graphics.h>
#include<dos.h>
void dcurve(float,float,float,float,float,float,float,float);
void boundaryfill(int x, int y, int fcolor, int bcolor)
{
	int a,b,c;
	int x1, y1;
	x1=x;
	y1=y;
	a=getpixel(x,y);
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
		y++;
		x=x1;
		b=getpixel(x,y);
		c=getpixel(x,y);
	}
	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y++;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}

	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
		x=x1;
		y=y1;
		b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
}

void main()
{
	int gd,gm,points[100],num,d[100],i;
	clrscr();
	gd=DETECT;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	dcurve(270,70,280,130,40,20,-10,50);
	dcurve(280,70,285,130,40,20,-10,50);
	line(270,70,280,70);
	line(280,130,285,130);
	boundaryfill(276,75,2,WHITE);
	boundaryfill(282,125,2,WHITE);
	//dcurve(287,90,400,250,700,-300,200,1);
	dcurve(286,120,280,400,700,-350,-300,-300);
	dcurve(280,120,280,400,-700,-350,300,-300);
	boundaryfill(310,411,RED,WHITE);
	boundaryfill(355,145,RED,WHITE);
	boundaryfill(222,104,RED,WHITE);
	boundaryfill(260,125,RED,WHITE);

	getch();
	closegraph();
}
void dcurve(float x1,float y1,float x2,float y2,float dx1,float dy1,float dx2,float dy2)
{
	float u,xu,yu;
	for(u = 0.0;u<=1.0;u=u+0.001)
	{
		xu = x1*((2*u*u*u)-(3*u*u)+1)+x2*((-2*u*u*u)+(3*u*u))+dx1*((u*u*u)-(2*u*u)+u)+dx2*((u*u*u)-(u*u));
		yu = y1*((2*u*u*u)-(3*u*u)+1)+y2*((-2*u*u*u)+(3*u*u))+dy1*((u*u*u)-(2*u*u)+u)+dy2*((u*u*u)-(u*u));
		putpixel(xu,yu,WHITE);
	}
}