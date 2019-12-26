#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
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
      int gd,gm,xc,yc,r,fcolor,bcolor;
      gd=DETECT;
      clrscr();
      printf("\n\t Enter the centre(xc and yc): ");
      scanf("%d %d",&xc,&yc);
      printf("\n\t Enter the radius: ");
      scanf("%d",&r);
      printf("\n\t Enter the boundary color code: ");
      scanf("%d",&bcolor);
      printf("\n\t Enter the fill color code: ");
      scanf("%d",&fcolor);
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawcircle(xc,yc,r,bcolor);
      boundaryfill(1+xc,1+yc,fcolor,bcolor);
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
