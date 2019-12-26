#include<stdio.h>
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
	{		while(c!=bcolor)
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
	int gd,gm;
	clrscr();
	gd=DETECT;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	//putpixel(186,80,RED);
	dcurve(190,45,190,99,0,-5,100,200);//curves
	dcurve(200,40,200,102,0,0,100,200);

	dcurve(200,100,300,100,100,-100,100,-100);//stick
	dcurve(90,100,190,100,100,-200,130,-100);
	boundaryfill(185,70,BROWN,WHITE);
	boundaryfill(182,78,BROWN,WHITE);
	boundaryfill(186,82,BROWN,WHITE);

	dcurve(100,30,300,30,100,100,100,100);//branch
	dcurve(100,40,300,40,100,100,100,100);
	dcurve(100,30,100,40,100,100,100,100);
	dcurve(300,30,300,40,100,100,100,100);
	boundaryfill(139,40,BROWN,WHITE);
	boundaryfill(195,38,BROWN,WHITE);
	boundaryfill(223,28,BROWN,WHITE);

	dcurve(150,100,150,200,-50,-10,100,100);//1st row
	dcurve(150,100,150,200,100,-10,-100,-10);
	dcurve(190,100,190,200,-50,-10,100,100);
	dcurve(190,100,190,200,100,-10,-100,-10);
	dcurve(230,100,230,200,-50,-10,100,100);
	dcurve(230,100,230,200,100,-10,-100,-10);
	boundaryfill(150,150,GREEN,WHITE);
	boundaryfill(190,190,GREEN,WHITE);
	boundaryfill(235,150,GREEN,WHITE);

	dcurve(170,190,170,290,-50,-10,100,100);//2nd row
	dcurve(170,190,170,290,100,-10,-100,-10);
	dcurve(210,190,210,290,-50,-10,100,100);
	dcurve(210,190,210,290,100,-10,-100,-10);
	boundaryfill(170,200,GREEN,WHITE);
	boundaryfill(210,210,GREEN,WHITE);

	dcurve(190,280,190,380,-50,-10,100,100);//3rd row
	dcurve(190,280,190,380,100,-10,-100,-10);
	boundaryfill(190,290,GREEN,WHITE);

	boundaryfill(172,150,GREEN,WHITE);//spaces
	boundaryfill(212,150,GREEN,WHITE);
	boundaryfill(192,240,GREEN,WHITE);

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