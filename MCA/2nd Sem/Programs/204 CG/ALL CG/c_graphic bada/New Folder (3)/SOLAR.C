#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void dellipse(double xc,double yc,double rx,double ry);
void drawcircle(int,int,int,int);
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
      int gd,gm;
      float xc=300,yc=230;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawcircle(300,230,20,WHITE);
      boundaryfill(301,231,YELLOW,WHITE);

      dellipse(xc,yc,80,65);
      drawcircle(380,230,10,WHITE);
      boundaryfill(381,231,7,WHITE);

      dellipse(xc,yc,120,105);
      drawcircle(380,150,15,WHITE);
      boundaryfill(381,151,8,WHITE);

      dellipse(xc,yc,160,145);
      drawcircle(350,90,20,WHITE);
      boundaryfill(351,91,1,WHITE);

      dellipse(xc,yc,200,185);
      drawcircle(485,160,15,WHITE);
      boundaryfill(486,161,4,WHITE);
      getch();
      closegraph();
}
void drawcircle(int xc,int yc,int r,int bcolor)
{
	int x,maxx,i,y,pk;
	x=0;
	y=r;
	pk=1-r;
	while(x<y)
	{
		if(pk<0)
		{
			pk=pk+2*x+3;
			x=x+1;
			y=y;
		}
		else
		{
			pk=pk+2*x-2*y+5;
			x=x+1;
			y=y-1;

		}
		putpixel(xc+x,yc+y,bcolor);
		putpixel(xc+y,yc+x,bcolor);
		putpixel(xc+y,yc-x,bcolor);
		putpixel(xc+x,yc-y,bcolor);
		putpixel(xc-x,yc-y,bcolor);
		putpixel(xc-y,yc-x,bcolor);
		putpixel(xc-y,yc+x,bcolor);
		putpixel(xc-x,yc+y,bcolor);
		putpixel(xc-r,yc,bcolor);
		putpixel(xc+r,yc,bcolor);

	}
}
void dellipse(double xc,double yc,double rx,double ry)
{
	double pk,x=0,y;
	pk=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
	y=ry;
	putpixel(xc,(y+yc),7);
	putpixel(xc,(-y+yc),7);
	// drawing the first region
	do
	{
		x++;
		if(pk<0)
			pk=pk+(2*ry*ry*x)+(ry*ry);
		else if(pk>=0)
		{
			y--;
			pk=pk+(2*ry*ry*x)+(ry*ry)-(2*rx*rx*y);
		}
		putpixel((x+xc),(y+yc),7);
		putpixel((x+xc),(-y+yc),7);
		putpixel((-x+xc),(y+yc),7);
		putpixel((-x+xc),(-y+yc),7);
	}while((ry*ry*x)<(rx*rx*y));
	// end of region 1

	// drawing the second region
	pk=(ry*ry*pow((x+1/2),2))+(rx*rx*pow((y-1),2))-(rx*rx*ry*ry);
	putpixel((x+xc),(y+yc),7);
	putpixel((x+xc),(-y+yc),7);
	putpixel((-x+xc),(y+yc),7);
	putpixel((-x+xc),(-y+yc),7);
	do
	{
		y--;
		if(pk>0)
			pk=pk-2*rx*rx*y+rx*rx;
		else
			pk=pk-2*rx*rx*y+rx*rx+2*ry*ry*++x;
		putpixel((x+xc),(y+yc),7);
		putpixel((x+xc),(-y+yc),7);
		putpixel((-x+xc),(y+yc),7);
		putpixel((-x+xc),(-y+yc),7);
	}while(y>=0);
	// end of region 2
}